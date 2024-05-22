// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Widget/AuraWidgetController.h"
#include "OverlayWidgetController.generated.h"

struct FOnAttributeChangeData;
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChangedSignature, float, NewHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxHealthChangedSignature, float, NewMaxHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnManaChangedSignature, float, NewMana);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxManaChangedSignature, float, NewMaxMana);

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable, Category="Aura|WidgetController")
class AURA_API UOverlayWidgetController : public UAuraWidgetController
{
	GENERATED_BODY()

	virtual void BroadcastInitialValues() const override;
	virtual void BindToAttributeChanges() const override;

	UPROPERTY(BlueprintAssignable,  Category="GAS|Attributes")
	FOnHealthChangedSignature OnHealthChangedDelegate;

	UPROPERTY(BlueprintAssignable,  Category="GAS|Attributes")
	FOnMaxHealthChangedSignature OnMaxHealthChangedDelegate;
	
	UPROPERTY(BlueprintAssignable,  Category="GAS|Attributes")
	FOnManaChangedSignature OnManaChangedDelegate;

	UPROPERTY(BlueprintAssignable,  Category="GAS|Attributes")
	FOnMaxManaChangedSignature OnMaxManaChangedDelegate;

	void OnHealthAttributeChanged(const FOnAttributeChangeData& Data) const;
	void OnMaxHealthAttributeChanged(const FOnAttributeChangeData& Data) const;
	void OnManaAttributeChanged(const FOnAttributeChangeData& Data) const;
	void OnMaxManaAttributeChanged(const FOnAttributeChangeData& Data) const;
	
};
