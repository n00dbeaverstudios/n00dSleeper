// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Net/UnrealNetwork.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/ActorComponent.h"
#include "Components/WidgetComponent.h"
#include "Components/SphereComponent.h"
#include "Camera/CameraComponent.h"
//#include "N00dSleeperInterface.h"
#include "N00dSleeperPawn.generated.h"

class USkeletalMeshComponent;
class UArrowComponent;
class USphereComponent;
class USceneComponent;
//struct FN00dSleeperData;
//struct FN00dSleeperSettings;


UCLASS(ClassGroup = (Sleeper), HideCategories = (Camera, Rendering, Collision, LOD, Cooking))
class N00DSLEEPER_API AN00dSleeperPawn : public APawn //, public IN00dSleeperInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AN00dSleeperPawn();


	///////////////////// PROPERTIES /////////////////////


	// COMPONENTS


	// Root
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "N00dComponents|Sleeper|Pawn|Do Not Edit")
		TObjectPtr<USceneComponent> Root;
	// Mesh Component to use as the representation of the logged out player character.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = default)
		TObjectPtr<USkeletalMeshComponent> SleeperMesh;
	// Camera boom
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = default)
		TObjectPtr<USpringArmComponent> CameraBoom;
	// Camera for the pawn
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = default)
		TObjectPtr<UCameraComponent> Camera;
	

	// SLEEPER SETTINGS


	// Have we triggered the wake up thread
	UPROPERTY(Replicated, VisibleAnywhere, BlueprintReadWrite, Category = "N00dComponents|Sleeper|Pawn|Config")
		bool Triggered;
	// The meshes for the sleeper, taken from the sleeper actor
	UPROPERTY(Replicated, VisibleAnywhere, BlueprintReadOnly, Category = "N00dComponents|Sleeper|Pawn|Config")
		TArray <TObjectPtr<USkeletalMesh>> SleeperMeshes;
	// The materials on all of the meshes
	UPROPERTY(Replicated, VisibleAnywhere, BlueprintReadOnly, Category = "N00dComponents|Sleeper|Pawn|Config")
		TArray<TObjectPtr<UMaterialInterface>> SleeperMaterials;
	// Should the system wait for player input before waking up - if this is disabled we wake up instantly
	UPROPERTY(BlueprintReadOnly, Category = "N00dComponents|Sleeper|Pawn|Do Not Edit")
		bool WaitForPlayerInput;
	// The looping animation from the actor
	UPROPERTY(Replicated, VisibleAnywhere, BlueprintReadOnly, Category = "N00dComponents|Sleeper|Pawn|Config")
		TObjectPtr<UAnimSequence> SleeperLoop;
	// Loaded animation from soft reference. 
	UPROPERTY(Replicated, BlueprintReadWrite, Category = "N00dComponents|Sleeper|Actor|Do Not Edit")
		TObjectPtr<UAnimSequence> LoadedFromSleepAnimation;


	// INITIALISE


	// The owning controller of this pawn
	UPROPERTY(Replicated, BlueprintReadOnly, Category = default)
		TObjectPtr<APlayerController> OwningController;
	// The owning sleeper actor that represented this player whilst logged out
	UPROPERTY(Replicated, BlueprintReadOnly, Category = default)
		TObjectPtr<AN00dSleeperActor> OwningSleeperActor;
	/* Skeletal mesh component cache */
	UPROPERTY(BlueprintReadWrite, Category = "N00dComponents|Sleeper|Pawn|Do Not Edit")
		TArray<TObjectPtr<USkeletalMeshComponent>> MeshComponents;
	/** OnRep notify for when the mesh components are built */
	UPROPERTY(BlueprintReadWrite, Category = "N00dComponents|Sleeper|Pawn|Config")
		bool OwnerMeshesBuilt;


	// PLAYER DATA


	/** Current Health */
	UPROPERTY(BlueprintReadOnly, Category = "N00dComponents|Sleeper|Pawn|Config")
		float Health;
	/** Max Health */
	UPROPERTY(BlueprintReadOnly, Category = "N00dComponents|Sleeper|Pawn|Config")
		float MaxHealth;
	/** The formatted health */
	UPROPERTY(BlueprintReadWrite, Category = default)
		FText HealthDisplay;

	   	   
private: 

#if WITH_EDITORONLY_DATA
	/** Component shown in the editor only to indicate character facing */
	UPROPERTY()
		UArrowComponent* ArrowComponent;
#endif

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

