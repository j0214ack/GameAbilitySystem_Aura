// Fill out your copyright notice in the Description page of Project Settings.


#include "AuraGameplayTags.h"
#include "GameplayTagsManager.h"

FAuraGameplayTags FAuraGameplayTags::GameplayTags;

const FAuraGameplayTags& FAuraGameplayTags::Get()
{
	return GameplayTags;
}

void FAuraGameplayTags::InitializeGameplayTags()
{
	// Primary Attributes
    UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.Intelligence"), TEXT("Intelligence"));
    GameplayTags.Attributes_Primary_Intelligence = FGameplayTag::RequestGameplayTag(FName("Attributes.Primary.Intelligence"));

    UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.Resilience"), TEXT("Resilience"));
    GameplayTags.Attributes_Primary_Resilience = FGameplayTag::RequestGameplayTag(FName("Attributes.Primary.Resilience"));

    UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.Strength"), TEXT("Strength"));
    GameplayTags.Attributes_Primary_Strength = FGameplayTag::RequestGameplayTag(FName("Attributes.Primary.Strength"));

    UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.Vitality"), TEXT("Vitality"));
    GameplayTags.Attributes_Primary_Vitality = FGameplayTag::RequestGameplayTag(FName("Attributes.Primary.Vitality"));

    // Secondary Attributes
    UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.Armor"), TEXT("Reduce physical damage taken."));
    GameplayTags.Attributes_Secondary_Armor = FGameplayTag::RequestGameplayTag(FName("Attributes.Secondary.Armor"));

    UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.ArmorPenetration"), TEXT("Armor Penetration"));
    GameplayTags.Attributes_Secondary_ArmorPenetration = FGameplayTag::RequestGameplayTag(FName("Attributes.Secondary.ArmorPenetration"));

    UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.BlockChance"), TEXT("Block Chance"));
    GameplayTags.Attributes_Secondary_BlockChance = FGameplayTag::RequestGameplayTag(FName("Attributes.Secondary.BlockChance"));

    UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.CriticalHitChance"), TEXT("Critical Hit Chance"));
    GameplayTags.Attributes_Secondary_CriticalHitChance = FGameplayTag::RequestGameplayTag(FName("Attributes.Secondary.CriticalHitChance"));

    UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.CriticalHitDamage"), TEXT("Critical Hit Damage"));
    GameplayTags.Attributes_Secondary_CriticalHitDamage = FGameplayTag::RequestGameplayTag(FName("Attributes.Secondary.CriticalHitDamage"));

    UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.CriticalHitResistance"), TEXT("Critical Hit Resistance"));
    GameplayTags.Attributes_Secondary_CriticalHitResistance = FGameplayTag::RequestGameplayTag(FName("Attributes.Secondary.CriticalHitResistance"));

    UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.HealthRegeneration"), TEXT("Health Regeneration"));
    GameplayTags.Attributes_Secondary_HealthRegeneration = FGameplayTag::RequestGameplayTag(FName("Attributes.Secondary.HealthRegeneration"));

    UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.ManaRegeneration"), TEXT("Mana Regeneration"));
    GameplayTags.Attributes_Secondary_ManaRegeneration = FGameplayTag::RequestGameplayTag(FName("Attributes.Secondary.ManaRegeneration"));
	
    UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.MaxHealth"), TEXT("MaxHealth"));
    GameplayTags.Attributes_Secondary_MaxHealth = FGameplayTag::RequestGameplayTag(FName("Attributes.Secondary.MaxHealth"));

    UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.MaxMana"), TEXT("MaxMana"));
    GameplayTags.Attributes_Secondary_MaxMana = FGameplayTag::RequestGameplayTag(FName("Attributes.Secondary.MaxMana"));

    // Vital Attributes
    UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Vital.Health"), TEXT("Health"));
    GameplayTags.Attributes_Vital_Health = FGameplayTag::RequestGameplayTag(FName("Attributes.Vital.Health"));

    UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Vital.Mana"), TEXT("Mana"));
    GameplayTags.Attributes_Vital_Mana = FGameplayTag::RequestGameplayTag(FName("Attributes.Vital.Mana"));

}
