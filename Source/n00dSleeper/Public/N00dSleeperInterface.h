// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FN00dSleeperData.h"
#include "UObject/Interface.h"
#include "N00dSleeperComponent.h"
#include "N00dSleeperSettings.h"

#include "N00dSleeperInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UN00dSleeperInterface : public UInterface
{
	GENERATED_BODY()
};

class N00DSLEEPER_API IN00dSleeperInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.

public:

	///////////////////// TRIGGER /////////////////////


	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dComponents|Sleeper|Interface|Controller")
		void N00dTriggerWake();


	///////////////////// GETTERS /////////////////////

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dComponents|Sleeper|Interface|Controller")
		void N00dGetSleeperSettings(UN00dSleeperSettings* & SleeperSettings, USaveGame* & SaveGame);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dComponents|Sleeper|Interface|Controller")
		void N00dGetSleeperID(FString &SleeperID);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dComponents|Sleeper|Interface|Multiple")
		void N00dGetIsSleeperDead(bool &IsDead);


	///////////////////// SETTERS /////////////////////

	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dComponents|Sleeper|Interface|Controller")
		void N00dSetSleeperID(const FString &SleeperID);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dComponents|Sleeper|Interface|Controller")
		void N00dSleeperBroadcastMessage(const FText &Message);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dComponents|Sleeper|Interface|Controller")
		void N00dSetExampleSleeperMesh (const FString & ForComponent, USkeletalMesh* NewMesh);

	// Sleeper

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "N00dComponents|Sleeper|Interface|Sleeper")
		void N00dSleeperLogout(class APlayerController* Controller);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "N00dComponents|Sleeper|Interface|Multiple")
		void N00dSleeperSetData(FN00dSleeperData Data);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "N00dComponents|Sleeper|Interface|Multiple")
		void N00dSleeperGetData(FN00dSleeperData &Data);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "N00dComponents|Sleeper|Interface|Sleeper")
		void N00dSleeperDamage(float ByAmount, class AController* Instigator, class AActor* Causer, TSubclassOf< UDamageType > DamageType);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "N00dComponents|Sleeper|Interface|Game Mode")
		void N00dAddSleeper(class AN00dSleeperActor* SleeperActor);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "N00dComponents|Sleeper|Interface|Game Mode")
		void N00dRemoveSleeper(class AN00dSleeperActor* SleeperActor);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "N00dComponents|Sleeper|Interface|Game Mode")
		void N00dClearSleepers();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "N00dComponents|Sleeper|Interface|Controller")
		void N00dSleeperWidgetVisibility(UWidgetComponent * SleeperWidget, bool NewVisibility);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "N00dComponents|Sleeper|Interface|Character")
		void N00dBuildCharacterFromSleeper(const TArray<USkeletalMesh*> &Meshes, const TArray<UMaterialInterface*> &Materials);

};
