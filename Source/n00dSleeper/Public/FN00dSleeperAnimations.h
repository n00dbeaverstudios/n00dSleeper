// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/SoftObjectPtr.h"
#include "Engine/UserDefinedStruct.h"
#include "FN00dSleeperAnimations.generated.h"


USTRUCT(BlueprintType)
struct FN00dSleeperAnimations
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "N00dComponents|Sleeper|Animations")
		TSoftObjectPtr<class UAnimSequence> ToSleep;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "N00dComponents|Sleeper|Animations")
		TSoftObjectPtr<class UAnimSequence> SleepLoop;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "N00dComponents|Sleeper|Animations")
		TSoftObjectPtr<class UAnimSequence> FromSleep;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "N00dComponents|Sleeper|Animations")
		TSoftObjectPtr<class UAnimSequence> SleepHit;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "N00dComponents|Sleeper|Animations")
		TSoftObjectPtr<class UAnimSequence> SleepDeath;

	// Default Constructor
	FN00dSleeperAnimations()
	{
		// Construct any values here

	}
};

UCLASS()
class N00DSLEEPER_API UFN00dSleeperAnimations : public UUserDefinedStruct
{
	GENERATED_BODY()
	
};
