// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AuraEnemy.h"

AAuraEnemy::AAuraEnemy()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
}

void AAuraEnemy::Highlight()
{
	UE_LOG(LogTemp, Warning, TEXT("Highlighting enemy: %s"), *GetName());
	bIsHighlighted = true;
}

void AAuraEnemy::Unhighlight()
{
	UE_LOG(LogTemp, Warning, TEXT("Unhighlighting enemy: %s"), *GetName());
	bIsHighlighted = false;
}

void AAuraEnemy::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (bIsHighlighted)
	{
		DrawDebugSphere(GetWorld(), GetActorLocation(), 100.0f, 32, FColor::Green, false, 0.1f, 0, 1.0f);
	}
}
