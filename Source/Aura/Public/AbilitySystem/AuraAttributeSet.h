// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "AuraAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

USTRUCT()
struct FEffectProperties
{
	GENERATED_BODY()

	FEffectProperties(): TargetAbilitySystemComponent(nullptr), SourceAbilitySystemComponent(nullptr),
	                     TargetController(nullptr), SourceController(nullptr),
	                     TargetAvatarActor(nullptr),
	                     SourceAvatarActor(nullptr),
	                     TargetOwnerActor(nullptr),
	                     SourceOwnerActor(nullptr),
	                     TargetCharacter(nullptr),
	                     SourceCharacter(nullptr)
	{
	}

	UPROPERTY()
	UAbilitySystemComponent* TargetAbilitySystemComponent;
	UPROPERTY()
	UAbilitySystemComponent* SourceAbilitySystemComponent;

	UPROPERTY()
	AController* TargetController;
	UPROPERTY()
	AController* SourceController;

	UPROPERTY()
	AActor* TargetAvatarActor;
	UPROPERTY()
	AActor* SourceAvatarActor;

	UPROPERTY()
	AActor* TargetOwnerActor;
	UPROPERTY()
	AActor* SourceOwnerActor;

	UPROPERTY()
	ACharacter* TargetCharacter;
	UPROPERTY()
	ACharacter* SourceCharacter;
	
	FGameplayEffectContextHandle EffectContextHandle;
};

/**
 * 
 */
UCLASS()
class AURA_API UAuraAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UAuraAttributeSet();
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health, Category = "Health Attributes")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Health)
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealth, Category = "Health Attributes")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, MaxHealth)

	// Mana and MaxMana attributes
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Mana, Category = "Mana Attributes")
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Mana)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxMana, Category = "Mana Attributes")
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, MaxMana)
	

	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldHealth) const;
	
	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const;

	UFUNCTION()
	void OnRep_Mana(const FGameplayAttributeData& OldMana) const;

	UFUNCTION()
	void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const;

	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;

private:
	static void SetEffectProperties(const FGameplayEffectModCallbackData& Data, FEffectProperties& EffectProperties);
};
