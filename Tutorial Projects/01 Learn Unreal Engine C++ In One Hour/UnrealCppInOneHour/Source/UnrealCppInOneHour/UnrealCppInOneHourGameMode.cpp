// Copyright Epic Games, Inc. All Rights Reserved.

#include "UnrealCppInOneHourGameMode.h"
#include "UnrealCppInOneHourCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUnrealCppInOneHourGameMode::AUnrealCppInOneHourGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
