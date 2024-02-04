**Chaos Vehicle Movement Component**

- **Overview:**
  - Extends functionality of `UChaosWheeledVehicleMovementComponent`.
  - Enables control over the vehicle's suspension system with dynamic adjustments during runtime.

- **Key Features:**
  - **Class Definition:**
    - Inherits from `UChaosWheeledVehicleMovementComponent`.
    - Functions and variables for suspension control.
    - Adjustable suspension speed for responsiveness.
    - Flags for dynamic suspension raise/lower actions.
    - Array of wheels for suspension management.

  - **Constructor:**
    - Instantiates wheel objects according to pre-defined configurations for the suspension system.
    - Implements error logging for wheel creation issues.

  - **Function Implementations:**
    - **AdjustSuspension:**
      - Adjustment of suspension height for all wheels.

    - **RaiseSuspension and LowerSuspension:**
      - Flags for initiating suspension raise/lower actions.
      - Logs key presses for user interaction insight.

    - **StopSuspensionAction:**
      - Resets flags for suspension actions.

    - **AdjustSuspensionHeight and AdjustSuspensionHeightForWheels:**
      - Customization of suspension height for all or specific wheel pairs.

    - **TickComponent:**
      - Handles key inputs, adjusts suspension dynamically.
      - Responds to Y and H keys for raising/lowering suspension.
      - Responds to Q and W keys for raising/lowering specific wheelpairs(boogie).
