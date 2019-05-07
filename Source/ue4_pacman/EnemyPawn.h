#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "EnemyPawn.generated.h"

UCLASS()
class UE4_PACMAN_API AEnemyPawn : public APawn
{
    GENERATED_BODY()

public:
    AEnemyPawn();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
