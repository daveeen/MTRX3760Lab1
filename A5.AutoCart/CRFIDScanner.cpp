//---CRFIDScanner.cpp -- Implementation of CRFIDScanner-------------------------
// Written by Partner A
#include <iostream>
#include <string>
#include "CRFIDScanner.h"

// The constructor starts the scan count at zero and sets an initial
// placeholder tag ID, using the member initialiser list.
CRFIDScanner::CRFIDScanner()
  : CSubsystem( "RFIDScanner" ), mScanCount( 0 ),
    mLastTagID( "NONE" )
{
}
//-------------------------------------------------------------------------
// Step simulates one scan cycle: the scan count increases, and a new tag ID
// is generated to represent whatever tag was just read.
void CRFIDScanner::Step()
{
  ++mScanCount;
  mLastTagID = "TAG" + std::to_string( mScanCount );
}
//-------------------------------------------------------------------------
// Report prints the total scan count and the most recently read tag ID.
void CRFIDScanner::Report()
{
  std::cout << "[" << mName << "] scans: " << mScanCount
            << ", last tag: " << mLastTagID << std::endl;
}
