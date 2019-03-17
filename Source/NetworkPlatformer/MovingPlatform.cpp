// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;
	SetMobility(EComponentMobility::Movable);
}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();


	if (HasAuthority())
	{
		SetReplicates(true);
		SetReplicateMovement(true);
	}

	StartWorldLocation = GetActorLocation();
	TargetWorldLocation = GetTransform().TransformPosition(TargetLocation);
}

void AMovingPlatform::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if (HasAuthority())
	{
		FVector Direction = (TargetWorldLocation - StartWorldLocation).GetSafeNormal();
		FVector SelfToTarget = TargetWorldLocation - GetActorLocation();
		if (FVector::DotProduct(SelfToTarget, Direction) > 0)
		{
			AddActorWorldOffset(Direction*Speed*DeltaSeconds);
		}
		else
		{
			Swap(StartWorldLocation, TargetWorldLocation);
		}

	}
}
