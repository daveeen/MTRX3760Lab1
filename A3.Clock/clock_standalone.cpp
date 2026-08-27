// A clock model, with a standalone alarm clock
//
// This program models a simple clock that keeps a time in minutes and can
// advance, report, and reset it. main() creates one plain clock and steps it
// forward by a minute.
//
// It also models an alarm clock, CAlarmClockStandalone, built as a brand-new
// class with no relation to CClock. It repeats CClock's time-keeping
// behaviour internally, and adds the ability to set an alarm and check
// whether it is ringing.
//
// Copyright (c) Donald Dansereau, 2026

//--Includes-------------------------------------------------------------------
#include <iostream>
#include <string>

//---CClock--------------------------------------------------------------------
// A CClock keeps a time, measured in whole minutes, and can advance it one
// minute at a time, report it, and reset it to where it started.
class CClock
{
  public:
    // Creates a clock with the given name and starting time, in minutes
    // since midnight.
    CClock( const std::string& aName, int aStartMinutes );

    // Tick advances the clock by one minute.
    void Tick();

    // GetTime returns the current time, in minutes since midnight.
    int GetTime();

    // Reset returns the clock to its starting time.
    void Reset();

    // Report prints the clock's name and current time as HH:MM.
    void Report();

  private:
    std::string mName;          // the clock's label, e.g. "Kitchen"
    int mStartMinutes;          // the time the clock was initialised to
    int mCurrentMinutes;        // current time, in minutes since midnight
};

//---CAlarmClockStandalone-------------------------------------------------------
// CAlarmClockStandalone is a brand-new class, unrelated to CClock. It keeps
// its own time in whole minutes, exactly duplicating CClock's time-keeping
// behaviour, and adds the ability to set an alarm time and check whether the
// alarm is currently ringing.
class CAlarmClockStandalone
{
  public:
    // Creates an alarm clock with the given name and starting time, in
    // minutes since midnight.
    CAlarmClockStandalone( const std::string& aName, int aStartMinutes );

    // Tick advances the clock by one minute.
    void Tick();

    // GetTime returns the current time, in minutes since midnight.
    int GetTime();

    // Reset returns the clock to its starting time.
    void Reset();

    // Report prints the clock's name and current time as HH:MM.
    void Report();

    // SetAlarm sets the alarm time, in minutes since midnight.
    void SetAlarm( int aAlarmMinutes );

    // IsRinging reports whether the current time has reached the alarm time.
    bool IsRinging();

  private:
    std::string mName;          // the clock's label, e.g. "Kitchen"
    int mStartMinutes;          // the time the clock was initialised to
    int mCurrentMinutes;        // current time, in minutes since midnight
    int mAlarmMinutes;          // time at which the alarm should ring
};

//---main----------------------------------------------------------------------
// Creates one plain clock, starts it at 06:59, advances it one minute, and
// reports it. Also creates a standalone alarm clock, sets its alarm, advances
// it until it rings, and reports it.
int main()
{
  CClock clock( "Kitchen", 419 );    // 419 minutes = 06:59
  clock.Tick();
  clock.Report();

  CAlarmClockStandalone alarmClock( "Bedroom", 419 );  // 419 minutes = 06:59
  alarmClock.SetAlarm( 425 );                          // ring at 07:05

  while( !alarmClock.IsRinging() )
    alarmClock.Tick();

  std::cout << "Alarm ringing: ";
  alarmClock.Report();

  return 0;
}

//---CClock Implementation-----------------------------------------------------
CClock::CClock( const std::string& aName, int aStartMinutes )
  : mName( aName ),
    mStartMinutes( aStartMinutes ),
    mCurrentMinutes( aStartMinutes )
{
}
//---
void CClock::Tick()
{
  ++mCurrentMinutes;
}
//---
int CClock::GetTime()
{
  return mCurrentMinutes;
}
//---
void CClock::Reset()
{
  mCurrentMinutes = mStartMinutes;
}
//---
void CClock::Report()
{
  int hours = ( mCurrentMinutes / 60 ) % 24;
  int minutes = mCurrentMinutes % 60;
  std::cout << mName << " "
            << ( hours < 10 ? "0" : "" ) << hours << ":"
            << ( minutes < 10 ? "0" : "" ) << minutes << std::endl;
}

//---CAlarmClockStandalone Implementation---------------------------------------
CAlarmClockStandalone::CAlarmClockStandalone( const std::string& aName, int aStartMinutes )
  : mName( aName ),
    mStartMinutes( aStartMinutes ),
    mCurrentMinutes( aStartMinutes ),
    mAlarmMinutes( aStartMinutes )        // no alarm set yet; defaults to start time
{
}
//---
void CAlarmClockStandalone::Tick()
{
  ++mCurrentMinutes;
}
//---
int CAlarmClockStandalone::GetTime()
{
  return mCurrentMinutes;
}
//---
void CAlarmClockStandalone::Reset()
{
  mCurrentMinutes = mStartMinutes;
}
//---
void CAlarmClockStandalone::Report()
{
  int hours = ( mCurrentMinutes / 60 ) % 24;
  int minutes = mCurrentMinutes % 60;
  std::cout << mName << " "
            << ( hours < 10 ? "0" : "" ) << hours << ":"
            << ( minutes < 10 ? "0" : "" ) << minutes << std::endl;
}
//---
void CAlarmClockStandalone::SetAlarm( int aAlarmMinutes )
{
  mAlarmMinutes = aAlarmMinutes;
}
//---
bool CAlarmClockStandalone::IsRinging()
{
  return mCurrentMinutes >= mAlarmMinutes;
}
