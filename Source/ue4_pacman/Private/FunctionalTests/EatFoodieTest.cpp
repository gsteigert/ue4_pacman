#include "EatFoodieTest.h"
#include "Engine\World.h"

AEatFoodieTest::AEatFoodieTest() {
    Author = "gsteigert";
    Description = "Moves the Pacman to the right until colliding with the foodie";
    TimeLimit = 1;
    TimesUpMessage = FText::FromString("No foodie was eaten within the time limit");
}

void AEatFoodieTest::PrepareTest() {
    Super::PrepareTest();
    LogMessage("[EatFoodieTest] PrepareTest()");

    PacmanController = Cast<APacmanController>(GetWorld()->GetFirstPlayerController());
    TargetFoodie->OnFoodieEaten.AddUObject(this, &AEatFoodieTest::OnFoodieEaten);
}

void AEatFoodieTest::StartTest() {
    Super::StartTest();
    LogMessage("[EatFoodieTest] StartTest()");

    PacmanController->MoveRightPressed();
}

void AEatFoodieTest::Tick(float DeltaSeconds) {
    Super::Tick(DeltaSeconds);
}

void AEatFoodieTest::CleanUp() {
    Super::CleanUp();
    LogMessage("[EatFoodieTest] CleanUp()");
}

void AEatFoodieTest::OnFoodieEaten() {
    LogMessage("[EatFoodieTest] OnFoodieEaten()");

    FinishTest(EFunctionalTestResult::Succeeded, "Foodie eaten");
}
