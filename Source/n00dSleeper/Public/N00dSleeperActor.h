// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Net/UnrealNetwork.h"
//#include "N00dSleeperTypes.h"
#include "GameFramework/SaveGame.h"
#include "Components/ActorComponent.h"
#include "Components/WidgetComponent.h"
#include "Components/SphereComponent.h"
#include "Animation/AnimSequence.h"

#include "N00dSleeperActor.generated.h"

class USkeletalMeshComponent;
class UArrowComponent;
class USphereComponent;
class USceneComponent;


UCLASS(ClassGroup = (Sleeper), HideCategories = ("N00dComponents|Sleeper|Actor|DoNotEdit", Camera, Rendering, Collision, Input, LOD, Cooking))
class N00DSLEEPER_API AN00dSleeperActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties 
	AN00dSleeperActor();



	// INITIALISE


	// Owner of the sleeper actor
	UPROPERTY(Replicated, BlueprintReadOnly, Category = default)
		class APlayerController* OwningController;
	// Mesh Component to use as the representation of the logged out player character.
	UPROPERTY(Replicated, BlueprintReadOnly, Category = "N00dComponents|Sleeper|Actor|Do Not Edit")
		FString SleeperOwnerID;
	// Skeletal mesh component cache 
	UPROPERTY(Replicated, BlueprintReadWrite, Category = "N00dComponents|Sleeper|Actor|Do Not Edit")
		TArray<USkeletalMeshComponent*> MeshComponents;
	// Cache the meshes on this actor 
	UPROPERTY(Replicated, BlueprintReadOnly, Category = "N00dComponents|Sleeper|Actor|Config")
		TArray<USkeletalMesh*> CachedMeshes;
	// Cache the materials on this actor/
	UPROPERTY(Replicated, BlueprintReadOnly, Category = "N00dComponents|Sleeper|Actor|Config")
		TArray<UMaterialInterface*> CachedMaterials;
	// The name of the owner of the sleeper
	UPROPERTY(Replicated, BlueprintReadOnly, Category = "N00dComponents|Sleeper|Actor|Do Not Edit")
		FText SleeperName;
	// Cache the meshes on this actor 
	UPROPERTY(Replicated, BlueprintReadOnly, Category = "N00dComponents|Sleeper|Actor|Config")
		TArray<class ACharacter*> CachedProxies;


	// DAMAGE


	// Current Health 
	UPROPERTY(Replicated, BlueprintReadWrite, Category = "N00dComponents|Sleeper|Actor|Config")
		float Health;
	// Max Health 
	UPROPERTY(Replicated, BlueprintReadOnly, Category = "N00dComponents|Sleeper|Actor|Config")
		float MaxHealth;
	// Max Health 
	UPROPERTY(BlueprintReadWrite, Category = "N00dComponents|Sleeper|Actor|Do Not Edit")
		class AController* DamageInstigator;
	// Max Health 
	UPROPERTY(BlueprintReadWrite, Category = "N00dComponents|Sleeper|Actor|Do Not Edit")
		class AActor* DamageCauser;


