#include "SteppingAction.hh"
#include "RunAction.hh"

#include <G4Step.hh>
#include <G4Electron.hh>

SteppingAction::SteppingAction(RunAction *runAction)
    : fRunAction(runAction)
{
}

void SteppingAction::UserSteppingAction(const G4Step *aStep)
{
  // Task 4a.2: Get the volume where the step starts (the length is inside).
  //G4VPhysicalVolume* volume= ...
  G4VPhysicalVolume *volume = aStep->GetPreStepPoint()->GetTouchable()->GetVolume();

  //   Take care, because this volume might not be available: be sure that the pointer
  //   "volume" is non-NULL, otherwise any volume->Get... would cause a crash.

  // Task 4a.2: If the volume exists and has a proper name (absorber0), use the appropriate
  //   run action method to accumulate the track length. Apply this
  //   only for electrons.
  // Getting the total track length of each run only for the absorber0 
  if (volume && volume->GetName() == "absorber0")
  {
    auto parDef = aStep->GetTrack()->GetParticleDefinition();
    // Get step length only for electrons

    if (parDef == G4Electron::Electron())
    {
      // need to call AddTrackLength()
      fRunAction->AddTrackLength(aStep->GetStepLength());
    }
  }
}