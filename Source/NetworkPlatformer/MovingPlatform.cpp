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
}

void AMovingPlatform::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if (HasAuthority())
	{
		MoveForwardAtSpeed(Speed, DeltaSeconds);

	}
}

void AMovingPlatform::MoveForwardAtSpeed(float Speed, float DeltaSeconds)
{
	AddActorWorldOffset(GetActorForwardVector()*Speed*DeltaSeconds);
}
