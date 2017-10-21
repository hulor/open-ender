// Fill out your copyright notice in the Description page of Project Settings.

#include "BasicPlayerController.h"

#include "BasicCharacter.h"
#include <UnrealMathUtility.h>
#include <Casts.h>


void ABasicPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	InputComponent->BindAxis("MoveImpulseForward", this, &ABasicPlayerController::ImpulseForward);
	InputComponent->BindAxis("MoveImpulseSide", this, &ABasicPlayerController::ImpulseSide);
	InputComponent->BindAxis("CameraPitch", this, &ABasicPlayerController::RotateCameraPitch);
	InputComponent->BindAxis("CameraYaw", this, &ABasicPlayerController::RotateCameraYaw);
	InputComponent->BindAction("Grab", IE_Pressed, this, &ABasicPlayerController::Grab);
	InputComponent->BindAction("Grab", IE_Released, this, &ABasicPlayerController::Release);
}

void ABasicPlayerController::ImpulseForward(float ImpulseValue)
{
	ABasicCharacter* character = Cast<ABasicCharacter>(GetPawn());

	if (character)
		character->ImpulseForward(FMath::Clamp<float>(ImpulseValue, -1.0, 1.0));
}

void ABasicPlayerController::ImpulseSide(float ImpulseValue)
{
	ABasicCharacter* character = Cast<ABasicCharacter>(GetPawn());

	if (character)
		character->ImpulseSide(FMath::Clamp<float>(ImpulseValue, -1.0, 1.0));
}

void ABasicPlayerController::RotateCameraPitch(float PitchValue)
{
	ABasicCharacter* character = Cast<ABasicCharacter>(GetPawn());

	if (character)
		character->RotatePitch(PitchValue);
}

void ABasicPlayerController::RotateCameraYaw(float YawValue)
{
	ABasicCharacter* character = Cast<ABasicCharacter>(GetPawn());

	if (character)
		character->RotateYaw(YawValue);
}

void ABasicPlayerController::Grab()
{
	ABasicCharacter* character = Cast<ABasicCharacter>(GetPawn());

	if (character)
		character->Grab();
}

void ABasicPlayerController::Release()
{
	ABasicCharacter* character = Cast<ABasicCharacter>(GetPawn());

	if (character)
		character->Release();
}
