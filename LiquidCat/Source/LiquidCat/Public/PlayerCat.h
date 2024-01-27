// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "EnhancedPlayerInput.h"
#include "EnhancedInputComponent.h"
#include "PlayerCat.generated.h"

/**
 * 
 */
UCLASS()
class LIQUIDCAT_API APlayerCat : public APaperCharacter
{
	GENERATED_BODY()

public:
	APlayerCat();

	//InputMappingContext
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = InputSystem)
	class UInputMappingContext* IMCPlayerInput;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = InputSystem)
	class UInputAction* IA_MoveRigthLeft;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = InputSystem)
	class UInputAction* IA_Squish;
	
};
