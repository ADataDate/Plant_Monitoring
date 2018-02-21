# IoT Plant Monitoring
An IoT introductory project, sensing the status of your plant's soil moisture level, leaveraging Cayenne, an IOT platform,  as well as some SparkFun hardware. 

## Getting Started
Create an account with MyDevices: https://mydevices.com/
Once you have created an account, click on `All Devices` and select the SparkFun ESP8266 Thing Dev Board. 
From this page you'll see the steps required to connect as well as the info you need in your Arduino Sketch like the MQTT username and password, Client ID, server and port info and you can also name your board.

## Steps to Connect 
Install Arduino if you haven't done so already: https://www.arduino.cc/en/Main/Software 
Install the FTDI drivers: https://learn.sparkfun.com/tutorials/how-to-install-ftdi-drivers


### Install the ESP8266 Thing Dev Board add-on for Arduino
To begin, you’ll need to point the Arduino IDE board manager to a custom URL. Open up Arduino, then go to the Preferences (File > Preferences). Then, towards the bottom of the window, paste this URL into the “Additional Board Manager URLs” text box: - http://arduino.esp8266.com/stable/package_esp8266com_index.json 

You can add multiple URLs by clicking the window icon, and pasting in one URL per line. Hit OK, then navigate to the Board Manager by going to Tools > Boards > Boards Manager. Look for esp8266 by ESP8266 Comunity. Click on that entry, then select Install. Once the installation has completed, an Arduino-blue “INSTALLED” will appear next to the entry.

To select the ESP8266 Thing Dev board as your device navigate to Tools>Board:  > and choose "SparkFun ESP8266 Thing Dev" from the drop down menu (it will be towards the bottom). From the same Tools menu navigate to Port and select your board port ie: COM14 for Windows.


The next step is to add the Library that allows Arduino to talk to Cayenne. Go to Sketch > Include Library > Manage Libraries a menu will pop-up. Allow the Library Manager to update and then search for “Cayenne”. Select “Cayenne-MQTT-ESP8266”  and install. If this doesn't work see below. 

### Manual Install of Cayenne MQTT for ESP8266
Download this ZIP file found in the repo under Template. Install the downloaded zip library from Sketch -> Include Library -> Add .ZIP Library. Connect your ESP module to your computer using a USB to Serial FTDI or console cable. Select your ESP module and port from the Tools menu.

## Get and Push Your Plant Data

### Wifi
Open the Arduino IDE, have the ESP8266 Thing Dev board selected along with the correct serial port and the library installed. Look through the sketch and find `//WiFi Network info`. Enter the SSID and WiFi password inside the brackets. 

### Cayenne Authentication, Compile and Upload
Scroll through the sketch and look for `//Cayenne Authentication info` Insert the username, password and client ID given on your Cayenne Account page (connect your device). Once this is all finished click on the check mark buton at the top lef hand of the screen and see if it compiles. If not, let an instructor know. If everything is good click on the right arrow button at the top left and see if you program has uploaded to the device. Wait a few minutes and check your account on Cayenne as you should see the number of miliseconds your device has been running as well as a random-value (floating pin) for the soil moisture - Next we need to connect hardware.  


### Hardware
Part of this workshop will be setting up the hardware, so those instructions will not live here. Once your project is up and running - navigate to the user menu on the top right side of the  window and select `Triggers and Alerts`. Add a new trigger by naming it and then dragging the board name on the left side of the window into the `if` box. Then click on the `then` box and set up your email or phone number. When the event you choose happens you'll either get an email or a text message! Youcan also set up triggers and alerts from the Specific data block you want. We will cover that in the workshop as well. 


-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
### Why IoT??

The seamlessness of fitness trackers are a good starting point for answering this question. I can wear a device and it will log all sorts of biometric data which I can then parse through in a meaningful-graphical way and even storeon my phone or personal computer. I can update the way I live my life based on real-time data about my activity and body feedback (exercise, sleep, blood-sugar levels). While we are hacking our health I figured why not hack other areas of my life. 

IoT at SparkFun is an exciting fusion between hardware and the internet. In this project I am using the ESP8266 Thing Dev Board. This Arduino programmable developmenet board is designed around the ESP8266 Wifi enabled microcontroller. It has built-in FTDI USB-to-Serial so programming is a sinch.

### Not relevant to workshop 2/22
------------------------------------------------------------------------------------
There are two major drawbacks to this board. 1) Limited IO. 2)ADC voltage must be 1V MAX. To solve problem 1 I added an IO explander and a 16 channel MUX. Now this projec thas room to grow. The IO Expander handles the digital temperature readings and the analog MUX handles to analog soil moisture sensor readings. Eventually this project will also monitor air quality, light, humidity, pressure, and the environemntal temperature. To solve problem 2 I simply used a resistor divider circuit to scale the 3.3V output of the sensor to 1V max going into the ESP8266. R1= 1.38K and R2=600 OHMs. 

Currently this project is monitoring the soil moisture and soil temperature of the five plants shown in the pictures that normally live on my window sill. The data collected is then pushed to MyDevices' IoT platform, Cayenne. Getting Started with Cayenne with easy and quick. In this repo you will find the aruidno sketch I am using as well as a templete for getting started pushing time data to Cayenne within minutes on turning on the device. 

Once you have your project set up, navigate to the `user menu` and select `Triggers and Alerts`. From here, you can set up email and text message alerts based on events you set. My trigger sends me a text" "Water me!!" when the soil moisture is below a threshold I set. My plants will never be dry again!

Collecting data is a fine thing to do with hardware but analyzing and have a visual display of your data is even better. On your project page you can `download chart data`. What will you do with all this data? How will you visualize it and how might it improve your life? The art-info combo packs are a personal passion of mine so I am all about collecting more data than I know what to do with.   