#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "EnemyPawn.generated.h"

class AAIController;

UENUM(BlueprintType)
enum class EEnemyState : uint8 {
    Default UMETA(DisplayName = "Default"),
    Vulnerable UMETA(DisplayName = "Vulnerable"),
    Dead UMETA(DisplayName = "Dead")
};

UCLASS()
class UE4_PACMAN_API AEnemyPawn : public APawn
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "General")
    EEnemyState state = EEnemyState::Default;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "References")
    AActor* Origin = nullptr;

};
