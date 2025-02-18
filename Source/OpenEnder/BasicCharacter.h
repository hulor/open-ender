// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BasicCharacter.generated.h"

class USphereComponent;

UCLASS()
class OPENENDER_API ABasicCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABasicCharacter(const FObjectInitializer& ObjectInitializer);

public:
	// UProperties
	/** Force applied when impulsing a movement.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement", DisplayName = "ImpulseForce")
	float ImpulseForce;

	/**Collision shape used by ZeroGCharacterMovementComponet if necessary to detect object to lean on.*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movement")
	USphereComponent* MovementCollision;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void ImpulseForward(float value);
	void ImpulseSide(float value);
	void RotatePitch(float pitch);
	void RotateYaw(float yaw);
	void Grab();
	void Release();
	
	
};
