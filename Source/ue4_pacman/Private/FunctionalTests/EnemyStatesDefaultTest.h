#pragma once

#include "CoreMinimal.h"
#include "EnemyStatesTest.h"
#include "EnemyStatesDefaultTest.generated.h"

UCLASS()
class AEnemyStatesDefaultTest : public AEnemyStatesTest
{
	GENERATED_BODY()

public:
    AEnemyStatesDefaultTest();

protected:
    virtual void StartTest() override;
    virtual void OnEnemyStateChanged(EEnemyState newState);
};
