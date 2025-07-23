#pragma once

#include "ItemInterface.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseItem.generated.h"

class USphereComponent;

UCLASS()
class HW08_API ABaseItem : public AActor, public IItemInterface
{
	GENERATED_BODY()

public:
	ABaseItem();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item");
	FName ItemType;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item|Component");
	USceneComponent* SceneRoot;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item|Component");
	USphereComponent* Collision;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item|Component");
	UStaticMeshComponent* StaticMesh;

	virtual void OnItemBeginOverlap(
		UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIdx,
		bool bFromSweep,
		const FHitResult& SweepResult
	) override;
	virtual void OnItemEndOverlap(
		UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIdx
	) override;
	virtual void ActivateItem(AActor* Activator) override;
	virtual FName GetItemType() const override;
	virtual void DestroyItem();
};
