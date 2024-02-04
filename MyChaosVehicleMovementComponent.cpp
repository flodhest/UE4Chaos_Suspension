#include "MyChaosVehicleMovementComponent.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"

UMyChaosVehicleMovementComponent::UMyChaosVehicleMovementComponent()
    : bIsRaisingSuspension(false),
    bIsLoweringSuspension(false),
    SuspensionAdjustmentSpeed(5.0f)
{
    for (const FChaosWheelSetup& WheelSetup : WheelSetups)
    {
        UChaosVehicleWheel* NewWheel = CreateDefaultSubobject<UChaosVehicleWheel>(WheelSetup.BoneName);
        if (NewWheel)
        {
            Wheels.Add(NewWheel);
        }
        else
        {
            UE_LOG(LogTemp, Error, TEXT("Failed to create wheel for bone %s"), *WheelSetup.BoneName.ToString());
        }
    }
}

void UMyChaosVehicleMovementComponent::AdjustSuspension(float TargetHeight)
{
    for (UChaosVehicleWheel* Wheel : Wheels)
    {
        if (Wheel)
        {
            Wheel->SuspensionForceOffset = FMath::Lerp(Wheel->SuspensionForceOffset, FVector(0, 0, TargetHeight), SuspensionAdjustmentSpeed * GetWorld()->GetDeltaSeconds());
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("A wheel is null while adjusting suspension height."));
        }
    }
}

void UMyChaosVehicleMovementComponent::RaiseSuspension()
{
    bIsRaisingSuspension = true;
    bIsLoweringSuspension = false;

    UE_LOG(LogTemp, Warning, TEXT("Raise Suspension key pressed"));
}

void UMyChaosVehicleMovementComponent::LowerSuspension()
{
    bIsRaisingSuspension = false;
    bIsLoweringSuspension = true;

    UE_LOG(LogTemp, Warning, TEXT("Lower Suspension key pressed"));
}

void UMyChaosVehicleMovementComponent::StopSuspensionAction()
{
    bIsRaisingSuspension = false;
    bIsLoweringSuspension = false;
}

void UMyChaosVehicleMovementComponent::AdjustSuspensionHeight(float NewHeight)
{
    AdjustSuspension(NewHeight);
}

void UMyChaosVehicleMovementComponent::AdjustSuspensionHeightForWheels(int32 WheelIndex1, int32 WheelIndex2, float NewHeight)
{
    if (Wheels.IsValidIndex(WheelIndex1) && Wheels.IsValidIndex(WheelIndex2))
    {
        Wheels[WheelIndex1]->SuspensionForceOffset = FMath::Lerp(Wheels[WheelIndex1]->SuspensionForceOffset, FVector(0, 0, NewHeight), SuspensionAdjustmentSpeed * GetWorld()->GetDeltaSeconds());
        Wheels[WheelIndex2]->SuspensionForceOffset = FMath::Lerp(Wheels[WheelIndex2]->SuspensionForceOffset, FVector(0, 0, NewHeight), SuspensionAdjustmentSpeed * GetWorld()->GetDeltaSeconds());
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("Invalid wheel indices (%d, %d) while adjusting suspension height for wheels."), WheelIndex1, WheelIndex2);
    }
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
        AdjustSuspension(35.0f);
    }
    else if (bIsLoweringSuspension)
    {
        AdjustSuspension(0.0f);
    }
    else
    {
        StopSuspensionAction();
    }
}
