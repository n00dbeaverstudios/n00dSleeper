/* © Copyright 2020-2021 | n00dbeaver Studios */


#include "N00dSleeperComponent.h"

// Sets default values for this component's properties
UN00dSleeperComponent::UN00dSleeperComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false; // Disable Tick as we will be using the owning actor for ticking anything
	// ...
	


}
// Called when the game starts
void UN00dSleeperComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}
// Called every frame
void UN00dSleeperComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


///////////////////// FUNCTIONS (CONTROLLER) /////////////////////


// Set sleeper data
void UN00dSleeperComponent::SetSleeperData(FN00dSleeperData Data)
{
	SleeperData = Data;
}

// Set widget visibility
void UN00dSleeperComponent::SetWidgetVisibility_Implementation(UWidgetComponent * SleeperWidget, bool NewVisibility)
{
	if (SleeperWidget)
	{
		SleeperWidget->SetVisibility(NewVisibility, false);
	}
}
// get sleeper settings
void UN00dSleeperComponent::GetSleeperSettings(UN00dSettingsSleeper*& Settings)
{
//////////////////////////////////////////////////////////////////////
// GET DATA FROM THE PROJECT SETTINGS

	Settings = GetMutableDefault<UN00dSettingsSleeper>();

// GET DATA FROM THE PROJECT SETTINGS
//////////////////////////////////////////////////////////////////////
}


////////////////////// FUNCTIONS (GAME MODE) /////////////////////


// SPAWNING


// Respawn
void UN00dSleeperComponent::Respawn_Implementation(class APlayerController* ForController, APawn* &SpawnedPawn)
{
	if (ForController)
	{
	}
}
// Find sleeper
bool UN00dSleeperComponent::FindSleeper_Implementation(class APlayerController* ForController, class AN00dSleeperActor* &SleeperActor)
{
	return false;
}
// Spawn at sleeper
void UN00dSleeperComponent::SpawnAtSleeper_Implementation(class AN00dSleeperActor* SleeperActor, class APlayerController* ForController, class AN00dSleeperPawn* &SleeperPawn)
{
}
// Spawn default pawn
void UN00dSleeperComponent::DefaultSpawn_Implementation(class APlayerController* ForController, class APawn* &DefaultPawn)
{
}
// Can spawn
bool UN00dSleeperComponent::CanSpawnAtSleeper_Implementation(class APlayerController* ForController, class AN00dSleeperActor* Sleeper)
{
	return false;
}


// CACHE


// Add sleeper
bool UN00dSleeperComponent::AddSleeper_Implementation(class AN00dSleeperActor* SleeperActor)
{
	return false;
}
// Remove sleeper
bool UN00dSleeperComponent::RemoveSleeper_Implementation(class AN00dSleeperActor* SleeperActor)
{
	return false;
}
// Clear sleepers
bool UN00dSleeperComponent::ClearSleepers_Implementation()
{
	return false;
}
// Cache player
void UN00dSleeperComponent::CachePlayer(APlayerController * Player)
{
	PlayerCache.Add(Player);
}
// Remove player
void UN00dSleeperComponent::RemovePlayer(APlayerController * Player)
{
	PlayerCache.Remove(Player);
}


////////////////////// FUNCTIONS (CHARACTER) /////////////////////


// SPAWNING


// Initialise sleeper player
bool UN00dSleeperComponent::InitialiseSleeperPlayer_Implementation(ACharacter * OwnerCharacter, const TArray<USkeletalMeshComponent*>& SkeletalComponents)
{
	return false;
}
// Sleep
bool UN00dSleeperComponent::Sleep_Implementation(bool Logout)
{
	return false;
}
// Can sleep
bool UN00dSleeperComponent::CanSleep_Implementation()
{
	return false;
}
// Spawn sleeper
bool UN00dSleeperComponent::SpawnSleeper_Implementation()
{
	return false;
}
// Get player id
void UN00dSleeperComponent::GetSleeperPlayerID_Implementation(class APlayerController* ForController, FString &PlayerID)
{
}


// Set sleeper character params
void UN00dSleeperComponent::SetSleeperCharacterParams(TArray<USkeletalMesh*> Meshes, TArray<UMaterialInterface*> Materials)
{
	CharacterMeshes = Meshes;
	CharacterMaterials = Materials;
}


