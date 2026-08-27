// A clock model, with an alarm clock built via inheritance
//
// This program models a simple clock that keeps a time in minutes and can
// advance, report, and reset it. main() creates one plain clock and steps it
// forward by a minute.
//
// It also models an alarm clock, CAlarmClockInherit, built by inheriting from
// CClock. CClock itself is unmodified; the alarm clock adds only what's new
// (an alarm time, and a way to check if it's ringing) and reuses CClock's
// time-keeping behaviour (Tick, GetTime, Reset, Report) for free.
//

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

//---CAlarmClockInherit----------------------------------------------------------
// CAlarmClockInherit is a CClock that also has an alarm. It inherits all of
// CClock's time-keeping behaviour, and adds only an alarm time and a way to
// check whether it is currently ringing.
class CAlarmClockInherit: public CClock
{
  public:
    // Creates an alarm clock with the given name and starting time, in
    // minutes since midnight.
    CAlarmClockInherit( const std::string& aName, int aStartMinutes );

    // SetAlarm sets the alarm time, in minutes since midnight.
    void SetAlarm( int aAlarmMinutes );

    // IsRinging reports whether the current time has reached the alarm time.
    bool IsRinging();

  private:
    int mAlarmMinutes;          // time at which the alarm should ring
};

//---main----------------------------------------------------------------------
// Creates one plain clock, starts it at 06:59, advances it one minute, and
// reports it. Also creates an alarm clock, sets its alarm, advances it until
// it rings, and reports it.
int main()
{
  CClock clock( "Kitchen", 419 );    // 419 minutes = 06:59
  clock.Tick();
  clock.Report();

  CAlarmClockInherit alarmClock( "Bedroom", 419 );  // 419 minutes = 06:59
  alarmClock.SetAlarm( 425 );                       // ring at 07:05

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

//---CAlarmClockInherit Implementation--------------------------------------------
CAlarmClockInherit::CAlarmClockInherit( const std::string& aName, int aStartMinutes )
  : CClock( aName, aStartMinutes ),       // build the CClock part of the object
    mAlarmMinutes( aStartMinutes )        // no alarm set yet; defaults to start time
{
}
//---
void CAlarmClockInherit::SetAlarm( int aAlarmMinutes )
{
  mAlarmMinutes = aAlarmMinutes;
}
//---
bool CAlarmClockInherit::IsRinging()
{
  return GetTime() >= mAlarmMinutes;      // GetTime() is inherited from CClock
}
