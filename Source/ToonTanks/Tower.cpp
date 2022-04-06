// Fill out your copyright notice in the Description page of Project Settings.

#include "Kismet/GameplayStatics.h"
#include "Tank.h"
#include "Tower.h"

void ATower::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    if (Tank)
    {  
        // Find the distance to the Tank
        float Distance = FVector::Dist(GetActorLocation(), Tank->GetActorLocation());


        //Check to see if the Tank is in range
        if (Distance <= FireRange)
        {
            //if in range , rotate the turret toward Tank
            RotateTurret(Tank->GetActorLocation());
        }
        
    }
}

void ATower::BeginPlay()
{
    Super::BeginPlay();

    Tank = Cast<ATank>( UGameplayStatics::GetPlayerPawn(this,0));

}
