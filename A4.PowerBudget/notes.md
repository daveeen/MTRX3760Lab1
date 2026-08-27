# A4 Power Budget — Notes
LED output-> 0W?
## Key Differences Between Version 1 and Version 2

| Feature | Version 1 | Version 2 |
|---|---|---|
| `PowerDraw()` on `CDevice` | Not declared | Pure virtual (`= 0`) |
| How `PowerDraw()` is resolved | At compile time (static dispatch) | At runtime (dynamic dispatch) |
| How devices are stored in `main` | Individual concrete variables | Array of `CDevice*` pointers |
| How devices are iterated | Manual — one block per device | Loop over the array |
| Adding a new device to `main` | Add object + 3 manual lines | Bump `NumDevices` + add pointer to array |
| Polymorphism used | No | Yes |

---

## Virtual Functions (Version 2)

- `virtual int PowerDraw() = 0` in `CDevice` is a **pure virtual function**
- The `= 0` means `CDevice` provides no implementation — it is an **abstract class**
- Any subclass that does not implement `PowerDraw()` cannot be instantiated (compiler error)
- `virtual` tells C++ to resolve the call at **runtime** based on the actual object type, not the pointer type
- This is called **dynamic dispatch**

---

## Polymorphism

- Version 2 stores all devices as `CDevice*` (base class pointers)
- At runtime, each pointer points to a different concrete type (`CMotor`, `CLed`, `CHeater`)
- Calling `devices[i]->PowerDraw()` automatically calls the correct subclass version
- One call site — multiple possible behaviours — this is **polymorphism**

---

## What Was Added — CHeater

### Class Structure (same in both versions)

| Member | Type | Purpose |
|---|---|---|
| `CHeater(const std::string& aName)` | Constructor | Initialises base `CDevice` and sets `mHeatSetting = 0` |
| `SetHeatSetting(int aSetting)` | Method | Sets the heat level |
| `PowerDraw()` | Method | Returns `mHeatSetting * 5` if on, else `0` |
| `mHeatSetting` | `int` (private) | Stores the current heat setting |

### Power Formula

```
PowerDraw = mHeatSetting * 5   (when on)
PowerDraw = 0                  (when off)
```

Example: `SetHeatSetting(20)` → 100 W

### Changes Made to main()

| Change | Version 1 | Version 2 |
|---|---|---|
| Create heater object | `CHeater centralheater("CentralHeater")` | Same |
| Turn on | `centralheater.TurnOn()` | Same |
| Set heat | `centralheater.SetHeatSetting(20)` | Same |
| Report draw | Added manual print + `total +=` block | Bump `NumDevices` to `3`, add `&centralheater` to array |

---

## Expected Output (Both Versions)

```
DriveMotor: 60 W
StatusLed: 0 W
CentralHeater: 100 W
Total: 160 W
```

Note: StatusLed outputs 0 W because `TurnOn()` was never called on it — this is intentional from the starter code.

---

## Comment Reminders

- [ ] Add `//---CHeater---` section header comment above the `CHeater` class declaration (both files)
- [ ] Add a brief description comment under the header explaining what `CHeater` is (both files)
- [ ] Add `//---CHeater Implementation---` section header above the implementation at the bottom (both files)
- [ ] Add inline comments on `SetHeatSetting` and `PowerDraw` declarations in the class body, matching the style of `CMotor` and `CLed`

---

## Report Questions

**1. What did you have to change in each version to add the heater?**

*Version 1:* Added the `CHeater` class declaration and implementation, then manually added three lines to `main` to create the object, call `TurnOn()`/`SetHeatSetting()`, and print its power draw.
*Version 2:* Added the same `CHeater` class declaration and implementation, then in `main` created the object, incremented `NumDevices` from 2 to 3, and added `&centralheater` to the `devices[]` array — the loop handled the rest automatically.

**2. Which version was easier to extend, and what specifically made it easier?**

Version 2 was easier to extend because the loop in `main` already handled printing and totalling for any device in the array, so adding the heater only required bumping the device count and adding one pointer — no new print or accumulation logic needed.

**3. What is the name of the object-oriented principle behind that difference?**

The principle is **polymorphism** — specifically, runtime polymorphism via virtual functions, which allows `main` to call `PowerDraw()` through a base-class pointer and have the correct subclass implementation execute automatically.
