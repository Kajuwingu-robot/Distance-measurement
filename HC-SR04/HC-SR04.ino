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