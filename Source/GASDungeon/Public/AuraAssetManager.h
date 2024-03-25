// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "AuraAssetManager.generated.h"


/**
 * 请确保在DefaultEngine.ini中设置了AssetManagerClassName
 * 该值为AssetManagerClassName=/Script/GASDungeon.AuraAssetManager
 */
UCLASS()
class GASDUNGEON_API UAuraAssetManager : public UAssetManager
{
	DECLARE_LOG_CATEGORY_CLASS(AuraAssetManagerLog, Log, All);

	#define AURA_ASSET_MANAGER_LOG(Verbosity, Format, ...) \
	UE_LOG(AuraAssetManagerLog, Verbosity, Format, ##__VA_ARGS__)
	GENERATED_BODY()

public:
	static UAssetManager& Get();
protected:
	virtual void StartInitialLoading() override;
};
