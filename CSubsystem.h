//---CSubsystem.h -- Abstract interface for controller subsystems--------------
// Written by Partner A
//
// CSubsystem defines the common interface that every subsystem on the
// baggage cart must implement. The controller (built by Partner B) talks to
// every subsystem only through this interface, so new subsystem types can be
// added later without the controller needing to change.
#ifndef _CSUBSYSTEM_H
#define _CSUBSYSTEM_H

class CSubsystem
{
  public:
    // Virtual destructor: required so that deleting a subsystem through a
    // CSubsystem* correctly runs the derived class's destructor.
    virtual ~CSubsystem() {}

    // Step advances the subsystem by one control cycle, updating its
    // internal state.
    virtual void Step() = 0;

    // Report prints the subsystem's current state to std::cout.
    virtual void Report() = 0;
};

#endif
