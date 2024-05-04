// All rights to the code are with DoubleBox Studio. Founded in 2021, located in South Korea.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InputActionValue.h"
#include "UnitBase.generated.h"

UCLASS()
class ISECONVI_API AUnitBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AUnitBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// 유닛마다 가지고 있어야하는 기초 스테이터스
	UPROPERTY(EditAnywhere, Category = "Status")
	FString UnitName;
	UPROPERTY(EditAnywhere, Category = "Status")
	float MaxHP;	
	UPROPERTY(EditAnywhere, Category = "Status")
	float CurrentHP;
	UPROPERTY(EditAnywhere, Category = "Status")
	float MaxMP;
	UPROPERTY(EditAnywhere, Category = "Status")
	float CurrentMP;
	UPROPERTY(EditAnywhere, Category = "Status")
	float AGI;

	// 위치 정보 스테이터스
	UPROPERTY(EditAnywhere, Category = "Status")
	FVector2D CurrentLocation2D;

	UFUNCTION(BlueprintCallable, Category = "Set Status")
	void setCurrentLocation(FVector2D Value);

	UFUNCTION(BlueprintCallable, Category = "Get Status")
	FVector2D getCurrentLocation();

	
	UFUNCTION(BlueprintCallable, Category = "Get Status")
	FString getUnitName();

	UFUNCTION(BlueprintCallable, Category = "Get Status")
    float getCurrentHP();

	UFUNCTION(BlueprintCallable, Category = "Get Status")
	float getCurrentMP();

	UFUNCTION(BlueprintCallable, Category = "Get Status")
	float getMaxHP();

	UFUNCTION(BlueprintCallable, Category = "Get Status")
	float getMaxMP();

	UFUNCTION(BlueprintCallable, Category = "Set Status")
	void decreaseHP(float Value);

	UFUNCTION(BlueprintCallable, Category = "Set Status")
	void increaseHP(float Value);

	/* TODO *
	
	   문제상황 : 키값을 받는것은 현재 ok, 그러나 만들어진 Battle Field Manager에게 좌표값이 변할때마다 업데이트가 안됨.

	   1. 유닛의 Current Location을 Battle FieldManager 에게 업데이트 하는 함수가 필요힘.
	   2. DecreaseHP 함수 실행시 이펙트 / 사운드 를 재생하는 이벤트 디스패쳐가 필요함.
	   3. 해당 업데이트가 발생 시, UI 업데이트를 호출 할 수 있어야함.
	   4. 유닛마다 Skill의 Name 값을 저장하고 있는 변수가 존재해야함.
	   
	   5. Turn Stack Logic 에 본인의 행동을 Send 하는 함수가 필요함.

	   6. 자신의 행동이 발동될 때, 공격 / 이동 시의 시나리오가 필요함.
	   7. 특수공격 ( 설치형 액터를 스폰하는 등의 경우의 수 )도 저장해 놓을 것.
	 
	
	*/

	
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
