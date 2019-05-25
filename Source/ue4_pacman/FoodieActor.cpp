#include "FoodieActor.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundCue.h"

AFoodieActor::AFoodieActor()
{
    PrimaryActorTick.bCanEverTick = false;
}

void AFoodieActor::Consume()
{
    UGameplayStatics::PlaySound2D(this, RegularFoodieConsumptionSound);
    FoodieEatenEvent.Broadcast();
    Destroy();
}
