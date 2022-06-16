// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/SkeletalMesh.h"
#include "Materials/MaterialInterface.h"
#include "Engine/UserDefinedStruct.h"
#include "FN00dSleeperPlayerData.h"
#include "FN00dSleeperData.generated.h"

USTRUCT(BlueprintType)
struct FN00dSleeperData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "N00dComponents|Sleeper|Data")
		FN00dSleeperPlayerData PlayerData;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "N00dComponents|Sleeper|Data")
		TArray<TObjectPtr<USkeletalMesh>> Meshes;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "N00dComponents|Sleeper|Data")
		TArray<TObjectPtr<UMaterialInterface>> Materials;

	// Default Constructor
	FN00dSleeperData()
	{
		// Construct any values here

	}
};

UCLASS()
class N00DSLEEPER_API UFN00dSleeperData : public UUserDefinedStruct
{
	GENERATED_BODY()
	
};
