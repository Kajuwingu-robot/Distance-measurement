
## Characteristics of the VL53L0X sensor

    Sensor documentation: https://www.st.com/en/imaging-and-photonics-solutions/vl53l0x.html
    communication with the Arduino board via the I2c bus (SDA and SCL pins).
    digital output
    5V sensor supply (presence of a 3.3V regulator on the sensor board)

## VL53L0X sensor connections : 

![VL53L0X](VL53L0X/VL53L0X.jpg)

Program

To implement it, I use Adafruit's BSD licensed library. https://github.com/adafruit/Adafruit_VL53L0X
This library can be installed from the library manager of the Arduino IDE (sketch -> include a library -> manage libraries)

```cpp
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
```
