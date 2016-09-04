#include<ESP8266WiFi.h>  // WiFi functonality
#include<ESP8266HTTPClient.h>  // WiFi functonality
#define  MY_LED  14
#define  HUMIDITYSENSOR  A0
#define  NEW_PIN  D8

void setup() {
  // put your setup code here, to run once:
  pinMode(MY_LED, OUTPUT);
  pinMode(NEW_PIN, OUTPUT);
  digitalWrite(NEW_PIN, LOW);
  Serial.begin(9600);
  WiFi.mode(WIFI_STA);
  // ESSID + password of our WiFi
  WiFi.begin("Toblerone", "Schokolade");
  Serial.print("I'm Arduino, trying to connect to the Wifi");
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

  // check humidity sensor
  digitalWrite(NEW_PIN, HIGH);  // turn sensor on
  delay(200);
  int humidityvalue = analogRead(HUMIDITYSENSOR);  // measure
  digitalWrite(NEW_PIN, LOW);  // turn sensor off

  // tweet when it's too dry
  String requestURL;
  if(humidityvalue > 500) {
    HTTPClient MyClient;
    requestURL = ""; // enter IFTTT URL here, replacing https with http
    requestURL.concat("?value1=");
    requestURL.concat(humidityvalue);
    MyClient.begin(requestURL);
    MyClient.GET();
    MyClient.end();
  }
  Serial.println(requestURL);
  delay(600000); // 10 minutes
}
