#include "TeleporterActor.h"
#include "Components/SceneComponent.h"
#include "Engine/Public/TimerManager.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundCue.h"

void ATeleporterActor::BeginPlay()
{
    Super::BeginPlay();

    // assertion macros are useful for ensuring the context is valid prior to running this code,
    // exposing potential issues earlier; see: https://docs.unrealengine.com/en-US/Programming/Assertions/index.html

    // check will halt execution with a meaningful error message
    checkf(Target != nullptr, TEXT("[%s] No target teleporter was set"), *GetName());
    checkf(Target != this, TEXT("[%s] Target teleporter cannot be self"), *GetName());
    checkf(IsValid(Target), TEXT("[%s] Target teleporter is not valid"), *GetName());

    OnActorBeginOverlap.AddDynamic(this, &ATeleporterActor::OnOverlapBegin);
}

void ATeleporterActor::OnOverlapBegin(AActor* overlappedActor, AActor* otherActor)
{
    UE_LOG(LogTemp, Log, TEXT("[%s] OnOverlapBegin(overlapped=%s, other=%s)"),
        *GetName(), *overlappedActor->GetName(), *otherActor->GetName());

    if (!otherActor->IsA<APawn>()) {
        UE_LOG(LogTemp, Log, TEXT("[%s] Skipping teleportation: not a pawn"),
            *GetName(), *overlappedActor->GetName(), *otherActor->GetName());
        return;
    }

    // calling SetActorLocation within OnOverlapBegin results in odd behaviors:
    // (1) OnOverlapBegin fires multiple times
    // (2) the pacman would carry velocity after getting teleported
    // (3) the pacman would teleport between the teleporters indefinitely

    // to workaround that, the teleportation will be postponed to the next frame
    GetWorldTimerManager().SetTimerForNextTick([otherActor, this]() { TeleportToTarget(otherActor); });
}

void ATeleporterActor::TeleportToTarget(AActor* actor)
{
    UE_LOG(LogTemp, Log, TEXT("[%s] Teleporting %s to %s"),
        *GetName(), *actor->GetName(), *Target->GetName());

    USceneComponent* targetSpawn = Cast<USceneComponent>(Target->GetDefaultSubobjectByName("Spawn"));

    // ensure won't halt execution but will log an error and generate a debug call stack
    if (ensureMsgf(targetSpawn != nullptr,
        TEXT("[%s] Target spawn location not found!"), *GetName()))
    {
        UGameplayStatics::PlaySound2D(this, TeleportSound);
        actor->SetActorLocation(targetSpawn->GetComponentLocation());
        TeleportedEvent.Broadcast(this, Target);
    }
}
