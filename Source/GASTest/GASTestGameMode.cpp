// Copyright Epic Games, Inc. All Rights Reserved.

#include "GASTestGameMode.h"
#include "GASTestCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGASTestGameMode::AGASTestGameMode()
	: Super()
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
