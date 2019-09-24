#include "ActionInitialization.hh"
#include "PrimaryGeneratorAction.hh"
//! Optional user classes
#include "RunAction.hh"
#include "StackingAction.hh"
#include "SteppingAction.hh"
// Task 5.2: Include the header for EventAction
//#include "EventAction.hh"
void ActionInitialization::Build() const
{
    SetUserAction(new PrimaryGeneratorAction());
    /* These two classes are used only in task3-4.*/ 
    RunAction* theRunAction = new RunAction();
    SetUserAction(theRunAction);
    SetUserAction(new StackingAction(theRunAction));

    SteppingAction* theSteppingAction = new SteppingAction(theRunAction);
    SetUserAction(theSteppingAction);
    //Task 5.2: Add a properly initialized instance of EventAction
      //EventAction* theEventAction = new ..........;
      //SetUserAction(theEvent.....);
}

void ActionInitialization::BuildForMaster() const
{
  // By default, don't do anything. This applies only in MT mode:
  SetUserAction(new RunAction());
}
