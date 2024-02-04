
### Steg 1: Lägg till C++-koden i projektet

1. Kopiera båda filerna till mappen Source/UE4Chaos_VehicleRig.

### Steg 2: Generera projektfiler

1. Högerklicka på projektfilen UE4Chaos_VehicleRig.uproject.
2. Klicka på "Generate Visual studio project files".

### Steg 3: Bygg projektet

1. Öppna Visual Studio 2019(Obs! Måste vara 2019).
2. Bygg projektet genom att högerklicka på Solution -> "Build".

### Steg 4: Lägg till komponenten i Blueprint

1. Kompilera Unrealprojektet för att integrera och konvertera C++ kklassen till en komponent.
2. Öppna Blueprinten `BP_Volvo_Truck_EV_Chassi` i Unreal Engine Editor.
3. I Components-fönstret, klicka på "Add Component" och sök efter `MyChaosVehicleMovementComponent`.
4. Välj komponenten och den kommer att läggas till i din Blueprint.

**OBS! Följande sektion kräver TEST, öppna Output log för att uppmärksamma fel**

### Steg 5: Justera komponentens inställningar

1. Med Blueprinten öppen, markera den nyss tillagda komponenten.
2. I detaljfönstret till höger kan du justera inställningar som `SuspensionAdjustmentSpeed` och andra parametrar.
3. Observera att knapparna Y och H samt Q och W är bundnda till funktionerna. Ändra i .cpp filen till önskvärda knappar.

### Steg 6: Kör projektet

1. Spara Blueprinten och stäng Blueprint-fönstret.
2. Tryck på "Play" för att köra ditt projekt och observera de dynamiska justeringarna i fordonets fjädring baserat på användarinput.

**Antecka eventuella fel som underlag för refaktorering**




-----------------------------------------



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
