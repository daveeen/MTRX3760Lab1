//---CDriveMotor.cpp -- Implementation of CDriveMotor---------------------------
// Written by Partner A
#include <iostream>
#include "CDriveMotor.h"

// The constructor sets the motor's speed and starts distance travelled at
// zero, using the member initialiser list.
CDriveMotor::CDriveMotor( double aSpeed )
  : mSpeed( aSpeed ),
    mDistanceTravelled( 0.0 )
{
}
//-------------------------------------------------------------------------
// Step increases the distance travelled by the motor's speed, modelling one
// control cycle of forward motion.
void CDriveMotor::Step()
{
  mDistanceTravelled += mSpeed;
}
//-------------------------------------------------------------------------
// Report prints the motor's speed and the distance accumulated so far.
void CDriveMotor::Report()
{
  std::cout << "[DriveMotor] speed: " << mSpeed
            << ", distance travelled: " << mDistanceTravelled << std::endl;
}
