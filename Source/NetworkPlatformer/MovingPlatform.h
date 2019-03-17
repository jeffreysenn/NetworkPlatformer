// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MovingPlatform.generated.h"

/**
 * 
 */
UCLASS()
class NETWORKPLATFORMER_API AMovingPlatform : public AStaticMeshActor
{
	GENERATED_BODY()

public:
	AMovingPlatform();

protected:
	UPROPERTY(EditAnywhere, Category = "Movement")
	float Speed = 10;

public:
	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaSeconds) override;

protected:
	void MoveForwardAtSpeed(float Speed, float DeltaSeconds);
};