// ACTOR SETTINGS PROPERTIES


	// If the player logs back in and the sleeper is dead, should the server start them at the default spawn zones, or back at the dead pawn
	UPROPERTY(BlueprintReadOnly, Category = "N00dComponents|Sleeper|Actor|Do Not Edit")
		bool SpawnAtSleeperIfDead;
	// If your game requires that all players sleep at a set time (i.e., once all players are asleep), we will broadcast it to the server so that we can handle that if needed. 
	UPROPERTY(Replicated, BlueprintReadOnly, Category = "N00dComponents|Sleeper|Actor|Do Not Edit")
		bool ShouldBroadcastSleep;
	// If you would like the game server to let other players know that this sleeper is now dead, flag this as true
	UPROPERTY(Replicated, BlueprintReadOnly, Category = "N00dComponents|Sleeper|Actor|Do Not Edit")
		bool ShouldBroadcastDeath;
	// The time it takes for the sleeper to be destroyed after death
	UPROPERTY(BlueprintReadOnly, Category = "N00dComponents|Sleeper|Actor|Do Not Edit")
		float DeathDelay;
	// Should we use a proxy collision to determine if a player is near
	UPROPERTY(BlueprintReadOnly, Category = "N00dComponents|Sleeper|Actor|Do Not Edit")
		bool UseProximity;
	// The radius of the sphere collision for our sleeper to know if a player is near
	UPROPERTY(Replicated, BlueprintReadOnly, Category = "N00dComponents|Sleeper|Actor|Do Not Edit")
		float ProximityRadius;
	// Independent from bUseProximity to display a 3D widget on the sleeper for N duration. Will not do anything if overlap exists. 
	UPROPERTY(BlueprintReadOnly, Category = "N00dComponents|Sleeper|Actor|Do Not Edit")
		bool ShowWidgetOnSleeperDamaged;
	// The time it takes for the widget to disappear if it hasn't been triggered again
	UPROPERTY(BlueprintReadOnly, Category = "N00dComponents|Sleeper|Actor|Do Not Edit")
		float SleeperWidgetCloseDelay;
	// The class of save game to interface with for if this sleeper has any changes made to it, we want to save those to the server. 
	UPROPERTY(BlueprintReadOnly, Category = "N00dComponents|Sleeper|Actor|Do Not Edit")
		class USaveGame* SleeperSaveGame;
	// The class of save game to interface with for if this sleeper has any changes made to it, we want to save those to the server. 
	UPROPERTY(BlueprintReadOnly, Category = "N00dComponents|Sleeper|Actor|Do Not Edit")
		FString SleeperSaveSlot;
	// Independent from bUseProximity to display a 3D widget on the sleeper for N duration. Will not do anything if overlap exists. 
	UPROPERTY(BlueprintReadOnly, Category = "N00dComponents|Sleeper|Actor|Do Not Edit")
		class UWidgetComponent* SleeperWidgetComponent;

		
	// ANIMATIONS


	// Loaded animation from soft reference. 
	UPROPERTY(Replicated, BlueprintReadWrite, Category = "N00dComponents|Sleeper|Actor|Do Not Edit")
		class UAnimSequence* LoadedToSleepAnimation;
	// Loaded animation from soft reference. 
	UPROPERTY(Replicated, BlueprintReadWrite, Category = "N00dComponents|Sleeper|Actor|Do Not Edit")
		class UAnimSequence* LoadedSleepLoopAnimation;
	// Loaded animation from soft reference. 
	UPROPERTY(Replicated, BlueprintReadWrite, Category = "N00dComponents|Sleeper|Actor|Do Not Edit")
		class UAnimSequence* LoadedHitAnimation;
	// Loaded animation from soft reference. 
	UPROPERTY(Replicated, BlueprintReadWrite, Category = "N00dComponents|Sleeper|Actor|Do Not Edit")
		class UAnimSequence* LoadedDeathAnimation;




private:

	   	 
	// Root 
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = "N00dComponents|Sleeper|Actor|Do Not Edit")
		class USceneComponent* Root;

	// Mesh Component to use as the representation of the logged out player character.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = default)
		class USkeletalMeshComponent* SleeperMesh;

	// Used to show or hide the widget depending on distance to the interacting player
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = "N00dComponents|Sleeper|Actor|Do Not Edit")
		class USphereComponent* Proximity;

#if WITH_EDITORONLY_DATA
	// Component shown in the editor only to indicate character facing
	UPROPERTY()
		UArrowComponent* ArrowComponent;
