// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "GameFramework/Character.h"
#include "TavernGameJamCharacter.generated.h"

class UInputMappingContext;
class UInputAction;

UCLASS(Blueprintable)
class ATavernGameJamCharacter : public ACharacter
{
	GENERATED_BODY()

		
	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* DefaultMappingContext;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* MoveAction;

	
	

public:
	ATavernGameJamCharacter();

	// Called every frame.
	virtual void Tick(float DeltaSeconds) override;

	/** Returns TopDownCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

private:
	/** Top down camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* TopDownCameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

protected:

	
	bool bPlayerCanWalk = true;

	UFUNCTION(BlueprintCallable)
	void SetWalkState(bool walkState)
	{
		bPlayerCanWalk = walkState;
	}
	
	void Move(const FInputActionValue& Value);
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void CameraZoomIn();
	
};

