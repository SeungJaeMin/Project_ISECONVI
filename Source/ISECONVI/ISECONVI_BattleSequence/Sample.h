// All rights to the code are with DoubleBox Studio. Founded in 2021, located in South Korea.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Sample.generated.h"

UCLASS()
class ISECONVI_API ASample : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASample();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
