#include <Servo.h>

#define SERVO_PIN   7
#define MIN_POS     10
#define MAX_POS     170

int pos = 0;

Servo myservo;

void setup() {
  myservo.attach(SERVO_PIN);
}

void loop() {
  for (pos = MIN_POS; pos <= MAX_POS; pos += 5)
  {
    myservo.write(pos);
    delay(70);
  }

  for (pos = MAX_POS; pos >= MIN_POS; pos -= 5)
  {
    myservo.write(pos);
    delay(70);
  }
}
