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
    // Creates a drive motor at a given speed mode (1–5).
    // Mode 1 = 10 km/h,  additional modes adds 20 km/h.
    CDriveMotor( int aMode );

    // Step advances the motor by one cycle, moving it forward by mSpeed.
    void Step();

    // Report prints the motor's speed and total distance travelled.
    void Report();

  private:
    double mSpeed;             // speed in km/h
    double mDistanceTravelled; // total distance travelled in km
};

#endif
