// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class TAVERNGAMEJAM_API UMainUserWidget : public UUserWidget
{
	GENERATED_BODY()

	protected:
		
		float typeTimer = 1, timerMax = 1;

		UFUNCTION(BlueprintCallable)
		void TypeOutString(FString stringToType, float typeSpeed, FString& outString, bool& bIsComplete);
	
};
