// Fill out your copyright notice in the Description page of Project Settings.

#include "BasicCharacter.h"
#include "ZeroGCharacterMovementComponent.h"

#include "Components/SphereComponent.h"


// Sets default values
ABasicCharacter::ABasicCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer.SetDefaultSubobjectClass<UZeroGCharacterMovementComponent>(ACharacter::CharacterMovementComponentName))
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MovementCollision = CreateDefaultSubobject<USphereComponent>(TEXT("ActorComponentCollider"));
	if (MovementCollision)
	{
		MovementCollision->InitSphereRadius(40.0f);
		MovementCollision->SetupAttachment(RootComponent);
	}
}

// Called when the game starts or when spawned
void ABasicCharacter::BeginPlay()
{
	UZeroGCharacterMovementComponent* zeroGMvtComp = Cast<UZeroGCharacterMovementComponent>(GetMovementComponent());
	if (zeroGMvtComp && MovementCollision)
		zeroGMvtComp->CollisionDetectionSphere = MovementCollision;
	Super::BeginPlay();
	
}

// Called every frame
void ABasicCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABasicCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABasicCharacter::ImpulseForward(float value)
{
	GetCharacterMovement()->AddForce(GetActorForwardVector() * value * ImpulseForce);
}

void ABasicCharacter::ImpulseSide(float value)
{
	GetCharacterMovement()->AddForce(GetActorRightVector() * value * ImpulseForce);
}

void ABasicCharacter::RotatePitch(float pitch)
{
	AddActorLocalRotation(FRotator(pitch, 0.0, 0.0));
}

void ABasicCharacter::RotateYaw(float yaw)
{
	AddActorLocalRotation(FRotator(0.0, yaw, 0.0));
}

void ABasicCharacter::Grab()
{

}

void ABasicCharacter::Release()
{

}
