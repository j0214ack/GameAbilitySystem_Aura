// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/AuraAttributeSet.h"

#include "GameplayEffectExtension.h"
#include "GameFramework/Character.h"
#include "Net/UnrealNetwork.h"

UAuraAttributeSet::UAuraAttributeSet()
{
	InitHealth(50.0f);
	InitMaxHealth(100.0f);
	InitMana(75.0f);
	InitMaxMana(100.0f);
}

void UAuraAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet, Health, COND_None, REPNOTIFY_Always)
	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always)
	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet, Mana, COND_None, REPNOTIFY_Always)
	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet, MaxMana, COND_None, REPNOTIFY_Always)
}

void UAuraAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
	FEffectProperties EffectProperties;
	SetEffectProperties(Data, EffectProperties);
	
}

void UAuraAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSet, Health, OldHealth);
}

void UAuraAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSet, MaxHealth, OldMaxHealth);
}
void UAuraAttributeSet::OnRep_Mana(const FGameplayAttributeData& OldMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSet, Mana, OldMana);
}

void UAuraAttributeSet::OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSet, MaxMana, OldMaxMana);
}

void UAuraAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	if (Attribute == GetHealthAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxHealth());
	}
	if (Attribute == GetManaAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxMana());
	}
}

void UAuraAttributeSet::SetEffectProperties(const FGameplayEffectModCallbackData& Data,
	FEffectProperties& EffectProperties)
{
	EffectProperties.EffectContextHandle = Data.EffectSpec.GetContext();
	
	EffectProperties.SourceAbilitySystemComponent = Data.EffectSpec.GetEffectContext().GetOriginalInstigatorAbilitySystemComponent();

	if (IsValid(EffectProperties.SourceAbilitySystemComponent))
	{
		EffectProperties.SourceAvatarActor = EffectProperties.SourceAbilitySystemComponent->GetAvatarActor();
		EffectProperties.SourceOwnerActor = EffectProperties.SourceAbilitySystemComponent->GetOwnerActor();
		EffectProperties.SourceController = EffectProperties.SourceAbilitySystemComponent->AbilityActorInfo->PlayerController.Get();

		// Source is not a player controller, could be a AI controller
		if (EffectProperties.SourceController == nullptr && EffectProperties.SourceAvatarActor != nullptr)
		{
			if (APawn* Pawn = Cast<APawn>(EffectProperties.SourceAvatarActor))
			{
				EffectProperties.SourceController = Pawn->GetController();
			}
		}
		// if source indeed has a controller, get the character
		if (IsValid(EffectProperties.SourceController))
		{
			EffectProperties.SourceCharacter = Cast<ACharacter>(EffectProperties.SourceController->GetPawn());
		}
	}

	if (Data.Target.AbilityActorInfo.IsValid() && Data.Target.AbilityActorInfo->AvatarActor.IsValid())
	{
		EffectProperties.TargetAbilitySystemComponent = Data.Target.AbilityActorInfo->AbilitySystemComponent.Get();
		EffectProperties.TargetAvatarActor = Data.Target.AbilityActorInfo->AvatarActor.Get();
		EffectProperties.TargetOwnerActor = Data.Target.AbilityActorInfo->OwnerActor.Get();
		EffectProperties.TargetController = Data.Target.AbilityActorInfo->PlayerController.Get();

		// Target is not a player controller, could be a AI controller
		if (EffectProperties.TargetController == nullptr && EffectProperties.TargetAvatarActor != nullptr)
		{
			if (APawn* Pawn = Cast<APawn>(EffectProperties.TargetAvatarActor))
			{
				EffectProperties.TargetController = Pawn->GetController();
			}
		}
		// if target indeed has a controller, get the character
		if (IsValid(EffectProperties.TargetController))
		{
			EffectProperties.TargetCharacter = Cast<ACharacter>(EffectProperties.TargetController->GetPawn());
		}
	}
}
