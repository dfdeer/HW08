#pragma once

#include "CoreMinimal.h"
#include "ItemSpawnRow.h"
#include "GameFramework/Actor.h"
#include "SpawnVolume.generated.h"

class UBoxComponent;

UCLASS()
class HW08_API ASpawnVolume : public AActor
{
	GENERATED_BODY()
	
public:
	ASpawnVolume();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawning")
	USceneComponent* SceneRoot;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawning")
	UBoxComponent* SpawningBox;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	UDataTable* ItemDataTable;

	FItemSpawnRow* GetRandomItem() const;
	FVector GetRandomPointInVolume() const;
	AActor* SpawnItem(TSubclassOf<AActor> ItemClass);
	AActor* SpawnRandomItem();
};
