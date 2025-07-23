#include "MyGameMode.h"
#include "MyGameState.h"

AMyGameMode::AMyGameMode()
{	
	GameStateClass = AMyGameState::StaticClass();
}