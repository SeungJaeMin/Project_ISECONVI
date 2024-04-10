// All rights to the code are with DoubleBox Studio. Founded in 2021, located in South Korea.


#include "ISECONVI_BattleSequence/TurnListObject.h"

// Sets default values
ATurnListObject::ATurnListObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATurnListObject::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATurnListObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

