#include "EnemyStatesVulnerableTest.h"
#include "BlueprintUtils.h"

AEnemyStatesVulnerableTest::AEnemyStatesVulnerableTest()
{
    Author = "gsteigert";
    Description = "EEnemyState::Vulnerable test (activated by Run() method)";
    TimeLimit = 10.0f;
    TimesUpMessage = FText::FromString("Enemy didn't run away or didn't restore to default state");
}

void AEnemyStatesVulnerableTest::StartTest()
{
    Super::StartTest();
    LogMessage("[AEnemyStatesVulnerableTest] StartTest()");

    Enemy->Run();

    BlueprintUtils::SetProperty<bool>(Enemy, "Frozen", false);
}

void AEnemyStatesVulnerableTest::OnEnemyStateChanged(EEnemyState newState)
{
    Super::OnEnemyStateChanged(newState);

    switch (EventCounter) {
    case 0:
        AssertEqual_Int(
            static_cast<int>(newState),
            static_cast<int>(EEnemyState::Vulnerable),
            "Enemy state");
        break;
    case  1:
        AssertEqual_Bool(DidPacmanDie, false, "Did Pacman die?");
        AssertEqual_Int(
            static_cast<int>(newState),
            static_cast<int>(EEnemyState::Default),
            "Enemy state");
        FinishTest(EFunctionalTestResult::Default, "Test completed");
        break;
    }

    EventCounter++;
}
