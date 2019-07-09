#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WinConditionActorComponent.generated.h"

enum class EFoodieType : uint8;

/**
 * Manages the regular foodie count to detect level completion.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class UE4_PACMAN_API UWinConditionActorComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UWinConditionActorComponent();

    UPROPERTY(BlueprintReadOnly)
    int RegularFoodiesLeft;

protected:
    virtual void BeginPlay() override;

private:
    UFUNCTION()
    void OnRegularFoodieEaten(EFoodieType foodieType);

};
