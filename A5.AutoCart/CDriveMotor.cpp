//---CDriveMotor.cpp -- Implementation of CDriveMotor---------------------------
// Written by Partner A
#include <iostream>
#include "CDriveMotor.h"

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
  mDistanceTravelled += mSpeed * 0.5;  // 30 minutes per cycle (0.5 hours)
}
//-------------------------------------------------------------------------
void CDriveMotor::Report()
{
  std::cout << "[" << mName << "] speed: " << mSpeed << " km/h"
            << ", distance travelled: " << mDistanceTravelled << " km" << std::endl;
}
