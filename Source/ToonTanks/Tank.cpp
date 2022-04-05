// Fill out your copyright notice in the Description page of Project Settings.

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Tank.h"

ATank::ATank()
{
    SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
    SpringArm->SetupAttachment(RootComponent);

    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    Camera->SetupAttachment(SpringArm);
    UE_LOG(LogTemp, Warning, TEXT("TUNA DEBUG Value: %f"), 10000.f);

}

void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
    UE_LOG(LogTemp, Warning, TEXT("TUNA DEBUG Value: %f"), 55555.f);

    PlayerInputComponent->BindAxis(("MoveForward"), this, &ATank::Move);
}

void ATank::Move(float Value)
{
    UE_LOG(LogTemp, Warning, TEXT("Value: %f"), Value);
}

