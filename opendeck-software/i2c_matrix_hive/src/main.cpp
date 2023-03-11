#include <Arduino.h>
#include <Wire.h>

#define i2c_addr 8
#define msg_size 4

int count = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Wire.begin();

}

void loop() {
  //ask i2c device for the reading
  Serial.print("Request number ");
  Serial.println(count);
  Wire.requestFrom(i2c_addr, msg_size);


  //print the reading
  while(Wire.available()){
    char c = Wire.read();
    Serial.print(c);
  }

  Serial.println("");

  count++;

  //wait
  delay(1000);
}