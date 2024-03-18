// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HUD/AuraHUD.h"

UOverlayWidgetController* AAuraHUD::GetOverlayWidgetController(const FWidgetControllerParams& WCParams)
{
	if (OverlayWidgetController==nullptr)
	{
		OverlayWidgetController=NewObject<UOverlayWidgetController>(this,OverlayWidgetControllerClass);
		//Set the Widget Controller Params
		OverlayWidgetController->SetWidgetControllerParams(WCParams);
		//Bind the Callbacks to the Dependencies
		OverlayWidgetController->BindCallbacksToDependencies();		
		return OverlayWidgetController;
	}
	return OverlayWidgetController;
}

void AAuraHUD::InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	checkf(OverlayWidgetClass,TEXT("OverlayWidgetClass is not set in AuraHUD"));
	checkf(OverlayWidgetControllerClass,TEXT("OverlayWidgetControllerClass is not set in AuraHUD"));
	
	UUserWidget* Widget = CreateWidget<UAuraUserWidget>(GetWorld(), OverlayWidgetClass);
	OverlayWidget=Cast<UAuraUserWidget>(Widget);

	// Create Widget Controller By passing the parameters
	const FWidgetControllerParams WCParams(PC,PS,ASC,AS);
	UOverlayWidgetController* WidgetController=GetOverlayWidgetController(WCParams);

	OverlayWidget->SetWidgetController(WidgetController);
	//Broadcast InitValues
	WidgetController->BroadcastInitValues();
	
	Widget->AddToViewport();
}

