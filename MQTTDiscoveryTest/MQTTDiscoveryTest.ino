// This is an include file I have locally with my netework data.  Anything prefixed with "Hayfield" should be replaced in the sketch
#include <Hayfield.h>
#include "EspMQTTClient.h"

String discoveryTopic = "homeassistant/sensor/testsensor/config";
String discovery = "{\"name\": \"testsensor\", \"state_topic\": \"mystates/sensor/testsensor/state\" }";

int i = 0;
int millisecs = 0;
bool discoSent = false;

EspMQTTClient client(
  HayfieldSSID, // Wifi SSID
  HayfieldPSK,  // Wifi key
  HayfieldMQTTServer,  // MQTT Broker server ip
  "",   // Can be omitted if not needed
  "",   // Can be omitted if not needed
  "TestClientDiscovery",     // Client name that uniquely identify your device
  1883              // The MQTT port, default to 1883. this line can be omitted
);


void setup()
{
  Serial.begin(115200);  
  delay(1000);
  millisecs = millis();
}

void onConnectionEstablished()
{
  Serial.println(client.isConnected());
  client.enableDebuggingMessages(); // Enable debugging messages sent to serial output
}

void SendReadings()
{
  if(millis() > millisecs + 10000 && client.isConnected()) {
    millisecs = millis();
    i++;
    if(i > 40) { i = 10; }

    // had some issues with timing.  This fixed it.
    if(!discoSent) {
      Serial.println("Sending the discovery message");
      Serial.println(discoveryTopic);
      Serial.println(discovery);
      client.publish(discoveryTopic, discovery, true);
      discoSent = true;
    }

    client.publish("mystates/sensor/testsensor/state",(String)i);
  }
}

void loop()
{
  client.loop();
  SendReadings();
}
