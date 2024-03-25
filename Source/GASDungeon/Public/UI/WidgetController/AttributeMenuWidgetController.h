// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetController/AuraWidgetController.h"
#include "AttributeMenuWidgetController.generated.h"

/**
 * 
 */
UCLASS()
class GASDUNGEON_API UAttributeMenuWidgetController : public UAuraWidgetController
{
	GENERATED_BODY()
	void BindCallbacksToDependencies() override;
	void BroadcastInitValues() override;
};
