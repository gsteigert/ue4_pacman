#pragma once

#include "CoreMinimal.h"
#include "FunctionalTest.h"
#include "PacmanPawn.h"
#include "EnemyPawn.h"
#include "EnemyMovementTest.generated.h"

UCLASS()
class AEnemyMovementTest : public AFunctionalTest
{
	GENERATED_BODY()

public:
    AEnemyMovementTest();

    UPROPERTY(EditAnywhere, Category = "Test References")
    APacmanPawn* Pacman;

    UPROPERTY(EditAnywhere, Category = "Test References")
    AEnemyPawn* Enemy;

protected:
    virtual void PrepareTest() override;
    virtual void StartTest() override;

private:
    void OnPacmanDied();
};
