#include <Servo.h>
Servo Servo1;

int X_pin = 0;
int Y_pin = 1;
byte X_val = 0;
byte Y_val = 0;
int Last_Position = 0;

//int switchPin = 7;


void setup() {
  Serial.begin(9600);
  pinMode(X_pin, INPUT);
  pinMode(Y_pin, INPUT);

  Servo1.attach(9);
}


void loop() {
  X_val = analogRead(X_pin);
  Y_val = analogRead(Y_pin);
  Serial.print(X_val);
  Serial.print("   ");
  Serial.println(Y_val);

   if(X_val == 0 && Y_val > 100 && Y_val < 250){
      for (int position = Last_Position; position == 0; position++) {
       Servo1.write(position);
      delay(15);
      }
      Last_Position = 0;
   }
   if(X_val == 0 && Y_val == 0){
      for (int position = Last_Position; position == 45; position++) {
       Servo1.write(position);
      delay(15);
      }
      Last_Position = 45;
   }
   if(X_val > 0 && X_val < 100 && Y_val == 0){
      for (int position = Last_Position; position == 90; position++) {
       Servo1.write(position);
      delay(15);
      }
      Last_Position = 90;
   }
   if(X_val > 250 && Y_val == 0){
      for (int position = Last_Position; position == 135; position++) {
       Servo1.write(position);
      delay(15);
      }
      Last_Position = 135;
   }
   if(X_val == 255 && Y_val > 100 && Y_val < 250){
      for (int position = Last_Position; position == 180; position++) {
       Servo1.write(position);
      delay(15);
      }
      Last_Position = 180;
   }
   if(X_val > 250 && Y_val > 250){
      for (int position = Last_Position; position == -135; position--) {
       Servo1.write(position);
      delay(15);
      }
      Last_Position = -135;
   }
   if(X_val > 0 && X_val < 100 && Y_val > 250){
      for (int position = Last_Position; position == -90; position--) {
       Servo1.write(position);
      delay(15);
      }
      Last_Position = -90;
   }
   if(X_val == 0 && Y_val > 255){
      for (int position = Last_Position; position == -45; position--) {
       Servo1.write(position);
      delay(15);
      }
      Last_Position = -45;
   }

  delay(100);
}
