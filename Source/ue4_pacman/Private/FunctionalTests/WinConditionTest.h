#pragma once

#include "FoodieActor.h"
#include "PacmanController.h"
#include "WinConditionActorComponent.h"

#include "CoreMinimal.h"
#include "FunctionalTest.h"
#include "WinConditionTest.generated.h"

UCLASS()
class AWinConditionTest : public AFunctionalTest
{
	GENERATED_BODY()

public:
    AWinConditionTest();

    UPROPERTY(EditAnywhere, Category = "Test References")
    AFoodieActor* Foodie1 = nullptr;

    UPROPERTY(EditAnywhere, Category = "Test References")
    AFoodieActor* Foodie2 = nullptr;

    UPROPERTY(EditAnywhere, Category = "Test References")
    AFoodieActor* Fruit = nullptr;

protected:
    virtual void PrepareTest() override;
    virtual void StartTest() override;

private:
    APacmanController* PacmanController = nullptr;
    UWinConditionActorComponent* WinConditionComponent = nullptr;

    bool Foodie1EatenEventReceived = false;
    bool Foodie2EatenEventReceived = false;
    bool FruitEatenEventReceived = false;
    bool LevelCompletedEventReceived = false;

    UFUNCTION()
    void OnFoodie1Eaten(EFoodieType foodieType);

    UFUNCTION()
    void OnFoodie2Eaten(EFoodieType foodieType);

    UFUNCTION()
    void OnFruitEaten(EFoodieType foodieType);

    UFUNCTION()
    void OnLevelCompleted();

    /**
     * The order of the events is not guaranteed, so the level completed event
     * handling will be delayed to make it the last one.
     */
    UFUNCTION()
    void ScheduleOnLevelCompleted();
	
};
