// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AuraUIFunctionLibrary.generated.h"

class UAttributesMenuWidgetController;
/**
 * 
 */
UCLASS()
class AURA_API UAuraUIFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "Aura UI")
	static UAttributesMenuWidgetController* GetAttributesMenuWidgetController(const UObject* WorldContextObject);
	
};
