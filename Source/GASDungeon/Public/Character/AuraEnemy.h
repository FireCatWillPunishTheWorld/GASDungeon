// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "GASDungeon/GASDungeon.h"
#include "GASDungeon/Interaction/EnemyInterface.h"
#include "AuraEnemy.generated.h"


/**
 * 
 */
class UAuraAbilitySystemComponent;
class UAttributeSet;
UCLASS()
class GASDUNGEON_API AAuraEnemy : public AAuraCharacterBase , public IEnemyInterface
{
	GENERATED_BODY()
public:
	AAuraEnemy();
	UPROPERTY(BlueprintReadOnly)
	bool bHighLightActor=false;
	
protected:
	virtual void BeginPlay() override;
	virtual void InitAbilityActorInfo() override;
	// virtual void HighLightActor_Implementation() override;
	//
	// virtual void UnHighLightActor_Implementation() override;
};
