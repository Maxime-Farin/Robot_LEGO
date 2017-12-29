#include <Servo.h>

Servo Servo1;

void setup() {
  // put your setup code here, to run once:
  Servo1.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:

  // Fait bouger le bras de 0° à 180°
  for (int position = 0; position <= 180; position++) {
    Servo1.write(position);
    delay(15);
  }
  
  // Fait bouger le bras de 180° à 10°
  for (int position = 180; position >= 0; position--) {
    Servo1.write(position);
    delay(15);
  }
}
