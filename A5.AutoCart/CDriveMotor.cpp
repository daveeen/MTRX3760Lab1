//---CDriveMotor.cpp -- Implementation of CDriveMotor---------------------------
// Written by Partner A
#include <iostream>
#include "CDriveMotor.h"

// 30 minutes per control cycle.
const double CDriveMotor::CYCLE_TIME_H = 0.5;

// Setting the speed based on the user input mode
// initializing distance travelled to 0
CDriveMotor::CDriveMotor( int aMode )
  : CSubsystem( "DriveMotor" ), mSpeed( 10.0 + ( aMode - 1 ) * 20.0 ),
    mDistanceTravelled( 0.0 )
{
}
//-------------------------------------------------------------------------
void CDriveMotor::Step()
{
  mDistanceTravelled += mSpeed * CYCLE_TIME_H;
}
//-------------------------------------------------------------------------
void CDriveMotor::Report()
{
  std::cout << "[" << mName << "] speed: " << mSpeed << " km/h"
            << ", distance travelled: " << mDistanceTravelled << " km" << std::endl;
}
