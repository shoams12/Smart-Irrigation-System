#include <WiFi.h>
#include <Wire.h>
#include <ESP32Servo.h>
#include <Arduino.h>
#include <Adafruit_NeoPixel.h>


#define LDR 32//not for web
#define PIN 33 // neopixels
#define NUMPIXELS 24

#define WATER_PIN 34//not for web
#define WATER_SENSOR_RAIN 35

#define LM75_addr 0x48
#define servo_pin 18
#define LED 25

// const char* ssid = "yaaqov13";
// const char* password = "29071972";

const char* ssid = "Avigail";
const char* password = "0534184025";

// const char* ssid = "MICHAL";
// const char* password = "55555555";

// const char* ssid = "ZTE_099AFB";
// const char* password = "27237836";

// const char* ssid = "netfree111";
// const char* password = " 0583202476";

WiFiClient client;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
 
float valtemp;  //holds the value for the temp sensor
int resval = 0;           // holds the value for the water sensor in container
int rainval=0;            // holds the value for the water sensor on roof
Servo my_servo;
String ligthLevel;
// bool is_roof_open_flag = false;
bool web_control_flag = false; // FLAG to control web or sensor
byte flag_print = 0;
WiFiServer server(80);
String request;

void setup() {
  delay(500);
  Serial.begin(115200);
  Wire.begin();
  pixels.begin();
  configTemp(LM75_addr);
  my_servo.attach(servo_pin);
  my_servo.write(0);
  pinMode(WATER_PIN, INPUT);
  pinMode(WATER_SENSOR_RAIN, INPUT);
  pinMode(LDR, INPUT);
  pinMode(LED, OUTPUT);
 
  connectToWifi();
  delay(5000);
  server.begin();
 
}

void loop() {
    client = server.available();
   if (client) {
    Serial.println("New client connected.");
    handleTheRequest();
    sendResponse();
    delay(1000);
    client.stop();
    Serial.println("Client disconnected.");
  }
 //-----------------------------
  
  // water_container_sensor();
     if(water_container_sensor()){
      digitalWrite(LED, HIGH);
    }else{
      digitalWrite(LED, LOW);
    }
   Serial.println(return_weather()); 
   
//automatic
 if (!web_control_flag) {
    // Automatic control when web control is off
    if (ldr_sensor())
      led_on();
    else
      led_off();

    // if temp high or there is rain
    if(is_open_roof() || rain_detect()) {
      open_roof_servo();
    }else{close_roof_servo();} 
    
  }
  
}