#include "Adafruit_VL53L0X.h"

Adafruit_VL53L0X capteur = Adafruit_VL53L0X();
VL53L0X_RangingMeasurementData_t mesure;

void setup() {
  Serial.begin(9600);

  // sensor initializationr
  if (!capteur.begin()) {
    Serial.println(F("Failed to connect to VL53L0X sensor"));
    while (1);
  }
}

void loop() {
  capteur.rangingTest(&mesure, false); // 'true' debugging info 
// Range Status = 4 means the measurement is wrong
  if (mesure.RangeStatus != 4) {   
    Serial.print("Distance in mm : ");
    Serial.println(mesure.RangeMilliMeter);
  }
  else {
    Serial.println(" wrong measurement  ");
  }
  delay(1000);
}