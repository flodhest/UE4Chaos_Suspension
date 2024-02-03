
#include "MyChaosVehicleMovementComponent.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"

UMyChaosVehicleMovementComponent::UMyChaosVehicleMovementComponent()
    : bIsRaisingSuspension(false),
    bIsLoweringSuspension(false)
{

    for (const FChaosWheelSetup& WheelSetup : WheelSetups)
    {
        UChaosVehicleWheel* NewWheel = CreateDefaultSubobject<UChaosVehicleWheel>(WheelSetup.BoneName);
        Wheels.Add(NewWheel);
    }
}
void UMyChaosVehicleMovementComponent::RaiseSuspension()
{
    bIsRaisingSuspension = true;
    bIsLoweringSuspension = false;
}

void UMyChaosVehicleMovementComponent::LowerSuspension()
{
    bIsRaisingSuspension = false;
    bIsLoweringSuspension = true;
}

void UMyChaosVehicleMovementComponent::StopSuspensionAction()
{
    bIsRaisingSuspension = false;
    bIsLoweringSuspension = false;
}

void UMyChaosVehicleMovementComponent::AdjustSuspensionHeight(float NewHeight)
{
    for (UChaosVehicleWheel* Wheel : Wheels)
    {
        if (Wheel)
        {
            Wheel->SuspensionForceOffset = FVector(0, 0, NewHeight);
        }
    }
}

void UMyChaosVehicleMovementComponent::AdjustSuspensionHeightForWheels(int32 WheelIndex1, int32 WheelIndex2, float NewHeight)
{
    if (!Wheels.IsValidIndex(WheelIndex1) || !Wheels.IsValidIndex(WheelIndex2))
    {
        return;
    }

    Wheels[WheelIndex1]->SuspensionForceOffset = FVector(0, 0, NewHeight);
    Wheels[WheelIndex2]->SuspensionForceOffset = FVector(0, 0, NewHeight);
}

void UMyChaosVehicleMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
    if (PlayerController)
    {
        if (PlayerController->IsInputKeyDown(EKeys::Y))
        {
            RaiseSuspension();
        }
        else if (PlayerController->IsInputKeyDown(EKeys::H))
        {
            LowerSuspension();
        }

        if (PlayerController->IsInputKeyDown(EKeys::Q))
        {
         
            AdjustSuspensionHeightForWheels(3, 5, 35.0f); 
        }
        else if (PlayerController->IsInputKeyDown(EKeys::W))
        {
            
            AdjustSuspensionHeightForWheels(3, 5, 0.0f); 
        }
    }

   
    if (bIsRaisingSuspension)
    {
        AdjustSuspensionHeight(35.0f); 
    }
    else if (bIsLoweringSuspension)
    {
        AdjustSuspensionHeight(0.0f); 
    }
    else
    {    
        StopSuspensionAction();
    }
}
