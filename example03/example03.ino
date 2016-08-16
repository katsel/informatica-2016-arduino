/*
 *  you need a board with a light sensor to run this,
 *  e.g. Arduino Mega ADK
 *
 *  this program turns on the LED on the board when it's dark,
 *  and off when it's bright
 */

#define  MEINE_LED  6
#define  LICHTSENSOR  A2
#define  FINSTERGRENZE  150 // darkness
#define  HELLGRENZE  500    // brightness

void setup() {
  // put your setup code here, to run once:
  pinMode(MEINE_LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  // detect light value from sensor
  int lichtwert = analogRead(LICHTSENSOR);
  Serial.println(lichtwert);  // print light value

  // when it's dark
  if (lichtwert < FINSTERGRENZE) {
    analogWrite(MEINE_LED, 0); // 0 is light, 255 is dark
    }
  // when it's bright
  if (lichtwert > HELLGRENZE) {  
    analogWrite(MEINE_LED, 255);
  }
}
