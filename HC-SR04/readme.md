To take a measurement, you must:

    send an impulse to the trigger pin (= trigger)
    the sensor emits a burst of ultrasonic waves
    the output pin goes to 1 for a period proportional to the distance

## HC-SR04 Sensor Connections :
![HC-SR04](HC-SR04/HC-SR04jpg.jpg)

## Code arduino: 

```cpp
int trig = 3 ;
int echo = 2 ;
long duree;
float distance ;

void setup() {
  pinMode(trig, OUTPUT );
  pinMode(echo, INPUT );
  Serial.begin(9600);
}

void loop() {
  // pulse of 10 us on the trig pin => triggering of the measurement
  digitalWrite(trig, 1 );
  delayMicroseconds(10);
  digitalWrite(trig, 0 );
 // read the duration of the high state of the pulse inus
  duree = pulseIn(echo, HIGH);
  distance = 0.017 * duration;
  Serial.print("distance in cm  : ");
  Serial.println(distance);
  delay(1000);
}
```

All that remains is to open the "serial monitor" to see the distance to the obstacle displayed.

The pulseIn () instruction is blocking. It does not allow you to move forward in the program until the falling edge of the pulse has appeared.
When we only want to read distances less than 1 m, i.e. a maximum pulse duration of the output pin of 5882 us, we will limit the pulse reading duration by adding a timeout to the pulseIn () instruction .
When the duration is greater than timeout, pulseIn () returns the value 0. In the following program, the distance is displayed only if it is less than 1 m (i.e. distance is different from 0)

Second code arduino : 

```cpp
int trig = 3;
    int echo = 2;
    long term;
    float distance;
     
    void setup () {
      pinMode (trig, OUTPUT);
      pinMode (echo, INPUT);
      Serial.begin (9600);
    }
     
    void loop () {
      // pulse of 10 us on the trig pin => triggering of the measurement
      digitalWrite (trig, 1);
      delayMicroseconds (10);
      digitalWrite (trig, 0);
      // read the duration of the pulse (max 5882)
      duration = pulseIn (echo, HIGH, 5882);
      distance = 0.017 * duration;
      if (distance) {
        Serial.print ("distance in cm:");
        Serial.println (distance);
      }
      delay (1000);
    }
```
