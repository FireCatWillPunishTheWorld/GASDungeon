// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataAsset.h"
#include "AttributeInfo.generated.h"

USTRUCT(BlueprintType)
struct FAuraAttributeInfo
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	FGameplayTag AttributeTag=FGameplayTag();

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	FText AttributeName=FText();
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	FText AttributeDescription=FText();

	UPROPERTY(BlueprintReadOnly)
	float AttributeValue=0.f;

};
/**
 * 
 */
UCLASS()
class GASDUNGEON_API UAttributeInfo : public UDataAsset
{
	GENERATED_BODY()
public:
	//查找标签对应的属性信息
	FAuraAttributeInfo FindAttributeInfoForTag(const FGameplayTag& Tag,bool bLogNotFound=false) const;

	
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	TArray<FAuraAttributeInfo> AttributeInfos;
};
