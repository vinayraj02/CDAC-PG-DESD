// Blinking LED for FireBeetle-ESP32

const int ledPin = 25; // Pin number where the LED is connected on FireBeetle-ESP32

void setup() {
   Serial.begin(9600);
  pinMode(ledPin, OUTPUT); // Set the LED pin as an output
}

void loop() {
  digitalWrite(ledPin, HIGH); // Turn the LED on
  delay(1000); // Wait for 1 second
  digitalWrite(ledPin, LOW); // Turn the LED off
  delay(1000); // Wait for 1 second
}
