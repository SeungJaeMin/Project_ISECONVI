// All rights to the code are with DoubleBox Studio. Founded in 2021, located in South Korea.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BattleTile.h"
#include "BattleGridManager.generated.h"

UCLASS()
class ISECONVI_API ABattleGridManager : public AActor
{
	GENERATED_BODY()
	
public:	
    ABattleGridManager();

	UFUNCTION(BlueprintCallable, Category = "Battle Grid")
	void SpawnBattleTileActor(FVector2D GridSize);

    UFUNCTION(BlueprintCallable, Category = "Battle Grid")
    void SetTileIndex(FVector2D Index, ABattleTile* TargetBattleTileComponent);

    UPROPERTY(EditAnywhere, Category = "Tile", meta = (AllowPrivateAccess = "true"))
    TSubclassOf<class ABattleTile> BattleTileClass;

	UPROPERTY(EditAnywhere, Category = "Battle Grid")
	float TileSize = 200.0f;

	UPROPERTY(EditAnywhere, Category = "Battle Grid")
	float TileSpace = 10.0f;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Allocated Battle Tile List")
    TMap<FVector2D, ABattleTile*> BattleGrid;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;  

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
