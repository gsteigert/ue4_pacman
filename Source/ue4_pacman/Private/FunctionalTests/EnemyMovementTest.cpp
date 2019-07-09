#include "EnemyMovementTest.h"
#include "Engine/World.h"

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

    Pacman->OnPacmanDied().AddUObject(this, &AEnemyMovementTest::OnPacmanDied);
}

void AEnemyMovementTest::OnPacmanDied()
{
    LogMessage("[EnemyMovementTest] OnPacmanDied()");

    FinishTest(EFunctionalTestResult::Succeeded, "Pacman died");
}
