#pragma once

#include "CoreMinimal.h"
#include "FunctionalTest.h"
#include "FruitSpawnerTest.generated.h"

UCLASS()
class AFruitSpawnerTest : public AFunctionalTest
{
    GENERATED_BODY()

public:
    AFruitSpawnerTest();

    UPROPERTY(EditAnywhere, Category = "Test References")
    AActor* FruitSpawner;

protected:
    virtual void PrepareTest() override;
    virtual void StartTest() override;
    virtual void Tick(float DeltaSeconds) override;
    virtual void CleanUp() override;

private:
    void ScheduleFruitCount(int expected, float elapsedTime);
    void CheckFruitCount(int expected, float elapsedTime);
    void ScheduleFruitConsumption(float elapsedTime);
    void ConsumeFruit();
    void ScheduleTestCompletion(float elapsedTime);
    void CompleteTest();

};
