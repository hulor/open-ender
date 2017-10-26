// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "ZeroGCharacterMovementComponent.generated.h"

class USphereComponent;
/**
 * 
 */
UCLASS()
class OPENENDER_API UZeroGCharacterMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()
public:
	/**Collision shape to detect object to lean on.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Collision")
		USphereComponent* CollisionDetectionSphere;

protected:
	bool Overlapping;
	TArray<UPrimitiveComponent*> OverlappingElements;

protected:
	UFUNCTION()
	void BeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void EndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

public:
	UZeroGCharacterMovementComponent(const FObjectInitializer& ObjectInitializer);
	virtual void AddForce(FVector Force) override;
	virtual void BeginPlay() override;
};
