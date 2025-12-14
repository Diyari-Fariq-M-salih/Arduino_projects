# Arduino Projects – Learning, Experiments, and Robotics Notes

This repository is a **collection of Arduino-based projects** focused on:
- Electronics fundamentals
- Embedded programming
- Robotics and motion control
- Display systems
- System-level thinking (mechanical + electrical + software)

The projects are not just “builds”, but can also be used as **study notes**, **revision material**, and **reference implementations** for Arduino, sensors, motors, and control logic.

---

## Repository Structure

```text
Arduino_projects-main/
├── 32x8-LED-Matrix-Display-19072025/
│   └── 32x8-LED-Matrix-Display-19072025.ino
│
├── Mecanum_omi_directional_wheel_24072025/
│   ├── Arduino code & references
│   ├── Schematics (PDF)
│   ├── Mechanical designs (STL, images)
│   ├── KiCad PCB files
│   └── Motor shield library
│
├── Nano_wireless_drone_24072025/
│   ├── Arduino drone references
│   ├── Wiring diagrams
│   ├── Frame design files
│   └── Notes and parts lists
│
└── .gitattributes
```

---

## 1. 32×8 LED Matrix Display

### What This Project Does
This project controls a **32×8 LED matrix**, allowing text or patterns to be displayed by rapidly turning LEDs on and off.

### Core Concept: Multiplexing

Instead of powering all LEDs at once, the Arduino:
- Activates **one row at a time**
- Turns on the correct columns
- Switches rows very quickly

Because this happens faster than human vision can detect, it *appears* that the entire display is on.

### Analogy
Think of a **flipbook animation**:
- Only one page is visible at a time
- But flipping fast enough creates smooth motion

### Timing Equation
The refresh rate must exceed human flicker perception:

```
Refresh Rate ≥ 60 Hz
```

If there are 8 rows:

```
Row Update Frequency ≥ 8 × 60 = 480 Hz
```

### What You Learn
- Digital I/O control
- Timing & delays
- Human visual perception limits
- Efficient use of limited pins

---

## 2. Mecanum Omni-Directional Wheel Robot

### What This Project Does
This project builds a **mecanum wheel robot** capable of:
- Moving forward / backward
- Strafing left / right
- Rotating in place
- Any combination of the above

### Why Mecanum Wheels Are Special
Each wheel has rollers at a **45° angle**, allowing force to be decomposed into X and Y components.

### Force Decomposition

For a wheel force \( F \):

```
Fx = F · cos(45°)
Fy = F · sin(45°)
```

### Motion Mapping

| Desired Motion | Wheel Behavior |
|---------------|----------------|
| Forward | All wheels same speed |
| Sideways | Wheels spin in opposing diagonal pairs |
| Rotate | Left and right sides opposite |

### Analogy
Imagine **four people pushing a table**:
- Same direction → forward motion
- Sideways pushes → lateral motion
- Opposite pushes → rotation

### What You Learn
- Vector math in robotics
- Motor coordination
- Differential control
- Applied trigonometry

---

## 3. Nano Wireless Drone (Quadcopter)

### What This Project Does
This is a **nano quadcopter design study**, covering:
- Frame design
- Wiring diagrams
- Motor and ESC layout
- Arduino-based control concepts

### Lift Equation

For stable flight:

```
Total Thrust ≥ Weight
```

With four motors:

```
Thrust_per_motor ≥ Weight / 4
```

### Control Axes

| Axis | Control Method |
|----|----------------|
| Pitch | Front vs back motors |
| Roll | Left vs right motors |
| Yaw | Opposing motor speeds |

### Analogy
Like **balancing on four fingers**:
- Press harder on one side → tilt
- Equal pressure → hover

### What You Learn
- Control systems thinking
- Force balance
- Embedded safety concepts

---

## Using This Repository as Notes

### Suggested Study Method
1. Choose one project
2. Read the code and schematics
3. Rewrite concepts in your own words
4. Modify parameters and observe results

### Note-Taking Tips
- Add a `NOTES.md` per project
- Comment equations in `.ino` files
- Draw block diagrams

### Questions to Ask
- Why is this delay used?
- What happens if timing changes?
- How does software map to hardware?

---

## Requirements

- Arduino IDE
- Arduino Uno / Nano
- Motor drivers / shields
- Basic electronics knowledge

---

## Learning Outcomes

By working through this repository, you gain:
- Practical Arduino experience
- Electronics intuition
- Robotics motion understanding
- Math-to-hardware insight

---

## Final Note

This repository functions as a **personal engineering notebook** where theory meets hardware.
