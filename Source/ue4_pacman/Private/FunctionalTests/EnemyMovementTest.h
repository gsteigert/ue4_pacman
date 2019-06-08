#pragma once

#include "CoreMinimal.h"
#include "FunctionalTest.h"
#include "PacmanPawn.h"
#include "EnemyMovementTest.generated.h"

UCLASS()
class AEnemyMovementTest : public AFunctionalTest
{
	GENERATED_BODY()

public:
    AEnemyMovementTest();

    UPROPERTY(EditAnywhere, Category = "Test References")
    APacmanPawn* Pacman;

protected:
    virtual void PrepareTest() override;

private:
    void OnPacmanDied();
};
