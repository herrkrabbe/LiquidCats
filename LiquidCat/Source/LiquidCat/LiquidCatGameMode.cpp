// Copyright Epic Games, Inc. All Rights Reserved.

#include "LiquidCatGameMode.h"
#include "LiquidCatCharacter.h"

ALiquidCatGameMode::ALiquidCatGameMode()
{
	// Set default pawn class to our character
	DefaultPawnClass = ALiquidCatCharacter::StaticClass();	
}
