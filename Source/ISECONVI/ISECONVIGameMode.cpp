// Copyright Epic Games, Inc. All Rights Reserved.

#include "ISECONVIGameMode.h"
#include "ISECONVICharacter.h"
#include "UObject/ConstructorHelpers.h"

AISECONVIGameMode::AISECONVIGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
