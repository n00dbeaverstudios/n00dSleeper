// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FN00dSleeperInventory.h"
#include "Engine/UserDefinedStruct.h"
#include "FN00dSleeperPlayerData.generated.h"

USTRUCT(BlueprintType)
struct FN00dSleeperPlayerData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "N00dComponents|Sleeper|Data")
		FText Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "N00dComponents|Sleeper|Data")
		float HealthCurrent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "N00dComponents|Sleeper|Data")
		float HealthMax;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "N00dComponents|Sleeper|Data")
		TArray<FN00dSleeperInventory> Inventory;

	// Default Constructor
	FN00dSleeperPlayerData()
	{
		// Construct any values here

	}
};

UCLASS()
class N00DSLEEPER_API UFN00dSleeperPlayerData : public UUserDefinedStruct
{
	GENERATED_BODY()
	
};
