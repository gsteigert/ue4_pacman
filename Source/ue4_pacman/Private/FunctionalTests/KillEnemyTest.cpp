#include "KillEnemyTest.h"
#include "Engine/World.h"
#include "BlueprintUtils.h"

AKillEnemyTest::AKillEnemyTest()
{
    Author = "gsteigert";
    Description = "Eat the power up and then kill the enemy";
    TimeLimit = 3.0f;
    TimesUpMessage = FText::FromString("Enemy wasn't killed by Pacman within time");
}

void AKillEnemyTest::PrepareTest()
{
    Super::PrepareTest();
    LogMessage("[KillEnemyTest] PrepareTest()");

    Pacman->OnPacmanDied().AddUObject(this, &AKillEnemyTest::OnPacmanDied);
    Enemy->OnStateChanged().AddDynamic(this, &AKillEnemyTest::OnEnemyStateChanged);
}

void AKillEnemyTest::StartTest()
{
    Super::StartTest();
    LogMessage("[KillEnemyTest] StartTest()");

    BlueprintUtils::SetProperty<bool>(Pacman, "Frozen", false);
    BlueprintUtils::SetProperty<bool>(Enemy, "Frozen", false);
}

void AKillEnemyTest::OnPacmanDied()
{
    LogMessage("[KillEnemyTest] OnPacmanDied()");

    FinishTest(EFunctionalTestResult::Failed, "Pacman should not have died");
}

void AKillEnemyTest::OnEnemyStateChanged(EEnemyState newState)
{
    LogMessage(FString::Printf(TEXT("[KillEnemyTest] OnEnemyDied(newState=%d)"), newState));

    switch (EnemyStateChangedEventCount++)
    {
    case 0:
        // the first event is related to the enemy turning vulnerable;
        // the default state happens before, but it's broadcasted before the test sets up the delegate
        AssertEqual_Int(static_cast<int>(newState), static_cast<int>(EEnemyState::Vulnerable), "New enemy state");
    case 1:
        AssertEqual_Int(static_cast<int>(newState), static_cast<int>(EEnemyState::Dead), "New enemy state");
        FinishTest(EFunctionalTestResult::Default, "Enemy died as expected");
    default:
        FinishTest(EFunctionalTestResult::Failed, "Unexpected event received");
    }
}
