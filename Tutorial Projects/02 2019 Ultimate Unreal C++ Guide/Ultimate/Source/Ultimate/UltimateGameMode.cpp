// Copyright Epic Games, Inc. All Rights Reserved.

#include "UltimateGameMode.h"
#include "UltimateCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "UltimateGameState.h"

AUltimateGameMode::AUltimateGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	PointsToWin = 5;
}

void AUltimateGameMode::OnTargetHit()
{
	if (AUltimateGameState* gameState = Cast<AUltimateGameState>(GameState))
	{
		gameState->Points++;

		if (gameState->Points > PointsToWin)
		{
			UE_LOG(LogTemp, Warning, TEXT("You won!"));
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("You have %d points."), gameState->Points);
		}
	}
}
