#include "ThingSpeak.h"
#include "WiFi.h"

//----------- Enter you Wi-Fi Details---------//
char ssid[] = "wildsoul"; //SSID
char pass[] = "funkey11"; // Password
//-------------------------------------------//

WiFiClient  client;

unsigned long myChannelField =  2400735; // Channel ID
const int ChannelField = 1; // Which channel to write data
//const int ChannelField1=2;
const char * myWriteAPIKey = "WAMGNWZV2DMRJGQ0"; // Your write API Key


int ld= 02;
int re=0;
//int led=26;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ld,INPUT);
 // pinMode(led,OUTPUT);
  WiFi.mode(WIFI_STA);
  ThingSpeak.begin(client);
}

void loop() {
  // put your main code here, to run repeatedly:
   if (WiFi.status() != WL_CONNECTED)
  {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    while (WiFi.status() != WL_CONNECTED)
    {
      WiFi.begin(ssid, pass);
      Serial.print(".");
      delay(5000);
    }
    Serial.println("\nConnected.");
  }

  re= analogRead(ld);  //storing the ldr value 

   if (isnan(re)) 
      {
        Serial.println("Failed to read from LDR sensor!");
        return;
      }

  // if(re<1000){
  //     digitalWrite(led,0);
  // }
  // else if(re>1000){
  //   digitalWrite(led,1);
  // }
  
  Serial.println(re);

  delay(1000);
  ThingSpeak.writeField(myChannelField, ChannelField, re, myWriteAPIKey);
  delay(1000);
}
