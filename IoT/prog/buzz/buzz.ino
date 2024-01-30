int buz =25;

void setup() {
  // put your setup code here, to run once:
  pinMode(buz,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(buz,1); 
  delay(1000);
   digitalWrite(buz,0);
  delay(1000);
  

}
