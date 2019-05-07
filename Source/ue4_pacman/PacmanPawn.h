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
    void SetVerticalMovementInput(const float value);
    void SetHorizontalMovementInput(const float value);
    virtual void Tick(const float DeltaTime) override;

protected:
    virtual void BeginPlay() override;

private:
    UPROPERTY(VisibleAnywhere, Category = "Movement")
    FVector VerticalDirection;
    UPROPERTY(VisibleAnywhere, Category = "Movement")
    FVector HorizontalDirection;
};
