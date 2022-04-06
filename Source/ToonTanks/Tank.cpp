// Fill out your copyright notice in the Description page of Project Settings.

#include "Camera/CameraComponent.h"
#include "DrawDebugHelpers.h"
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

    PlayerInputComponent->BindAction(TEXT("Fire"), IE_Pressed, this, &ATank::Fire);
}

// Called every frame
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    FHitResult HitResult;
    if (PlayerControllerRef)
    {
        PlayerControllerRef->GetHitResultUnderCursor(
            ECollisionChannel::ECC_Visibility, 
            false, 
            HitResult);
        RotateTurret(HitResult.ImpactPoint);
    }
    

}


// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();

    // GetController is on the APawn class , our player is a APlayerController not AController so we need to cast it to APlayerController
    PlayerControllerRef = Cast<APlayerController>(GetController());
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

