//---CController.cpp ---------------------------
// Implementation of CController, owns and interacts with CSubsystem objects.
// Written by 540853236
#include "CController.h"

CController::CController() //cTor, init count to 0 and set all subsystems to NULL
  : mCount( 0 )
{
  for( int i = 0; i < 10; i++ )
    mSubsystems[i] = NULL;
}
// virtual dTor, deletes all subsystems that were added to the controller
CController::~CController()
{
  for( int i = 0; i < mCount; i++ )
    delete mSubsystems[i];
}
// AddSubsystem adds a new subsystem to the controller by using pointers. Checking if there is space for a new subsystem through mCount.
void CController::AddSubsystem( CSubsystem* aSub )
{
  if( mCount < 10 )
  {
    mSubsystems[mCount] = aSub;
    mCount++;
  }
}
//Calling Step() to advance each subsytem by one control cycle.
void CController::Step()
{
  for( int i = 0; i < mCount; i++ )
    mSubsystems[i]->Step();
}
// Calling Report() to print the current state of each subsystem.
void CController::Report()
{
  for( int i = 0; i < mCount; i++ )
    mSubsystems[i]->Report();
}
