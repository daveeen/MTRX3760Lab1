# A1 Robot Notes

## What I Added

### Function-based (`robot_function_based.cpp`)

| What | Where | Detail |
|---|---|---|
| `LowSpeed` const | top-level consts | low speed when battery < 80% |
| `SBattery` struct | new struct | holds `double charge` |
| `InitBattery` / `DrainBattery` declarations | function declarations | new prototypes |
| `SBattery battery` + `InitBattery` call | `main()` | declare and init battery |
| `DrainBattery` + dead-battery check + `break` | `main()` loop | drain each cycle, stop if dead |
| `SBattery* apBattery` param to `UpdateRobot` | signature | battery passed in explicitly |
| Low-speed branch in `UpdateRobot` | `UpdateRobot` | uses `LowSpeed` when charge < 80% |
| `InitBattery` / `DrainBattery` implementations | bottom of file | set charge=100, subtract+clamp |

### Object-based (`robot_object_based.cpp`)

| What | Where | Detail |
|---|---|---|
| `LowSpeed` const | top-level consts | low speed when battery < 80% |
| `CBattery` class | new class | `CBattery()`, `GetCharge()`, `Drain()` |
| `mBattery` member | `CRobot` private | `CBattery` instance owned by robot |
| `mBattery.Drain` + charge checks | `CRobot::Update()` | drain, return if dead, pick speed |
| `CBattery` implementation | bottom of file | constructor, getter, drain+clamp |
| `main()` | unchanged | no changes needed |

---

## Things That Still Need Comments

### Function-based

| Location | What needs a comment |
|---|---|
| `UpdateRobot` signature | note that `apBattery` param was added for battery-aware speed selection |
| Low-speed `if` block in `UpdateRobot` | explain the 80% threshold and why LowSpeed is used |
| `DrainBattery` clamp logic | clarify that clamping prevents underflow/overflow, not just "clamp" |

### Object-based

| Location | What needs a comment |
|---|---|
| `CBattery` method declarations | `GetCharge()` and `Drain()` have no doc comments above them |
| misplaced comment in `CRobot::Update()` | `// drain 10% of the battery each cycle` appears *after* the drain call |
| Low-speed `else if` in `CRobot::Update()` | explain the 80% threshold |
| `mBattery` member in `CRobot` | no comment on the member |

---

## Lab Report Answers

### 1. What changed in `main()` when you added the battery?

| Version | Change to `main()` |
|---|---|
| Function-based | Had to declare `SBattery battery`, call `InitBattery`, call `DrainBattery` each cycle, check `battery.charge <= 0` and `break`, and pass `&battery` into `UpdateRobot`. |
| Object-based | Nothing — `main()` was not touched. The battery is fully managed inside `CRobot::Update()`. |

### 2. What does `main()` have to know about the robot's parts?

| Version | What `main()` knows |
|---|---|
| Function-based | Every individual part: `SLineSensor`, `SController`, `SMotor` (×2), and `SBattery`. It must call an init function for each, drain the battery itself, check the charge, and pass all parts into `UpdateRobot` and `ReportRobot`. |
| Object-based | Only `CRobot`. It has no knowledge of the sensor, controller, motors, or battery — it just calls `robot.Update()` and `robot.Report()`. |

### 3. What OOP principle produced this saving?

**Encapsulation.** By bundling data and behaviour inside a class and exposing only a narrow public interface (`Update`, `Report`), the internal parts (battery, sensor, motors) are hidden from callers. `main()` doesn't need to know or manage what's inside the robot.
