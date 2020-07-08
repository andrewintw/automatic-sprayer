#include <Servo.h>

#define SERVO_PIN           7
#define SERVO_INIT_POS     40

int pos = 0;

Servo myservo;

void setup() {
  myservo.attach(SERVO_PIN);
  myservo.write(SERVO_INIT_POS);
}

void loop() {
}
