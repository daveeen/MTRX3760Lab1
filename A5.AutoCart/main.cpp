//---main.cpp -- Baggage-cart controller demo----------------------------------
// Written by 540853236
#include <iostream>
#include "CController.h"
#include "CDriveMotor.h"
#include "CRFIDScanner.h"

int main()
{
  //User input for speed mode, ensuring it is between 1 and 5
    int mode = 0;
  while( mode < 1 || mode > 5 )
  {
    std::cout << "Enter speed mode (1-5): ";
    std::cin >> mode;
  }

  // Create a controller and adds two subsystems: a drive motor and an RFID scanner.
  CController controller;
  controller.AddSubsystem( new CDriveMotor( mode ) );
  controller.AddSubsystem( new CRFIDScanner() );

  // 5 control cycles reporting each state of the subsystems each step.
  for( int i = 0; i < 5; i++ )
  {
    controller.Step();
    controller.Report();
  }

  return 0;
}
