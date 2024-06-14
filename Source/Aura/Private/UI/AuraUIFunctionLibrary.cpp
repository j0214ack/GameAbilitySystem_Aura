// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/AuraUIFunctionLibrary.h"

#include "Kismet/GameplayStatics.h"
#include "UI/HUD/AuraHUD.h"

UAttributesMenuWidgetController* UAuraUIFunctionLibrary::GetAttributesMenuWidgetController(const UObject* WorldContextObject)
{
	if(APlayerController* PlayerController = UGameplayStatics::GetPlayerController(WorldContextObject, 0))
	{
		if(AAuraHUD* AuraHUD = Cast<AAuraHUD>(PlayerController->GetHUD()))
		{
			return AuraHUD->GetAttributesMenuWidgetController();
		}
	}
	return nullptr;
}
