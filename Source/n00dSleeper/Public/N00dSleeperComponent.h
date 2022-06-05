// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Net/UnrealNetwork.h"
#include "Containers/Array.h"
#include "FN00dSleeperData.h"
#include "N00dSleeperActor.h"
#include "N00dSleeperPawn.h"
#include "GameFramework/SaveGame.h"
#include "Animation/AnimInstance.h"
#include "N00dSleeperSettings.h"

#include "N00dSleeperComponent.generated.h"

class USkeletalMeshComponent;
//struct FN00dSleeperData;
//struct FN00dSleeperSettings;

UCLASS(Blueprintable, ClassGroup=(Sleeper), HideCategories=(Collision, AssetUserData, Cooking, Variable, Activation, ComponentTick), meta=(BlueprintSpawnableComponent) )
class N00DSLEEPER_API UN00dSleeperComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties (components that aren't constructed on an actor in C++ should be set to replicate in the BP its added to (i.e., N00dSleeperComponent->SetIsReplicated(true);))

	UN00dSleeperComponent();

	///////////////////// PROPERTIES /////////////////////


// N00DCOMPONENTS UNIVERSAL


	// The component's name
	UPROPERTY(VisibleAnywhere, Category = "N00dComponents|Master|Internal")
		FText ComponentName;
	// The release version
	UPROPERTY(EditAnywhere, Category = "N00dComponents|Master|Internal")
		FText ComponentVersion;
	// Should we debug
	UPROPERTY(EditAnywhere, Category = "N00dComponents|Master|Debug")
		bool DebugComponent;
	// Should we disable the component
	UPROPERTY(EditAnywhere, Category = "N00dComponents|Master|Debug")
		bool DisableComponent;
	// Should we disable the component
	UPROPERTY(Replicated, BlueprintReadOnly, Category = "N00dComponents|Sleeper|Character")
		class APlayerController* OwningController;
	/** Mesh Component to use as the representation of the logged out player character. */
	UPROPERTY(Replicated, BlueprintReadOnly, Category = "N00dComponents|Sleeper|Actor|Do Not Edit")
		FString SleeperOwnerID;


// CONTROLLER


	// The mutatable data the sleepers require
	UPROPERTY(Replicated, BlueprintReadOnly, Category = "N00dComponents|Sleeper|Controller")
		struct FN00dSleeperData SleeperData;


// GAME MODE


	// The active cache of sleeper actors that exist on the server
	UPROPERTY(BlueprintReadWrite, Category = "N00dComponents|Sleeper|Game Mode")
		TArray<class AN00dSleeperActor*> SleeperCache;
	// The active cache of players whom exist on the server
	UPROPERTY(BlueprintReadOnly, Category = "N00dComponents|Sleeper|Game Mode")
		TArray<class APlayerController*>PlayerCache;


// CHARACTER


	// Skeletal mesh component cache
	UPROPERTY(Replicated, BlueprintReadWrite, Category = default)
		TArray<USkeletalMeshComponent*> MeshComponents;
	// Skeletal mesh component cache
	UPROPERTY(BlueprintReadOnly, Category = default)
		class ACharacter* OwningCharacter;
	// Skeletal mesh references from the built components
	UPROPERTY(Replicated, BlueprintReadOnly, Category = default)
		TArray<USkeletalMesh*> CharacterMeshes;
	// An array containing all of the mesh materials in order of set
	UPROPERTY(Replicated, BlueprintReadOnly, Category = default)
		TArray<UMaterialInterface*> CharacterMaterials;
	// The looping animation from the actor
	UPROPERTY(Replicated, BlueprintReadWrite, Category = default)
		class UAnimSequence* LoadedSleepLoop;
	// Loaded animation from soft reference. 
	UPROPERTY(Replicated, BlueprintReadWrite, Category = default)
		class UAnimSequence* LoadedFromSleep;
	// Loaded animation from soft reference. 
	UPROPERTY(Replicated, BlueprintReadWrite, Category = default)
		class UAnimSequence* LoadedToSleep;
	// Is the player asleep.
	UPROPERTY(Replicated, BlueprintReadWrite, Category = default)
		bool Asleep;
	// Are we currently triggered
	UPROPERTY(Replicated, BlueprintReadWrite, Category = default)
		bool Triggered;
	UPROPERTY(Replicated, BlueprintReadWrite, Category = default)
		TSubclassOf<class UAnimInstance> CachedAnimInstance;



protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;




///////////////////// FUNCTIONS (CONTROLLER) /////////////////////


	// SETTERS


	// Set the sleeper data - this data should be mutated on the controller.
	UFUNCTION(BlueprintCallable, Category = "N00dComponents|Sleeper|Controller")
		void SetSleeperData(FN00dSleeperData Data);
	// Set the incoming widget component's visibility on the owner who wants it displayed or not displayed.
	UFUNCTION(Client, Reliable, BlueprintCallable, Category = "N00dComponents|Sleeper|Controller")
		void SetWidgetVisibility(UWidgetComponent* SleeperWidget, bool NewVisibility);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "N00dComponents|Sleeper|Controller")
		void GetSleeperSettings(UN00dSleeperSettings* & Settings);

		   	 
