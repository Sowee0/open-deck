#include <Arduino.h>
#include <Wire.h>


#define i2c_addr 8
#define msg_size 4

char char0 = 'A';
char char1 = 'B';
char char2 = 'C';
char char3 = 'D';
int ledpin = 13;

char char_array [] = {'A', 'B', 'C', 'D'};

void transmit_four(){
  Serial.println("Request!");
  digitalWrite(ledpin, HIGH);
  Wire.write(char0);
  Wire.write(char1);
  Wire.write(char2);
  Wire.write(char3);
  //Wire.write(char_array, msg_size);
  //Wire.endTransmission(true);

  delay(200);
  digitalWrite(ledpin, LOW);
  delay(200);
}

void setup() {
  Serial.begin(9600);
  pinMode(ledpin, OUTPUT);

  digitalWrite(ledpin, HIGH);
  delay(200);
  digitalWrite(ledpin, LOW);
  delay(200);
  digitalWrite(ledpin, HIGH);
  delay(200);
  digitalWrite(ledpin, LOW);
  delay(200);
  digitalWrite(ledpin, HIGH);
  delay(200);
  digitalWrite(ledpin, LOW);
  delay(200);


  Wire.begin(i2c_addr);
  Wire.onRequest(transmit_four);
  Serial.println("Starting!");
}

void loop() {
  delay(100);
}
