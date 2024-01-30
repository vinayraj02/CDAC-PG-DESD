int ld= 02;
int re=0;
int led=26;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ld,INPUT);
  pinMode(led,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  re= analogRead(ld);

  if(re<1000){
      digitalWrite(led,0);
  }
  else if(re>1000){
    digitalWrite(led,1);
  }
  Serial.println(re);
  delay(1000);
}
