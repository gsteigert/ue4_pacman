#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FoodieActor.generated.h"

class USoundCue;

UCLASS()
class UE4_PACMAN_API AFoodieActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AFoodieActor();
	void Consume();

private:
    UPROPERTY(EditAnywhere, Category = "Sound Effects")
    USoundCue* RegularFoodieConsumptionSound;

};
