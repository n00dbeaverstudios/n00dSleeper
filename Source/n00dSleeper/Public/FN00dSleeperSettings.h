// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/UserDefinedStruct.h"
#include "N00dSleeperActor.h"
#include "N00dSleeperPawn.h"
#include "FN00dSleeperAnimations.h"
#include "Templates/SubclassOf.h"
#include "GameFramework/SaveGame.h"
#include "FN00dSleeperSettings.generated.h"

USTRUCT(BlueprintType)
struct FN00dSleeperSettings
{
	GENERATED_BODY()


	// Should the system wait for player input before waking up - if this is disabled we wake up instantly.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "N00dComponents|Sleeper|Settings")
		bool WaitForPlayerInput;
	// The class of your sleeper pawn - this is spawned on entry.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "N00dComponents|Sleeper|Settings")
		TSubclassOf<AN00dSleeperPawn> SleeperPawn;
	// The class of your sleeper actor - this is spawned on exit.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "N00dComponents|Sleeper|Settings")
		TSubclassOf<AN00dSleeperActor> SleeperActor;
	// Should we let the player know they have died when they login.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "N00dComponents|Sleeper|Settings")
		bool InformPlayerDead;
	// If logging in and dead, should we still spawn at the sleeper pawn.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "N00dComponents|Sleeper|Settings")
		bool SpawnAtSleeperIfDead;
	// Should we broadcast the player to sleep to the server for all players to be notified of a player logging off.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "N00dComponents|Sleeper|Settings")
		bool ShouldBroadcastSleep;
	// Should we broadcast the player to death to the server for all players to be notified of a sleeper death.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "N00dComponents|Sleeper|Settings")
		bool ShouldBroadcastDeath;
	// How long before we remove the dead player actor from the world - 0 = indefinite.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "N00dComponents|Sleeper|Settings")
		float DeathDelay;
	// Your save game class (we interface with your save to save the game - check out the included sleeper save for an example). 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "N00dComponents|Sleeper|Settings")
		TSubclassOf<USaveGame> SaveGameClass;
	// The animations to use across the sleeper system.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "N00dComponents|Sleeper|Settings")
		FN00dSleeperAnimations Animations;
	// Are we using the proxy system.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "N00dComponents|Sleeper|Settings")
		bool UseProximity;
	// What's the radius of the proxy.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "N00dComponents|Sleeper|Settings")
		float ProximityRadius;
	// Should the widget temporarily be displayed to the player when we damage the sleeper.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "N00dComponents|Sleeper|Settings")
		bool ShowWidgetOnSleeperDamage;
	// If we are showing the widget on sleeper damage, define the delay to hide the widget. 
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "N00dComponents|Sleeper|Settings")
		float SleeperWidgetCloseDelay;
	// The save game that is loaded into memory
	UPROPERTY(BlueprintReadWrite, Category = "N00dComponents|Sleeper|Settings")
		class USaveGame* SaveGame;
	// The save slot we want to save to
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "N00dComponents|Sleeper|Settings")
		FString SleeperSaveSlot;


	// Default Constructor
	FN00dSleeperSettings()
	{
		// Construct any values here

	}
};

UCLASS()
class N00DSLEEPER_API UFN00dSleeperSettings : public UUserDefinedStruct
{
	GENERATED_BODY()
	
};
