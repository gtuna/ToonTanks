// Fill out your copyright notice in the Description page of Project Settings.

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Tank.h"

ATank::ATank()
{
    SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
    SpringArm->SetupAttachment(RootComponent);

    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    Camera->SetupAttachment(SpringArm);

}

void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ATank::Move);
    PlayerInputComponent->BindAxis(TEXT("Turn"), this, &ATank::Turn);
}

void ATank::Move(float Value)
{
    FVector DeltaLocation = FVector::ZeroVector;
    float DeltaTime = UGameplayStatics::GetWorldDeltaSeconds(this);

    DeltaLocation.X = Value * MoveSpeed * DeltaTime;

   	AddActorLocalOffset(DeltaLocation, true);
}

void ATank::Turn(float Value)
{   
    FRotator DeltaRotation = FRotator::ZeroRotator;

    // float DeltaTime = GetWorld()->GetDeltaSeconds(); 
    float DeltaTime = UGameplayStatics::GetWorldDeltaSeconds(this);

    DeltaRotation.Yaw = Value * TurnSpeed * DeltaTime;

    AddActorLocalRotation(DeltaRotation, true);
}

