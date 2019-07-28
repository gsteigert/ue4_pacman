#include "EnemyStatesDefaultTest.h"
#include "BlueprintUtils.h"

AEnemyStatesDefaultTest::AEnemyStatesDefaultTest()
{
    Author = "gsteigert";
    Description = "EEnemyState::Default test (activated by Hunt() method)";
    TimeLimit = 3.0f;
    TimesUpMessage = FText::FromString("Enemy didn't collide with Pacman");
}

void AEnemyStatesDefaultTest::StartTest()
{
    Super::StartTest();
    LogMessage("[AEnemyStatesDefaultTest] StartTest()");

    Enemy->Hunt();

    BlueprintUtils::SetProperty<bool>(Enemy, "Frozen", false);
}

void AEnemyStatesDefaultTest::OnEnemyStateChanged(EEnemyState newState)
{
    Super::OnEnemyStateChanged(newState);

    switch (EventCounter) {
    case 0:
        AssertEqual_Int(
            static_cast<int>(newState),
            static_cast<int>(EEnemyState::Default),
            "Enemy state");
        break;
    case  1:
        AssertEqual_Bool(DidPacmanDie, true, "Did Pacman die?");
        AssertEqual_Int(
            static_cast<int>(newState),
            static_cast<int>(EEnemyState::Idle),
            "Enemy state");
        FinishTest(EFunctionalTestResult::Default, "Test completed");
        break;
    }

    EventCounter++;
}
