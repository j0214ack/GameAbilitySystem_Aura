// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AuraCharacter.h"

#include "AbilitySystemComponent.h"
#include "Player/AuraPlayerController.h"
#include "Player/AuraPlayerState.h"
#include "UI/HUD/AuraHUD.h"

// Only called on the server (or in standalone).
// See: https://docs.unrealengine.com/4.27/en-US/API/Runtime/Engine/GameFramework/APawn/PossessedBy/
void AAuraCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	// initialize ability system for server
	InitializeAbilitySystem();
	InitializeHUD();
}

void AAuraCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	InitializeAbilitySystem();
	InitializeHUD();
}

void AAuraCharacter::InitializeAbilitySystem()
{
	AAuraPlayerState* AuraPlayerState = GetPlayerState<AAuraPlayerState>();
	check(AuraPlayerState);
	AbilitySystemComponent = AuraPlayerState->GetAbilitySystemComponent();
	
	AbilitySystemComponent->InitAbilityActorInfo(AuraPlayerState, this);
	AttributeSet = AuraPlayerState->GetAttributeSet();
	ApplyOnSpawnEffects();
}

void AAuraCharacter::InitializeHUD() const
{
	if (APlayerController* PlayerController = Cast<AAuraPlayerController>(GetController()))
	{
		if (AAuraHUD* HUD = Cast<AAuraHUD>(PlayerController->GetHUD()))
		{
			HUD->InitOverlay(PlayerController, GetPlayerState(), AbilitySystemComponent, AttributeSet);
		}
	}
}

void AAuraCharacter::ApplyOnSpawnEffects()
{
	for (const TSubclassOf<UGameplayEffect> Effect : OnSpawnEffects)
	{
		UE_LOG(LogTemp, Warning, TEXT("Applying effect %s"), *Effect->GetName());
		const FGameplayEffectContextHandle Context = AbilitySystemComponent->MakeEffectContext();
		const FGameplayEffectSpecHandle EffectSpecHandle = AbilitySystemComponent->MakeOutgoingSpec(Effect, 1, Context);
		AbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*EffectSpecHandle.Data.Get());
	}
}
