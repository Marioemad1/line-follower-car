# 🤖 Line Follower Robot Using Arduino Nano, L298N & IR Sensors

This project demonstrates a fully functional **line follower robot** controlled by an **Arduino Nano**, using **IR sensors for line detection** and an **L298N motor driver** to control two DC motors. The robot follows a black line on a white surface using simple logic and PWM-based motor control.

It’s a great beginner-friendly project to understand:
- 🔍 Sensor-based control
- ⚙️ Motor driving using an H-Bridge (L298N)
- 💡 Real-time decision-making logic

---

## 📷 Project Photos & Simulation

> Replace the placeholders below with actual images from your circuit and simulation.

![Proteus Schematic](![image](https://github.com/user-attachments/assets/26733727-50bb-46ba-91f5-9f2b37d93f60)
)

![Robot Car Photo](./images/robot_car_photo.jpg)

---

## 🧠 How It Works

The robot uses **two IR sensors** to detect whether it is over the black line or the white background. The sensor outputs are read by the Arduino Nano, which then determines:

- If both sensors detect white → go **forward**
- If left detects black, right detects white → turn **right**
- If right detects black, left detects white → turn **left**
- If both detect black (off-line) → **stop**

The Arduino uses **PWM signals** to control motor speed via the **ENA/ENB** pins of the **L298N** motor driver.

---

## 🧱 Components Used

| Component         | Quantity | Description                       |
|------------------|----------|-----------------------------------|
| Arduino Nano     | 1        | Main microcontroller              |
| L298N Motor Driver | 1        | Drives 2 DC motors                |
| IR Sensors       | 2        | Line detection (left and right)   |
| DC Motors        | 2        | Drive left and right wheels       |
| 12V Battery      | 1        | Power for motors and driver       |
| Wires & Chassis  | As needed | For building the robot            |
| Proteus 8+       | -        | Simulation environment            |

---

## 📡 Wiring Diagram (Mermaid)

```mermaid
graph TD
    A[🔋 12V Battery] --> L298VCC[L298N VCC]
    A --> ArduinoVin[Arduino Nano VIN]

    subgraph Arduino Nano
        D2[Pin D2] --> IR1[IR Sensor Left OUT]
        D3[Pin D3] --> IR2[IR Sensor Right OUT]
        D7[Pin D7] --> IN4
        D8[Pin D8] --> IN3
        D9[Pin D9] --> IN2
        D10[Pin D10] --> IN1
        D11[Pin D11 - PWM] --> ENA
        D12[Pin D12 - PWM] --> ENB
        GND_Nano[GND] --> CommonGND
    end

    subgraph IR Sensors
        IR1 --> VCC1[5V]
        IR2 --> VCC2[5V]
        IR1 --> GND1[GND]
        IR2 --> GND2[GND]
    end

    subgraph L298N Driver
        IN1 --> L298IN1
        IN2 --> L298IN2
        IN3 --> L298IN3
        IN4 --> L298IN4
        ENA --> L298ENA
        ENB --> L298ENB
        L298ENA --> M1[⬅️ Left Motor]
        L298ENB --> M2[➡️ Right Motor]
        L298GND[GND] --> CommonGND
    end

    CommonGND --> L298GND
    CommonGND --> IR_GND[IR Sensors GND]
```
## 🧠 Functional Flowchart (Mermaid)

```mermaid
flowchart TD
    Start --> ReadIR
    ReadIR --> CheckCase

    CheckCase -->|Left = 1, Right = 1| Forward
    CheckCase -->|Left = 1, Right = 0| TurnRight
    CheckCase -->|Left = 0, Right = 1| TurnLeft
    CheckCase -->|Left = 0, Right = 0| Stop

    Forward --> ReadIR
    TurnLeft --> ReadIR
    TurnRight --> ReadIR
    Stop --> ReadIR


```
