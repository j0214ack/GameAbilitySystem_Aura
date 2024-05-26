// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "AuraWidgetController.generated.h"

class UAuraUserWidget;
class UAbilitySystemComponent;
class UAttributeSet;

USTRUCT(BlueprintType)
struct FWidgetControllerParams
{
	GENERATED_BODY()

	FWidgetControllerParams() {}
	FWidgetControllerParams(APlayerController* InPlayerController, APlayerState* InPlayerState, UAbilitySystemComponent* InAbilitySystemComponent, UAttributeSet* InAttributeSet)
		: PlayerController(InPlayerController)
		, PlayerState(InPlayerState)
		, AbilitySystemComponent(InAbilitySystemComponent)
		, AttributeSet(InAttributeSet)
	{
	}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Aura|WidgetController")
	TObjectPtr<APlayerController> PlayerController = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Aura|WidgetController")
	TObjectPtr<APlayerState> PlayerState = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Aura|WidgetController")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Aura|WidgetController")
	TObjectPtr<UAttributeSet> AttributeSet = nullptr;
};

USTRUCT(BlueprintType)
struct FMessageTagUIWidgetRow : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Aura|WidgetController")
	FGameplayTag MessageTag = FGameplayTag::EmptyTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Aura|WidgetController")
	FText Message;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Aura|WidgetController")
	TSubclassOf<UAuraUserWidget> WidgetClass;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Aura|WidgetController")
	UTexture2D* Icon = nullptr;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMessageTagAddedSignature, const FGameplayTag&, Tag,
                                             const FMessageTagUIWidgetRow&, WidgetData);

/**
 * 
 */
UCLASS()
class AURA_API UAuraWidgetController : public UObject
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	void SetWidgetControllerParams(const FWidgetControllerParams& InWidgetControllerParams);
	virtual void BroadcastInitialValues() const {}
	virtual void BindToAttributeChanges() const {}

protected:
	UPROPERTY(BlueprintReadOnly, Category = "Aura|WidgetController")
	TObjectPtr<APlayerController> PlayerController;
	
	UPROPERTY(BlueprintReadOnly, Category = "Aura|WidgetController")
	TObjectPtr<APlayerState> PlayerState;

	UPROPERTY(BlueprintReadOnly, Category = "Aura|WidgetController")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
	
	UPROPERTY(BlueprintReadOnly, Category = "Aura|WidgetController")
	TObjectPtr<UAttributeSet> AttributeSet;

	UPROPERTY(EditDefaultsOnly, Category = "Aura|WidgetController|GameplayTags Widget Data")
	TObjectPtr<UDataTable> MessageTagUIWidgetTable;

	UPROPERTY(BlueprintAssignable, Category = "Aura|WidgetController|GameplayTags Widget Data")
	FOnMessageTagAddedSignature OnMessageTagReceivedDelegate;
};
