// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/UserDefinedStruct.h"
#include "FN00dSleeperInventory.generated.h"


USTRUCT(BlueprintType)
struct FN00dSleeperInventory
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "N00dComponents|Sleeper|Data")
		FString ItemStringID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "N00dComponents|Sleeper|Data")
		int32 ItemAmount;

	// Default Constructor
	FN00dSleeperInventory()
	{
		// Construct any values here

	}
};


UCLASS()
class N00DSLEEPER_API UFN00dSleeperInventory : public UUserDefinedStruct
{
	GENERATED_BODY()
	


};
