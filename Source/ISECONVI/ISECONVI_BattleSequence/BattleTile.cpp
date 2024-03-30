// Fill out your copyright notice in the Description page of Project Settings.


#include "ISECONVI_BattleSequence/BattleTile.h"

// Sets default values
ABattleTile::ABattleTile()
{
    // Set this actor to call Tick() every frame
    PrimaryActorTick.bCanEverTick = false;    
    TileIndex = FVector2D::ZeroVector;
}

// Called when the game starts or when spawned
void ABattleTile::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void ABattleTile::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void ABattleTile::SetTileCount(FVector2D Count)
{
    // Set the tile count value
    TileIndex = Count;
}

FVector2D ABattleTile::GetTileLocation(){    
    return TileIndex;    
}