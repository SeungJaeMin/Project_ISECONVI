#include "ISECONVI_BattleSequence/BattleGridManager.h"
// Sets default values
ABattleGridManager::ABattleGridManager(){
    // Set this actor to call Tick() every frame
    PrimaryActorTick.bCanEverTick = false;
    
    BattleGrid.Empty();
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
                    // 인스턴스 스폰시 호출하는 곳
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


ABattleTile* ABattleGridManager::GetTileInstance(FVector2D Key){
    // BattleGrid에서 제공된 키가 포함되어 있는지 확인합니다.
    if (BattleGrid.Contains(Key)) {
        // 제공된 키와 연결된 ABattleTile 인스턴스를 가져옵니다.
        return BattleGrid[Key];
    }
    // 키가 BattleGrid에 없는 경우 nullptr을 반환합니다.
    return nullptr;
}

FVector2D ABattleGridManager::GetTileIndex(ABattleTile* TargetBattleTileInstance){
       FVector2D Key = FVector2D(-1, -1); // 초기화된 Key를 반환할 것입니다.

    // BattleGrid가 비어 있는지 확인합니다.
    if (BattleGrid.Num() > 0)
    {
        // TPair를 반복하여 해당 인스턴스를 찾습니다.
        for (const TPair<FVector2D, ABattleTile*>& Pair : BattleGrid)
        {
            if (Pair.Value == TargetBattleTileInstance)
            {
                // 인스턴스를 찾으면 해당 키를 반환합니다.
                Key = Pair.Key;
                break; // 키를 찾았으므로 반복문을 빠져나갑니다.
            }
        }
    }

    return Key;
}