#endif



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	///////////////////// FUNCTIONS /////////////////////


	// INITALISE


	// Set the owning controller.
	UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, Category = "N00dComponents|Sleeper|Actor|Initialise")
		void SetOwningController(class APlayerController* ForController);
	// Intitialise sleeper - cache the data onto the sleeper from the controller.
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dComponents|Sleeper|Actor|Initialise")
		bool InitialiseSleeper(class APlayerController* ForController);
	// Get the sleeper data from the owning controller
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dComponents|Sleeper|Actor|Initialise")
		bool SetupSleeperFromOwnerData();
	// Cache the relevant meshes on this actor
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dComponents|Sleeper|Actor|Initialise")
		bool CacheMeshes(class USkeletalMesh* Mesh, int32 OnIndex);
	// Cache the relevant materials on this actor for the cached meshes
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dComponents|Sleeper|Actor|Initialise")
		bool CacheMaterials(class UMaterialInterface* Material, int32 OnIndex);
	// Called when sleep has been acheived
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dComponents|Sleeper|Actor|Initialise")
		bool OnSleep();
	// Set the owner ID for the system to use
	UFUNCTION(BlueprintCallable, Category = "N00dComponents|Sleeper|Actor|Initialise")
		bool SetOwnerID(FString OwnerID);
	// Set the owner ID for the system to use
	UFUNCTION(BlueprintCallable, Category = "N00dComponents|Sleeper|Actor|Initialise")
		bool SetOwnerName(FText OwnerName);
	// Set the owner ID for the system to use
	UFUNCTION(BlueprintCallable, NetMulticast, Reliable, Category = "N00dComponents|Sleeper|Actor|Initialise")
		void MulticastSetSphereRadius(class USphereComponent* Proxy, float Radius);
	// Set a reference to the actor's widget
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dComponents|Sleeper|Actor|Initialise")
		bool SetupWidget();
	// Perform the loop
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dComponents|Sleeper|Actor|Initialise")
		void ToLoop();
	// Set a reference to the actor's widget
	UFUNCTION(BlueprintCallable, Category = "N00dComponents|Sleeper|Actor|Initialise")
		void SetSleeperActorParameters(bool BDeath, float DDelay, bool UseProxy, float ProxyRadius, bool WOnDamage, float WDelay, USaveGame * SGame, const FString & SSlot);


	// DAMAGE


	// Damage the sleeper.
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dComponents|Sleeper|Actor|Damage")
		bool DamageSleeper(float DamageAmount, AController* DInstigator, AActor* DCauser, TSubclassOf<UDamageType> DamageTypeClass);
	// What to do when the sleeper is hit.
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dComponents|Sleeper|Actor|Damage")
		bool SleeperHit();
	// Handle killing the sleeper.
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dComponents|Sleeper|Actor|Damage")
		bool KillSleeper();
	// Set the health value
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dComponents|Sleeper|Actor|Damage")
		void SetHealth(float NewHealth, bool &IsDead, float &OutHealth);
	// Set the current health of the sleeper
	UFUNCTION(BlueprintCallable, Category = "N00dComponents|Sleeper|Actor|Damage")
		void SetMaxHealth(float NewMaxHealth);
	// Input should be coming from a damage out
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dComponents|Sleeper|Actor|Damage")
		bool ModifyHealth(float DamageIn);
	// Format the health for UI
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, BlueprintPure, Category = "N00dComponents|Sleeper|Actor|Damage")
		void FormatHealth(float CurrentHealth, FText &Formatted);
	// Let all clients know that this sleeper was just created.
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dComponents|Sleeper|Actor|Damage")
		bool BroadcastSleep();
	// Let the server and clients know that a sleeper has died, via UMG
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dComponents|Sleeper|Actor|Damage")
		bool BroadcastDeath();
	// Destroy the sleeper after a delay
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dComponents|Sleeper|Actor|Damage")
		void DeathOnDelay();
		

	// MESHES
	

	// Apply the cached meshes to the skeletal mesh components
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dComponents|Sleeper|Actor|Meshes")
		bool ApplyMeshes();
	// Apply the meshes to this character over the network for other clients to see the change.
	UFUNCTION(NetMulticast, Reliable, BlueprintCallable, Category = "N00dComponents|Sleeper|Actor|Meshes")
		void MulticastApplyMeshes(class USkeletalMeshComponent* MeshComponent, class USkeletalMesh* Mesh);
	// Apply the meshes to this character over the network for other clients to see the change.
	UFUNCTION(NetMulticast, Reliable, BlueprintCallable, Category = "N00dComponents|Sleeper|Actor|Meshes")
		void MulticastApplyMaterials(class USkeletalMeshComponent* MeshComponent, int32 OnIndex, class UMaterialInterface* Material);


	// ANIMATIONS


	// Load the animations from the cached data
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dComponents|Sleeper|Actor|Animations")
		void LoadAnimations();
	// Send the animations off to all clients.
	UFUNCTION(BlueprintCallable, NetMulticast, Reliable, Category = "N00dComponents|Sleeper|Actor|Animations")
		void MulticastSleeperAnimation(class USkeletalMeshComponent* Mesh, class UAnimSequence* Animation, bool Looping);
	

	// PROXIMITY


	// Handle what happens when the player overlaps the proximity sphere
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dComponents|Sleeper|Actor|Proximity")
		bool SleeperOverlap(bool Begin, class AActor* OtherActor);
	// From the defined settings, construct the proxy
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dComponents|Sleeper|Actor|Proximity")
		bool SetupProximity();
	// Check if there are currently any registered actors in proximity
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "N00dComponents|Sleeper|Actor|Proximity")
		bool AreProxiesValid();
	// Add the player to the registered proximity actors
	UFUNCTION(BlueprintCallable, Category = "N00dComponents|Sleeper|Actor|Proximity")
		bool AddPlayerToProxies(ACharacter * Player);
	// Remove the player from the registered proximity actors
	UFUNCTION(BlueprintCallable, Category = "N00dComponents|Sleeper|Actor|Proximity")
		bool RemovePlayerFromProxies(ACharacter * Player);


	// SAVE LOAD


		// Remove the player from the registered proximity actors
	UFUNCTION(BlueprintCallable, Category = "N00dComponents|Sleeper|Actor|Proximity")
		bool SaveLoad();
		// Save - update the sleeper on the server at anytime.
	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "N00dComponents|Sleeper|Actor|Save Load")
		void ServerSaveLoad();


};




