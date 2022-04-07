// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ToonTanksGameMode.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API AToonTanksGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:

	void ActorDied(AActor* DeadActor);

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//BlueprintImplementableEvent: dont need to give function body, but we can call it from cpp class
	UFUNCTION(BlueprintImplementableEvent, Category = "GameMode")
	void StartGame();

private:
	class ATank* Tank;
	class AToonTanksPlayerController* ToonTanksPlayerController;

	float StartDelay = 3.f;
	void HandleGameStart();
};
