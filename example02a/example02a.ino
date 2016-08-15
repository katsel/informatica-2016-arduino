// make LED on the board change brightness and blink

#define  MEIN_LED  14
void setup() {
  // put your setup code here, to run once:
  pinMode(MEIN_LED, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  // 0 - no current
  // 1024 - maximum current

  analogWrite(MEIN_LED, 255);
  delay(500);
  analogWrite(MEIN_LED, 511);
  delay(500);
  analogWrite(MEIN_LED, 767);
  delay(500);
  analogWrite(MEIN_LED, 1024);
  delay(500);
  analogWrite(MEIN_LED, 0);
  delay(1000);
}
