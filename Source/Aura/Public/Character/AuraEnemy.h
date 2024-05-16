// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "Interaction/HighlightableInterface.h"
#include "AuraEnemy.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AAuraEnemy : public AAuraCharacterBase, public IHighlightableInterface
{
	GENERATED_BODY()
public:
	AAuraEnemy();
	virtual void Highlight() override;
	virtual void Unhighlight() override;
protected:
	virtual void Tick(float DeltaSeconds) override;
private:
	bool bIsHighlighted = false;
};
