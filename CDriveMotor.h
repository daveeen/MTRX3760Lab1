//---CDriveMotor.h -- A drive motor subsystem-----------------------------------
// Written by Partner A
//
// CDriveMotor models the cart's drive motor. It holds a constant speed
// setting, and accumulates distance travelled as the controller steps it
// through successive control cycles.
#ifndef _CDRIVEMOTOR_H
#define _CDRIVEMOTOR_H

#include "CSubsystem.h"

class CDriveMotor: public CSubsystem
{
  public:
    // Creates a drive motor with a given constant speed, in units per cycle.
    CDriveMotor( double aSpeed );

    // Step advances the motor by one cycle, moving it forward by mSpeed.
    void Step();

    // Report prints the motor's speed and total distance travelled.
    void Report();

  private:
    double mSpeed;               // constant speed, in units per cycle
    double mDistanceTravelled;   // total distance accumulated so far
};

#endif
