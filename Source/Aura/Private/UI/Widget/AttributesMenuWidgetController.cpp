// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/AttributesMenuWidgetController.h"

#include "AuraGameplayTags.h"
#include "AbilitySystem/AuraAttributeSet.h"


void UAttributesMenuWidgetController::BroadcastInitialValues() const
{
	Super::BroadcastInitialValues();

	const UAuraAttributeSet* AuraAttributeSet = CastChecked<UAuraAttributeSet>(AttributeSet);
	check(AttributeInfo);

	FAuraAttributeInfo StrengthAttributeInfo = AttributeInfo->FindAttributeInfoByTag(
		FAuraGameplayTags::Get().Attributes_Primary_Strength);
	StrengthAttributeInfo.AttributeValue = AuraAttributeSet->GetStrength();
	OnAttributeChangedDelegate.Broadcast(StrengthAttributeInfo);

	FAuraAttributeInfo MaxHealthAttributeInfo = AttributeInfo->FindAttributeInfoByTag(
		FAuraGameplayTags::Get().Attributes_Secondary_MaxHealth);
	MaxHealthAttributeInfo.AttributeValue = AuraAttributeSet->GetMaxHealth();
	OnAttributeChangedDelegate.Broadcast(MaxHealthAttributeInfo);

	FAuraAttributeInfo ManaAttributeInfo = AttributeInfo->FindAttributeInfoByTag(
		FAuraGameplayTags::Get().Attributes_Vital_Mana);
	ManaAttributeInfo.AttributeValue = AuraAttributeSet->GetMana();
	OnAttributeChangedDelegate.Broadcast(ManaAttributeInfo);

	FAuraAttributeInfo MaxManaAttributeInfo = AttributeInfo->FindAttributeInfoByTag(
		FAuraGameplayTags::Get().Attributes_Secondary_MaxMana);
	MaxManaAttributeInfo.AttributeValue = AuraAttributeSet->GetMaxMana();
	OnAttributeChangedDelegate.Broadcast(MaxManaAttributeInfo);

	FAuraAttributeInfo HealthRegenerationAttributeInfo = AttributeInfo->FindAttributeInfoByTag(
		FAuraGameplayTags::Get().Attributes_Secondary_HealthRegeneration);
	HealthRegenerationAttributeInfo.AttributeValue = AuraAttributeSet->GetHealthRegeneration();
	OnAttributeChangedDelegate.Broadcast(HealthRegenerationAttributeInfo);

	FAuraAttributeInfo ManaRegenerationAttributeInfo = AttributeInfo->FindAttributeInfoByTag(
		FAuraGameplayTags::Get().Attributes_Secondary_ManaRegeneration);
	ManaRegenerationAttributeInfo.AttributeValue = AuraAttributeSet->GetManaRegeneration();
	OnAttributeChangedDelegate.Broadcast(ManaRegenerationAttributeInfo);

	FAuraAttributeInfo ArmorAttributeInfo = AttributeInfo->FindAttributeInfoByTag(
		FAuraGameplayTags::Get().Attributes_Secondary_Armor);
	ArmorAttributeInfo.AttributeValue = AuraAttributeSet->GetArmor();
	OnAttributeChangedDelegate.Broadcast(ArmorAttributeInfo);

	FAuraAttributeInfo ArmorPenetrationAttributeInfo = AttributeInfo->FindAttributeInfoByTag(
		FAuraGameplayTags::Get().Attributes_Secondary_ArmorPenetration);
	ArmorPenetrationAttributeInfo.AttributeValue = AuraAttributeSet->GetArmorPenetration();
	OnAttributeChangedDelegate.Broadcast(ArmorPenetrationAttributeInfo);

	FAuraAttributeInfo BlockChanceAttributeInfo = AttributeInfo->FindAttributeInfoByTag(
		FAuraGameplayTags::Get().Attributes_Secondary_BlockChance);
	BlockChanceAttributeInfo.AttributeValue = AuraAttributeSet->GetBlockChance();
	OnAttributeChangedDelegate.Broadcast(BlockChanceAttributeInfo);

	FAuraAttributeInfo CriticalHitChanceAttributeInfo = AttributeInfo->FindAttributeInfoByTag(
		FAuraGameplayTags::Get().Attributes_Secondary_CriticalHitChance);
	CriticalHitChanceAttributeInfo.AttributeValue = AuraAttributeSet->GetCriticalHitChance();
	OnAttributeChangedDelegate.Broadcast(CriticalHitChanceAttributeInfo);

	FAuraAttributeInfo CriticalHitDamageAttributeInfo = AttributeInfo->FindAttributeInfoByTag(
		FAuraGameplayTags::Get().Attributes_Secondary_CriticalHitDamage);
	CriticalHitDamageAttributeInfo.AttributeValue = AuraAttributeSet->GetCriticalHitDamage();
	OnAttributeChangedDelegate.Broadcast(CriticalHitDamageAttributeInfo);

	FAuraAttributeInfo CriticalHitResistanceAttributeInfo = AttributeInfo->FindAttributeInfoByTag(
		FAuraGameplayTags::Get().Attributes_Secondary_CriticalHitResistance);
	CriticalHitResistanceAttributeInfo.AttributeValue = AuraAttributeSet->GetCriticalHitResistance();
	OnAttributeChangedDelegate.Broadcast(CriticalHitResistanceAttributeInfo);

	FAuraAttributeInfo IntelligenceAttributeInfo = AttributeInfo->FindAttributeInfoByTag(
		FAuraGameplayTags::Get().Attributes_Primary_Intelligence);
	IntelligenceAttributeInfo.AttributeValue = AuraAttributeSet->GetIntelligence();
	OnAttributeChangedDelegate.Broadcast(IntelligenceAttributeInfo);

	FAuraAttributeInfo ResilienceAttributeInfo = AttributeInfo->FindAttributeInfoByTag(
		FAuraGameplayTags::Get().Attributes_Primary_Resilience);
	ResilienceAttributeInfo.AttributeValue = AuraAttributeSet->GetResilience();
	OnAttributeChangedDelegate.Broadcast(ResilienceAttributeInfo);

	FAuraAttributeInfo VitalityAttributeInfo = AttributeInfo->FindAttributeInfoByTag(
		FAuraGameplayTags::Get().Attributes_Primary_Vitality);
	VitalityAttributeInfo.AttributeValue = AuraAttributeSet->GetVitality();
	OnAttributeChangedDelegate.Broadcast(VitalityAttributeInfo);
}

