// Fill out your copyright notice in the Description page of Project Settings.


#include "AuraAssetManager.h"

#include "AuraGamePlayTags.h"


DEFINE_LOG_CATEGORY_CLASS(UAuraAssetManager, AuraAssetManagerLog)

UAssetManager& UAuraAssetManager::Get()
{
	UAuraAssetManager* AuraAssetManager = Cast<UAuraAssetManager>(GEngine->AssetManager);
	if (AuraAssetManager)
	{
		return *AuraAssetManager;
	}
	else
	{
		AURA_ASSET_MANAGER_LOG(Warning,TEXT("UAuraAssetManager::Get() - AssetManager is not valid"));		
		return *NewObject<UAuraAssetManager>();
	}
}

void UAuraAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();

	FAuraGameplayTags::InitializeNativeGameplayTags();

	
}
