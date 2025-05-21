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

		UFUNCTION(BlueprintCallable)
		bool IsTalking()
		{
			return bIsComplete;
		}

	protected:

		UPROPERTY(BlueprintReadWrite)
		FString newString;

		UPROPERTY(BlueprintReadWrite)
		float typeSpeed = 50;

		
	
		float typeTimer = 30, timerMax = 30;
		int characterToAdd = 0;
		FString stringToType;
		bool bIsComplete = true,bCanStartDialogue = false;;

		

		UFUNCTION(BlueprintCallable)
		void TypeOutString();

		UFUNCTION(BlueprintCallable)
		void SkipToString();

		UFUNCTION(BlueprintCallable)
		void ClearString();

		

	
	
};
