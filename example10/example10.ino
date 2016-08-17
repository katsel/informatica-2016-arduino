#include<ESP8266WiFi.h>  // WiFi functonality
#define  MY_LED  14
#define  HUMIDITYSENSOR  A0
#define  NEW_PIN  D8
WiFiServer MyServer(80);  // HTTP server on port 80

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

  // start HTTP server
  MyServer.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  WiFiClient myClient;
  myClient = MyServer.available();
  // no client connected
  if (!myClient) {
    return;  // break out of the loop
  }
  // client connected, yay!
  // check humidity sensor
  digitalWrite(NEW_PIN, HIGH);  // turn sensor on
  delay(200);
  int humidityvalue = analogRead(HUMIDITYSENSOR);  // measure
  digitalWrite(NEW_PIN, LOW);  // turn sensor off
  // read from existing HTTP connection
  String request = myClient.readString();
  Serial.println(request);
  // empty the message queue
  myClient.flush();
  // send HTTP response to client
  myClient.printf("HTTP/1.0\r\nContent-Type:text/html\r\n\r\n<html><head>"
    "<title>Arduino light switch</title></head><body><form method=\"GET\">"
    "<input type=\"submit\" name=\"LightsOn\" value=\"on\" />"
    "<input type=\"submit\" name=\"LightsOff\" value=\"off\" /></form>"
    "%d</body></html>\n", humidityvalue);  delay(100);
  int questionmarkposition=request.indexOf('?');
  Serial.println(questionmarkposition);
  if (questionmarkposition > -1) {
    if(request.startsWith("?LightsOn", questionmarkposition)) {
      Serial.println("Button LightsOn has been pressed");
      analogWrite(MY_LED, 1024);
    }
    else if(request.startsWith("?LightsOff", questionmarkposition)) {
      Serial.println("Button LightsOff has been pressed");
      analogWrite(MY_LED, 0);
    }
  }
}
