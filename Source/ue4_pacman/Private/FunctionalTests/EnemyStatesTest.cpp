#include "EnemyStatesTest.h"
#include "BlueprintUtils.h"

void AEnemyStatesTest::PrepareTest()
{
    Super::PrepareTest();
    LogMessage("[AEnemyStatesTest] PrepareTest()");

    // reset Pacman's state
    BlueprintUtils::SetProperty<bool>(Pacman, "Frozen", true);
    Pacman->SetActorLocation(FVector(-500, 0, 100));
    Pacman->OnPacmanDied().Clear();
    Pacman->OnPacmanDied().AddDynamic(this, &AEnemyStatesTest::OnPacmanDied);

    // reset the enemy's state
    BlueprintUtils::SetProperty<bool>(Enemy, "Frozen", true);
    Enemy->SetActorLocation(FVector(500, 0, 100));
    Enemy->OnStateChanged().Clear();
    Enemy->OnStateChanged().AddDynamic(this, &AEnemyStatesTest::OnEnemyStateChanged);
}

void AEnemyStatesTest::StartTest()
{
    LogMessage("[AEnemyStatesTest] StartTest()");
}

void AEnemyStatesTest::OnPacmanDied()
{
    LogMessage("[AEnemyStatesTest] OnPacmanDied()");

    DidPacmanDie = true;
}

void AEnemyStatesTest::OnEnemyStateChanged(EEnemyState newState)
{
    LogMessage(FString::Printf(
        TEXT("[AEnemyStatesTest] OnEnemyStateChanged(newState=%d, EventCounter=%d)"),
        newState,
        EventCounter));
}
