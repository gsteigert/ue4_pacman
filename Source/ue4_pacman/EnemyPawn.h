#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "EnemyPawn.generated.h"

UCLASS()
class UE4_PACMAN_API AEnemyPawn : public APawn
{
    GENERATED_BODY()

public:
    virtual void Tick(const float DeltaTime) override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
    bool Frozen = true;
};
