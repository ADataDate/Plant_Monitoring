#include <SparkFunSX1509.h> //Library for the SX1509 IO Expander
#include <OneWire.h> //Library for the DS18B20 One-wire temp sensor 
//#include <SparkFunCCS811.h> //Library for the CCS811 Air Quality Sensor
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

#if 0 
//Air Quality Sensor 
#define CCS811_ADDR 0x5B //Default I2C Address
CCS811 mySensor(CCS811_ADDR);
#endif


//SX1509 IO Expander
const byte SX1509_ADDRESS = 0x3E;  // SX1509 I2C address
SX1509 io; // Create an SX1509 object to be used throughout
const byte SX1509_PWR_SM1 = 12; // Soil Moisture 1 VCC
const byte SX1509_PWR_SM2 = 11; // Soil Moisture 2 VCC
const byte SX1509_PWR_SM3 = 10; // Soil Moisture 3 VCC
const byte SX1509_PWR_SM4 = 9; // Soil Moisture 4 VCC
const byte SX1509_PWR_SM5 = 8; // Soil Moisture 5 VCC


//MUX Control Pins
int s0 = 4;
int s1 = 13;
int s2 = 12;
int s3 = 16;
int SIG_pin = A0; 

// WiFi network info.
char ssid[] = "sparkfun-guest";
char wifiPassword[] = "sparkfun6333";

// Cayenne authentication info. This should be obtained from the Cayenne Dashboard.
char username[] = "601aa000-6fb9-11e7-a036-7dfc05936e4e";
char password[] = "aab2fbba5ec8b37cb54f1aeccc9e24109fb29e11";
char clientID[] = "9ca1ebc0-714c-11e7-bc8f-4d8331e13947";

unsigned long lastMillis = 0;


void setup() {
  Serial.begin(9600);
  Cayenne.begin(username, password, clientID, ssid, wifiPassword);
  Serial.println("Internet of Plants!!!");

 


  /
  

  //Analog MUX set up:
  pinMode(s0, OUTPUT); 
  pinMode(s1, OUTPUT); 
  pinMode(s2, OUTPUT); 
  pinMode(s3, OUTPUT); 

  digitalWrite(s0, LOW);
  digitalWrite(s1, LOW);
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);
  
}

