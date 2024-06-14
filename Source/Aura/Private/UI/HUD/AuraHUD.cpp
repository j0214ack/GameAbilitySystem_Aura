// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HUD/AuraHUD.h"

#include "UI/Widget/AttributesMenuWidgetController.h"
#include "UI/Widget/AuraUserWidget.h"
#include "UI/Widget/OverlayWidgetController.h"
#include "UI/Widget/AuraWidgetController.h"

UAuraWidgetController* AAuraHUD::GetOverlayWidgetController()
{
	checkf(OverlayWidgetController, TEXT("OverlayWidgetController is not set in %s"), *GetName());
	return OverlayWidgetController;
}

UAttributesMenuWidgetController* AAuraHUD::GetAttributesMenuWidgetController()
{
	checkf(AttributesMenuWidgetController, TEXT("AttributesMenuWidgetController is not set in %s"), *GetName());
	return AttributesMenuWidgetController;
}

void AAuraHUD::Init(APlayerController* PlayerController, APlayerState* PlayerState,
                    UAbilitySystemComponent* AbilitySystemComponent, UAttributeSet* AttributeSet)
{
	const FWidgetControllerParams WidgetControllerParams(PlayerController, PlayerState, AbilitySystemComponent, AttributeSet);
	InitOverlayWidget(WidgetControllerParams);
	InitAttributesMenuWidgetController(WidgetControllerParams);
}

void AAuraHUD::InitOverlayWidgetController(const FWidgetControllerParams& WidgetControllerParams)
{
	if (OverlayWidgetController == nullptr)
	{
		checkf(OverlayWidgetControllerClass, TEXT("OverlayWidgetControllerClass is not set in %s"), *GetName());
		OverlayWidgetController = NewObject<UOverlayWidgetController>(this, OverlayWidgetControllerClass);
		OverlayWidgetController->SetWidgetControllerParams(WidgetControllerParams);
		OverlayWidgetController->BindToAttributeChanges();
	}
}

void AAuraHUD::InitAttributesMenuWidgetController(const FWidgetControllerParams& WidgetControllerParams)
{
	if (AttributesMenuWidgetController == nullptr)
	{
		checkf(AttributesMenuWidgetControllerClass, TEXT("AttributesMenuWidgetControllerClass is not set in %s"), *GetName());
		AttributesMenuWidgetController = NewObject<UAttributesMenuWidgetController>(this, AttributesMenuWidgetControllerClass);
		AttributesMenuWidgetController->SetWidgetControllerParams(WidgetControllerParams);
		AttributesMenuWidgetController->BindToAttributeChanges();
	}
}

void AAuraHUD::InitOverlayWidget(const FWidgetControllerParams& WidgetControllerParams)
{
	checkf(OverlayWidgetClass, TEXT("OverlayWidgetClass is not set in %s"), *GetName());
	
	OverlayWidget = CreateWidget<UAuraUserWidget>(GetWorld(), OverlayWidgetClass);
	
	InitOverlayWidgetController(WidgetControllerParams);
	
	OverlayWidget->SetWidgetController(OverlayWidgetController);
	OverlayWidgetController->BroadcastInitialValues();
	OverlayWidget->AddToViewport();
}
