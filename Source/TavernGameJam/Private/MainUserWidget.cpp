// Fill out your copyright notice in the Description page of Project Settings.


#include "MainUserWidget.h"

void UMainUserWidget::TypeOutString(FString stringToType, float typeSpeed, FString& outString, bool& bIsComplete)
{
	outString = "";
	bIsComplete = false;
			
	for (TCHAR character : stringToType)
	{
		typeTimer -= GetWorld()->DeltaTimeSeconds * typeSpeed;
		if(typeSpeed <= 0)
		{
			outString += character;
			typeTimer = timerMax;

			if(outString.Len() >= stringToType.Len())
				bIsComplete = true;

			return;
		}
	}

	bIsComplete = (outString.Len() >= stringToType.Len());
}


