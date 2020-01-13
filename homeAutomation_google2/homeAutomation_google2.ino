//Google Assistant Home Automation
#include <ESP8266WiFi.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"

#define Relay1            D1
#define Relay2            D2
#define Relay3            D3
#define Relay4            D4
#define Relay5            D5

#define WLAN_SSID       "***"             // Your SSID
#define WLAN_PASS       "********"        // Your password

/************************* Adafruit.io Setup *********************************/

#define AIO_SERVER      "io.adafruit.com" //Adafruit Server
#define AIO_SERVERPORT  1883                   
#define AIO_USERNAME    "*****8"            // Username
#define AIO_KEY         "fc9388eb1472cb61f0176ea9327fd"   // Auth Key

//WIFI CLIENT
WiFiClient client;

Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);

Adafruit_MQTT_Subscribe Light1 = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME"/feeds/Relay1"); // Feeds name should be same everywhere
Adafruit_MQTT_Subscribe Light2 = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/Relay2");
Adafruit_MQTT_Subscribe Light3 = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/Relay3");
Adafruit_MQTT_Subscribe Light4 = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/Relay4");
Adafruit_MQTT_Subscribe Light5 = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/Relay5");
Adafruit_MQTT_Subscribe Light6 = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/Resetall");

char data = 0; 
String  i;
WiFiServer server(80);

void MQTT_connect();

void setup() {
  Serial.begin(9600);
  i = ' ' ;

  pinMode(Relay1, OUTPUT);
  pinMode(Relay2, OUTPUT);
  pinMode(Relay3, OUTPUT);
  pinMode(Relay4, OUTPUT);
  pinMode(Relay5, OUTPUT);

  
  // Connect to WiFi access point.
  Serial.println(); Serial.println();
  Serial.print("Connecting to ");
  Serial.println(WLAN_SSID);

  WiFi.begin(WLAN_SSID, WLAN_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print("...");
  }
  Serial.println();

  Serial.println("WiFi connected");
  Serial.println("IP address: "); 
  Serial.println(WiFi.localIP());

  server.begin();
 
  mqtt.subscribe(&Light1);
  mqtt.subscribe(&Light3);
  mqtt.subscribe(&Light2);
  mqtt.subscribe(&Light4);
  mqtt.subscribe(&Light5);
  mqtt.subscribe(&Light6);
}

void loop() {
 
  {MQTT_connect();
  
  Adafruit_MQTT_Subscribe *subscription;
  while ((subscription = mqtt.readSubscription(20000))) {
    if (subscription == &Light1) {
      Serial.print(F("Got: "));
      Serial.println((char *)Light1.lastread);
      int Light1_State = atoi((char *)Light1.lastread);
      digitalWrite(Relay1, Light1_State);
      
    }
    if (subscription == &Light2) {
      Serial.print(F("Got: "));
      Serial.println((char *)Light2.lastread);
      int Light2_State = atoi((char *)Light2.lastread);
      digitalWrite(Relay2, Light2_State);
    }
    if (subscription == &Light3) {
      Serial.print(F("Got: "));
      Serial.println((char *)Light3.lastread);
      int Light3_State = atoi((char *)Light3.lastread);
      digitalWrite(Relay3, Light3_State);
    }
    if (subscription == &Light4) {
      Serial.print(F("Got: "));
      Serial.println((char *)Light4.lastread);
      int Light4_State = atoi((char *)Light4.lastread);
      digitalWrite(Relay4, Light4_State);
      
    }
      if (subscription == &Light5) {
      Serial.print(F("Got: "));
      Serial.println((char *)Light5.lastread);
      int Light5_State = atoi((char *)Light5.lastread);
      digitalWrite(Relay5, Light5_State);
      
    }
     if (subscription == &Light6) {
      Serial.print(F("Got: "));
      Serial.println((char *)Light6.lastread);
      int Light6_State = atoi((char *)Light6.lastread);
      digitalWrite(Relay1, Light6_State);
      Serial.println("relay1 OFF");
      digitalWrite(Relay2, Light6_State);
      Serial.println("relay2 OFF");
      digitalWrite(Relay3, Light6_State);
      Serial.println("relay3 OFF");
      digitalWrite(Relay4, Light6_State);
      Serial.println("relay4 OFF");
      digitalWrite(Relay5, Light6_State);
      Serial.println("relay5 OFF");
      
    }
  }
  }
BT_connect();
App_Wifi();

}





