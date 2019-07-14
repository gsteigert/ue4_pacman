#include "WinConditionTest.h"
#include "Engine/World.h"
#include "Engine/Public/TimerManager.h"
#include "GameFramework/GameModeBase.h"

AWinConditionTest::AWinConditionTest()
{
    Author = "gsteigert";
    Description = "Moves the Pacman to the right until eating all foodies and completing the level";
    TimeLimit = 2;
    TimesUpMessage = FText::FromString("Level not completed within the time limit");
}

void AWinConditionTest::PrepareTest()
{
    Super::PrepareTest();
    LogMessage("[WinConditionTest] PrepareTest()");

    checkf(Foodie1 != nullptr, TEXT("Foodie1 not set"));
    checkf(Foodie2 != nullptr, TEXT("Foodie2 not set"));
    checkf(Fruit != nullptr, TEXT("Fruit not set"));

    AGameModeBase* gameMode = GetWorld()->GetAuthGameMode();
    WinConditionComponent = gameMode->FindComponentByClass<UWinConditionActorComponent>();
    WinConditionComponent->LevelCompletedEvent().AddDynamic(this, &AWinConditionTest::ScheduleOnLevelCompleted);

    PacmanController = Cast<APacmanController>(GetWorld()->GetFirstPlayerController());
    Foodie1->OnFoodieEaten().AddDynamic(this, &AWinConditionTest::OnFoodie1Eaten);
    Foodie2->OnFoodieEaten().AddDynamic(this, &AWinConditionTest::OnFoodie2Eaten);
    Fruit->OnFoodieEaten().AddDynamic(this, &AWinConditionTest::OnFruitEaten);
}

void AWinConditionTest::StartTest()
{
    Super::StartTest();
    LogMessage("[WinConditionTest] StartTest()");

    PacmanController->MoveRightPressed();
    Cast<APacmanPawn>(PacmanController->GetPawn())->SetFrozen(false);
}

void AWinConditionTest::OnFoodie1Eaten(EFoodieType foodieType)
{
    LogMessage("[WinConditionTest] OnFoodie1Eaten()");

    Foodie1EatenEventReceived = true;

    AssertEqual_Int(static_cast<int>(foodieType), static_cast<int>(EFoodieType::Regular), "[OnFoodie1Eaten] FoodieType");
    AssertEqual_Bool(Foodie1EatenEventReceived, true, "[OnFoodie1Eaten] Foodie1EatenEventReceived");
    AssertEqual_Bool(Foodie2EatenEventReceived, false, "[OnFoodie1Eaten] Foodie2EatenEventReceived");
    AssertEqual_Bool(FruitEatenEventReceived, false, "[OnFoodie1Eaten] FruitEatenEventReceived");
    AssertEqual_Bool(LevelCompletedEventReceived, false, "[OnFoodie1Eaten] LevelCompletedEventReceived");
    AssertEqual_Bool(WinConditionComponent->IsLevelCompleted(), false, "[OnFoodie1Eaten] WinConditionComponent->IsLevelCompleted()");
}

void AWinConditionTest::OnFruitEaten(EFoodieType foodieType)
{
    LogMessage("[WinConditionTest] OnFruitEaten()");

    FruitEatenEventReceived = true;

    AssertEqual_Int(static_cast<int>(foodieType), static_cast<int>(EFoodieType::Fruit), "[OnFruitEaten] FoodieType");
    AssertEqual_Bool(Foodie1EatenEventReceived, true, "[OnFruitEaten] Foodie1EatenEventReceived");
    AssertEqual_Bool(Foodie2EatenEventReceived, false, "[OnFruitEaten] Foodie2EatenEventReceived");
    AssertEqual_Bool(FruitEatenEventReceived, true, "[OnFruitEaten] FruitEatenEventReceived");
    AssertEqual_Bool(LevelCompletedEventReceived, false, "[OnFruitEaten] LevelCompletedEventReceived");
    AssertEqual_Bool(WinConditionComponent->IsLevelCompleted(), false, "[OnFruitEaten] WinConditionComponent->IsLevelCompleted()");
}

void AWinConditionTest::OnFoodie2Eaten(EFoodieType foodieType)
{
    LogMessage("[WinConditionTest] OnFoodie2Eaten()");

    Foodie2EatenEventReceived = true;

    AssertEqual_Int(static_cast<int>(foodieType), static_cast<int>(EFoodieType::Regular), "[OnFoodie2Eaten] FoodieType");
    AssertEqual_Bool(Foodie1EatenEventReceived, true, "[OnFoodie2Eaten] Foodie1EatenEventReceived");
    AssertEqual_Bool(Foodie2EatenEventReceived, true, "[OnFoodie2Eaten] Foodie2EatenEventReceived");
    AssertEqual_Bool(FruitEatenEventReceived, true, "[OnFoodie2Eaten] FruitEatenEventReceived");
    AssertEqual_Bool(LevelCompletedEventReceived, false, "[OnFoodie2Eaten] LevelCompletedEventReceived");
    AssertEqual_Bool(WinConditionComponent->IsLevelCompleted(), true, "[OnFoodie2Eaten] WinConditionComponent->IsLevelCompleted()");
}

void AWinConditionTest::OnLevelCompleted()
{
    LogMessage("[WinConditionTest] OnLevelCompleted()");

    LevelCompletedEventReceived = true;

    AssertEqual_Bool(Foodie1EatenEventReceived, true, "[OnLevelCompleted] Foodie1EatenEventReceived");
    AssertEqual_Bool(Foodie2EatenEventReceived, true, "[OnLevelCompleted] Foodie2EatenEventReceived");
    AssertEqual_Bool(FruitEatenEventReceived, true, "[OnLevelCompleted] FruitEatenEventReceived");
    AssertEqual_Bool(LevelCompletedEventReceived, true, "[OnLevelCompleted] LevelCompletedEventReceived");
    AssertEqual_Bool(WinConditionComponent->IsLevelCompleted(), true, "[OnLevelCompleted] WinConditionComponent->IsLevelCompleted()");

    FinishTest(EFunctionalTestResult::Default, "Level completed");
}

void AWinConditionTest::ScheduleOnLevelCompleted()
{
    LogMessage("[WinConditionTest] ScheduleOnLevelCompleted()");

    FTimerHandle someHandle;
    float delay = 0.100f;

    GetWorldTimerManager().SetTimer(someHandle, [this]() { OnLevelCompleted(); }, delay, false);
}
