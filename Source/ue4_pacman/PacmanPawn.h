#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PacmanPawn.generated.h"

class AFoodieActor;

UCLASS()
class UE4_PACMAN_API APacmanPawn : public APawn
{
    GENERATED_BODY()

public:
    APacmanPawn();
    virtual void Tick(const float DeltaTime) override;

    void SetVerticalMovementInput(const float value);
    void SetHorizontalMovementInput(const float value);

    UFUNCTION()
    void OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor);

protected:
    virtual void BeginPlay() override;
    void ConsumeRegularFoodie(AFoodieActor* foodie);

private:
    UPROPERTY(VisibleAnywhere, Category = "Movement")
    FVector VerticalDirection;

    UPROPERTY(VisibleAnywhere, Category = "Movement")
    FVector HorizontalDirection;
};
