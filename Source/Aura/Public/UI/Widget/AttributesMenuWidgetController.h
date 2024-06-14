// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Data/AttributeInfo.h"
#include "UI/Widget/AuraWidgetController.h"
#include "AttributesMenuWidgetController.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAttributeInfoChangedSignature, FAuraAttributeInfo, NewAttributeInfo);


/**
 * 
 */
UCLASS(BlueprintType, Blueprintable, Category="Aura|WidgetController")
class AURA_API UAttributesMenuWidgetController : public UAuraWidgetController
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	virtual void BroadcastInitialValues() const override;
	virtual void BindToAttributeChanges() const override;

protected:
	UPROPERTY(EditDefaultsOnly, Category="GAS|Attributes")
	TObjectPtr<UAttributeInfo> AttributeInfo;
	
	UPROPERTY(BlueprintAssignable, Category="GAS|Attributes")
	FOnAttributeInfoChangedSignature OnAttributeChangedDelegate;
};
