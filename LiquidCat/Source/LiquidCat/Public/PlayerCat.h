// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "PaperFlipbookComponent.h"
#include "Components/InputComponent.h"
#include "InputActionValue.h"
#include "EnhancedPlayerInput.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "PlayerCat.generated.h"

/**
 * 
 */
UCLASS()
class LIQUIDCAT_API APlayerCat : public APaperCharacter
{
	GENERATED_BODY()


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	APlayerCat();

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void Tick(float DeltaTime) override;


	//Actions
	UFUNCTION(BlueprintCallable, Category = InputSys)
	void MoveXAxis(const FInputActionValue& val);
	UFUNCTION(BlueprintCallable, Category = InputSys)
	void MoveXAxisCompleted(const FInputActionValue& val);

	//Camera
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerSprite")
	class UPaperFlipbookComponent* PlayerSprite;
	UPROPERTY()



	//Movement data
	float DeltaX = 0.f;
	float DeltaY = 0.f;
	float Speed = 5.f;

	FVector InitLocation = FVector::ZeroVector;



	//InputMappingContext
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = InputSystem)
	class UInputMappingContext* IMCPlayerInput;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = InputSystem)
	class UInputAction* IA_MoveRigthLeft;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = InputSystem)
	class UInputAction* IAJump;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = InputSystem)
	class UInputAction* IA_Squish;
	
};
