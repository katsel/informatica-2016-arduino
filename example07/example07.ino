#include<ESP8266WiFi.h>  // WiFi functonality
WiFiServer MyServer(80);  // HTTP server on port 80

void setup() {
  // put your setup code here, to run once:
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
  // read from existing connection
  String request = myClient.readString();
  Serial.println(request);
  // empty the message queue
  myClient.flush();
  // send HTTP response to client
  myClient.print("HTTP/1.0\r\nContent-Type:text/plain\r\n\r\nGuckuck!\n");
}
