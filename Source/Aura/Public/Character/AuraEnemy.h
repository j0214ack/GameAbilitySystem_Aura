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
	/** Highlightable Interface */
	virtual void Highlight() override;
	virtual void Unhighlight() override;
	
	/** Combat Interface */
	virtual int32 GetCharacterLevel() override { return Level; }
	
protected:
	virtual void Tick(float DeltaSeconds) override;
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Character Class Default")
	int32 Level = 1;
	
private:
	
	UPROPERTY(EditAnywhere, Category="Highlight")
	bool bIsHighlighted = false;

};