// INITIALISE


// Set character reference
void UN00dSleeperComponent::SetOwningCharacter(ACharacter * ForCharacter)
{
	OwningCharacter = ForCharacter;
}
// Server set owning controller
void UN00dSleeperComponent::ServerSetOwnerID_Implementation(const FString &OwnerID)
{
	SleeperOwnerID = OwnerID;
}
// Server set owning controller
void UN00dSleeperComponent::ServerSetOwningController_Implementation(class APlayerController* ForController)
{
	OwningController = ForController;
}
// Build mesh components
void UN00dSleeperComponent::BuildCharacterMeshComponents_Implementation(const TArray<class USkeletalMeshComponent*> &SkeletalComponents)
{
}
// Server build mesh components
void UN00dSleeperComponent::ServerBuildCharacterMeshComponents_Implementation(const TArray<USkeletalMeshComponent*> &SkeletalComponents)
{
}
// Refresh sleeper meshes
bool UN00dSleeperComponent::RefreshSleeperMeshes_Implementation()
{
	return false;
}
// Refresh other data
bool UN00dSleeperComponent::RefreshOtherData_Implementation()
{
	return false;
}
// Apply meshes
bool UN00dSleeperComponent::ApplyMeshes_Implementation()
{
	return false;
}
// Build character materials
void UN00dSleeperComponent::BuildCharacterMaterials(class UMaterialInterface* Material)
{
	CharacterMaterials.Add(Material);
}
// Clear character materials
void UN00dSleeperComponent::ClearCharacterMaterials()
{
	CharacterMaterials.Empty();

}







// SLEEP FUNCTIONALITY


// Load sleep animations
void UN00dSleeperComponent::LoadSleepAnimations_Implementation()
{
}
// Trigger sleep
bool UN00dSleeperComponent::TriggerSleep_Implementation()
{
	return false;
}
// Server sleep
void UN00dSleeperComponent::ServerSleep_Implementation()
{
	TriggerSleep();
}
// Trigger wake
bool UN00dSleeperComponent::TriggerWake_Implementation()
{
	return false;
}
// Server wake
void UN00dSleeperComponent::ServerWake_Implementation()
{
	TriggerWake();
}
// On sleep
bool UN00dSleeperComponent::OnSleep_Implementation()
{
	return false;
}
// Multicast sleep animation
void UN00dSleeperComponent::MulticastSleepAnimation_Implementation(USkeletalMeshComponent* OwnerMesh, UAnimSequence* SleepAnim, bool LoopingAnim)
{
	OwnerMesh->PlayAnimation(SleepAnim, LoopingAnim);
}
// To loop
void UN00dSleeperComponent::ToLoop_Implementation()
{
}
// To loop
void UN00dSleeperComponent::ToWoke_Implementation()
{
}


// BROADCASTING


// Broadcast sleeper message
bool UN00dSleeperComponent::BroadcastSleeperMessage_Implementation(const FText &Message)
{
	return false;
}

///////////////////// PROPERTIES /////////////////////


// Replicate properties
void UN00dSleeperComponent::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UN00dSleeperComponent, OwningController);
	DOREPLIFETIME(UN00dSleeperComponent, SleeperData);
	DOREPLIFETIME(UN00dSleeperComponent, CharacterMeshes);
	DOREPLIFETIME(UN00dSleeperComponent, CharacterMaterials);
	DOREPLIFETIME(UN00dSleeperComponent, MeshComponents);
	DOREPLIFETIME(UN00dSleeperComponent, LoadedSleepLoop);
	DOREPLIFETIME(UN00dSleeperComponent, LoadedFromSleep);
	DOREPLIFETIME(UN00dSleeperComponent, LoadedToSleep);
	DOREPLIFETIME(UN00dSleeperComponent, Asleep);
	DOREPLIFETIME(UN00dSleeperComponent, Triggered);
	DOREPLIFETIME(UN00dSleeperComponent, CachedAnimInstance);
}

void UN00dSleeperComponent::MulticastSetAnimInstance_Implementation(USkeletalMeshComponent* ForMesh)
{
	if (CachedAnimInstance != nullptr) {
		ForMesh->SetAnimInstanceClass(CachedAnimInstance);
	}
}
