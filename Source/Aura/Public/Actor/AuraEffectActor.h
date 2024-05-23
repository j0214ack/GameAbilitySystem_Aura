// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AuraEffectActor.generated.h"

class UAbilitySystemComponent;
class UGameplayEffect;

UENUM(BlueprintType)
enum class EEndOverlapPolicy : uint8
{
	None,
	RemoveEffect
};

USTRUCT(BlueprintType)
struct FEffectLevel
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UGameplayEffect> Effect;

	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float Level;
};

UCLASS()
class AURA_API AAuraEffectActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAuraEffectActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<FEffectLevel> EffectsToApply;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	EEndOverlapPolicy EndOverlapPolicy = EEndOverlapPolicy::RemoveEffect;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bDestroyAfterApply = true;
	
	UFUNCTION(BlueprintCallable)
	void OnOverlay(AActor* TargetActor);

	UFUNCTION(BlueprintCallable)
	void OnEndOverlay(AActor* TargetActor);

private:
	void ApplyEffects(UAbilitySystemComponent* TargetAbilitySystemComponent);
	void RemoveEffects(UAbilitySystemComponent* TargetAbilitySystemComponent);
};
