#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TeleporterActor.generated.h"

class USoundCue;

/**
 * Teleports any pawn that enters the trigger volume to another teleporter.
 * The target (destination) teleporter needs to be set manually, through the editor.
 */
UCLASS()
class UE4_PACMAN_API ATeleporterActor : public AActor
{
    GENERATED_BODY()

public:
    void TeleportToTarget(AActor* actor);

    DECLARE_EVENT_TwoParams(ATeleporterActor, FTeleportedEvent, ATeleporterActor*, ATeleporterActor*)
    FTeleportedEvent& OnTeleported() { return TeleportedEvent; }

protected:
    virtual void BeginPlay() override;

    UPROPERTY(EditAnywhere, Category = "Setup")
    ATeleporterActor* Target = nullptr;

private:
    FTeleportedEvent TeleportedEvent;

    UPROPERTY(EditAnywhere, Category = "Setup")
    USoundCue* TeleportSound;

    UFUNCTION()
    void OnOverlapBegin(AActor* overlappedActor, AActor* otherActor);
};
