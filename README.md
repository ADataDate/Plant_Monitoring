# Plant_Monitoring
IoT project using Cayenne  and ESP8266 Thing Dev Board

## Getting Started
Create an account with MyDevices: https://mydevices.com/
Once you have created an account, click on `All Devices` and select the SparkFun ESP8266 Thing Dev Board. 
From this page you'll see the steps required to connect as well as the info you need in your Arduino Sketch like the MQTT username and password, Client ID, server and port info and you can also name your baord.

Be sure to install the Cayenne libraries.

Once your project is up and running - navigate to the user menu on the top right side of the  window and slect `Triggers and Alerts`. Add a new trigger by naming it and then dragging the board name on the left side of the window into the `if` box. 
Then click on the `then` box and set up your email or phone number. When the event you choose happens you'll either get an email or a text message! 

In this Repo, in the folder named IoP, you'll find a template to help you get started even faster. 

## Hardware Required
http://sfe.io/w142042
You will also need hook-up wire, soldering iron and solder, a power supply, plastic wrap for the temp sensors, and heat shrink. 

## Helpful Data Processing info
For those aquainted with Python:
http://matplotlib.org/index.html

FusionCharts:
https://www.fusioncharts.com/

HighCharts:
https://www.highcharts.com/

DataWrapper:
https://www.datawrapper.de/

I'm a fan of dataWrapper for those who do not want to program. It all cut/paste and design around templates on the site. 


## Why IoT??

The seamlessness of fitness trackers are a good starting point for answering this question. I can wear a device and it will log all sorts of biometric data 
which I can then parse through in a meaningful-graphical way on my phone or personal computer. I can update the way I live my life based on real-time data 
about how I am living (exercise, sleep, blood-sugar levels). While we are hacking our health I figured why not hack other areas of my life. 

The internet of things at SparkFun is an exciting fusion between hardware and the internet. In this project I am using the ESP8266 Thing Dev Board. This Arduino
programmable developmenet board is designed aroun the ESP8266 Wifi enabled microcontroller. It has built-in FTDI USB-to-Serial so programming is a sinch. 

There are two major drawbacks to this board. 1) Limited IO. 2)ADC voltage must be 1V MAX. To solve problem 1 I added an IO explander and a 16 channel MUX. Now this project
has room to grow. The IO Expander handles the digital temperature readings and the analog MUX handles to analog soil moisture sensor readings. Eventually this project will
also monitor air quality, light, humidity, pressure, and the environemntal temperature. To solve problem 2 I simply used a resitor divider circuit to scale the 3.3V output
of the sensor to 1V max going into the ESP8266. R1= 1.38K and R2=600 OHMs. 

Currently this project is monitoring the soil moisture and soil temoerature od the five plants shown in the pictures that normally live on my window sill. The data collected
is then pushed to MyDevices' IoT platform, Cayenne. Getting Started with Cayenne with easy and quick. In this repo you will find the aruidno sketch I am using as well as a templete 
for getting started pushing time data to Cayenne within minutes on turning on the device. 

Once you have your project set up, navigate to the `user menu` and select `Triggers and Alerts`. From here, you can set up email and text message alerts based on events you set. My trigger
sends me a text" "Water me!!" when the soil moisture is below a threshold I set. My plants will never be dry again!

Collecting data is a fine thing to do with hardware but analyzing and have a visual display of your data is even better. On your project page you can `download chart data`. What will
you do with all this data? How will you visualize it and how might it improve your life? The art-info combo packs are a personal passion of mine so I am all about collecting more data than 
I know what to do with.  This repo also contains links to data processing tools like matplotlib fo rpython, and datawrapper. 