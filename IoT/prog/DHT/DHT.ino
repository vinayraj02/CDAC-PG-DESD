#include<DHT.h>
#include<stdio.h>

#define dhtpin 2
#define dhttype DHT11


float hum=0,temp=0;

DHT dht(dhtpin,dhttype); 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //initialising the dht
  dht.begin();
  
}

void loop() {
  // put your main code here, to run repeatedly:
  hum=dht.readHumidity();
  temp=dht.readTemperature();

  Serial.printf("humidity:%f %%\n",hum);
  Serial.printf("temperature: %f °C\n",temp);

  // Serial.print(F("Humidity: "));
  // Serial.print(hum);
  // Serial.println(" ");
  //  Serial.print(F("%  Temperature: "));Serial.print(temp);
  // Serial.print(temp);
  // Serial.print(F("°C "));


  delay(2000);
}
