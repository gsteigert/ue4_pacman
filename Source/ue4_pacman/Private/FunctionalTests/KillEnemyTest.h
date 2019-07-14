#pragma once

#include "CoreMinimal.h"
#include "FunctionalTest.h"
#include "PacmanPawn.h"
#include "EnemyPawn.h"
#include "KillEnemyTest.generated.h"

UCLASS()
class AKillEnemyTest : public AFunctionalTest
{
	GENERATED_BODY()

public:
    AKillEnemyTest();

    UPROPERTY(EditAnywhere, Category = "Test References")
    APacmanPawn* Pacman;

    UPROPERTY(EditAnywhere, Category = "Test References")
    AEnemyPawn* Enemy;

protected:
    virtual void PrepareTest() override;
    virtual void StartTest() override;

private:
    UFUNCTION()
    void OnPacmanDied();

    UFUNCTION()
    void OnEnemyStateChanged(EEnemyState newState);

    int EnemyStateChangedEventCount = 0;
};
