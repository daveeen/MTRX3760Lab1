# MTRX3760 Lab 1 — Baggage Cart Controller

A simple OOP baggage cart simulation in C++. A controller drives two subsystems — a drive motor and an RFID scanner — through 5 control cycles of 30 minutes each.

## Files

| File | Description |
|---|---|
| `CSubsystem.h` | Abstract base class defining the `Step()`/`Report()` interface |
| `CDriveMotor.h/.cpp` | Drive motor subsystem — tracks speed and distance travelled |
| `CRFIDScanner.h/.cpp` | RFID scanner subsystem — tracks scan count and last tag read |
| `CController.h/.cpp` | Controller that owns and drives any number of subsystems |
| `main.cpp` | Entry point — takes user input, runs simulation |

## Build

```
g++ main.cpp CController.cpp CDriveMotor.cpp CRFIDScanner.cpp -o cart
```

## Run

```
./cart
```

Prompts for a speed mode (1–5):

| Mode | Speed |
|---|---|
| 1 | 10 km/h |
| 2 | 30 km/h |
| 3 | 50 km/h |
| 4 | 70 km/h |
| 5 | 90 km/h |

## Example Output

```
Enter speed mode (1-5): 2
[DriveMotor] speed: 30 km/h, distance travelled: 15 km
[RFIDScanner] scans: 1, last tag: TAG1
[DriveMotor] speed: 30 km/h, distance travelled: 30 km
[RFIDScanner] scans: 2, last tag: TAG2
...
```
