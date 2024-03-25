// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Data/AttributeInfo.h"

#include "GASDungeon/GASDungeon.h"

FAuraAttributeInfo UAttributeInfo::FindAttributeInfoForTag(const FGameplayTag& Tag, bool bLogNotFound) const
{
	for (const FAuraAttributeInfo& AttributeInfo : AttributeInfos)
	{
		if (AttributeInfo.AttributeTag.MatchesTagExact(Tag))
		{
			return AttributeInfo;
		}
	}

	if (bLogNotFound)
	{
		AURA_LOG(Error, TEXT("UAttributeInfo::FindAttributeInfoForTag - Couldn't find AttributeInfo for tag: %s"), *Tag.ToString());
	}
	return FAuraAttributeInfo();
}
