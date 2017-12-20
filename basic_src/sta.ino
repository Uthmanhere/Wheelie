//STA


#include <ESP8266WiFi.h>

//led pins
byte ledPin = 2;
uint8_t received = D0;

//WiFi credentials
char ssid[] = "grace";
char pass[] = "gracious";

//IP address of the server
IPAddress server(192,168,4,15);

//initiate client object
WiFiClient client;

void setup() 
{
  //serial communication
  Serial.begin(9600);

  //wifi mode : Station
  WiFi.mode(WIFI_STA);

  //initiate WiFi
  WiFi.begin(ssid, pass);
  
  //Check connection status
  Serial.println();
  Serial.println("Connection to the AP");
  while (WiFi.status() != WL_CONNECTED) 
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.println("Connected");

  //Connection details
  /*
  Serial.print("LocalIP:"); Serial.println(WiFi.localIP());
  Serial.println("MAC:" + WiFi.macAddress());
  Serial.print("Gateway:"); Serial.println(WiFi.gatewayIP());
  Serial.print("AP MAC:"); Serial.println(WiFi.BSSIDstr());
  */

  //pin modes
  pinMode(ledPin, OUTPUT);
  pinMode(received, OUTPUT);
}

void loop() 
{
  //connect to the server
  client.connect(server, 80);

  //connection indication
  digitalWrite(ledPin, LOW);

  //server response
  String response = client.readStringUntil('\r');
  Serial.println("The Signal is : " + response);

  //react to server response
  if (response == "HIGH")
    digitalWrite(received, HIGH);
  else
    digitalWrite(received, LOW);

  //flush the client
  client.flush();

  //stop client
  client.stop();
  delay(100);
}
