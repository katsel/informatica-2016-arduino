/*
 * Check humidity. Display a warning (blinking LED)
 * if it's too dry.
 */

#define  HUMIDITYSENSOR  A0
#define  MY_LED  14
// above this value we assume it's too dry for our plant
#define  DRYNESSBOUNDARY  400

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  int humidityvalue = analogRead(HUMIDITYSENSOR);
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
