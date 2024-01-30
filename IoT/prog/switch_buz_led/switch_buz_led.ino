const int buz = 26;
const int led = 25;
const int sw = 36;

int pressCount = 0;
int buttonState = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(buz,OUTPUT);
  pinMode(led,OUTPUT);
  pinMode(sw,INPUT);
 Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int reading = digitalRead(sw);
      buttonState = reading;
   
      // If button is pressed, increment pressCount
      if (buttonState == HIGH) {
        pressCount++;
      }
        // Toggle LED and buzzer based on pressCount
        if (pressCount == 1) {
          digitalWrite(led, HIGH);
          Serial.println("LED ON");
        } else if (pressCount == 2) {
          digitalWrite(led, LOW);
          digitalWrite(buz, HIGH);
          Serial.println("Buzzer ON");
        }
      
  

}
