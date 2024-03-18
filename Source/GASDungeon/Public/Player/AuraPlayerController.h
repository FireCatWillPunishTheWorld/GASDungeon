// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputMappingContext.h"
#include "GameFramework/PlayerController.h"
#include "GASDungeon/Interaction/EnemyInterface.h"
#include "AuraPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class GASDUNGEON_API AAuraPlayerController : public APlayerController
{
	GENERATED_BODY()
	virtual void PlayerTick(float DeltaTime) override;
public:
	AAuraPlayerController();
private:
	UPROPERTY(EditAnywhere,Category="Input")
	TObjectPtr<UInputMappingContext> AuraContext;

	UPROPERTY(EditAnywhere,Category="Input")
	TObjectPtr<UInputAction> MoveAction;

	void MoveActionTriggered(const FInputActionValue& Value);

	void CursorTrace();
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

	IEnemyInterface* LastActor;
	IEnemyInterface* ThisActor;
};
