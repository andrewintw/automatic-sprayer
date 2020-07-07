#define LED_BUILTIN_PIN     13

void setup() {

  pinMode(LED_BUILTIN_PIN, OUTPUT);
}


void loop() {
  digitalWrite(LED_BUILTIN_PIN, HIGH);
  delay(200);
  digitalWrite(LED_BUILTIN_PIN, LOW);
  delay(200);
  digitalWrite(LED_BUILTIN_PIN, HIGH);
  delay(200);
  digitalWrite(LED_BUILTIN_PIN, LOW);
  delay(1000);
}
