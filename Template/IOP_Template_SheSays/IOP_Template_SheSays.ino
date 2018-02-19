//Add addiotnal libraries as needed. 
#include <Wire.h>
#include <SPI.h>
#include <Client.h>
#include <CayenneArduinoDefines.h>
#include <CayenneArduinoMQTTClient.h>
#include <CayenneHandlers.h>
#include <CayenneMessage.h>
#include <CayenneMQTTESP8266.h>
#include <CayenneMQTTWiFiClient.h>
#include <DetectDevice.h>

// This example shows how to connect to Cayenne using an ESP8266 and send/receive sample data.
// Make sure you install the ESP8266 Board Package via the Arduino IDE Board Manager and select the correct ESP8266 board before compiling. 

//#define CAYENNE_DEBUG
#define CAYENNE_PRINT Serial



// WiFi network info.
char ssid[] = ""; //Place your SSID within the quotations
char wifiPassword[] = ""; //Place your wifi password within the quotations 

// Cayenne authentication info. This should be obtained from the Cayenne Dashboard.
char username[] = ""; //Place username from your account within the quotations
char password[] = ""; //Place password from your account within the quotations. 
char clientID[] = ""; //Place Client ID from your account within the quotations. 

unsigned long lastMillis = 0;

//Analog SIG pin on Soil Moisture Sensor
int SIG_pin = A0; 

//Soil Moisture power pin
int PWR = 4;



void setup() {
  Serial.begin(9600);
  Cayenne.begin(username, password, clientID, ssid, wifiPassword);
  Serial.println("She Says in the house!");

  pinMode(PWR, OUTPUT);
  digitalWrite(PWR, LOW);
}

void loop() {
  Cayenne.loop();

 

  //Publish data every  2 minutes (120000 milliseconds). Change this value to publish at a different interval.
  if (millis() - lastMillis > 120000) {
    lastMillis = millis();
    //Write data to Cayenne here. This example just sends the current uptime in milliseconds.
    Cayenne.virtualWrite(0, lastMillis);

    //Set PWR for Soil Moisture Sensor high, take a reading, set PWR Low
    //View data on serial monitor and then publish data to Cayenne's platform. 
    digitalWrite(PWR, HIGH);
    delay(500);
    int SoilMoisture = analogRead(SIG_pin);
    delay(500);
    digitalWrite(PWR, LOW);

    //Print Values
    Serial.print("Soil Moisture Level: ");
    Serial.print(SoilMoisture);

    //Publish to Cayenne
    Cayenne.virtualWrite(1, SoilMoisture);
  }
}

//With this code you should see "millis" posted to your account. 

//Default function for processing actuator commands from the Cayenne Dashboard.
//You can also use functions for specific channels, e.g CAYENNE_IN(1) for channel 1 commands.
CAYENNE_IN_DEFAULT()
{
  CAYENNE_LOG("CAYENNE_IN_DEFAULT(%u) - %s, %s", request.channel, getValue.getId(), getValue.asString());
  //Process message here. If there is an error set an error message using getValue.setError(), e.g getValue.setError("Error message");
}


