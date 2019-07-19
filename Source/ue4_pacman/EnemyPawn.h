#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "EnemyPawn.generated.h"

class AAIController;

UENUM(BlueprintType)
enum class EEnemyState : uint8 {
    Default UMETA(DisplayName = "Default"),
    Vulnerable UMETA(DisplayName = "Vulnerable"),
    Dead UMETA(DisplayName = "Dead"),
    Idle UMETA(DisplayName = "Idle")
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FEnemyStateChangedEvent, EEnemyState, newState);

UCLASS()
class UE4_PACMAN_API AEnemyPawn : public APawn
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "General")
    EEnemyState state = EEnemyState::Default;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "References")
    AActor* Origin = nullptr;

    FEnemyStateChangedEvent& OnStateChanged() { return StateChangedEvent; }

    UFUNCTION(BlueprintCallable)
    void Hunt();

    UFUNCTION(BlueprintCallable)
    void Run();

    UFUNCTION(BlueprintCallable)
    void Die();

    UFUNCTION(BlueprintCallable)
    void Idle();

private:
    UPROPERTY(BlueprintAssignable, BlueprintCallable)
    FEnemyStateChangedEvent StateChangedEvent;

};
