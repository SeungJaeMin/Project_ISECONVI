// All rights to the code are with DoubleBox Studio. Founded in 2021, located in South Korea.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BattleTile.generated.h"

UCLASS()
class ISECONVI_API ABattleTile : public AActor
{
	GENERATED_BODY()
	
public:	
    // Sets default values for this actor's properties
    ABattleTile();

    // Tile count value
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Tile")
    FVector2D TileIndex;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Tile")
    FVector TileSize;

    // Set the tile value
    void SetTileCount(FVector2D Count);       

    UFUNCTION(BlueprintCallable, Category = "Tile Location")
    FVector2D GetTileLocation();



	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
