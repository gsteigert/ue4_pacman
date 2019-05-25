#pragma once

#include "TeleporterActor.h"
#include "PacmanController.h"

#include "CoreMinimal.h"
#include "FunctionalTest.h"
#include "TeleportPawnTest.generated.h"

UCLASS()
class ATeleportPawnTest : public AFunctionalTest
{
    GENERATED_BODY()

public:
    ATeleportPawnTest();

    UPROPERTY(EditAnywhere, Category = "Test References")
    ATeleporterActor* RightTeleporter;

    UPROPERTY(EditAnywhere, Category = "Test References")
    ATeleporterActor* LeftTeleporter;

protected:
    virtual void PrepareTest() override;
    virtual void StartTest() override;
    virtual void Tick(float DeltaSeconds) override;
    virtual void CleanUp() override;

private:
    APacmanController* PacmanController;
    void OnTeleportedFromRight(ATeleporterActor* origin, ATeleporterActor* destination);
    void OnTeleportedFromLeft(ATeleporterActor* origin, ATeleporterActor* destination);
};
