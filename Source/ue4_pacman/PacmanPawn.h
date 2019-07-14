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
    bool IsFrozen() { return Frozen; }

    DECLARE_EVENT(APacmanPawn, FPacmanDiedEvent)
    FPacmanDiedEvent& OnPacmanDied() { return PacmanDiedEvent; }

    UFUNCTION(BlueprintCallable)
    void SetFrozen(bool value) { Frozen = value; };

    UFUNCTION(BlueprintCallable)
    void Die();

protected:
    virtual void BeginPlay() override;

    UPROPERTY(BlueprintReadOnly, Category = "State")
    bool Frozen = true;

private:
    UFUNCTION()
    void OnOverlapBegin(AActor* overlappedActor, AActor* otherActor);

    FPacmanDiedEvent PacmanDiedEvent;

};
