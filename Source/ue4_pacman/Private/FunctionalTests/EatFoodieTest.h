#pragma once

#include "FoodieActor.h"
#include "PacmanController.h"

#include "CoreMinimal.h"
#include "FunctionalTest.h"
#include "EatFoodieTest.generated.h"

UCLASS()
class AEatFoodieTest : public AFunctionalTest
{
    GENERATED_BODY()

public:
    AEatFoodieTest();

    UPROPERTY(EditAnywhere, Category = "Test References")
    AFoodieActor* TargetFoodie;

protected:
    virtual void PrepareTest() override;
    virtual void StartTest() override;
    virtual void Tick(float DeltaSeconds) override;
    virtual void CleanUp() override;

private:
    APacmanController* PacmanController;

    UFUNCTION()
    void OnFoodieEaten(EFoodieType foodieType);
};
