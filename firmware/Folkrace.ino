#include <WiFi.h>
#include <ArduinoOTA.h>
#include <Wire.h>
#include <Adafruit_VL53L0X.h>

#define I2C_SDA_PIN 21
#define I2C_SCL_PIN 22

const uint8_t XSHUT_PINS[] = {33, 32, 27, 26, 25};
#define NUM_SENSORS (sizeof(XSHUT_PINS) / sizeof(XSHUT_PINS[0]))

const int MD[2] = {19, 18}; 
const int SensorIndex[5] = {0, 1, 2, 3, 4}; 

int weights[5] = {-2, -1, 0, 1, 2}; 

Adafruit_VL53L0X lox_sensors[NUM_SENSORS];
const uint8_t NEW_I2C_ADDRESSES[] = {0x30, 0x31, 0x32, 0x33, 0x34}; 

const char* ssid = "Billys";
const char* password = "12345678";

unsigned long lastTime = 0;
float dt = 0.0001;

float Kp = 150;
float Ki = 0;
float Kd = 0;

float error = 0;
float integral = 0;
float previous_error = 0;

const int baseSpeed = 200;

const int bootButtonPin = 0;
bool motorsEnabled = false;
bool lastButtonState = HIGH;
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50;

void tof_init() {
  for (int i = 0; i < NUM_SENSORS; i++) {
    pinMode(XSHUT_PINS[i], OUTPUT);
    digitalWrite(XSHUT_PINS[i], LOW);
  }
  delay(10); 

  for (int i = 0; i < NUM_SENSORS; i++) {
    digitalWrite(XSHUT_PINS[i], HIGH); 
    delay(10); 
    
    lox_sensors[i] = Adafruit_VL53L0X();
    if (!lox_sensors[i].begin()) {
      
    } else {
        lox_sensors[i].setAddress(NEW_I2C_ADDRESSES[i]);
    }
  }
}

int read_tof_distance(int sensor_index) {
  VL53L0X_RangingMeasurementData_t measure;
  lox_sensors[sensor_index].rangingTest(&measure, false); 
  
  if (measure.RangeStatus != 4) {
      int distance = measure.RangeMilliMeter;
      int mapped_value = map(distance, 500, 50, 0, 1000); 
      
      return constrain(mapped_value, 0, 1000);
  } else {
      return 0; 
  }
}

void setup() {
    WiFi.mode(WIFI_AP);
    WiFi.softAP(ssid, password);

    Serial.begin(9600);
    

    ArduinoOTA.setHostname("esp32-ota");
    ArduinoOTA.begin();

    pinMode(MD[0], OUTPUT); 
    pinMode(MD[1], OUTPUT); 
    
    pinMode(bootButtonPin, INPUT_PULLUP);
    
    Wire.begin(I2C_SDA_PIN, I2C_SCL_PIN);
    tof_init();
}

void loop() {
    ArduinoOTA.handle();

    bool buttonState = digitalRead(bootButtonPin);
    if (buttonState != lastButtonState) {
        lastDebounceTime = millis();
        lastButtonState = buttonState;
    }

    if ((millis() - lastDebounceTime) > debounceDelay) {
        if (buttonState == LOW) {
            bool previousState = motorsEnabled;
            motorsEnabled = !motorsEnabled;

            while (digitalRead(bootButtonPin) == LOW);

            if (motorsEnabled && !previousState) {
                delay(5000);
            }
        }
    }

    if (!motorsEnabled) {
        analogWrite(MD[0], 0);
        analogWrite(MD[1], 0);
        return;
    }

    unsigned long now = micros();
    dt = (now - lastTime) / 1000000.0;
    lastTime = now;

    int total = 0;
    int weightedSum = 0;

    for (int i = 0; i < 5; i++) {
        int value = read_tof_distance(SensorIndex[i]); 
        weightedSum += value * weights[i];
        total += value;
    }

    float position = (total > 0) ? (float)weightedSum / total : 0;

    error = 0 - position;
    integral += error * dt; 
    float derivative = (error - previous_error) / dt;
    float correction = Kp * error + Ki * integral + Kd * derivative;
    previous_error = error;

    int leftMotor = constrain(baseSpeed + correction, 20, 255);
    int rightMotor = constrain(baseSpeed - correction, 20, 255);

    analogWrite(MD[1], leftMotor);
    analogWrite(MD[0], rightMotor);
}