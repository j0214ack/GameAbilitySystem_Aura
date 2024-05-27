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
		.AddLambda([this](const FOnAttributeChangeData& Data) { OnHealthChangedDelegate.Broadcast(Data.NewValue); });
	
	AbilitySystemComponent
		->GetGameplayAttributeValueChangeDelegate(AuraAttributeSet->GetMaxHealthAttribute())
		.AddLambda([this](const FOnAttributeChangeData& Data) { OnMaxHealthChangedDelegate.Broadcast(Data.NewValue); });

	AbilitySystemComponent
		->GetGameplayAttributeValueChangeDelegate(AuraAttributeSet->GetManaAttribute())
		.AddLambda([this](const FOnAttributeChangeData& Data) { OnManaChangedDelegate.Broadcast(Data.NewValue); });

	AbilitySystemComponent
		->GetGameplayAttributeValueChangeDelegate(AuraAttributeSet->GetMaxManaAttribute())
		.AddLambda([this](const FOnAttributeChangeData& Data) { OnMaxManaChangedDelegate.Broadcast(Data.NewValue); });
	
	AbilitySystemComponent->OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UOverlayWidgetController::OnGameplayEffectApplied);
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
