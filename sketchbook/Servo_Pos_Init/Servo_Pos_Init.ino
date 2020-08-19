#include <Servo.h>

#define SERVO_PIN          7
#define SERVO_INIT_POS    10

String incomingPos = "";

Servo myservo;

void setup() {
  myservo.attach(SERVO_PIN);
  myservo.write(SERVO_INIT_POS);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    incomingPos = Serial.readString();
    int pos = incomingPos.toInt();
    Serial.println(pos);

    if (pos > 180) {
      pos = 180;
    }
    if (pos < 0) {
      pos = 0;
    }
    myservo.write(pos);
  }
}