///////////////////// FUNCTIONS (GAME MODE) /////////////////////


	// SPAWNING


	// Respawn function for the SpawnDefaultPawnFor GameMode function
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dComponents|Sleeper|Game Mode")
		void Respawn(class APlayerController* ForController, APawn* &SpawnedPawn);
	// Loop the sleeper cache, compare with the invoking player controller, and return 
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dComponents|Sleeper|Game Mode")
		bool FindSleeper(class APlayerController* ForController, class AN00dSleeperActor* &SleeperActor);
	// Spawn the invoking controller as a sleeping pawn, at their sleeper actor.
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dComponents|Sleeper|Game Mode")
		void SpawnAtSleeper(class AN00dSleeperActor* SleeperActor, class APlayerController* ForController, class AN00dSleeperPawn* &SleeperPawn);
	// If we can't find a sleeper actor, we will spawn normally. Override to perform your own spawn functions
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dComponents|Sleeper|Game Mode")
		void DefaultSpawn(class APlayerController* ForController, class APawn* &DefaultPawn);
	// Respawn function for the SpawnDefaultPawnFor GameMode function
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, BlueprintPure, Category = "N00dComponents|Sleeper|Game Mode")
		bool CanSpawnAtSleeper(class APlayerController* ForController, class AN00dSleeperActor* Sleeper);


	// CACHE


	// Add a sleeper reference to the active sleeper cache
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dComponents|Sleeper|Game Mode")
		bool AddSleeper(class AN00dSleeperActor* SleeperActor);
	// Remove a sleeper reference from the active sleeper cache
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dComponents|Sleeper|Game Mode")
		bool RemoveSleeper(class AN00dSleeperActor* SleeperActor);
	// Clear the sleeper references from the active sleeper cache
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dComponents|Sleeper|Game Mode")
		bool ClearSleepers();
	// Add the player to the cache so we can broadcast to them
	UFUNCTION(BlueprintCallable, Category = "N00dComponents|Sleeper|Game Mode")
		void CachePlayer(class APlayerController* Player);
	// Remove the player from the stack
	UFUNCTION(BlueprintCallable, Category = "N00dComponents|Sleeper|Game Mode")
		void RemovePlayer(class APlayerController* Player);


	// BROADCASTING

	// Broadcast a message to all players on the server
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dComponents|Sleeper|Game Mode")
		bool BroadcastSleeperMessage(const FText &Message);




	   
