#pragma once

#include "CoreMinimal.h"
#include "ChaosWheeledVehicleMovementComponent.h"
#include "ChaosVehicleWheel.h"
#include "MyChaosVehicleMovementComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class UE4CHAOS_VEHICLERIG_API UMyChaosVehicleMovementComponent : public UChaosWheeledVehicleMovementComponent
{
    GENERATED_BODY()

public:
    UMyChaosVehicleMovementComponent();

    UFUNCTION(BlueprintCallable, Category = "Vehicle Suspension")
        void RaiseSuspension();

    UFUNCTION(BlueprintCallable, Category = "Vehicle Suspension")
        void LowerSuspension();

    UFUNCTION(BlueprintCallable, Category = "Vehicle Suspension")
        void StopSuspensionAction();

    UFUNCTION(BlueprintCallable, Category = "Vehicle Suspension")
        void AdjustSuspensionHeight(float NewHeight);

    UFUNCTION(BlueprintCallable, Category = "Vehicle Suspension")
        void AdjustSuspensionHeightForWheels(int32 WheelIndex1, int32 WheelIndex2, float NewHeight);

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Vehicle Suspension")
        float SuspensionAdjustmentSpeed;

    bool bIsRaisingSuspension;
    bool bIsLoweringSuspension;

    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
