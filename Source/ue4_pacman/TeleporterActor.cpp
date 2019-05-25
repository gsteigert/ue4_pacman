#include "TeleporterActor.h"
#include "Engine\Classes\Components\SceneComponent.h"
#include "Engine\Public\TimerManager.h"

ATeleporterActor::ATeleporterActor()
{
}

void ATeleporterActor::BeginPlay()
{
    Super::BeginPlay();

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

    // calling SetActorLocation within OnOverlapBegin resulted in odd behaviors:
    // (1) OnOverlapBegin was firing multiple times
    // (2) the pacman would carry velocity after getting teleported
    // (3) the pacman would teleport between the teleporters indefinitely

    // to workaround that, the teleportation will be postponed to the next tick
    GetWorldTimerManager().SetTimerForNextTick([otherActor, this]() { TeleportToTarget(otherActor); });
}

void ATeleporterActor::TeleportToTarget(AActor* actor)
{
    UE_LOG(LogTemp, Log, TEXT("[%s] Teleporting %s to %s"),
        *GetName(), *actor->GetName(), *Target->GetName());

    USceneComponent* targetSpawn = Cast<USceneComponent>(Target->GetDefaultSubobjectByName("Spawn"));

    if (targetSpawn)
    {
        actor->SetActorLocation(targetSpawn->GetComponentLocation());
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("[%s] Spawn location not found!"), *GetName());
    }
}
