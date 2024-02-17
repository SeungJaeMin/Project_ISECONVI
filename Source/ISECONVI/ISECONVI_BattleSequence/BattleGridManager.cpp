#include "ISECONVI_BattleSequence/BattleGridManager.h"
// Sets default values
ABattleGridManager::ABattleGridManager(){
    // Set this actor to call Tick() every frame
    PrimaryActorTick.bCanEverTick = false;

    SpawnedTiles.Empty();
}

// Called when the game starts or when spawned
void ABattleGridManager::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void ABattleGridManager::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void ABattleGridManager::SpawnTileActors(int32 Height, int32 Width, float TileSize, float TileSpacing)
{
    // Spawn tile actors in a 2D array
    for (int32 Y = 0; Y < Height; ++Y)
    {
        for (int32 X = 0; X < Width; ++X)
        {
            // Calculate tile index
            FVector2D TileIndex(X, Y);

            // Spawn the tile actor
            ABattleTile* BattleTileInstance = SpawnTileActor(TileIndex, TileSize, TileSpacing);

            // Add the spawned tile actor to the map
            if (BattleTileInstance)
            {
                SpawnedTiles.Add(TileIndex, BattleTileInstance);
            }
        }
    }
}

ABattleTile* ABattleGridManager::SpawnTileActor(FVector2D TileIndex, float TileSize, float TileSpacing)
{
    // Calculate spawn location
    FVector SpawnLocation = FVector(TileIndex.X * (TileSize + TileSpacing), TileIndex.Y * (TileSize + TileSpacing), 0.0f);

    // Spawn the tile actor
    ABattleTile* BattleTileInstance = GetWorld()->SpawnActor<ABattleTile>(BattleTileClass, SpawnLocation, FRotator::ZeroRotator);
    if (BattleTileInstance)
    {
        BattleTileInstance->SetTileCount(TileIndex);
    }

    return BattleTileInstance;
}
