// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "AuraCharacter.generated.h"

class UGameplayEffect;
/**
 * 
 */
UCLASS()
class AURA_API AAuraCharacter : public AAuraCharacterBase
{
	GENERATED_BODY()
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

public:
	/** Combat Interface */
	virtual int32 GetCharacterLevel() override;

protected:
	UPROPERTY(EditAnywhere)
	TArray<TSubclassOf<UGameplayEffect>> OnSpawnEffects;

private:
	void InitializeAbilitySystem();
	void InitializeHUD() const;
	void ApplyOnSpawnEffects();
};
