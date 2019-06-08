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

    DECLARE_EVENT(APacmanPawn, FPacmanDiedEvent)
    FPacmanDiedEvent& OnPacmanDied() { return PacmanDiedEvent; }

protected:
    virtual void BeginPlay() override;
    void ConsumeRegularFoodie(AFoodieActor* foodie);
    void Die();

private:
    UPROPERTY(VisibleAnywhere, Category = "Movement")
    FVector VerticalDirection;

    UPROPERTY(VisibleAnywhere, Category = "Movement")
    FVector HorizontalDirection;

    UFUNCTION()
    void OnHit(AActor* selfActor, AActor* otherActor, FVector normalImpulse, const FHitResult& hit);

    UFUNCTION()
    void OnOverlapBegin(AActor* overlappedActor, AActor* otherActor);

    FPacmanDiedEvent PacmanDiedEvent;
};
