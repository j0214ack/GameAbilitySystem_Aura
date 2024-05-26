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
	
	AbilitySystemComponent->OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UOverlayWidgetController::OnGameplayEffectApplied);
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

void UOverlayWidgetController::OnGameplayEffectApplied(UAbilitySystemComponent* AppliedASC, const FGameplayEffectSpec& EffectSpec,
	FActiveGameplayEffectHandle EffectHandle) const
{
	// get tag name
	FGameplayTagContainer EffectTags;
	EffectSpec.GetAllAssetTags(EffectTags);
	
	for (const FGameplayTag& EffectTag : EffectTags)
	{
		// if TagName starts with "Message."
		if (EffectTag.MatchesTag(FGameplayTag::RequestGameplayTag(FName("Message"), true)))
		{
			OnMessageTagReceived(EffectTag);
		}
	}
}

void UOverlayWidgetController::OnMessageTagReceived(const FGameplayTag& MessageTag) const
{
	FMessageTagUIWidgetRow* MessageTagUIWidgetRow = MessageTagUIWidgetTable->FindRow<FMessageTagUIWidgetRow>(
		MessageTag.GetTagName(), TEXT(""));

	UE_LOG(LogTemp, Warning, TEXT("MessageTag: %s"), *MessageTag.GetTagName().ToString());
	OnMessageTagReceivedDelegate.Broadcast(MessageTag, *MessageTagUIWidgetRow);
}
