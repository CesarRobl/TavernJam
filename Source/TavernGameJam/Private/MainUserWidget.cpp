// Fill out your copyright notice in the Description page of Project Settings.


#include "MainUserWidget.h"
void UMainUserWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	if (bCanStartDialogue)
	{
		TypeOutString();
	}
}

void UMainUserWidget::StartWriting(FString savedString, bool savedBool)
{
	stringToType = savedString;
	bCanStartDialogue = savedBool;
}



void UMainUserWidget::TypeOutString()
{
		float typeSpeed = 10;
	
		if(!bIsComplete)
		{
			TChar characters[] = stringToType.GetCharArray();
			
			
				typeTimer -= GetWorld()->DeltaTimeSeconds * typeSpeed;
				UE_LOG(LogTemp, Warning, TEXT("Type Timer: %s"), *stringToType);
				if(typeTimer <= 0)
				{
					newString += characters[characterToAdd];
					typeTimer = timerMax;

					characterToAdd++;

					if(newString.Len() >= stringToType.Len())
						bIsComplete = true;

					return;
				}
			
		}
	

	bIsComplete = (newString.Len() >= stringToType.Len());
}


