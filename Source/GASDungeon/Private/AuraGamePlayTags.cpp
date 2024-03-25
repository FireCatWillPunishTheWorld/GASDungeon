// Fill out your copyright notice in the Description page of Project Settings.


#include "AuraGamePlayTags.h"

#include "GameplayTagsManager.h"

FAuraGameplayTags FAuraGameplayTags::GameplayTag;

void FAuraGameplayTags::InitializeNativeGameplayTags()
{
	//Vital Attributess
	GameplayTag.Attribute_Secondary_MaxHealth = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attribute.Secondary.MaxHealth"), FString("Maximum Health"));
	GameplayTag.Attribute_Secondary_MaxMana = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attribute.Secondary.MaxMana"), FString("Maximum Mana"));

	//Primary Attributes;
	GameplayTag.Attributes_Primary_Intelligence = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attribute.Primary.Intelligence"), FString("Increases magical damage"));
	GameplayTag.Attributes_Primary_Resilience = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attribute.Primary.Resilience"), FString("Increases health and reduces damage taken"));
	GameplayTag.Attributes_Primary_Strength = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attribute.Primary.Strength"), FString("Increases physical damage"));
	GameplayTag.Attributes_Primary_Vigor = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attribute.Primary.Vigor"), FString("Increases health and stamina"));

	//Secondary Attributes
	GameplayTag.Attributes_Secondary_AromorPenetration = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attribute.Secondary.ArmorPenetration"), FString("Ignores a portion of the target's armor"));
	GameplayTag.Attributes_Secondary_BlockChance = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attribute.Secondary.BlockChance"), FString("Chance to block incoming damage"));
	GameplayTag.Attributes_Secondary_CriticalHitChance = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attribute.Secondary.CriticalHitChance"), FString("Chance to deal double damage"));
	GameplayTag.Attributes_Secondary_CriticalHitDamage = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attribute.Secondary.CriticalHitDamage"), FString("Increased damage dealt on critical hit"));
	GameplayTag.Attributes_Secondary_Aromor = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attribute.Secondary.Armor"), FString("Reduce damage taken,improves block chance"));
	GameplayTag.Attributes_Secondary_HealthRegeneration = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attribute.Secondary.HealthRegeneration"), FString("Regenerate health over time"));
	GameplayTag.Attributes_Secondary_ManaRegeneration = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attribute.Secondary.ManaRegeneration"), FString("Regenerate mana over time"));
}
