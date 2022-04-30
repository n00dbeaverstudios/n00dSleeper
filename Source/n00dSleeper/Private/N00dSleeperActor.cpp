/* © Copyright 2020-2021 | n00dbeaver Studios */


#include "N00dSleeperActor.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/SkinnedMeshComponent.h"
#include "Components/ArrowComponent.h"

// Sets default values
AN00dSleeperActor::AN00dSleeperActor()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	SetReplicates(true);
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	RootComponent = Root;

	SleeperMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SleeperMesh0"));
	if (SleeperMesh)
	{
		SleeperMesh->SetupAttachment(Root);
	}

	Proximity = CreateDefaultSubobject<USphereComponent>(TEXT("ProximityCollision"));
	if (Proximity)
	{
		Proximity->SetupAttachment(Root); 
	}

#if WITH_EDITORONLY_DATA
	ArrowComponent = CreateEditorOnlyDefaultSubobject<UArrowComponent>(TEXT("Arrow"));
	if (ArrowComponent)
	{
		ArrowComponent->ArrowColor = FColor(150, 200, 255);
		ArrowComponent->bTreatAsASprite = true;
		ArrowComponent->SetupAttachment(Root);
		ArrowComponent->bIsScreenSizeScaled = true;
	}
#endif // WITH_EDITORONLY_DATA
}

// Called when the game starts or when spawned
void AN00dSleeperActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AN00dSleeperActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


// INITIALISE


// Set owning controller (this is temporary on the actor as the player leaves the game)
void AN00dSleeperActor::SetOwningController(class APlayerController* ForController)
{
	if (ForController)
	{
		OwningController = ForController;
	}
}
// Intitialise sleeper 
bool AN00dSleeperActor::InitialiseSleeper_Implementation(class APlayerController* ForController)
{
	return false;
}
// Get data from owner
bool AN00dSleeperActor::SetupSleeperFromOwnerData_Implementation()
{
	return false;
}
// Cache meshes
bool AN00dSleeperActor::CacheMeshes_Implementation(class USkeletalMesh* Mesh, int32 OnIndex)
{
	return false;
}
// Cache materials
bool AN00dSleeperActor::CacheMaterials_Implementation(class UMaterialInterface* Material, int32 OnIndex)
{
	return false;
}
// Set owning ID
bool AN00dSleeperActor::SetOwnerID(FString OwnerID)
{	
		SleeperOwnerID = OwnerID;
		return true;
}
// Set owning name
bool AN00dSleeperActor::SetOwnerName(FText OwnerName)
{
	SleeperName = OwnerName;
	return true;
}
// Multicast set sphre radius
void AN00dSleeperActor::MulticastSetSphereRadius_Implementation(class USphereComponent* Proxy, float Radius)
{
	if (Proxy)
	{
		Proxy->SetSphereRadius(Radius, true);
	}
}
// Set sleeper widget
bool AN00dSleeperActor::SetupWidget_Implementation()
{
	return false;
}
// To loop
void AN00dSleeperActor::ToLoop_Implementation()
{
}
// On sleep
bool AN00dSleeperActor::OnSleep_Implementation()
{
	return false;
}
// Set sleeper params
void AN00dSleeperActor::SetSleeperActorParameters(bool BDeath, float DDelay, bool UseProxy, float ProxyRadius, bool WOnDamage, float WDelay, USaveGame * SGame, const FString & SSlot)
{
	ShouldBroadcastDeath = BDeath;
	DeathDelay = DDelay;
	UseProximity = UseProxy;
	ProximityRadius = ProxyRadius;
	ShowWidgetOnSleeperDamaged = WOnDamage;
	SleeperWidgetCloseDelay = WDelay;
	SleeperSaveGame = SGame;
	SleeperSaveSlot = SSlot;
}


// DAMAGE


// Damage the sleeper
bool AN00dSleeperActor::DamageSleeper_Implementation(float DAmount, AController* DInstigator, AActor* DCauser, TSubclassOf<UDamageType> DTypeClass)
{
	return false;
}
// Handle sleeper hit
bool AN00dSleeperActor::SleeperHit_Implementation()
{
	return false;
}
// Kill sleeper
bool AN00dSleeperActor::KillSleeper_Implementation()
{
	return false;
}
// Set health
void AN00dSleeperActor::SetHealth_Implementation(float TheHealth, bool &IsDead, float &OutHealth)
{
}
// Set max health
void AN00dSleeperActor::SetMaxHealth(float TheMaxHealth)
{
	MaxHealth = TheMaxHealth;
}
// Modify health
bool AN00dSleeperActor::ModifyHealth_Implementation(float DamageIn)
{
	return false;
}
// Format health 
void AN00dSleeperActor::FormatHealth_Implementation(float CHealth, FText &HDisplay)
{

}
// Broadcast sleep
bool AN00dSleeperActor::BroadcastSleep_Implementation()
{
	return false;
}
// Broadcast death
bool AN00dSleeperActor::BroadcastDeath_Implementation()
{
	return false;
}
// Death on delay
void AN00dSleeperActor::DeathOnDelay_Implementation()
{
}


