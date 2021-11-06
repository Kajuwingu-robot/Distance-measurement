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