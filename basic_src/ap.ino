//AP

#include <ESP8266WiFi.h>

//initiate server object
WiFiServer server(80);

//static ip settings
IPAddress IP(192,168,4,15);
IPAddress mask = (255, 255, 255, 0);

//pins
byte ledPin = D0;
uint8_t read_pin = D4;


void setup() 
{
  //serial communication
  Serial.begin(9600);

  //wifi mode : Access Point
  WiFi.mode(WIFI_AP);

  //WiFi config
  WiFi.softAP("grace", "gracious");
  WiFi.softAPConfig(IP, IP, mask);

  //initiate server
  server.begin();

  //pin modes
  pinMode(ledPin, OUTPUT);
  pinMode(read_pin, INPUT);
/*
  Serial.print("IP: ");     Serial.println(WiFi.softAPIP());
  Serial.print("MAC:");     Serial.println(WiFi.softAPmacAddress());
*/
}

void loop() 
{
  //check client availability
  WiFiClient client = server.available();
  if (!client) 
    return;

  //indicate connection
  digitalWrite(ledPin, LOW);

  //Redirect D4 input to client
  if (digitalRead(read_pin))
    client.println("HIGH\r");
  else
    client.println("LOW\r");

  //flush the client data
  client.flush();

  digitalWrite(ledPin, HIGH);
}
