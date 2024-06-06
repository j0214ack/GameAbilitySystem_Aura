// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/MMC_MaxMana.h"

#include "AbilitySystem/AuraAttributeSet.h"
#include "Interaction/CombatInterface.h"

UMMC_MaxMana::UMMC_MaxMana()
{
	IntelligenceDef.AttributeToCapture = UAuraAttributeSet::GetIntelligenceAttribute();
	IntelligenceDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
	IntelligenceDef.bSnapshot = false;

	RelevantAttributesToCapture.Add(IntelligenceDef);
}

float UMMC_MaxMana::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
	FAggregatorEvaluateParameters EvaluationParameters;
	EvaluationParameters.SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	EvaluationParameters.TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

	float Intelligence = 0.f;
	GetCapturedAttributeMagnitude(IntelligenceDef, Spec, EvaluationParameters, Intelligence);
	Intelligence = FMath::Max<float>(0.f, Intelligence);

	// this effect is to calculate the max health from vitality and level of an actor
	// the effect is applied to self, so the source object is the target actor
	ICombatInterface* TargetActor = Cast<ICombatInterface>(Spec.GetContext().GetSourceObject());
	const int32 CharacterLevel = TargetActor->GetCharacterLevel();

	return 30.f + (Intelligence * 1.5f) + (CharacterLevel * 5.f);
}
