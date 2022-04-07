// Fill out your copyright notice in the Description page of Project Settings.

#include "Kismet/GameplayStatics.h"
#include "Tank.h"
#include "ToonTanksGameMode.h"
#include "ToonTanksPlayerController.h"
#include "Tower.h"

void AToonTanksGameMode::ActorDied(AActor* DeadActor)
{
    if (DeadActor == Tank)
    {
        Tank->HandleDestruction();
        if (ToonTanksPlayerController)
        {
            ToonTanksPlayerController->SetPlayerEnabledState(false);
        }
        
    }
    else if ( ATower* DestroyedTower = Cast<ATower>(DeadActor))
    {
        DestroyedTower->HandleDestruction();
    }
}

void AToonTanksGameMode::BeginPlay() 
{
    Super::BeginPlay();

    HandleGameStart();
}

void AToonTanksGameMode::HandleGameStart()
{

    Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));
    ToonTanksPlayerController = Cast<AToonTanksPlayerController>(UGameplayStatics::GetPlayerController(this, 0));

    if (ToonTanksPlayerController)
    {
        ToonTanksPlayerController->SetPlayerEnabledState(false);

        FTimerHandle PlayerEnabledTimerHandle;

        FTimerDelegate InputDelegate = FTimerDelegate::CreateUObject(   
            ToonTanksPlayerController, 
            &AToonTanksPlayerController::SetPlayerEnabledState, 
            true
        );

        GetWorldTimerManager().SetTimer(
            PlayerEnabledTimerHandle, 
            InputDelegate, 
            StartDelay, 
            false
        );
    }

}