﻿// Copyright © Developed by Josh "db" Debelec - Published by n00dbeaver Studios 2022 - All Rights Reserved. 

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "N00dSleeperActor.h"
#include "N00dSleeperPawn.h"
#include "FN00dSleeperAnimations.h"

#include "N00dSleeperSettings.generated.h"

/**
 * Setting object used to hold both config settings and editable ones in one place
 * To ensure the settings are saved to the specified config file make sure to add
 * props using the globalconfig or config meta.
 */

UCLASS(config = Game, defaultconfig) // specify the name of the config file to use
class N00DSLEEPER_API UN00dSleeperSettings : public UObject
{

	GENERATED_BODY()

public:

	UN00dSleeperSettings(const FObjectInitializer& ObjectInitializer);

////////////////////////////////////////////////////////////
// START PROPERTIES

//////////////////////
// DEBUG			//
//////////////////////


	// Debug the sleeper system
	UPROPERTY(EditAnywhere, BlueprintReadOnly, config, Category = Debug)
		bool DebugSleeper;

//////////////////////
// CONFIG			//
//////////////////////

	// Should the system wait for player input before waking up - if this is disabled we wake up instantly.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, config, Category = Config)
		bool WaitForPlayerInput = true;
	// The class of your sleeper pawn - this is spawned on entry.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, config, Category = Config)
		TSubclassOf<AN00dSleeperPawn> SleeperPawn;
	// The class of your sleeper actor - this is spawned on exit.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, config, Category = Config)
		TSubclassOf<AN00dSleeperActor> SleeperActor;
	// Should we let the player know they have died when they login.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, config, Category = Config)
		bool InformPlayerDead;
	// If logging in and dead, should we still spawn at the sleeper pawn.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, config, Category = Config)
		bool SpawnAtSleeperIfDead;
	// Should we broadcast the player to sleep to the server for all players to be notified of a player logging off.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, config, Category = Config)
		bool ShouldBroadcastSleep;
	// Should we broadcast the player to death to the server for all players to be notified of a sleeper death.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, config, Category = Config)
		bool ShouldBroadcastDeath;
	// How long before we remove the dead player actor from the world - 0 = indefinite.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, config, Category = Config)
		float DeathDelay = 5.0f;
	// Your save game class (we interface with your save to save the game - check out the included sleeper save for an example). 
	UPROPERTY(EditAnywhere, BlueprintReadOnly, config, Category = Config)
		TSubclassOf<USaveGame> SaveGameClass;
	// The animations to use across the sleeper system.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, config, Category = Config)
		FN00dSleeperAnimations Animations;
	// Are we using the proxy system.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, config, Category = Config)
		bool UseProximity = true;
	// What's the radius of the proxy.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, config, Category = Config)
		float ProximityRadius = 200.0f;
	// Should the widget temporarily be displayed to the player when we damage the sleeper.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, config, Category = Config)
		bool ShowWidgetOnSleeperDamage;
	// If we are showing the widget on sleeper damage, define the delay to hide the widget. 
	UPROPERTY(EditAnywhere, BlueprintReadOnly, config, Category = Config)
		float SleeperWidgetCloseDelay;
	// The save slot we want to save to
	UPROPERTY(EditAnywhere, BlueprintReadOnly, config, Category = Config)
		FString SleeperSaveSlot = (TEXT("SleeperSave"));

// END PROPERTIES
////////////////////////////////////////////////////////////


	
};

