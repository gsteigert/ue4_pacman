#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PacmanPawn.generated.h"

UCLASS()
class UE4_PACMAN_API APacmanPawn : public APawn
{
    GENERATED_BODY()

public:
    APacmanPawn();
    void SetDirection(const FVector& direction);
    virtual void Tick(float DeltaTime) override;

protected:
    virtual void BeginPlay() override;

private:
    UPROPERTY(EditAnywhere, Category = "Movement")
    float Speed = 10.0f;

    UPROPERTY(VisibleAnywhere, Category = "Movement")
    FVector Direction;

};