///////////////////// FUNCTIONS (CHARACTER) /////////////////////
	

	// SPAWNING


	// Cache the meshes and reference to the owner
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dComponents|Sleeper|Character")
		bool InitialiseSleeperPlayer(class ACharacter* Owner, const TArray<USkeletalMeshComponent*> &SkeletalComponents);
	// Handle what happens when the player exits a server - called on EndPlay on the Character if logging out, or from the client input if invoking sleep manually
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dComponents|Sleeper|Character")
		bool Sleep(bool Logout);
	// Override to handle any custom conditions
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, BlueprintPure, Category = "N00dComponents|Sleeper|Character")
		bool CanSleep();
	// Spawn the sleeper actor
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dComponents|Sleeper|Character")
		bool SpawnSleeper();
	// Get the sleeper ID from the SetOwnerID function - override this function to get your Subsystem ID
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, BlueprintPure, Category = "N00dComponents|Sleeper|Game Mode")
		void GetSleeperPlayerID(class APlayerController* ForController, FString &PlayerID);
	// Reference the relevant values for this character, from the sleeper
	UFUNCTION(BlueprintCallable, Category = "N00dComponents|Sleeper|Character|Callable")
		void SetSleeperCharacterParams(TArray<USkeletalMesh*> Meshes, TArray<UMaterialInterface*> Materials);


	// INITIALISE


	// Set the character reference
	UFUNCTION(BlueprintCallable, Category = "N00dComponents|Sleeper|Controller")
		void SetOwningCharacter(class ACharacter* ForCharacter);
	// This is not mandatory to call; provides a way to set the owner independently from the getter
	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "N00dComponents|Sleeper|Actor|Callable")
		void ServerSetOwnerID(const FString &OwnerID);
	// Set the controller on the server
	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "N00dComponents|Sleeper|Controller")
		void ServerSetOwningController(class APlayerController* ForController);
	// Reference the mesh components to handle applying meshes to the relevant actor skeletal meshes.
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dComponents|Sleeper|Character|Callable")
		void BuildCharacterMeshComponents(const TArray<USkeletalMeshComponent*> &SkeletalComponents);
	// Reference the mesh components to handle applying meshes to the relevant actor skeletal meshes.
	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "N00dComponents|Sleeper|Character|Callable")
		void ServerBuildCharacterMeshComponents(const TArray<USkeletalMeshComponent*> &SkeletalComponents);
	// Apply the meshes onto the referenced components
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dComponents|Sleeper|Character|Callable")
		bool ApplyMeshes();
	// Rebuild the meshes from the component references
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dComponents|Sleeper|Character|Callable")
		bool RefreshSleeperMeshes();
	// Rebuild references to any extra data you might need the system to know
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dComponents|Sleeper|Character|Callable")
		bool RefreshOtherData();
	// Add incoming material to the CharacterMaterials array
	UFUNCTION(BlueprintCallable, Category = "N00dComponents|Sleeper|Character|Callable")
		void BuildCharacterMaterials(class UMaterialInterface* Material);
	// Clear the CharacterMaterials array
	UFUNCTION(BlueprintCallable, Category = "N00dComponents|Sleeper|Character|Callable")
		void ClearCharacterMaterials();


	
	// MANUAL SLEEP FUNCTIONALITY


	// Apply the meshes onto the referenced components
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dComponents|Sleeper|Character|Callable")
		void LoadSleepAnimations();
	// Trigger sleep when invoked from an input - this controls the owning player character instead of spawning an actor
	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "N00dComponents|Sleeper|Character")
		void ServerSleep();
	// Trigger sleep when invoked from an input - this controls the owning player character instead of spawning an actor
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dComponents|Sleeper|Character")
		bool TriggerSleep();
	// Trigger sleep when invoked from an input - this controls the owning player character instead of spawning an actor
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dComponents|Sleeper|Character")
		bool TriggerWake();
	// Trigger waking up from the client 
	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "N00dComponents|Sleeper|Character")
		void ServerWake();
	// Called once the sleep animations have been loaded
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dComponents|Sleeper|Character")
		bool OnSleep();
	// Reference the mesh components to handle applying meshes to the relevant actor skeletal meshes.
	UFUNCTION(NetMulticast, Reliable, BlueprintCallable, Category = "N00dComponents|Sleeper|Character|Callable")
		void MulticastSleepAnimation(USkeletalMeshComponent* OwnerMesh, UAnimSequence* SleepAnim, bool LoopingAnim);
	// Set the cached anim instance back to the owner mesh if we just performed a sleep action
	UFUNCTION(NetMulticast, Reliable, BlueprintCallable, Category = "N00dComponents|Sleeper|Character|Callable")
		void MulticastSetAnimInstance(USkeletalMeshComponent* ForMesh);
	// Handle when the player has completed the sleep animation
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dComponents|Sleeper|Character")
		void ToLoop();
	// Handle what happens when the waking animation has finished
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dComponents|Sleeper|Character")
		void ToWoke();



};

