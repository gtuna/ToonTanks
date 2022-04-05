// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"

UCLASS()
class TOONTANKS_API ABasePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABasePawn();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
private:
	
	// saying "class UCapsuleComponent": we are using "Forward Declaration" to not to include ucapsulecomp in the header file.
	// It is only used in the cpp file. in here, it is just an address.
	// we only include headers where u actually need them
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true")) 
	class UCapsuleComponent* CapsuleComp; 
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* BaseMesh; //included by default 

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* TurretMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USceneComponent* ProjectileSpawnPoint;

	//editanywhere: allows you to edit the value in the editor, 
	// blueprintreadwrite: allows you to read and write the value in the blueprint,
	// meta: allows you to add meta data to the property
	// UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true")) 
	// float MoveSpeed = 100.0f;
	
};