void UAttributesMenuWidgetController::BindToAttributeChanges() const
{
	Super::BindToAttributeChanges();

	const UAuraAttributeSet* AuraAttributeSet = CastChecked<UAuraAttributeSet>(AttributeSet);
	check(AttributeInfo);

	AbilitySystemComponent
		->GetGameplayAttributeValueChangeDelegate(AuraAttributeSet->GetStrengthAttribute())
		.AddLambda([this, AuraAttributeSet](const FOnAttributeChangeData& Data)
		{
			FAuraAttributeInfo StrengthAttributeInfo = AttributeInfo->FindAttributeInfoByTag(
				FAuraGameplayTags::Get().Attributes_Primary_Strength);
			StrengthAttributeInfo.AttributeValue = AuraAttributeSet->GetStrength();
			OnAttributeChangedDelegate.Broadcast(StrengthAttributeInfo);
		});

	AbilitySystemComponent
		->GetGameplayAttributeValueChangeDelegate(AuraAttributeSet->GetMaxHealthAttribute())
		.AddLambda([this, AuraAttributeSet](const FOnAttributeChangeData& Data)
		{
			FAuraAttributeInfo MaxHealthAttributeInfo = AttributeInfo->FindAttributeInfoByTag(
				FAuraGameplayTags::Get().Attributes_Secondary_MaxHealth);
			MaxHealthAttributeInfo.AttributeValue = AuraAttributeSet->GetMaxHealth();
			OnAttributeChangedDelegate.Broadcast(MaxHealthAttributeInfo);
		});

	AbilitySystemComponent
		->GetGameplayAttributeValueChangeDelegate(AuraAttributeSet->GetManaAttribute())
		.AddLambda([this, AuraAttributeSet](const FOnAttributeChangeData& Data)
		{
			FAuraAttributeInfo ManaAttributeInfo = AttributeInfo->FindAttributeInfoByTag(
				FAuraGameplayTags::Get().Attributes_Vital_Mana);
			ManaAttributeInfo.AttributeValue = AuraAttributeSet->GetMana();
			OnAttributeChangedDelegate.Broadcast(ManaAttributeInfo);
		});

	AbilitySystemComponent
		->GetGameplayAttributeValueChangeDelegate(AuraAttributeSet->GetMaxManaAttribute())
		.AddLambda([this, AuraAttributeSet](const FOnAttributeChangeData& Data)
		{
			FAuraAttributeInfo MaxManaAttributeInfo = AttributeInfo->FindAttributeInfoByTag(
				FAuraGameplayTags::Get().Attributes_Secondary_MaxMana);
			MaxManaAttributeInfo.AttributeValue = AuraAttributeSet->GetMaxMana();
			OnAttributeChangedDelegate.Broadcast(MaxManaAttributeInfo);
		});

	AbilitySystemComponent
		->GetGameplayAttributeValueChangeDelegate(AuraAttributeSet->GetHealthRegenerationAttribute())
		.AddLambda([this, AuraAttributeSet](const FOnAttributeChangeData& Data)
		{
			FAuraAttributeInfo HealthRegenerationAttributeInfo = AttributeInfo->FindAttributeInfoByTag(
				FAuraGameplayTags::Get().Attributes_Secondary_HealthRegeneration);
			HealthRegenerationAttributeInfo.AttributeValue = AuraAttributeSet->GetHealthRegeneration();
			OnAttributeChangedDelegate.Broadcast(HealthRegenerationAttributeInfo);
		});

	AbilitySystemComponent
		->GetGameplayAttributeValueChangeDelegate(AuraAttributeSet->GetManaRegenerationAttribute())
		.AddLambda([this, AuraAttributeSet](const FOnAttributeChangeData& Data)
		{
			FAuraAttributeInfo ManaRegenerationAttributeInfo = AttributeInfo->FindAttributeInfoByTag(
				FAuraGameplayTags::Get().Attributes_Secondary_ManaRegeneration);
			ManaRegenerationAttributeInfo.AttributeValue = AuraAttributeSet->GetManaRegeneration();
			OnAttributeChangedDelegate.Broadcast(ManaRegenerationAttributeInfo);
		});

	AbilitySystemComponent
		->GetGameplayAttributeValueChangeDelegate(AuraAttributeSet->GetArmorAttribute())
		.AddLambda([this, AuraAttributeSet](const FOnAttributeChangeData& Data)
		{
			FAuraAttributeInfo ArmorAttributeInfo = AttributeInfo->FindAttributeInfoByTag(
				FAuraGameplayTags::Get().Attributes_Secondary_Armor);
			ArmorAttributeInfo.AttributeValue = AuraAttributeSet->GetArmor();
			OnAttributeChangedDelegate.Broadcast(ArmorAttributeInfo);
		});

	AbilitySystemComponent
		->GetGameplayAttributeValueChangeDelegate(AuraAttributeSet->GetArmorPenetrationAttribute())
		.AddLambda([this, AuraAttributeSet](const FOnAttributeChangeData& Data)
		{
			FAuraAttributeInfo ArmorPenetrationAttributeInfo = AttributeInfo->FindAttributeInfoByTag(
				FAuraGameplayTags::Get().Attributes_Secondary_ArmorPenetration);
			ArmorPenetrationAttributeInfo.AttributeValue = AuraAttributeSet->GetArmorPenetration();
			OnAttributeChangedDelegate.Broadcast(ArmorPenetrationAttributeInfo);
		});

	AbilitySystemComponent
		->GetGameplayAttributeValueChangeDelegate(AuraAttributeSet->GetBlockChanceAttribute())
		.AddLambda([this, AuraAttributeSet](const FOnAttributeChangeData& Data)
		{
			FAuraAttributeInfo BlockChanceAttributeInfo = AttributeInfo->FindAttributeInfoByTag(
				FAuraGameplayTags::Get().Attributes_Secondary_BlockChance);
			BlockChanceAttributeInfo.AttributeValue = AuraAttributeSet->GetBlockChance();
			OnAttributeChangedDelegate.Broadcast(BlockChanceAttributeInfo);
		});

	AbilitySystemComponent
		->GetGameplayAttributeValueChangeDelegate(AuraAttributeSet->GetCriticalHitChanceAttribute())
		.AddLambda([this, AuraAttributeSet](const FOnAttributeChangeData& Data)
		{
			FAuraAttributeInfo CriticalHitChanceAttributeInfo = AttributeInfo->FindAttributeInfoByTag(
				FAuraGameplayTags::Get().Attributes_Secondary_CriticalHitChance);
			CriticalHitChanceAttributeInfo.AttributeValue = AuraAttributeSet->GetCriticalHitChance();
			OnAttributeChangedDelegate.Broadcast(CriticalHitChanceAttributeInfo);
		});

	AbilitySystemComponent
		->GetGameplayAttributeValueChangeDelegate(AuraAttributeSet->GetCriticalHitDamageAttribute())
		.AddLambda([this, AuraAttributeSet](const FOnAttributeChangeData& Data)
		{
			FAuraAttributeInfo CriticalHitDamageAttributeInfo = AttributeInfo->FindAttributeInfoByTag(
				FAuraGameplayTags::Get().Attributes_Secondary_CriticalHitDamage);
			CriticalHitDamageAttributeInfo.AttributeValue = AuraAttributeSet->GetCriticalHitDamage();
			OnAttributeChangedDelegate.Broadcast(CriticalHitDamageAttributeInfo);
		});

	AbilitySystemComponent
		->GetGameplayAttributeValueChangeDelegate(AuraAttributeSet->GetCriticalHitResistanceAttribute())
		.AddLambda([this, AuraAttributeSet](const FOnAttributeChangeData& Data)
		{
			FAuraAttributeInfo CriticalHitResistanceAttributeInfo = AttributeInfo->FindAttributeInfoByTag(
				FAuraGameplayTags::Get().Attributes_Secondary_CriticalHitResistance);
			CriticalHitResistanceAttributeInfo.AttributeValue = AuraAttributeSet->GetCriticalHitResistance();
			OnAttributeChangedDelegate.Broadcast(CriticalHitResistanceAttributeInfo);
		});

	AbilitySystemComponent
		->GetGameplayAttributeValueChangeDelegate(AuraAttributeSet->GetIntelligenceAttribute())
		.AddLambda([this, AuraAttributeSet](const FOnAttributeChangeData& Data)
		{
			FAuraAttributeInfo IntelligenceAttributeInfo = AttributeInfo->FindAttributeInfoByTag(
				FAuraGameplayTags::Get().Attributes_Primary_Intelligence);
			IntelligenceAttributeInfo.AttributeValue = AuraAttributeSet->GetIntelligence();
			OnAttributeChangedDelegate.Broadcast(IntelligenceAttributeInfo);
		});

	AbilitySystemComponent
		->GetGameplayAttributeValueChangeDelegate(AuraAttributeSet->GetResilienceAttribute())
		.AddLambda([this, AuraAttributeSet](const FOnAttributeChangeData& Data)
		{
			FAuraAttributeInfo ResilienceAttributeInfo = AttributeInfo->FindAttributeInfoByTag(
				FAuraGameplayTags::Get().Attributes_Primary_Resilience);
			ResilienceAttributeInfo.AttributeValue = AuraAttributeSet->GetResilience();
			OnAttributeChangedDelegate.Broadcast(ResilienceAttributeInfo);
		});

	AbilitySystemComponent
		->GetGameplayAttributeValueChangeDelegate(AuraAttributeSet->GetVitalityAttribute())
		.AddLambda([this, AuraAttributeSet](const FOnAttributeChangeData& Data)
		{
			FAuraAttributeInfo VitalityAttributeInfo = AttributeInfo->FindAttributeInfoByTag(
				FAuraGameplayTags::Get().Attributes_Primary_Vitality);
			VitalityAttributeInfo.AttributeValue = AuraAttributeSet->GetVitality();
			OnAttributeChangedDelegate.Broadcast(VitalityAttributeInfo);
		});
}
