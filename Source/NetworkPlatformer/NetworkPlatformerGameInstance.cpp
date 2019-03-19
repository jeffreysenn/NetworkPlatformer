// Fill out your copyright notice in the Description page of Project Settings.

#include "NetworkPlatformerGameInstance.h"

#include "Engine/Engine.h"
#include "GameFramework/PlayerController.h"

void UNetworkPlatformerGameInstance::Init()
{
	UE_LOG(LogTemp, Warning, TEXT("Init"));
}

void UNetworkPlatformerGameInstance::Host()
{
	if (ensure(GEngine))
	{
		GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Green, TEXT("Hosting"));
	}

	UWorld* World = GetWorld();
	if (ensure(World))
	{
		World->ServerTravel("/Game/NetworkPlatformer/TestMap?listen");
	}
}

void UNetworkPlatformerGameInstance::Join(const FString &Address)
{
	if (ensure(GEngine))
	{
		GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Green, FString::Printf(TEXT("Joining %s"), *Address));
	}

	APlayerController* PlayerController = GetFirstLocalPlayerController();
	if (ensure(PlayerController))
	{
		PlayerController->ClientTravel(Address, ETravelType::TRAVEL_Absolute);
	}
}
