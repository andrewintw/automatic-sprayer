#include <Servo.h>

#define SERVO_PIN                7
#define SERVO_INIT_POS          31  // trigger init position (angle)
#define PRESS_ANGLE             25

#define OBSTACLE_PIN            12  // Infrared Obstacle Sensor
#define OBSTACLE_DETECTED       LOW

bool is_ir_detected             = 0;
bool is_time_checking           = 0;
unsigned long detected_time     = 0;
unsigned int keep_detecting_ms  = 800;

bool is_sprayer_ready  = 1;

Servo MG996R;

void pulling_trigger(unsigned pos, unsigned hold_ms) {
  if (pos < SERVO_INIT_POS) {
    return;
  }

  if (pos == SERVO_INIT_POS) {
    MG996R.write(pos);
  } else {
    MG996R.write(pos);
    delay(hold_ms);
    MG996R.write(SERVO_INIT_POS);
  }

  is_sprayer_ready = 0;
}

void setup() {
  MG996R.attach(SERVO_PIN);
  pulling_trigger(SERVO_INIT_POS, 0);
  pinMode(OBSTACLE_PIN, INPUT);
  //Serial.begin(9600);
}

void loop() {
  if (digitalRead(OBSTACLE_PIN) == OBSTACLE_DETECTED) {
    is_ir_detected = 1;

    if (is_time_checking = 0) {
      detected_time = millis();
      is_time_checking = 1;
    }

    if (millis() - detected_time > keep_detecting_ms) {
      detected_time = millis();
      is_time_checking = 0;
      /* keep few ms and pull trigger  */
      //Serial.println('time's up, pull trigger');
      if (is_sprayer_ready == 1) {
        pulling_trigger(SERVO_INIT_POS + PRESS_ANGLE, 500);
        is_sprayer_ready = 0;
      }
    }

  } else {
    detected_time = millis();
    //Serial.println(detected_time);
    is_ir_detected = 0;
    is_time_checking = 0;
    is_sprayer_ready = 1;
  }
}
