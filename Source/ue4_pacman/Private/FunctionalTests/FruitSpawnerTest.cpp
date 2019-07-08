#include "FruitSpawnerTest.h"
#include "FoodieActor.h"
#include "Engine/World.h"
#include "Engine/Public/TimerManager.h"
#include "Kismet/GameplayStatics.h"

AFruitSpawnerTest::AFruitSpawnerTest()
{
    Author = "gsteigert";
    Description = "Checks the fruit spawner behavior";
    TimeLimit = 0.0f;
}

void AFruitSpawnerTest::PrepareTest()
{
    Super::PrepareTest();
    LogMessage("[AFruitSpawnerTest] PrepareTest()");

    checkf(FruitSpawner != nullptr, TEXT("FruitSpawner not set"));

    // every second, the spawn is scheduled to [0.70-0.80] seconds;
    // in case the spawn location is available at that time, a fruit is spawned;
    // when the fruit is consumed, there is a 1.00 second cooldown to make the spawn location available again;

    ScheduleFruitCount(0, 0.0f); // there should be no fruit initially
    ScheduleFruitCount(1, 1.0f); // there should be one fruit after the max spawn time have passed for the first time
    ScheduleFruitCount(1, 2.0f); // there should still be one fruit because the spawn location is not available
    ScheduleFruitConsumption(2.1f); // schedule the fruit consumption, making the spawn location available
    ScheduleFruitCount(0, 3.0f); // there should be no fruit due to the cooldown time (which ends at 3.1 seconds)
    ScheduleFruitCount(1, 4.0f); // there should be one fruit again after the cooldown time has expired

    // this test has no time limit;
    // after all checks were done, the test fails if any assert failed
    ScheduleTestCompletion(4.2f);
}

void AFruitSpawnerTest::StartTest()
{
    Super::StartTest();
    LogMessage("[AFruitSpawnerTest] StartTest()");
}

void AFruitSpawnerTest::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
}

void AFruitSpawnerTest::CleanUp()
{
    Super::CleanUp();
    LogMessage("[AFruitSpawnerTest] CleanUp()");
}

void AFruitSpawnerTest::ScheduleFruitCount(int expected, float elapsedTime)
{
    FTimerHandle someHandle;
    GetWorldTimerManager().SetTimer(someHandle,
        [expected, elapsedTime, this]() { CheckFruitCount(expected, elapsedTime); },
        elapsedTime, false);
}

void AFruitSpawnerTest::CheckFruitCount(int expected, float elapsedTime)
{
    LogMessage(FString::Printf(TEXT("[AFruitSpawnerTest] CheckFruitCount(expected=%d, elapsedTime=%1.3f)"),
        expected, elapsedTime));

    TArray<AActor*> FoundActors;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), AFoodieActor::StaticClass(), FoundActors);
    FString what = FString::Printf(TEXT("foodieCount @ time %1.3f"), elapsedTime);

    AssertEqual_Int(FoundActors.Num(), expected, what);
}

void AFruitSpawnerTest::ScheduleFruitConsumption(float elapsedTime)
{
    FTimerHandle someHandle;
    GetWorldTimerManager().SetTimer(someHandle,
        [this]() { ConsumeFruit(); },
        elapsedTime, false);
}

void AFruitSpawnerTest::ConsumeFruit()
{
    LogMessage("[AFruitSpawnerTest] ConsumeFruit()");

    TArray<AActor*> FoundActors;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), AFoodieActor::StaticClass(), FoundActors);
    AFoodieActor* foodie = Cast<AFoodieActor>(FoundActors[0]);

    foodie->Consume();
}

void AFruitSpawnerTest::ScheduleTestCompletion(float elapsedTime)
{
    FTimerHandle someHandle;
    GetWorldTimerManager().SetTimer(someHandle,
        [this]() { CompleteTest(); },
        elapsedTime, false);
}

void AFruitSpawnerTest::CompleteTest()
{
    FinishTest(EFunctionalTestResult::Default, "Test completed");
}
