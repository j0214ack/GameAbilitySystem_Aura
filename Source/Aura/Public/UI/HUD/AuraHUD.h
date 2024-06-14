// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "AuraHUD.generated.h"

class UAttributesMenuWidgetController;
struct FWidgetControllerParams;
class UAttributeSet;
class UAbilitySystemComponent;
class UAuraUserWidget;
class UAuraWidgetController;
/**
 * 
 */
UCLASS()
class AURA_API AAuraHUD : public AHUD
{
	GENERATED_BODY()
public:

	UPROPERTY()
	TObjectPtr<UAuraUserWidget> OverlayWidget;

	UFUNCTION(BlueprintCallable)
	UAuraWidgetController* GetOverlayWidgetController();
	
	UFUNCTION(BlueprintCallable)
	UAttributesMenuWidgetController* GetAttributesMenuWidgetController();

	void Init(APlayerController* PlayerController, APlayerState* PlayerState, UAbilitySystemComponent* AbilitySystemComponent, UAttributeSet* AttributeSet);

private:
	void InitOverlayWidgetController(const FWidgetControllerParams& WidgetControllerParams);
	void InitAttributesMenuWidgetController(const FWidgetControllerParams& WidgetControllerParams);
	void InitOverlayWidget(const FWidgetControllerParams& WidgetControllerParams);
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<UAuraUserWidget> OverlayWidgetClass;
	
	UPROPERTY()
	TObjectPtr<UAuraWidgetController> OverlayWidgetController;

	UPROPERTY()
	TObjectPtr<UAttributesMenuWidgetController> AttributesMenuWidgetController;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UAuraWidgetController> OverlayWidgetControllerClass;
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<UAttributesMenuWidgetController> AttributesMenuWidgetControllerClass;
};
