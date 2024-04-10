// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ShowcaseBase.generated.h"

UCLASS()
class ISECONVI_API AShowcaseBase : public AActor
{
	GENERATED_BODY()
	
public:	
    // Sets default values for this actor's properties
    AShowcaseBase();


	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
