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
	public:
		virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

		

		UFUNCTION(BlueprintCallable)
		void StartWriting(FString savedString, bool savedBool);

		UFUNCTION(BlueprintCallable)
		bool CanStart()
		{
			return bCanStartDialogue;
		}

	protected:

		UPROPERTY(BlueprintReadWrite)
		FString newString;

		
	
		float typeTimer = 30, timerMax = 30;
		int characterToAdd = 0;
		FString stringToType;
		bool bIsComplete,bCanStartDialogue = false;;

		

		UFUNCTION(BlueprintCallable)
		void TypeOutString();

	
	
};
