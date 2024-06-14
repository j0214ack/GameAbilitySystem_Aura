// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Widget/AuraWidgetController.h"
#include "OverlayWidgetController.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAttributeChangedSignature, float, NewValue);

struct FGameplayEffectSpec;
struct FActiveGameplayEffectHandle;
struct FOnAttributeChangeData;

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
	FOnAttributeChangedSignature OnHealthChangedDelegate;

	UPROPERTY(BlueprintAssignable,  Category="GAS|Attributes")
	FOnAttributeChangedSignature OnMaxHealthChangedDelegate;
	
	UPROPERTY(BlueprintAssignable,  Category="GAS|Attributes")
	FOnAttributeChangedSignature OnManaChangedDelegate;

	UPROPERTY(BlueprintAssignable,  Category="GAS|Attributes")
	FOnAttributeChangedSignature OnMaxManaChangedDelegate;

	void OnGameplayEffectApplied(UAbilitySystemComponent* AppliedASC, const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle EffectHandle) const;
	void OnMessageTagReceived(const FGameplayTag& MessageTag) const;
};
