int potPin = 2;    // select the input pin for the potentiometer
int val = 0;       // variable to store the value coming from the sensor

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);
}

void loop() {
  Serial.println(digitalRead(potPin));
}