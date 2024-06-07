// Fill out your copyright notice in the Description page of Project Settings.


#include "AuraAssetManager.h"

#include "AuraGameplayTags.h"

UAuraAssetManager& UAuraAssetManager::Get()
{
	check(GEngine);

	UAuraAssetManager* This = Cast<UAuraAssetManager>(GEngine->AssetManager);
	return *This;
}

void UAuraAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();

	FAuraGameplayTags::InitializeGameplayTags();
}
