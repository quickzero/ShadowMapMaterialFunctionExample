// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "ShadowMapExampleGameMode.h"
#include "ShadowMapExamplePlayerController.h"
#include "ShadowMapExampleCharacter.h"
#include "UObject/ConstructorHelpers.h"

AShadowMapExampleGameMode::AShadowMapExampleGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AShadowMapExamplePlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}