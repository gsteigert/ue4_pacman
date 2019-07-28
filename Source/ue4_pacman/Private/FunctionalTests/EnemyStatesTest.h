#pragma once

#include "CoreMinimal.h"
#include "FunctionalTest.h"
#include "PacmanPawn.h"
#include "EnemyPawn.h"
#include "EnemyStatesTest.generated.h"

UCLASS()
class AEnemyStatesTest : public AFunctionalTest
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, Category = "Test References")
    APacmanPawn* Pacman;

    UPROPERTY(EditAnywhere, Category = "Test References")
    AEnemyPawn* Enemy;

protected:
    virtual void PrepareTest() override;
    virtual void StartTest() override;

    UFUNCTION()
    virtual void OnPacmanDied();

    UFUNCTION()
    virtual void OnEnemyStateChanged(EEnemyState newState);

    bool DidPacmanDie = false;
    int EventCounter = 0;

};
