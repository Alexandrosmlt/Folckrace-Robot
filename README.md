# Folckrace Robot

## 1. Project Overview

#### This is a special autonomous robot made for Folkrace (which is a robot competition centered around autonomous racing and steering skills). My design features 4 HS DC Motors paired with 5 ToF sensors, providing precise feedback in real time.

## 1.1 Why i am building this project

#### I am making this project to get real-life experience in developing complex systems and working with fast robotics controls. This project is great to help me improve my skills in putting together microcontrollers, motor drivers and sensors all to create a autonomous and competitive robot.

## 2. Hardware and Design

### 2.1 3D Visualization

* **Front View**:

![Front](/photos/Front.png)
* **Rear View**:

![Rear](/photos/Rear.png)
* **Right View**:

![Right](/photos/Right.png)
* **Left View**:

![Left](/photos/Left.png)
* **Final View**:

![Final](/photos/Final.png)


### 2.2 Custom PCB 

* **PCB Top View**:

![Top](/photos/pcb/PcbTop.png)

* **PCB Bottom View**:

![Bottom](/photos/pcb/PcbBottom.png)

* **PCB Schematic**:

![Schematic](/photos/pcb/PcbScmtc.png)


### 2.3 Wiring Diagram

* **Wiring diagram**:

![Wires!!](/photos/pcb/WiringDiagram.png)

### 2.4 Pinout

#### 1. ToF Sensor Connections (5 Sensors)

>| Component | Function | ESP32 Pin |
>| :--- | :--- | :--- |
>| **I2C Bus** | Data Line (SDA) | **GPIO 21** |
>| **I2C Bus** | Clock Line (SCL) | **GPIO 22** |
>| ToF 1 | XSHUT Pin | **GPIO 33** |
>| ToF 2 | XSHUT Pin | **GPIO 32** |
>| ToF 3 | XSHUT Pin | **GPIO 27** |
>| ToF 4 | XSHUT Pin | **GPIO 26** |
>| ToF 5 | XSHUT Pin | **GPIO 25** |

#### Motor Driver (MDD3A)

>| MDD3A | Motor | Function | ESP32 Pin |
>| :--- | :--- | :--- | :--- |
>| M1A | Motor 1 | Forward Speed | **GPIO 19** |
>| M1B | Motor 1 | Reverse Speed | **GPIO 18** |
>| M2A | Motor 2 | Forward Speed | **GPIO 14** |
>| M2B | Motor 2 | Reverse Speed | **GPIO 13** |

#### 3. Total Used Pins

>| Type | Pin Numbers Used | Total |
>| :--- | :--- | :--- |
>| **Motor Driver (PWM)** | 19, 18, 14, 13 | 4 |
>| **I2C** | 21, 22 | 2 |
>| **ToF XSHUT** | 33, 32, 27, 26, 25 | 5 |
>| **TOTAL GPIO PINS USED** | | **11** |





## 3.Filmware

### Summury of [Code](/firmware/Folkrace.ino) (**NOT TESTED**):

#### 1.Setup: The ESP32 initializes Wi-Fi, OTA and I2C bus and configures all ToF's and assigns them a unique addresses.

#### 2.Imput: The main loop is reading the distance from all the sensors and compines them using weighted coefficients to calculate a single positional error.

#### 3.Control: It gets the error and feeds it in the PID controller, which calculates the correction needed to reduce the error to 0.

#### 4.Output: The correction finaly is applied to the motors using PWM signals.

## 3D Printed Parts

### Parts List

* **[Front Bumper](/STLs/FrontBumper.stl)** (Quantity: 1)
* **[Rear Bumper](/STLs/RearBumper.stl)** (Quantity: 1)
* **[Side Bumpers](/STLs/SideBumper.stl)** (Quantity: 2)
* **[Motor Mounts](/STLs/MotorMount.stl)** (Quantity: 4)

## 4. Bill of Materials (BOM)

| Item | Description | Quantity | Unit Price (€) | Total Price (€) | URL | Running Total (€ with Tax) |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| **DC Motors** | Drive Motors (6V 750RPM) | 4 | 16.00 | 64.00 | [https://www.jsumo.com](https://www.jsumo.com/core-dc-motor-6v-750rpm) | 64.00 |
| **Wheels** | Aluminum - Silicone Wheel Set | 2 | 15.50 | 31.00 | [https://www.jsumo.com](https://www.jsumo.com/jsumo-wheel-43x11mm-pair-soft-silicone) | 95.00 |
| **Microcontroller** | ESP32-DevKitC Development Board | 1 | 9.90 | 9.90 | [https://grobotronics.com](https://grobotronics.com/esp32-development-board-devkit-v1.html) | 104.90 |
| **Sensors** | VL53L0X Time-of-Flight (ToF) | 5 | 2.50 | 12.50 | [https://www.temu.com](https://www.temu.com/ul/kuiper/un9.html?subj=goods-un&_bg_fs=1&_p_rfs=1&_x_ns_prz_type=-1&_x_ns_sku_id=17594988870614&_x_ns_gid=601100157918115&mrk_rec=1&_x_ads_sub_channel=shopping&_p_rfs=1&_x_ns_prz_type=-1&_x_ns_sku_id=17594988870614&_x_ns_gid=601100157918115&mrk_rec=1&_x_ads_channel=google&_x_gmc_account=772005384&_x_login_type=Google&_x_ns_gg_lnk_type=adr&_x_ads_account=6217438245&_x_ads_set=22821535431&_x_ads_id=188619669811&_x_ads_creative_id=765746251322&_x_ns_source=g&_x_ns_gclid=Cj0KCQiA_8TJBhDNARIsAPX5qxS74_q9dhiTIvByNhVh8ld3DEGTAj0bWG-MgXinbjivbOwGYiuwb1QaAoYZEALw_wcB&_x_ns_placement=&_x_ns_match_type=&_x_ns_ad_position=&_x_ns_product_id=772005384-en-17594988870614&_x_ns_target=&_x_ns_devicemodel=&_x_ns_wbraid=CkEKCQiA3L_JBhDxARIwAHTwe8yn1e11-pFJWKQUheZHO7OYuOSTSn3rBLRa37kyxPEg2BQDQ9y3-UNT8ucWGgL0Rg&_x_ns_gbraid=0AAAAAo4mICHMEfKcJ0oOLcvVhMiL34SOE&_x_ns_targetid=pla-2625318551272&gad_source=1&gad_campaignid=22821535431&gbraid=0AAAAAo4mICHMEfKcJ0oOLcvVhMiL34SOE&gclid=Cj0KCQiA_8TJBhDNARIsAPX5qxS74_q9dhiTIvByNhVh8ld3DEGTAj0bWG-MgXinbjivbOwGYiuwb1QaAoYZEALw_wcB&is_back=1) | 117.40 |
| **Motor Driver** | Cytron MDD3A | 1 | 8.50 | 8.50 | [https://botland.store](https://botland.store/motor-drivers-modules/15819-cytron-mdd3a-dual-channel-16v-3a-motor-controller-5904422324841.html) | 125.90 |
| **Battery** | Battery Lithium 18650 | 2 | 5.80 | 11.60 | [https://grobotronics.com](https://grobotronics.com/battery-lithium-18650-3.6v-3200mah-lg-inr18650-mh1.html?srsltid=AfmBOorO9rHicRFxCaTsiuH0z1Nu5r90yx-F4EEb-n_gA3Yru7VgAYtV) | 137.50 |
