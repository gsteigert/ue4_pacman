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

    void SetDirection(const FVector value);

    DECLARE_EVENT(APacmanPawn, FPacmanDiedEvent)
    FPacmanDiedEvent& OnPacmanDied() { return PacmanDiedEvent; }

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
    bool Frozen = true;

protected:
    virtual void BeginPlay() override;
    void ConsumeRegularFoodie(AFoodieActor* foodie);
    void Die();

private:
    UFUNCTION()
    void OnHit(AActor* selfActor, AActor* otherActor, FVector normalImpulse, const FHitResult& hit);

    UFUNCTION()
    void OnOverlapBegin(AActor* overlappedActor, AActor* otherActor);

    FPacmanDiedEvent PacmanDiedEvent;
};
