/*
 * Check humidity. Display a warning (blinking LED)
 * if it's too dry.
 */

#define  HUMIDITYSENSOR  A0
#define  MY_LED  14
#define  NEW_PIN  D8
// above this value we assume it's too dry for our plant
#define  DRYNESSBOUNDARY  400

void setup() {
  // put your setup code here, to run once:
  pinMode(NEW_PIN, OUTPUT);  // use D8 as a new output
  pinMode(MY_LED, OUTPUT);
  digitalWrite(NEW_PIN, LOW);  // digital sensor, so we can use low
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  // turn on the humidity sensor before measuring
  digitalWrite(NEW_PIN, HIGH);  // current on
  delay(200);                   // wait a little
  int humidityvalue = analogRead(HUMIDITYSENSOR);  // measure
  digitalWrite(NEW_PIN, LOW);   // current off

  Serial.print("Humidity value: ");
  Serial.println(humidityvalue);

  // too dry
  if (humidityvalue > DRYNESSBOUNDARY) {
    Serial.println("Water me!");
    analogWrite(MY_LED, 1023);
    delay(5000);
    analogWrite(MY_LED, 0);
  }
  // not too dry
  else {
    analogWrite(MY_LED, 0);
    delay(1000);
  }
}
