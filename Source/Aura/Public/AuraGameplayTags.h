// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

struct FAuraGameplayTags
{
	static const FAuraGameplayTags& Get();
	static void InitializeGameplayTags();

	// Primary Attributes
	FGameplayTag Attributes_Primary_Intelligence;
	FGameplayTag Attributes_Primary_Resilience;
	FGameplayTag Attributes_Primary_Strength;
	FGameplayTag Attributes_Primary_Vitality;

	// Secondary Attributes
	FGameplayTag Attributes_Secondary_Armor;
	FGameplayTag Attributes_Secondary_ArmorPenetration;
	FGameplayTag Attributes_Secondary_BlockChance;
	FGameplayTag Attributes_Secondary_CriticalHitChance;
	FGameplayTag Attributes_Secondary_CriticalHitDamage;
	FGameplayTag Attributes_Secondary_CriticalHitResistance;
	FGameplayTag Attributes_Secondary_HealthRegeneration;
	FGameplayTag Attributes_Secondary_ManaRegeneration;
	FGameplayTag Attributes_Secondary_MaxHealth;
	FGameplayTag Attributes_Secondary_MaxMana;

	// Vital Attributes
	FGameplayTag Attributes_Vital_Health;
	FGameplayTag Attributes_Vital_Mana;
	
private:
	static FAuraGameplayTags GameplayTags;
};

/**
 * 
 */
