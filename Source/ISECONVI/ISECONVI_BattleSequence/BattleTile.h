// Fill out your copyright notice in the Description page of Project Settings.

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

    // Set the tile count value
    void SetTileCount(FVector2D Count);
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
