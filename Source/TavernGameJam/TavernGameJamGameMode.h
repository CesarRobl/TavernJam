// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TavernGameJamGameMode.generated.h"

UCLASS(minimalapi)
class ATavernGameJamGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ATavernGameJamGameMode();
};

USTRUCT()
struct FDialogueData : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FName DialogueID;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FString SpeakerName;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FString LineText;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	int32 LineOrder;
};




