// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BasicPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class OPENENDER_API ABasicPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	void ImpulseForward(float ImpulseValue);
	void ImpulseSide(float ImpulseValue);
	void RotateCameraPitch(float PitchValue);
	void RotateCameraYaw(float YawValue);
	void Grab();
	void Release();

protected:
	virtual void SetupInputComponent();
	
	
};