// MESHES


// Apply meshes
bool AN00dSleeperActor::ApplyMeshes_Implementation()
{
	return true;
}
// Multicast apply meshes
void AN00dSleeperActor::MulticastApplyMeshes_Implementation(class USkeletalMeshComponent* MeshComponent, class USkeletalMesh* Mesh)
{
	if (MeshComponent)
	{
		MeshComponent->SetSkeletalMesh(Mesh, true);
	}
}
// Multicast apply materials
void AN00dSleeperActor::MulticastApplyMaterials_Implementation(class USkeletalMeshComponent* MeshComponent, int32 OnIndex, class UMaterialInterface* Material)
{
	if (MeshComponent)
	{
		MeshComponent->SetMaterial(OnIndex, Material);
	}
}


// ANIMATIONS


// Load animations
void AN00dSleeperActor::LoadAnimations_Implementation()
{
}
// Play the animation on all clients
void AN00dSleeperActor::MulticastSleeperAnimation_Implementation(class USkeletalMeshComponent* TheMesh, class UAnimSequence* TheAnimation, bool IsLooping)
{
	TheMesh->PlayAnimation(TheAnimation, IsLooping);
	//TheMesh->GetAnimInstance()->PlaySlotAnimationAsDynamicMontage(TheAnimation);
}


// PROXIMITY


// Sleeper overlap
bool AN00dSleeperActor::SleeperOverlap_Implementation(bool Begin, AActor * OtherActor)
{
	return false;
}
// Construct the proximity
bool AN00dSleeperActor::SetupProximity_Implementation()
{
	return false;
}
// Are proxies valid
bool AN00dSleeperActor::AreProxiesValid()
{
	if (CachedProxies.IsValidIndex(0))
	{
		return true;
	}
	else
	{
		return false;
	}

}
// Add player to proxies
bool AN00dSleeperActor::AddPlayerToProxies(ACharacter * Player)
{
	if (Player)
	{
		CachedProxies.Add(Player);
		return true;
	}
	else
	{
		return false;
	}
}
// Remove player form proxies
bool AN00dSleeperActor::RemovePlayerFromProxies(ACharacter * Player)
{
	if (Player)
	{
		CachedProxies.Remove(Player);
		return true;
	}
	else
	{
		return false;
	}
}


// SAVE LOAD


// Save load
bool AN00dSleeperActor::SaveLoad()
{
	return false;
}
// Server save load
void AN00dSleeperActor::ServerSaveLoad_Implementation()
{
}


///////////////////// PROPERTIES /////////////////////


// Replicate properties
void AN00dSleeperActor::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AN00dSleeperActor, OwningController);
	DOREPLIFETIME(AN00dSleeperActor, CachedMeshes);
	DOREPLIFETIME(AN00dSleeperActor, MeshComponents);
	DOREPLIFETIME(AN00dSleeperActor, CachedMaterials);
	DOREPLIFETIME(AN00dSleeperActor, LoadedToSleepAnimation);
	DOREPLIFETIME(AN00dSleeperActor, LoadedSleepLoopAnimation);
	DOREPLIFETIME(AN00dSleeperActor, LoadedHitAnimation);
	DOREPLIFETIME(AN00dSleeperActor, LoadedDeathAnimation);
	DOREPLIFETIME(AN00dSleeperActor, Health);
	DOREPLIFETIME(AN00dSleeperActor, MaxHealth);	
	DOREPLIFETIME(AN00dSleeperActor, ProximityRadius);
	DOREPLIFETIME(AN00dSleeperActor, CachedProxies);
	DOREPLIFETIME(AN00dSleeperActor, ShouldBroadcastSleep);
}



/* EXPERIMENTAL
///////////////////////////////////////////////////////////////////
// https://forums.unrealengine.com/t/tutorial-how-to-accept-wildcard-structs-in-your-ufunctions/18968/10


// Define runtime inventory array (store in memory and access at runtime)
// Remove from inventory
// 

// Add to Inventory
int32 AN00dSleeperActor::GenericArray_AddToInventory(void* TargetArray, const FArrayProperty* ArrayProp, const void* NewItem)
{
	int32 NewIndex = INDEX_NONE;
	if (TargetArray)
	{
		FScriptArrayHelper ArrayHelper(ArrayProp, TargetArray);
		FProperty* InnerProp = ArrayProp->Inner;

		NewIndex = ArrayHelper.AddValue();
		InnerProp->CopySingleValueToScriptVM(ArrayHelper.GetRawPtr(NewIndex), NewItem);
	}
	return NewIndex;
}
///////////////////////////////////////////////////////////////////
*/