// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "NetworkPlatformerGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class NETWORKPLATFORMER_API UNetworkPlatformerGameInstance : public UGameInstance
{
	GENERATED_BODY()
	

public:
	virtual void Init();

	UFUNCTION(Exec)
	void Host();

	UFUNCTION(Exec)
	void Join(const FString &Address);
};
