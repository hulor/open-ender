// Fill out your copyright notice in the Description page of Project Settings.

#include "ZeroGCharacterMovementComponent.h"

#include "Misc/AssertionMacros.h"
#include "Components/SphereComponent.h"

UZeroGCharacterMovementComponent::UZeroGCharacterMovementComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, Overlapping(true)
{
	RotationRate = FRotator(360.0, 360.0, 360.0);
	GravityScale = 0.0;
}

void UZeroGCharacterMovementComponent::AddForce(FVector Force)
{
	if (Overlapping == false) // We don't want to move if there is no object to lean on.
		return;
	AddImpulse(Force, true);
}

void UZeroGCharacterMovementComponent::BeginPlay()
{
	//checkf(CollisionDetectionSphere != nullptr, TEXT ("ZeroGCharacterMovementComponent need a sphere collision to work."));
	if (CollisionDetectionSphere == nullptr)
		return;
	CollisionDetectionSphere->OnComponentBeginOverlap.AddDynamic(this, &UZeroGCharacterMovementComponent::BeginOverlap);
	CollisionDetectionSphere->OnComponentEndOverlap.AddDynamic(this, &UZeroGCharacterMovementComponent::EndOverlap);
}

void UZeroGCharacterMovementComponent::BeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//if (OverlappedComp == UpdatedComponent) // we don't want to use ourself to move
	//	return;
	Overlapping = true;
	OverlappingElements.Push(OverlappedComp);
}

void UZeroGCharacterMovementComponent::EndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	//checkf(OverlappingElements.Contains(OverlappedComp), TEXT("Attempt to remove an overlapping element which is not in OverlappingElements."));
	if (OverlappingElements.Contains(OverlappedComp))
		OverlappingElements.Remove(OverlappedComp);
	Overlapping = !(OverlappingElements.Num() == 0);
}
