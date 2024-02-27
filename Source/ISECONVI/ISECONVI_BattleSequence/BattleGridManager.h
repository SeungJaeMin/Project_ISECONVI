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
	
	// Battle Grid에 관련된 함수
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

	// TODO: 
	/**

	1. Grid Manager : Tile의 좌표값을 관리하는 클래스 , 좌표값제공
	2. GetTileInstance -> 키값을 파라미터로 받아서, ABattleTile을 가져오기
	3. GetTileIndex -> ABattleTile을 파라미터로 받아서, 키값인 인덱스를 받아오기

	*/

	UFUNCTION(BlueprintCallable, Category = "Allocated Battle Tile List")
	ABattleTile* GetTileInstance(FVector2D Key);

	UFUNCTION(BlueprintCallable, Category = "Allocated Battle Tile List")
	FVector2D GetTileIndex(ABattleTile* TargetBattleTileInstance);

	






protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;  

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