///////////////////// FUNCTIONS /////////////////////
	

	// INITALISE


	// Set the owning controller.
	UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, Category = "N00dComponents|Sleeper|Pawn|Callable")
		void SetOwningController(class APlayerController* ForController);
	// Set the owning sleeper actor.
	UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, Category = "N00dComponents|Sleeper|Pawn|Callable")
		void SetOwningSleeperActor(class AN00dSleeperActor* Sleeper);
	// Intitialise sleeper - cache the data onto the sleeper from the data on the owning sleeper actor.
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dComponents|Sleeper|Pawn|Callable")
		bool InitialiseSleeperPawn(class APlayerController* ForController, class AN00dSleeperActor* OwningSleeper);
	// Load the data onto the sleeper from the cached data.
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dComponents|Sleeper|Pawn|Callable")
		bool LoadSleeperData();
	// Give the sleeper data to the owning controller
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dComponents|Sleeper|Pawn|Callable")
		bool GiveDataToOwner();
	// Cache the relevant meshes on this actor
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dComponents|Sleeper|Pawn|Callable")
		bool CacheMeshes(class USkeletalMesh* Mesh, int32 OnIndex);
	// Set the value
	UFUNCTION(BlueprintCallable, Category = "N00dComponents|Sleeper|Pawn|Callable")
		void SetWaitForPlayerInput(bool Waiting);
	// Trigger the wake logic - called from an input
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dComponents|Sleeper|Pawn|Callable")
		bool TriggerWake();
	// Trigger the wake on authority if we are a client
	UFUNCTION(BlueprintCallable, Server, Reliable, Category = "N00dComponents|Sleeper|Pawn|Callable")
		void ServerTriggerWake();
	// Perform the wake up
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dComponents|Sleeper|Pawn|Callable")
		bool ToWoke();
	// Handle the wake logic - called from inside trigger and used on Begin Play if desired
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dComponents|Sleeper|Pawn|Callable")
		bool Wake();
	// Possess the sleeper pawn
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dComponents|Sleeper|Pawn|Callable")
		bool PossessSleeper(class APlayerController* OnController);
	// Possess the sleeper pawn
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dComponents|Sleeper|Pawn|Callable")
		void OnWoke();
	// Spawn the default pawn defined in the game mode
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dComponents|Sleeper|Pawn|Callable")
		bool SpawnDefaultPawn();
	// Set the relevant meshes, materials, and animations on this sleeper
	UFUNCTION(BlueprintCallable, Category = "N00dComponents|Sleeper|Pawn|Callable")
		void SetSleeperPawnParams(TArray<USkeletalMesh*> Meshes, TArray<UMaterialInterface*> Materials, UAnimSequence* SleepLoop);

	

	// DAMAGE


	// Damage the sleeper.
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dComponents|Sleeper|Pawn|Callable")
		bool DamageSleeper(float DamageAmount, AController* DamageInstigator, AActor* DamageCauser, TSubclassOf<UDamageType> DamageTypeClass);
	// What to do when the sleeper is hit.
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dComponents|Sleeper|Pawn|Callable")
		bool SleeperHit();
	// Handle killing the sleeper.
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dComponents|Sleeper|Pawn|Callable")
		bool KillSleeper();
	/* Set the current health of the sleeper, returns false if health is less than or equal to 0, 
	or MaxHealth if anything above... otherwise sets the input as the new current */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dComponents|Sleeper|Pawn|Callable")
		bool SetHealth(float NewHealth, float &OutHealth);
	// Set the current health of the sleeper
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dComponents|Sleeper|Pawn|Callable")
		bool SetMaxHealth(float NewMaxHealth);
	/* Input determines how much to add or subtract from the current. Returns false if sleeper dead.
	Use Set Health in conjuction with this function if you want it to handle the health window for you. */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dComponents|Sleeper|Pawn|Callable")
		bool ModifyHealth(float Add);


	// MESHES


	// Apply the cached meshes to the skeletal mesh components
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dComponents|Sleeper|Pawn|Meshes")
		bool ApplyMeshes();
	// Apply the meshes to this character over the network for other clients to see the change.
	UFUNCTION(NetMulticast, Reliable, BlueprintCallable, Category = "N00dComponents|Sleeper|Pawn|Meshes")
		void MulticastApplyMeshes(class USkeletalMeshComponent* MeshComponent, class USkeletalMesh* Mesh);
	// Apply the meshes to this character over the network for other clients to see the change.
	UFUNCTION(NetMulticast, Reliable, BlueprintCallable, Category = "N00dComponents|Sleeper|Pawn|Meshes")
		void MulticastApplyMaterials(class USkeletalMeshComponent* MeshComponent, int32 OnIndex, class UMaterialInterface* Material);
	// Get the meshes that exist on this actor
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, BlueprintPure, Category = "N00dComponents|Sleeper|Pawn|Meshes")
		TArray<USkeletalMeshComponent*> GetSleeperMeshes();
	   	  

	// ANIMATIONS


	// Load the animations from the cached data
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dComponents|Sleeper|Pawn|Callable")
		void LoadAnimations();
	// Send the animations off to all clients.
	UFUNCTION(BlueprintCallable, NetMulticast, Reliable, Category = "N00dComponents|Sleeper|Pawn|Callable")
		void MulticastSleeperAnimation(class USkeletalMeshComponent* Mesh, class UAnimSequence* Animation, bool Looping);


};
