// Fill out your copyright notice in the Description page of Project Settings.


#include "ISECONVI_BusinessSequence\ShowcaseBase.h"

// Sets default values
AShowcaseBase::AShowcaseBase()
{
    // Set this actor to call Tick() every frame
    PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AShowcaseBase::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void AShowcaseBase::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

