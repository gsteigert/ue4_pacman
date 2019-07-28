#pragma once

#include "CoreMinimal.h"
#include "EnemyStatesTest.h"
#include "EnemyStatesVulnerableTest.generated.h"

UCLASS()
class AEnemyStatesVulnerableTest : public AEnemyStatesTest
{
    GENERATED_BODY()

public:
    AEnemyStatesVulnerableTest();

protected:
    virtual void StartTest() override;
    virtual void OnEnemyStateChanged(EEnemyState newState);
};
