#include "CoinItem.h"
#include "Engine/World.h"
#include "MyGameState.h"

ACoinItem::ACoinItem()
{
	CoinValue = 10;
	ItemType = "Coin";
}

void ACoinItem::ActivateItem(AActor* Activator)
{
	if (Activator && Activator->ActorHasTag("Player"))
	{
		if (UWorld * World = GetWorld())
		{
			if (AMyGameState* GameState = World->GetGameState<AMyGameState>())
			{
				GameState->AddScore(CoinValue);
				GameState->OnCoinCollected();
			}
		}
		DestroyItem();
	}
}