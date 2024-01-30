int buz =25;
int l=26;
void setup() {
  // put your setup code here, to run once:
  pinMode(buz,OUTPUT);
  pinMode(l,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(buz,1);
  digitalWrite(l,0); 
  delay(1000);
   digitalWrite(buz,0);
   digitalWrite(l,1);  
  delay(1000);
  

}
