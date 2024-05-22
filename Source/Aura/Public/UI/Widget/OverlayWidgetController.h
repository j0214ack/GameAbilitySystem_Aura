// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Widget/AuraWidgetController.h"
#include "OverlayWidgetController.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChangedSignature, float, NewHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxHealthChangedSignature, float, NewMaxHealth);

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable, Category="Aura|WidgetController")
class AURA_API UOverlayWidgetController : public UAuraWidgetController
{
	GENERATED_BODY()

	virtual void BroadcastInitialValues() const override;

	UPROPERTY(BlueprintAssignable,  Category="GAS|Attributes")
	FOnHealthChangedSignature OnHealthChanged;

	UPROPERTY(BlueprintAssignable,  Category="GAS|Attributes")
	FOnMaxHealthChangedSignature OnMaxHealthChanged;
};
