#include "EnemyMovementTest.h"
#include "Engine/World.h"
#include "BlueprintUtils.h"

AEnemyMovementTest::AEnemyMovementTest()
{
    Author = "gsteigert";
    Description = "Lets the enemy find its way to collide with Pacman";
    TimeLimit = 5;
    TimesUpMessage = FText::FromString("Enemy didn't collide with Pacman");
}

void AEnemyMovementTest::PrepareTest()
{
    Super::PrepareTest();
    LogMessage("[EnemyMovementTest] PrepareTest()");

    Pacman->OnPacmanDied().AddDynamic(this, &AEnemyMovementTest::OnPacmanDied);
}

void AEnemyMovementTest::StartTest()
{
    Super::StartTest();
    LogMessage("[EnemyMovementTest] StartTest()");

    BlueprintUtils::SetProperty<bool>(Enemy, "Frozen", false);
}

void AEnemyMovementTest::OnPacmanDied()
{
    LogMessage("[EnemyMovementTest] OnPacmanDied()");

    FinishTest(EFunctionalTestResult::Succeeded, "Pacman died");
}
