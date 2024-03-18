// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetController/OverlayWidgetController.h"

#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "AbilitySystem/AuraAttributeSet.h"

void UOverlayWidgetController::BroadcastInitValues()
{
	const UAuraAttributeSet* AuraAttributeSet=CastChecked<UAuraAttributeSet>(AttributeSet);

	OnHealthChanged.Broadcast(AuraAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(AuraAttributeSet->GetMaxHealth());	
}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	const UAuraAttributeSet* AuraAttributeSet=CastChecked<UAuraAttributeSet>(AttributeSet);
	
	//AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AuraAttributeSet->GetHealthAttribute()).AddUObject(this, &UOverlayWidgetController::HealthChanged);
	const FGameplayAttribute HealthAttribute= AuraAttributeSet->GetHealthAttribute();
	FOnGameplayAttributeValueChange* HealthChange= &(AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(HealthAttribute));
	HealthChange->AddUObject(this, &UOverlayWidgetController::HealthChanged);
	
	const FGameplayAttribute MaxHealthAttribute= AuraAttributeSet->GetMaxHealthAttribute();
	FOnGameplayAttributeValueChange* MaxHealthChange= &(AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(MaxHealthAttribute));
	MaxHealthChange->AddUObject(this, &UOverlayWidgetController::MaxHealthChanged);

	const FGameplayAttribute ManaAttribute= AuraAttributeSet->GetManaAttribute();
	FOnGameplayAttributeValueChange* ManaChange= &(AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(ManaAttribute));
	ManaChange->AddUObject(this, &UOverlayWidgetController::ManaChanged);

	const FGameplayAttribute MaxManaAttribute= AuraAttributeSet->GetMaxManaAttribute();
	FOnGameplayAttributeValueChange* MaxManaChange= &(AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(MaxManaAttribute));
	MaxManaChange->AddUObject(this, &UOverlayWidgetController::MaxManaChanged);

	Cast<UAuraAbilitySystemComponent>(AbilitySystemComponent)->EffectAssetTags.AddUObject(this,&UOverlayWidgetController::CheckEffectAssetTags);
	// ([](const FGameplayTagContainer& AssetTags)
	// {
	// 	for(const FGameplayTag& Tag:AssetTags)
	// 	{
	// 		const FString Msg=FString::Printf(TEXT("GE Tag:%s"),*Tag.ToString());
	// 		GEngine->AddOnScreenDebugMessage(-1,8.f,FColor::Blue,Msg);
	// 	}
	// }
	// 	);
}
void UOverlayWidgetController::CheckEffectAssetTags(const FGameplayTagContainer& AssetTags)
{
	for(const FGameplayTag& Tag:AssetTags)
	{
		const FString Msg=FString::Printf(TEXT("GE Tag:%s"),*Tag.ToString());
		GEngine->AddOnScreenDebugMessage(-1,8.f,FColor::Blue,Msg);
	}
}

void UOverlayWidgetController::HealthChanged(const FOnAttributeChangeData& Data) const
{
	OnHealthChanged.Broadcast(Data.NewValue);	
}

void UOverlayWidgetController::MaxHealthChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::ManaChanged(const FOnAttributeChangeData& Data) const
{
	OnManaChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxManaChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxManaChanged.Broadcast(Data.NewValue);
}
