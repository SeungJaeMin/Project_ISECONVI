// All rights to the code are with DoubleBox Studio. Founded in 2021, located in South Korea.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "UnitBase.generated.h"

UCLASS()
class ISECONVI_API AUnitBase : public ACharacter
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

	// 위치 정보 스테이터스
	UPROPERTY(EditAnywhere, Category = "Status")
	FVector2D CurrentLocation2D;

	UFUNCTION(BlueprintCallable, Category = "Set Status")
	void setCurrentLocation(FVector2D Value);
	
	UFUNCTION(BlueprintCallable, Category = "Get Status")
	FString getUnitName();

	UFUNCTION(BlueprintCallable, Category = "Get Status")
    float getCurrentHP();
y
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

	
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
