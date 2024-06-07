// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Data/AttributeInfo.h"

FAuraAttributeInfo UAttributeInfo::FindAttributeInfoByTag(const FGameplayTag& Tag, bool bLogNotFound) const
{
	for (const FAuraAttributeInfo& AttributeInfo : AttributeInfos)
	{
		if (AttributeInfo.AttributeTag.MatchesTag(Tag))
		{
			return AttributeInfo;
		}
	}

	if (bLogNotFound)
	{
		UE_LOG(LogTemp, Warning, TEXT("AttributeInfo with tag %s not found in %s"), *Tag.ToString(), *GetName());
	}

	return FAuraAttributeInfo();
}
