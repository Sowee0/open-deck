#include <Arduino.h>
#include <Wire.h>


#define i2c_addr 8
#define msg_size 4

char char0 = 'A';
char char1 = 'B';
char char2 = 'C';
char char3 = 'D';

char char_array [] = {'A', 'B', 'C', 'D'};

void transmit_four();

void setup() {
  Wire.begin(i2c_addr);
  Wire.onRequest(transmit_four);
}

void loop() {
  // put your main code here, to run repeatedly:
}

void transmit_four(){

  Wire.write(char0);
  Wire.write(char1);
  Wire.write(char2);
  Wire.write(char3);

}