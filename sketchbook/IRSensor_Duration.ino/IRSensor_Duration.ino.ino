#define OBSTACLE_PIN            12  // Infrared Obstacle Sensor
#define OBSTACLE_DETECTED       LOW

bool is_ir_detected             = 0;
bool is_time_checking           = 0;
unsigned long detected_time     = 0;
unsigned int keep_ms            = 2000;

void setup() {
  pinMode(OBSTACLE_PIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(OBSTACLE_PIN) == OBSTACLE_DETECTED) {
    is_ir_detected = 1;

    if (is_time_checking = 0) {
      detected_time = millis();
      is_time_checking = 1;
    }

    if (millis() - detected_time > keep_ms) {
      detected_time = millis();
      is_time_checking = 0;
      Serial.print("duration: ");
      Serial.print(keep_ms);
      Serial.println(" ms");
    }

  } else {
    detected_time = millis();
    Serial.println(detected_time);
    is_ir_detected = 0;
    is_time_checking = 0;
  }
}
