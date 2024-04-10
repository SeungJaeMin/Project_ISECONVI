// All rights to the code are with DoubleBox Studio. Founded in 2021, located in South Korea.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "ISECONVI_GameInstance_Global.generated.h"

/**
 * 
 */
UCLASS()
class ISECONVI_API UISECONVI_GameInstance_Global : public UGameInstance
{
	GENERATED_BODY()

public:
	// Set USER PROPERTY
	UPROPERTY(EditAnywhere, Category = "Player Status")
	FString PlayerName;
	UPROPERTY(EditAnywhere, Category = "Player Status")
	int PlayerProcessingGameChapter;
	UPROPERTY(EditAnywhere, Category = "Player Status")
	int PlayerProcessingDay;
	UPROPERTY(EditAnywhere, Category = "Player Status")
	float PlayerCurrentMoney;
		
};
