#include "TeleportPawnTest.h"
#include "Engine/World.h"

ATeleportPawnTest::ATeleportPawnTest()
{
    Author = "gsteigert";
    Description = "Moves the Pacman to the right until teleportation happens";
    TimeLimit = 5;
    TimesUpMessage = FText::FromString("Not teleported within the time limit");
}

void ATeleportPawnTest::PrepareTest()
{
    Super::PrepareTest();
    LogMessage("[TeleportPawnTest] PrepareTest()");

    checkf(RightTeleporter, TEXT("Teleporter not set: RightTeleporter"));
    checkf(LeftTeleporter, TEXT("Teleporter not set: LeftTeleporter"));

    PacmanController = Cast<APacmanController>(GetWorld()->GetFirstPlayerController());
    RightTeleporter->OnTeleported().AddUObject(this, &ATeleportPawnTest::OnTeleportedFromRight);
    LeftTeleporter->OnTeleported().AddUObject(this, &ATeleportPawnTest::OnTeleportedFromLeft);
}

void ATeleportPawnTest::StartTest()
{
    Super::StartTest();
    LogMessage("[TeleportPawnTest] StartTest()");

    PacmanController->MoveRightPressed();
    Cast<APacmanPawn>(PacmanController->GetPawn())->SetFrozen(false);
}

void ATeleportPawnTest::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
}

void ATeleportPawnTest::CleanUp()
{
    Super::CleanUp();
    LogMessage("[TeleportPawnTest] CleanUp()");
}

void ATeleportPawnTest::OnTeleportedFromRight(ATeleporterActor* origin, ATeleporterActor* destination)
{
    LogMessage("[TeleportPawnTest] OnTeleportedFromRight()");

    AssertEqual_String(origin->GetName(), "BP_Teleporter_Right", "teleporter name");
    AssertEqual_String(destination->GetName(), "BP_Teleporter_Left", "teleporter name");

    FinishTest(EFunctionalTestResult::Succeeded, "Pacman teleported");
}

void ATeleportPawnTest::OnTeleportedFromLeft(ATeleporterActor* origin, ATeleporterActor* destination)
{
    LogMessage("[TeleportPawnTest] OnTeleportedFromLeft()");

    FinishTest(EFunctionalTestResult::Failed, "Left teleporter should not have fired any event");
}
