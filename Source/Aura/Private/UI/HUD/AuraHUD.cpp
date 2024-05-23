// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HUD/AuraHUD.h"
#include "UI/Widget/AuraUserWidget.h"
#include "UI/Widget/OverlayWidgetController.h"
#include "UI/Widget/AuraWidgetController.h"

UAuraWidgetController* AAuraHUD::GetOverlayWidgetController()
{
	checkf(OverlayWidgetController, TEXT("OverlayWidgetController is not set in %s"), *GetName());
	return OverlayWidgetController;
}

void AAuraHUD::InitOverlay(APlayerController* PlayerController, APlayerState* PlayerState,
	UAbilitySystemComponent* AbilitySystemComponent, UAttributeSet* AttributeSet)
{
	checkf(OverlayWidgetClass, TEXT("OverlayWidgetClass is not set in %s"), *GetName());
	
	OverlayWidget = CreateWidget<UAuraUserWidget>(GetWorld(), OverlayWidgetClass);
	
	const FWidgetControllerParams WidgetControllerParams(PlayerController, PlayerState, AbilitySystemComponent, AttributeSet);
	InitOverlayWidgetController(WidgetControllerParams);
	
	OverlayWidget->SetWidgetController(OverlayWidgetController);
	OverlayWidgetController->BroadcastInitialValues();
	OverlayWidget->AddToViewport();
	
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
