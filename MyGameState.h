#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "MyGameState.generated.h"

UCLASS()
class HW08_API AMyGameState : public AGameState
{
	GENERATED_BODY()

public:
	AMyGameState();

	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnyWhere, BlueprintReadWrite, Category = "Score")
	int32 Score;
	UPROPERTY(VisibleAnyWhere, BlueprintReadWrite, Category = "Coin")
	int32 SpawnedCoinCount;
	UPROPERTY(VisibleAnyWhere, BlueprintReadWrite, Category = "Coin")
	int32 CollectedCoinCount;
	UPROPERTY(VisibleAnyWhere, BlueprintReadWrite, Category = "Level")
	float LevelDuration;
	UPROPERTY(VisibleAnyWhere, BlueprintReadWrite, Category = "Level")
	int32 CurrentLevelIndex;
	UPROPERTY(VisibleAnyWhere, BlueprintReadWrite, Category = "Level")
	int32 MaxLevel;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Level")
	TArray<FName> LevelMapNames;

	FTimerHandle LevelTimerHandle;
	FTimerHandle HUDUpdateTimerHandle;

	UFUNCTION(BlueprintPure, Category = "Score")
	int32 GetScore() const;
	UFUNCTION(BlueprintCallable, Category = "Score")
	void AddScore(int32 Amount);
	UFUNCTION(BlueprintCallable, Category = "Level")
	void OnGameOver();
	
	void OnCoinCollected();
	void OnLevelTimeUp();
	void StartLevel();
	void EndLevel();
	void UpdateHUD();
};
