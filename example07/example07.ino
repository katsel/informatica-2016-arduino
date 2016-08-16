#include<ESP8266WiFi.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  WiFi.mode(WIFI_STA);
  // ESSID + password of our WiFi
  WiFi.begin("Toblerone", "Schokolade");
  Serial.print("I'm Arduino and try to connect to the Wifi");
  // if not connected try again
  while(WiFi.status() != WL_CONNECTED) {
    Serial.print(" blubb");
    delay(500);
  }
  Serial.println(" successfully connected!");
  // print IP adress
  Serial.println(WiFi.localIP());
}

void loop() {
  // put your main code here, to run repeatedly:

}
