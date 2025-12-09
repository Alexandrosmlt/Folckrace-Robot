# Folckrace Robot

## 1. Project Overview

This is a special autonomous robot made for Folkrace (which is a robot competition centered around autonomous racing and steering skills). My design features 4 HS DC Motors paired with 5 ToF sensors, providing precise feedback in real time.

## 1.1 Why i am building this project

I am making this project to get real-life experience in developing complex systems and working with fast robotics controls. This project is a great challenge for me to help me improve my skills in putting together microcontrollers, motor drivers and sensors all to create a autonomous and competitive robot.

## 2. Hardware and Design

### 2.1 3D Model Visualization

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


<!-- ### 2.2 Custom PCB Design 


* **PCB Screenshot**:

### 2.3 Wiring Diagram

* **Wiring Diagram**:

## 3. Filmware and control

The robots autonomy is managed using the **ESP32** microcontroller programed in Arduino IDE.

* **Control System**: The primary control loop runs on the ESP32, using feedback from the ToF sensors to calculate the robot's position and speed relative to the track boundaries.

* **Actuators**: The Cytron MDD3A motor driver controls the four 6V DC motors, implementing a high-frequency PWM signal for precise velocity and steering control.

* **Sensors**: Five VL53L0X Time-of-Flight (ToF) sensors provide accurate distance readings. -->

## 4. Bill of Materials (BOM)

| Item | Description | Quantity | Unit Price (€) | Total Price (€) | URL | Running Total (€ with Tax) |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| **DC Motors** | Drive Motors (6V 750RPM) | 4 | 16.00 | 64.00 | [https://www.jsumo.com](https://www.jsumo.com/core-dc-motor-6v-750rpm) | 64.00 |
| **Wheels** | Aluminum - Silicone Wheel Set | 2 | 15.50 | 31.00 | [https://www.jsumo.com](https://www.jsumo.com/jsumo-wheel-43x11mm-pair-soft-silicone) | 95.00 |
| **Microcontroller** | ESP32-DevKitC Development Board | 1 | 9.90 | 9.90 | [https://grobotronics.com](https://grobotronics.com/esp32-development-board-devkit-v1.html) | 104.90 |
| **Sensors** | VL53L0X Time-of-Flight (ToF) | 5 | 2.50 | 12.50 | [https://www.temu.com](https://www.temu.com/ul/kuiper/un9.html?subj=goods-un&_bg_fs=1&_p_rfs=1&_x_ns_prz_type=-1&_x_ns_sku_id=17594988870614&_x_ns_gid=601100157918115&mrk_rec=1&_x_ads_sub_channel=shopping&_p_rfs=1&_x_ns_prz_type=-1&_x_ns_sku_id=17594988870614&_x_ns_gid=601100157918115&mrk_rec=1&_x_ads_channel=google&_x_gmc_account=772005384&_x_login_type=Google&_x_ns_gg_lnk_type=adr&_x_ads_account=6217438245&_x_ads_set=22821535431&_x_ads_id=188619669811&_x_ads_creative_id=765746251322&_x_ns_source=g&_x_ns_gclid=Cj0KCQiA_8TJBhDNARIsAPX5qxS74_q9dhiTIvByNhVh8ld3DEGTAj0bWG-MgXinbjivbOwGYiuwb1QaAoYZEALw_wcB&_x_ns_placement=&_x_ns_match_type=&_x_ns_ad_position=&_x_ns_product_id=772005384-en-17594988870614&_x_ns_target=&_x_ns_devicemodel=&_x_ns_wbraid=CkEKCQiA3L_JBhDxARIwAHTwe8yn1e11-pFJWKQUheZHO7OYuOSTSn3rBLRa37kyxPEg2BQDQ9y3-UNT8ucWGgL0Rg&_x_ns_gbraid=0AAAAAo4mICHMEfKcJ0oOLcvVhMiL34SOE&_x_ns_targetid=pla-2625318551272&gad_source=1&gad_campaignid=22821535431&gbraid=0AAAAAo4mICHMEfKcJ0oOLcvVhMiL34SOE&gclid=Cj0KCQiA_8TJBhDNARIsAPX5qxS74_q9dhiTIvByNhVh8ld3DEGTAj0bWG-MgXinbjivbOwGYiuwb1QaAoYZEALw_wcB&is_back=1) | 117.40 |
| **Motor Driver** | Cytron MDD3A | 1 | 8.50 | 8.50 | [https://botland.store](https://botland.store/motor-drivers-modules/15819-cytron-mdd3a-dual-channel-16v-3a-motor-controller-5904422324841.html) | 125.90 |
| **Battery** | Battery Lithium 18650 | 2 | 5.80 | 11.60 | [https://grobotronics.com](https://grobotronics.com/battery-lithium-18650-3.6v-3200mah-lg-inr18650-mh1.html?srsltid=AfmBOorO9rHicRFxCaTsiuH0z1Nu5r90yx-F4EEb-n_gA3Yru7VgAYtV) | 137.50 |
