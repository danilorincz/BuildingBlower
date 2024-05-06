//#include <WiFi.h>
//#include <AsyncTCP.h>
//#include <ESPAsyncWebServer.h>
//#include <AsyncElegantOTA.h>
// #include <ArduinoJson.h>
// #include <Preferences.h>
#include "FC-102_driver.h"
/*
// #define home
#define work

//? WIFI
#ifdef work
const char *ssid = "dentartwork";
const char *password = "tutititkos444";
IPAddress staticIP(192, 168, 5, 52);
IPAddress gateway(192, 168, 5, 1);
IPAddress subnet(255, 255, 255, 0);
#endif

#ifdef home
const char *ssid = "Lorincz";
const char *password = "ccLorincz2020cc";
IPAddress staticIP(192, 168, 22, 52);
IPAddress gateway(192, 168, 22, 1);
IPAddress subnet(255, 255, 255, 0);
#endif
*/
//? PINS
#define START_PIN 19
#define DIR_PIN 18
#define SPEED_PIN 33

FC_102 blower(START_PIN, DIR_PIN, SPEED_PIN);

void setup()
{
    Serial.begin(115200);
    blower.begin();
}

void loop()
{
    blower.forward();
    blower.start();
    blower.setSpeed(10);
    delay(2000);

    blower.forward();
    blower.stop();
    blower.setSpeed(40);
    delay(2000);

    blower.backward();
    blower.start();
    blower.setSpeed(90);
    delay(2000);

    blower.backward();
    blower.stop();
    blower.setSpeed(100);
    delay(2000);
}