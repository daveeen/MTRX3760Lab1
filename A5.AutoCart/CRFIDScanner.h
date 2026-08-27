//---CRFIDScanner.h -- An RFID tag scanner subsystem----------------------------
// Written by Partner A
//
// CRFIDScanner models a scanner that reads a baggage tag once per control
// cycle. It tracks how many tags it has scanned in total, and the ID of the
// most recently read tag.
#ifndef _CRFIDSCANNER_H
#define _CRFIDSCANNER_H

#include <string>
#include "CSubsystem.h"

class CRFIDScanner: public CSubsystem
{
  public:
    // Creates a scanner with no tags read yet.
    CRFIDScanner();

    // Step simulates reading a tag: it increments the scan count and
    // generates a new tag ID.
    void Step();

    // Report prints the scan count and the most recently read tag ID.
    void Report();

  private:
    int mScanCount;           // total number of tags scanned so far
    std::string mLastTagID;   // ID of the most recently scanned tag
};

#endif
