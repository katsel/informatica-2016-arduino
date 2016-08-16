/*
 * Display the humidity value of the sensor
 */

#define  HUMIDITYSENSOR  A0

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int humidityvalue = analogRead(HUMIDITYSENSOR);
  Serial.print("Humidity value: ");
  Serial.println(humidityvalue);
  delay(1000);
}
