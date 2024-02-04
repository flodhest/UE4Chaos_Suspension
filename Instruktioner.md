
### Steg 1: Lägg till C++-koden i projektet

1. Kopiera båda filerna till mappen Source/UE4Chaos_VehicleRig.

### Steg 2: Generera projektfiler

1. Högerklicka på projektfilen UE4Chaos_VehicleRig.uproject.
2. Klicka på "Generate Visual studio project files".

### Steg 3: Bygg projektet

1. Öppna Visual Studio 2019(Obs! Måste vara 2019).
2. Bygg projektet genom att högerklicka på Solution -> "Build".

### Steg 4: Lägg till komponenten i Blueprint

1. Öppna Blueprinten `BP_Volvo_Truck_EV_Chassi` i Unreal Engine Editor.
2. I Components-fönstret, klicka på "Add Component" och sök efter `MyChaosVehicleMovementComponent`.
3. Välj komponenten och den kommer att läggas till i din Blueprint.

**OBS! Följande sektion kräver TEST, öppna Output log för att uppmärksamma fel**

### Steg 5: Justera komponentens inställningar

1. Med Blueprinten öppen, markera den nyss tillagda komponenten.
2. I detaljfönstret till höger kan du justera inställningar som `SuspensionAdjustmentSpeed` och andra parametrar.
3. Observera att knapparna Y och H samt Q och W är bundnda till funktionerna. Ändra i .cpp filen till önskvärda knappar.

### Steg 6: Kör projektet

1. Spara Blueprinten och stäng Blueprint-fönstret.
2. Tryck på "Play" för att köra ditt projekt och observera de dynamiska justeringarna i fordonets fjädring baserat på användarinput.

**Antecka eventuella fel som underlag för refaktorering**



