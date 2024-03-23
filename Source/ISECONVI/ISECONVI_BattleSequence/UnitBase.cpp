// All rights to the code are with DoubleBox Studio. Founded in 2021, located in South Korea.


#include "ISECONVI_BattleSequence/UnitBase.h"

// Sets default values
AUnitBase::AUnitBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CurrentHP = MaxHP;
	CurrentMP = MaxMP;
}

// Called when the game starts or when spawned
void AUnitBase::BeginPlay()
{
	Super::BeginPlay();	
}

// Called every frame
void AUnitBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AUnitBase::setCurrentLocation(FVector2D value){
	CurrentLocation2D = value;
}

float AUnitBase::getCurrentHP(){
	return CurrentHP;
}
float AUnitBase::getMaxHP(){
	return MaxHP;
}

float AUnitBase::getCurrentMP(){
	return CurrentMP;
}

float AUnitBase::getMaxMP(){
	return MaxMP;
}

FString AUnitBase::getUnitName(){
	return UnitName;
}

void AUnitBase::decreaseHP(float Value){
	if(CurrentHP>0){
		CurrentHP = CurrentHP - Value;
	}
}

void AUnitBase::increaseHP(float Value){
	CurrentHP = CurrentHP + Value;
}

