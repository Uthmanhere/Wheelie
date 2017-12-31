uint8_t en_1 = D6;
uint8_t en_2 = D5;

void setup() {
  // put your setup code here, to run once:
  pinMode(en_1, OUTPUT);
  pinMode(en_2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(en_1, HIGH);
  digitalWrite(en_2, LOW);

  delay(3000);

//  digitalWrite(en_1, LOW);
//  digitalWrite(en_2, LOW);
  
  delay(1000);
}
