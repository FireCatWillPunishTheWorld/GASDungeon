// Fill out your copyright notice in the Description page of Project Settings.

#include "Player/AuraPlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"


void AAuraPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
	CursorTrace();
}

AAuraPlayerController::AAuraPlayerController()
{
	bReplicates = false;
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;
}


void AAuraPlayerController::BeginPlay()
{
	Super::BeginPlay();

	//断点检查AuraContext是否为空 不存在就会崩溃
	check(AuraContext);

	//得到增强输入子系统	
	UEnhancedInputLocalPlayerSubsystem* InputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(
		GetLocalPlayer());
	if (InputSubsystem)
	{		
		//添加输入上下文
		InputSubsystem->AddMappingContext(AuraContext, 0);
	}
	bShowMouseCursor =true;
	DefaultMouseCursor=EMouseCursor::Default;
	
	FInputModeGameAndUI InputMode;
	InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputMode.SetHideCursorDuringCapture(false);	
	SetInputMode(InputMode);
}

void AAuraPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this,
	                                   &AAuraPlayerController::MoveActionTriggered);
}

void AAuraPlayerController::MoveActionTriggered(const FInputActionValue& Value)
{
	const FVector2D InputAxisVector = Value.Get<FVector2D>();
	const FRotator YawRotation(0.f, GetControlRotation().Yaw, 0.f);
	const FVector ForwardDir = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDir = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (APawn* ControlledPawn = GetPawn())
	{
		ControlledPawn->AddMovementInput(ForwardDir, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDir, InputAxisVector.X);
	}
}

void AAuraPlayerController::CursorTrace()
{
	FHitResult CursorHit;
	GetHitResultUnderCursor(ECC_Visibility, false, CursorHit);
	if (!CursorHit.GetActor())return;
	LastActor = ThisActor;
	ThisActor = Cast<IEnemyInterface>(CursorHit.GetActor());
	/**
	* Line trace from cursor. There are several scenarios:
	* A. LastActor is null && ThisActor is null
	- Do nothing
	* B. LastActor is null && ThisActor is volid
	- Highlight ThisActor
	* C. LastActor is valid && ThisActor is null
	UnHighlight LastActor
	* D. Both actors are valid, but LastActor != ThisActor
	- UnHighlight LastActor, and Highlight ThisActor
	E. Both actors are valid, and are the same actor
	- Do nothing
	*/
	if (LastActor == nullptr)
	{
		if (ThisActor != nullptr)
		{
			//HighLightActor
			ThisActor->Execute_HighLightActor(ThisActor->_getUObject());
		}
		else
		{
			//A
		}
	}
	else
	{
		if (ThisActor==nullptr)
		{
			LastActor->Execute_UnHighLightActor(LastActor->_getUObject());
		}
		else
		{
			if (ThisActor==LastActor)
			{
				
			}
			else
			{
				LastActor->Execute_UnHighLightActor(LastActor->_getUObject());
				ThisActor->Execute_HighLightActor(ThisActor->_getUObject());
			}
		}
	}
}
