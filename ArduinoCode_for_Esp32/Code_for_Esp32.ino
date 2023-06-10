#include <WiFi.h>
const char* ssid     = "ASK4 Wireless";//Ur wifi name
const char* password = "password";//Ur wifi password
IPAddress ComputerIP(10, 128, 142, 107);//COMPUTER IP
int OldOrangeValue = 0;
int OldAppleValue = 0;
WiFiUDP Udp;
void setup() {
 Serial.begin(115200);
 WiFi.begin(ssid, password);
 while(WiFi.status() != WL_CONNECTED) {
   delay(500);
   Serial.print(".");
 }
   Serial.println("WiFi connected");
   Udp.begin(8888);
}

void loop() {
   Serial.println(OldAppleValue);
   Serial.println(OldOrangeValue);
   delay(100);
  if(touchRead(4)<=OldAppleValue-20){
    Udp.beginPacket(ComputerIP, 3002);//Should be the same port in ue5
    Udp.print("Apple");
    Udp.endPacket();
   }
  if(touchRead(12)<=OldOrangeValue-20){
    Udp.beginPacket(ComputerIP, 3002);//Should be the same port in ue5
    Udp.print("Orange");
    Udp.endPacket();
  }
  OldAppleValue=touchRead(4);
  OldOrangeValue=touchRead(12);
}
