// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataAsset.h"
#include "AttributeInfo.generated.h"


USTRUCT(BlueprintType)
struct FAuraAttributeInfo
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FGameplayTag AttributeTag = FGameplayTag::EmptyTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FText AttributeName = FText::GetEmpty();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FText AttributeDescription = FText::GetEmpty();

	UPROPERTY(BlueprintReadOnly)
	float AttributeValue = 0.0f;
};

/**
 * 
 */
UCLASS()
class AURA_API UAttributeInfo : public UDataAsset
{
	GENERATED_BODY()

public:
	FAuraAttributeInfo FindAttributeInfoByTag(const FGameplayTag& Tag, bool bLogNotFound = false) const;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<FAuraAttributeInfo> AttributeInfos;
};
