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
	UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.Armor"), "Reduce physical damage taken.");

	GameplayTags.Attributes_Secondary_Armor = FGameplayTag::RequestGameplayTag(FName("Attributes.Secondary.Armor"));
}