void loop() {
  Cayenne.loop();




  //Get Soil Moisture Readings
  //The Soil Moisture Sensors are powered by the output pin on the IO Expander
  //The raw adc value come from pins C5-C9 on the 16-Channel Analog Mux

  //Get Soil Moisture Levels from Sensor 1:
  io.digitalWrite(SX1509_PWR_SM1, HIGH);
  delay(500); // Delay half-a-second
  int SM1 = readMux(9);
  delay(500);
  io.digitalWrite(SX1509_PWR_SM1, LOW); // Set the I/O low
  Serial.print("SM1:  ");
  Serial.println(SM1);


  //Get Soil Moisture Levels from Sensor 2:
  io.digitalWrite(SX1509_PWR_SM2, HIGH);
  delay(500); // Delay half-a-second
  int SM2 = readMux(8);
  delay(500);
  io.digitalWrite(SX1509_PWR_SM2, LOW); // Set the I/O low
  Serial.print("SM2:  ");
  Serial.println(SM2);

  //Get Soil Moisture Levels from Sensor 3:
  io.digitalWrite(SX1509_PWR_SM3, HIGH);
  delay(500); // Delay half-a-second
  int SM3 = readMux(7);
  delay(500);
  io.digitalWrite(SX1509_PWR_SM3, LOW); // Set the I/O low
  Serial.print("SM3:  ");
  Serial.println(SM3);  

  //Get Soil Moisture Levels from Sensor 4:
  io.digitalWrite(SX1509_PWR_SM4, HIGH);
  delay(500); // Delay half-a-second
  int SM4 = readMux(6);
  delay(500);
  io.digitalWrite(SX1509_PWR_SM4, LOW); // Set the I/O low
  Serial.print("SM4:  ");
  Serial.println(SM4);

  
  //Get Soil Moisture Levels from Sensor 5:
  io.digitalWrite(SX1509_PWR_SM5, HIGH);
  delay(500); // Delay half-a-second
  int SM5 = readMux(5);
  delay(500);
  io.digitalWrite(SX1509_PWR_SM5, LOW); // Set the I/O low
  Serial.print("SM5:  ");
  Serial.println(SM5);

  

  float adc0 = readMux(0);
  float volt0 = adc0*0.00097752;
  float degc0 = (volt0 -0.5)*100.0;
  float temp1 = degc0 *(9.0/5.0)+32.0;  
  delay(500);
  Serial.print("Temp1:  ");
  Serial.println(temp1);

  float adc1 = readMux(1);
  float volt1 = adc1*0.00097752;
  float degc1 = (volt1 -0.5)*100.0;
  float temp2 = degc1 *(9.0/5.0)+32.0;  
  delay(500);
  Serial.print("Temp2:  ");
  Serial.println(temp2);

  float adc2 = readMux(2);
  float volt2 = adc2*0.00097752;
  float degc2 = (volt2 -0.5)*100.0;
  float temp3 = degc2 *(9.0/5.0)+32.0;
  delay(500);  
  Serial.print("Temp3:  ");
  Serial.println(temp3);
    
  float adc3 = readMux(3);
  float volt3 = adc3*0.00097752;
  float degc3 = (volt3 -0.5)*100.0;
  float temp4 = degc3 *(9.0/5.0)+32.0;
  delay(500);
  Serial.print("Temp4:  ");
  Serial.println(temp4);  
    
  float adc4 = readMux(4);
  float volt4 = adc4*0.00097752;
  float degc4 = (volt4 -0.5)*100.0;
  float temp5 = degc4 *(9.0/5.0)+32.0;
  delay(500);  
  Serial.print("Temp5:  ");
  Serial.println(temp5);  

  //Publish data every  2 minutes (120000 milliseconds). Change this value to publish at a different interval.
  if (millis() - lastMillis > 120000) {
    lastMillis = millis();
    //Write data to Cayenne here. This example just sends the current uptime in milliseconds.
    Cayenne.virtualWrite(0, lastMillis);
    Cayenne.virtualWrite(1, SM1);
    Cayenne.virtualWrite(2, SM2);
    Cayenne.virtualWrite(3, SM3);
    Cayenne.virtualWrite(4, SM4);
    Cayenne.virtualWrite(5, SM5);
    Cayenne.virtualWrite(6, temp1);
    Cayenne.virtualWrite(7, temp2);
    Cayenne.virtualWrite(8, temp3);
    Cayenne.virtualWrite(9, temp4);
    Cayenne.virtualWrite(10, temp5);
    Cayenne.virtualWrite(11, LIGHT);
    //Cayenne.virtualWrite(12, readCO2);
   // Cayenne.virtualWrite(13, readTVOC);
  }

 
}

//Default function for processing actuator commands from the Cayenne Dashboard.
//You can also use functions for specific channels, e.g CAYENNE_IN(1) for channel 1 commands.
CAYENNE_IN_DEFAULT()
{
  CAYENNE_LOG("CAYENNE_IN_DEFAULT(%u) - %s, %s", request.channel, getValue.getId(), getValue.asString());
  //Process message here. If there is an error set an error message using getValue.setError(), e.g getValue.setError("Error message");
}
int readMux(int channel){
  int controlPin[] = {s0, s1, s2, s3};

  int muxChannel[16][4]={
    {0,0,0,0}, //channel 0
    {1,0,0,0}, //channel 1
    {0,1,0,0}, //channel 2
    {1,1,0,0}, //channel 3
    {0,0,1,0}, //channel 4
    {1,0,1,0}, //channel 5
    {0,1,1,0}, //channel 6
    {1,1,1,0}, //channel 7
    {0,0,0,1}, //channel 8
    {1,0,0,1}, //channel 9
    {0,1,0,1}, //channel 10
    {1,1,0,1}, //channel 11
    {0,0,1,1}, //channel 12
    {1,0,1,1}, //channel 13
    {0,1,1,1}, //channel 14
    {1,1,1,1}  //channel 15
  };

  //loop through the 4 sig
  for(int i = 0; i < 4; i ++){
    digitalWrite(controlPin[i], muxChannel[channel][i]);
  }

  //read the value at the SIG pin
  int val = analogRead(SIG_pin);

  //return the value
  return val;
}

