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
	bIsComplete = false;
	
}

void UMainUserWidget::ClearString()
{
	characterToAdd = 0;
	newString = "";
	stringToType = "";
	bIsComplete = true;
	bCanStartDialogue = false;
}


void UMainUserWidget::TypeOutString()
{
		if(!bIsComplete)
		{
				typeTimer -= GetWorld()->DeltaTimeSeconds * typeSpeed;
				if(typeTimer <= 0)
				{
					if(characterToAdd < stringToType.Len())
					{
						newString += stringToType[characterToAdd];
						typeTimer = timerMax;
						characterToAdd++;
					}
					
					if(newString.Len() >= stringToType.Len())
						bIsComplete = true;

					return;
				}
		}
	
	bIsComplete = (newString.Len() >= stringToType.Len());
}

void UMainUserWidget::SkipToString()
{
	bIsComplete = true;
	newString = stringToType;
}



