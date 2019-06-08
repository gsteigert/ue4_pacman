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
    virtual void Tick(float DeltaTime) override;

protected:
    virtual void BeginPlay() override;

private:
    UPROPERTY(VisibleAnywhere, Category = "Movement")
    FVector VerticalDirection;

    UPROPERTY(VisibleAnywhere, Category = "Movement")
    FVector HorizontalDirection;
};
