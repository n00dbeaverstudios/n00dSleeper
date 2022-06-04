/* © Copyright 2020-2021 | n00dbeaver Studios */

#include "N00dSleeperPawn.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/SkinnedMeshComponent.h"
#include "Components/ArrowComponent.h"


// Sets default values
AN00dSleeperPawn::AN00dSleeperPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	RootComponent = Root;

	SleeperMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SleeperMesh0"));
	if (SleeperMesh)
	{
		SleeperMesh->SetupAttachment(Root);
	}

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom0"));
	if (CameraBoom)
	{
		CameraBoom->SetupAttachment(Root);
	}

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera0"));
	if (Camera)
	{
		Camera->SetupAttachment(CameraBoom);
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
void AN00dSleeperPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AN00dSleeperPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AN00dSleeperPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


// ACTOR AND PAWN


	// INITIALISE


// Set owning controller
void AN00dSleeperPawn::SetOwningController(class APlayerController* ForController)
{
	if (ForController)
	{
		OwningController = ForController;
	}
}
// Set owning sleeper actor
void AN00dSleeperPawn::SetOwningSleeperActor(class AN00dSleeperActor* Sleeper)
{
	if (Sleeper)
	{
		OwningSleeperActor = Sleeper;
	}
}
// Intitialise sleeper 
bool AN00dSleeperPawn::InitialiseSleeperPawn_Implementation(class APlayerController* ForController, class AN00dSleeperActor* OwningSleeper)
{
	return false;
}
// Load sleeper data
bool AN00dSleeperPawn::LoadSleeperData_Implementation()
{
	return false;
}
// Give data to owner
bool AN00dSleeperPawn::GiveDataToOwner_Implementation()
{
	return false;
}
// Cache meshes
bool AN00dSleeperPawn::CacheMeshes_Implementation(class USkeletalMesh* Mesh, int32 OnIndex)
{
	return false;
}
// Trigger wake
bool AN00dSleeperPawn::TriggerWake_Implementation()
{
	return false;
}
// Server trigger wake
void AN00dSleeperPawn::ServerTriggerWake_Implementation()
{
	TriggerWake();
}
// Possess sleeper
bool AN00dSleeperPawn::PossessSleeper_Implementation(class APlayerController* OnController)
{
	return false;
}
// To woke
bool AN00dSleeperPawn::ToWoke_Implementation()
{
	return false;
}
// Handle Wake
bool AN00dSleeperPawn::Wake_Implementation()
{
	return false;
}
// On Woke
void AN00dSleeperPawn::OnWoke_Implementation()
{
}
void AN00dSleeperPawn::SetWaitForPlayerInput(bool Waiting)
{
	WaitForPlayerInput = Waiting;
}
//Spawn the default pawn from the game mode
bool AN00dSleeperPawn::SpawnDefaultPawn_Implementation()
{
	return false;
}
// Set sleeper pawn parameters
void AN00dSleeperPawn::SetSleeperPawnParams(TArray<class USkeletalMesh*> Meshes, TArray<UMaterialInterface*> Materials, UAnimSequence* SleepLoop)
{
	SleeperMeshes = Meshes;
	SleeperMaterials = Materials;
	SleeperLoop = SleepLoop;
}


	// DAMAGE


// Damage the sleeper
bool AN00dSleeperPawn::DamageSleeper_Implementation(float DAmount, AController* DInstigator, AActor* DCauser, TSubclassOf<UDamageType> DTypeClass)
{
	return false;
}
// Handle sleeper hit
bool AN00dSleeperPawn::SleeperHit_Implementation()
{
	return false;
}
// Kill sleeper
bool AN00dSleeperPawn::KillSleeper_Implementation()
{
	return false;
}
// Set health
bool AN00dSleeperPawn::SetHealth_Implementation(float TheHealth, float &OutHealth)
{
	if (TheHealth <= 0.0f)
	{
		Health = 0.0f;
		OutHealth = 0.0f;
		return false;
	}
	if (TheHealth >= MaxHealth)
	{
		Health = MaxHealth;
		OutHealth = MaxHealth;
		return true;
	}
	else
	{
		Health = TheHealth;
		OutHealth = Health;
		return true;
	}
}
// Set max health
bool AN00dSleeperPawn::SetMaxHealth_Implementation(float TheMaxHealth)
{
	return false;
}
// Modify health
bool AN00dSleeperPawn::ModifyHealth_Implementation(float AddHealth)
{
	return false;
}


	// MESHES


// Apply meshes
bool AN00dSleeperPawn::ApplyMeshes_Implementation()
{
	return true;
}
// Multicast apply meshes
void AN00dSleeperPawn::MulticastApplyMeshes_Implementation(class USkeletalMeshComponent* MeshComponent, class USkeletalMesh* Mesh)
{
	if (MeshComponent)
	{
		MeshComponent->SetSkeletalMesh(Mesh, true);
	}
}
// Multicast apply materials
void AN00dSleeperPawn::MulticastApplyMaterials_Implementation(class USkeletalMeshComponent* MeshComponent, int32 OnIndex, class UMaterialInterface* Material)
{
	if (MeshComponent)
	{
		MeshComponent->SetMaterial(OnIndex, Material);
	}
}
// get sleeper meshes
TArray<USkeletalMeshComponent*> AN00dSleeperPawn::GetSleeperMeshes_Implementation()
{
	return TArray<USkeletalMeshComponent*>();
}


	// ANIMATIONS


// Load animations
void AN00dSleeperPawn::LoadAnimations_Implementation()
{
}
// Play the animation on all clients
void AN00dSleeperPawn::MulticastSleeperAnimation_Implementation(class USkeletalMeshComponent* TheMesh, class UAnimSequence* TheAnimation, bool IsLooping)
{
	TheMesh->PlayAnimation(TheAnimation, IsLooping);
}


///////////////////// PROPERTIES /////////////////////


// Replicate properties
void AN00dSleeperPawn::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AN00dSleeperPawn, OwningController);
	DOREPLIFETIME(AN00dSleeperPawn, OwningSleeperActor);
	DOREPLIFETIME(AN00dSleeperPawn, LoadedFromSleepAnimation);
	DOREPLIFETIME(AN00dSleeperPawn, Triggered);
	DOREPLIFETIME(AN00dSleeperPawn, SleeperMeshes);
	DOREPLIFETIME(AN00dSleeperPawn, SleeperMaterials);
	DOREPLIFETIME(AN00dSleeperPawn, SleeperLoop);
}

