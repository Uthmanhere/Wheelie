#include <ESP8266WiFi.h>

String  i;
WiFiServer server(80);

void setup(){
  i = "";
  Serial.begin(9600);

  pinMode(D0, OUTPUT); // GPIO pin16=D0 
  pinMode(D1, OUTPUT);  // GPIO pin5=D1
  pinMode(D4, OUTPUT);  // GPIO pin4=D2 
  pinMode(D3, OUTPUT);  // GPIO pin0=D3
    WiFi.disconnect();
  delay(2000);
  Serial.println("Connecting to WIFI");
   WiFi.begin("grace","gracious");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);
    Serial.print("..");

  }
  Serial.println("Connected!");
  Serial.println("My Local IP is : ");
  Serial.print((WiFi.localIP()));
  server.begin();
}


void loop(){
    WiFiClient client = server.available();
    if (!client) { return; }
    while(!client.available()){  delay(1); }
    i = (client.readStringUntil('\r'));
    i.remove(0, 5);
    i.remove(i.length()-9,9);
    if (i == "forward") {
      Serial.println("Forward Pressed");
      digitalWrite(D0, LOW);
      digitalWrite(D1, HIGH);
      digitalWrite(D3, LOW);
      digitalWrite(D4, HIGH);
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("");
      client.println("<!DOCTYPE HTML>");
      client.println("<html>");
      client.println("forward");
      client.println("</html>");
      client.stop();
      delay(1);
    }
    if (i == "reverse") {
      Serial.println("Reverse Pressed");
      digitalWrite(D0, HIGH);
      digitalWrite(D1, LOW);
      digitalWrite(D3, HIGH);
      digitalWrite(D4, LOW);
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("");
      client.println("<!DOCTYPE HTML>");
      client.println("<html>");
      client.println("reverse");
      client.println("</html>");
      client.stop();
      delay(1);
    }
    if (i == "right") {
      Serial.println("Right Pressed");
      digitalWrite(D0,LOW);
      digitalWrite(D1,LOW);
      digitalWrite(D4,HIGH);
      digitalWrite(D3,LOW);
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("");
      client.println("<!DOCTYPE HTML>");
      client.println("<html>");
      client.println("right");
      client.println("</html>");
      client.stop();
      delay(1);

    }
    if (i == "left") {
      Serial.println("Left Pressed.");
      digitalWrite(D0,HIGH);
      digitalWrite(D1,LOW);
      digitalWrite(D4,LOW);
      digitalWrite(D3,LOW);
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("");
      client.println("<!DOCTYPE HTML>");
      client.println("<html>");
      client.println("left");
      client.println("</html>");
      client.stop();
      delay(1);

    }
    if (i == "stop") { 
      digitalWrite(D0,LOW);
      digitalWrite(D1,LOW);
      digitalWrite(D4,LOW);
      digitalWrite(D3,LOW);
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("");
      client.println("<!DOCTYPE HTML>");
      client.println("<html>");
      client.println("stop");
      client.println("</html>");
      client.stop();
      delay(1);

    }
}
