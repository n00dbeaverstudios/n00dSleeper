﻿// © Copyright 2020-2021

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "N00dSleeperInterfaceUMG.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UN00dSleeperInterfaceUMG : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class N00DSLEEPER_API IN00dSleeperInterfaceUMG
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.

		// DEBUG

public:

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "N00dComponents|Sleeper|Interface|Game Mode")
		void N00dSetSleeperHealthDisplay(const FText & SleeperTitle);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "N00dComponents|Sleeper|Interface|Game Mode")
		void N00dSetSleeperTitleDisplay(const FText & HealthDisplay);
};
