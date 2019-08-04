#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WinConditionActorComponent.generated.h"

enum class EFoodieType : uint8;

/**
 * Fired when the level is completed (all regular foodies are eaten).
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FLevelCompletedEvent);

/**
 * Detects level completion.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class UE4_PACMAN_API UWinConditionActorComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UWinConditionActorComponent();
    bool IsLevelCompleted() const { return LevelCompleted; };
    FLevelCompletedEvent& LevelCompletedEvent() { return OnLevelCompleted; }

protected:
    virtual void BeginPlay() override;

    UPROPERTY(BlueprintReadOnly, Category = "General")
    int RegularFoodiesLeft = 0;

    UPROPERTY(BlueprintReadOnly, Category = "General")
    bool LevelCompleted = false;

    // The victory notification is only sent after this threshold is reached;
    // Can be changed through blueprints to ease testing
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "General")
    int Threshold = 0;

private:
    UPROPERTY(BlueprintAssignable, BlueprintCallable)
    FLevelCompletedEvent OnLevelCompleted;

    UFUNCTION()
    void OnRegularFoodieEaten(EFoodieType foodieType);

};
