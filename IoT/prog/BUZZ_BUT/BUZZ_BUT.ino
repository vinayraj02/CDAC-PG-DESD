int buz =25;
int l=36;

void setup() {
  // put your setup code here, to run once:
  pinMode(buz,OUTPUT);
  pinMode(l,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int read=digitalRead(l);
  if(read==HIGH){
     digitalWrite(buz,0);
  }
  else{
    digitalWrite(buz,1);
  }

  // digitalWrite(buz,1);
  // digitalWrite(l,0); 
  // delay(1000);
  //  digitalWrite(buz,0);
  //  digitalWrite(l,1);  
  // delay(1000);
  

}
