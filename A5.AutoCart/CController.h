//---CController.h -- Controller that drives a collection of subsystems--------
// Written by 540853236

//CController class is managing a bunch of subsystems. It has arrays of pointers to the subsystems and a count for each subsystem.
// The controller can add subsystems, advance them by one control cycle, and report their current state.
// Controller owns subsystems so it is responsible for clean up when controller gets destroyed.
#ifndef _CCONTROLLER_H
#define _CCONTROLLER_H
#include "CSubsystem.h"

class CController
{
  public:
    CController();

    ~CController();

    void AddSubsystem( CSubsystem* aSub );

    void Step();

    void Report();

  private:
    static const int MAX_SUBSYSTEMS = 10;
    CSubsystem* mSubsystems[MAX_SUBSYSTEMS];
    int mCount;
};

#endif
