// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/OverlayWidgetController.h"
#include "AbilitySystem/AuraAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues() const
{
	Super::BroadcastInitialValues();
	UAuraAttributeSet* AuraAttributeSet = CastChecked<UAuraAttributeSet>(AttributeSet);
	OnHealthChangedDelegate.Broadcast(AuraAttributeSet->GetHealth());
	OnMaxHealthChangedDelegate.Broadcast(AuraAttributeSet->GetMaxHealth());
	OnManaChangedDelegate.Broadcast(AuraAttributeSet->GetMana());
	OnMaxManaChangedDelegate.Broadcast(AuraAttributeSet->GetMaxMana());
}

void UOverlayWidgetController::BindToAttributeChanges() const
{
	Super::BindToAttributeChanges();

	const UAuraAttributeSet* AuraAttributeSet = CastChecked<UAuraAttributeSet>(AttributeSet);

	AbilitySystemComponent
		->GetGameplayAttributeValueChangeDelegate(AuraAttributeSet->GetHealthAttribute())
		.AddUObject(this, &UOverlayWidgetController::OnHealthAttributeChanged);
	
	AbilitySystemComponent
		->GetGameplayAttributeValueChangeDelegate(AuraAttributeSet->GetMaxHealthAttribute())
		.AddUObject(this, &UOverlayWidgetController::OnMaxHealthAttributeChanged);

	AbilitySystemComponent
		->GetGameplayAttributeValueChangeDelegate(AuraAttributeSet->GetManaAttribute())
		.AddUObject(this, &UOverlayWidgetController::OnManaAttributeChanged);

	AbilitySystemComponent
		->GetGameplayAttributeValueChangeDelegate(AuraAttributeSet->GetMaxManaAttribute())
		.AddUObject(this, &UOverlayWidgetController::OnMaxManaAttributeChanged);
}

void UOverlayWidgetController::OnHealthAttributeChanged(const FOnAttributeChangeData& Data) const
{
	OnHealthChangedDelegate.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::OnMaxHealthAttributeChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxHealthChangedDelegate.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::OnManaAttributeChanged(const FOnAttributeChangeData& Data) const
{
	OnManaChangedDelegate.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::OnMaxManaAttributeChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxManaChangedDelegate.Broadcast(Data.NewValue);
}
