// lighting a LED on the board

#define  MEIN_LED  14
void setup() {
  // put your setup code here, to run once:
  pinMode(MEIN_LED, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  // 0 - no current
  // 255 - maximum current (according to the manual; actually it's 1024)

  analogWrite(MEIN_LED, 0);

}
