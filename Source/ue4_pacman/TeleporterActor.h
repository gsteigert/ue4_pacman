#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TeleporterActor.generated.h"

UCLASS()
class UE4_PACMAN_API ATeleporterActor : public AActor
{
    GENERATED_BODY()

public:
    ATeleporterActor();
    void TeleportToTarget(AActor* actor);

protected:
    virtual void BeginPlay() override;

    UPROPERTY(EditAnywhere, Category = "General")
    ATeleporterActor* Target = nullptr;

private:
    UFUNCTION()
    void OnOverlapBegin(AActor* overlappedActor, AActor* otherActor);
};