/* EXPERIMENTAL
///////////////////////////////////////////////////////////////////



// Add an item to the defined inventory.
UFUNCTION(BlueprintCallable, CustomThunk, meta = (DisplayName = "Add To Inventory", ArrayParm = "TargetArray", ArrayTypeDependentParams = "NewItem", AutoCreateRefTerm = "NewItem"), Category = "N00dComponents|Sleeper|Actor|Callable")
static int32 Array_AddToInventory(const TArray<int32>& TargetArray, const int32& NewItem);


// Native functions that will be called by the below custom thunk layers, which read off the property address, and call the appropriate native handler
static int32 GenericArray_AddToInventory(void* TargetArray, const FArrayProperty* ArrayProp, const void* NewItem);


// Declare the array function
DECLARE_FUNCTION(execArray_AddToInventory)
{
	Stack.MostRecentProperty = nullptr;
	Stack.StepCompiledIn<FArrayProperty>(NULL);
	void* ArrayAddr = Stack.MostRecentPropertyAddress;
	FArrayProperty* ArrayProperty = CastField<FArrayProperty>(Stack.MostRecentProperty);
	if (!ArrayProperty)
	{
		Stack.bArrayContextFailed = true;
		return;
	}

	// Since NewItem isn't really an int, step the stack manually
	const FProperty* InnerProp = ArrayProperty->Inner;
	const int32 PropertySize = InnerProp->ElementSize * InnerProp->ArrayDim;
	void* StorageSpace = FMemory_Alloca(PropertySize);
	InnerProp->InitializeValue(StorageSpace);

	Stack.MostRecentPropertyAddress = NULL;
	Stack.StepCompiledIn<FProperty>(StorageSpace);

	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)RESULT_PARAM = GenericArray_AddToInventory(ArrayAddr, ArrayProperty, StorageSpace);
	P_NATIVE_END;
	InnerProp->DestroyValue(StorageSpace);
}




///////////////////////////////////////////////////////////////////
*/