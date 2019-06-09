#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyController.generated.h"

/**
 * A simple AI controller that triggers the navmesh path finding component to move towards Pacman.
 */
UCLASS()
class UE4_PACMAN_API AEnemyController : public AAIController
{
    GENERATED_BODY()

private:
    virtual void Tick(float deltaTime) override;
};
