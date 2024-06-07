// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

struct FAuraGameplayTags
{
	static const FAuraGameplayTags& Get();
	static void InitializeGameplayTags();

	FGameplayTag Attributes_Secondary_Armor;
	
private:
	static FAuraGameplayTags GameplayTags;
};

/**
 * 
 */
