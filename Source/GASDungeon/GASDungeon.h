// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Logging/LogMacros.h"
#include "CoreMinimal.h"


DECLARE_LOG_CATEGORY_EXTERN(AURALOG, Log, All);
#define AURA_LOG(Verbosity, Format, ...) \
	UE_LOG(AURALOG, Verbosity,Format, ##__VA_ARGS__)