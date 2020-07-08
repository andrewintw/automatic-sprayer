#include <Servo.h>

#define SERVO_PIN            7
#define SERVO_INIT_POS      30  // trigger init position (angle)
#define SERVO_END_POS       90  // trigger end position (angle)

#define OBSTACLE_PIN        12   // Infrared Obstacle Sensor
#define OBSTACLE_DETECTED   LOW

int pos = 0;

Servo myservo;

void setup() {
  myservo.attach(SERVO_PIN);
  myservo.write(SERVO_INIT_POS);
  pinMode(OBSTACLE_PIN, INPUT);
  Serial.begin(9600);
}

void pulling_trigger() {
  myservo.write(SERVO_END_POS);
  delay(300);
  myservo.write(SERVO_INIT_POS);
}

void loop() {
  if (digitalRead(OBSTACLE_PIN) == OBSTACLE_DETECTED) {
    pulling_trigger();
  }
  delay(1000);
}
