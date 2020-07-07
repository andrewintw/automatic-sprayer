#define OBSTACLE_PIN        12   // Infrared Obstacle Sensor
#define OBSTACLE_DETECTED   LOW

void setup()
{
  pinMode(OBSTACLE_PIN, INPUT);
  Serial.begin(9600);
}

void loop()
{
  if (digitalRead(OBSTACLE_PIN) == OBSTACLE_DETECTED) {
    Serial.println("Something is ahead");
  } else {
    Serial.println("Path is clear");
  }
  delay(200);
}
