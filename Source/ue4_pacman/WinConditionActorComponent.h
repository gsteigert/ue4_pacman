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

    UPROPERTY(BlueprintReadOnly)
    int RegularFoodiesLeft = 0;

    UPROPERTY(BlueprintReadOnly)
    bool LevelCompleted = false;

private:
    UPROPERTY(BlueprintAssignable, BlueprintCallable)
    FLevelCompletedEvent OnLevelCompleted;

    UFUNCTION()
    void OnRegularFoodieEaten(EFoodieType foodieType);

};
