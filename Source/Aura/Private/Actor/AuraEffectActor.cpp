#include "Actor/AuraEffectActor.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"
#include "GameplayEffect.h"

// Sets default values
AAuraEffectActor::AAuraEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SetRootComponent(CreateDefaultSubobject<USceneComponent>("SceneRoot"));;

}

void AAuraEffectActor::BeginPlay()
{
	Super::BeginPlay();

}

void AAuraEffectActor::OnOverlay(AActor* TargetActor)
{
	UAbilitySystemComponent* TargetAbilitySystemComponent =	UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);
	if (TargetAbilitySystemComponent == nullptr)
	{
		return;
	}

	checkf(EffectsToApply.Num() > 0, TEXT("EffectsToApply is not set in AuraEffectActor %s"), *GetName());

	ApplyEffects(TargetAbilitySystemComponent);

	if (bDestroyAfterApply)
	{
		Destroy();
	}
}

void AAuraEffectActor::OnEndOverlay(AActor* TargetActor)
{
	if (EndOverlapPolicy == EEndOverlapPolicy::None)
	{
		return;
	}
	
	UAbilitySystemComponent* TargetAbilitySystemComponent =	UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);
	if (TargetAbilitySystemComponent == nullptr)
	{
		return;
	}
	
	checkf(EffectsToApply.Num() > 0, TEXT("EffectsToApply is not set in AuraEffectActor %s"), *GetName());

	RemoveEffects(TargetAbilitySystemComponent);
}

void AAuraEffectActor::ApplyEffects(UAbilitySystemComponent* TargetAbilitySystemComponent)
{
	for (FEffectLevel EffectToApply : EffectsToApply)
	{
		FGameplayEffectContextHandle EffectContextHandle = TargetAbilitySystemComponent->MakeEffectContext();
		EffectContextHandle.AddSourceObject(this);
		FGameplayEffectSpecHandle EffectSpecHandle = TargetAbilitySystemComponent->MakeOutgoingSpec(EffectToApply.Effect, EffectToApply.Level, EffectContextHandle);
		TargetAbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*EffectSpecHandle.Data.Get());
	}
}

void AAuraEffectActor::RemoveEffects(UAbilitySystemComponent* TargetAbilitySystemComponent)
{
	for (FEffectLevel EffectToApply : EffectsToApply)
	{
		if (EffectToApply.Effect.GetDefaultObject()->DurationPolicy != EGameplayEffectDurationType::Infinite)
		{
			return;
		}
		
		FGameplayEffectQuery Query;
		Query.EffectSource = this;
		Query.EffectDefinition = EffectToApply.Effect;
		TArray<FActiveGameplayEffectHandle> EffectHandles;
		EffectHandles = TargetAbilitySystemComponent->GetActiveEffects(Query);
		for (FActiveGameplayEffectHandle& EffectHandle : EffectHandles)
		{
			TargetAbilitySystemComponent->RemoveActiveGameplayEffect(EffectHandle);
		}
	}
}
