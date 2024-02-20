#include "ISECONVI_BattleSequence/BattleGridManager.h"
// Sets default values
ABattleGridManager::ABattleGridManager(){
    // Set this actor to call Tick() every frame
    PrimaryActorTick.bCanEverTick = false;

    BattleTileClass = ABattleTile::StaticClass();
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
    BattleGrid.Empty();
}

void ABattleGridManager::SpawnBattleTileActor(FVector2D GridSize){
    if(BattleTileClass){
        // 상대트랜스폼을 위한 셀프 로케이션 로컬변수
        FVector GridRelativeLocation = GetActorLocation();
        // 가로 loop
        for(int32 X = 0; X < GridSize.X; ++X){
            // 세로 loop
            for(int32 Y = 0; Y < GridSize.Y; ++Y){
                FVector2D TileIndex(X,Y);
                FVector SpawnRelativeLocation = FVector(TileIndex.X * (TileSize + TileSpace), TileIndex.Y * (TileSize + TileSpace), 0.0f);
                FVector SpawnLocation = GridRelativeLocation + SpawnRelativeLocation;

                ABattleTile* BattleTileInstance = GetWorld()->SpawnActor<ABattleTile>(BattleTileClass, SpawnLocation, FRotator::ZeroRotator);
                if (BattleTileInstance){
                    BattleTileInstance->SetTileCount(TileIndex);
                    BattleGrid.Add(TileIndex, BattleTileInstance);
                }                
            }
        }
    }
}

void ABattleGridManager::SetTileIndex(FVector2D Index, ABattleTile* TargetBattleTileComponent){
    if (TargetBattleTileComponent)
    {        
            TargetBattleTileComponent->SetTileCount(Index);
            
    }
}