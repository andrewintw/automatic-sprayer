#include <Servo.h>

#define SERVO_PIN   7
#define MIN_POS     30
#define MAX_POS     150

int pos = 0;

Servo myservo;

void setup() {
  myservo.attach(SERVO_PIN);
}

void loop() {
  for (pos = MIN_POS; pos <= MAX_POS; pos += 10)
  {
    myservo.write(pos);
    delay(70);
  }

  for (pos = MAX_POS; pos >= MIN_POS; pos -= 10)
  {
    myservo.write(pos);
    delay(70);
  }
}
