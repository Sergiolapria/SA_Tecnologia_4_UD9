#include <Arduino.h>
#include "WiFi.h"
#include "PubSubClient.h"
#include "confidencial.h"
#include "AHT10.h"
#include "Wire.h"
#include <VEML6075.h>
long lastMsg=0;
char msg[50];
int value=0;
int IDsensor=0;
bool IDAHT=false;
bool IDVML=false;

float temp=0;
float hum=0;
float UVA_level=0;
float UVB_level=0;
float UV_level=0;
/*PINES
SDA           SCL
GPIO21/D21    GPIO22/D22
*/
AHT10 myAHT10(AHT10_ADDRESS_0X38);
VEML6075 veml6075 = VEML6075();

WiFiClient Grupo;//
PubSubClient client(Grupo);
void setup_wifi(){
  delay(10);
  Serial.print("Conectando a .....");
  Serial.println(ssid);
  WiFi.begin(ssid,psk);
  while(WiFi.status()!=WL_CONNECTED){
    delay(200);
    Serial.print(".");
  }
  Serial.print("Conectado a la Wifi con la IP: ");
  Serial.println(WiFi.localIP());
}
void callback(char* topic, byte* message, unsigned int length){
  Serial.print("Te ha llegado un mensaje con el topico:");
  Serial.print(topic);
  Serial.print("MENSAJE:");
  String messageTemp;
  for (int i = 0; i < length; i++) {
    Serial.print((char)message[i]);
    messageTemp += (char)message[i];
  }
  Serial.println();

}
void reconnect(){
  //loop mientras se reconnecta
  while (!client.connected()) {
    Serial.print("Esperando MQTT connection...");
    // Attempt to connect
    if (client.connect("Client")) {
      Serial.println("conectado");
      // Subscribe
      client.subscribe("esp32/output");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}
void setup() {
  Serial.begin(9600);
  //Coenexion WiFi
  setup_wifi();
  //Configuracion MQTT
  client.setServer(mqtt_broker,1883);
  client.setCallback(callback);
  if(!myAHT10.begin()){
    Serial.println("AHT10 no conectado");
    IDAHT=false;
  } else{
    IDAHT=true;
  }
  if(!veml6075.begin()){
    Serial.println("VEML no conectado");
    IDVML=false;
  }else {
    IDsensor=true;
  }

}
void sendTemp(float value){
  char tempString[8];
  dtostrf(value, 1, 2, tempString);
  client.publish("GRUPO/temperatura",tempString);
}
void sendHum(float value){
  char humString[8];
  dtostrf(value, 1, 2, humString);
  client.publish("GRUPO/humedad",humString);
}void sendUV(float value){
  char UVString[8];
  dtostrf(value, 1, 2, UVString);
  client.publish("GRUPO/UV",UVString);
}
void loop() {
    if (!client.connected()) {
    reconnect();
  }
  client.loop();

  long now = millis();
  if (now - lastMsg > 5000) {
    lastMsg = now;
  if(IDAHT==true){
        temp=myAHT10.readTemperature(AHT10_FORCE_READ_DATA);
        hum=myAHT10.readHumidity(AHT10_FORCE_READ_DATA);
        sendTemp(temp);
        sendHum(hum);
  }
  if(IDVML==true){
    UVA_level=veml6075.getUVA();
    UVB_level=veml6075.getUVB();
    UV_level=veml6075.getUVIndex();
    sendUV(UV_level);
  }
  
  }
}