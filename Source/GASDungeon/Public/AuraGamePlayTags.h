// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
/**
 * AuraGameplayTags
 *
 * SingleTon containing native Gameplay Tags
 */
struct FAuraGameplayTags
{
public:
 static const FAuraGameplayTags& Get(){return GameplayTag;};
 static void InitializeNativeGameplayTags();
protected:
private:
 static FAuraGameplayTags GameplayTag;
};
