// C

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

    UFUNCTION(BlueprintCallable)
    void SpawnTileActors(int32 Height, int32 Width, float TileSize, float TileSpacing);

    // Function to get the map of spawned tiles
    UFUNCTION(BlueprintPure, Category = "Tile")
    TMap<FVector2D, ABattleTile*> GetSpawnedTiles() const { return SpawnedTiles; };

    // Container for storing spawned tile actors
    UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Tile")
    TMap<FVector2D, ABattleTile*> SpawnedTiles;
	
    // Tile actor class to spawn
    UPROPERTY(EditDefaultsOnly, Category = "Tile")
    TSubclassOf<class ABattleTile> BattleTileClass;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
    // Function to spawn a single tile actor
    ABattleTile* SpawnTileActor(FVector2D TileIndex, float TileSize, float TileSpacing);
};
