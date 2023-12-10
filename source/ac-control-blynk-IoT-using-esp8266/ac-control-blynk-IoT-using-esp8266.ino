/*************************************************************

  This is a simple demo of sending and receiving some data.
  Be sure to check out other examples!
 *************************************************************/

/* Fill-in information from Blynk Device Info here */

#define BLYNK_TEMPLATE_ID           "ID_testTestTest"    // Change to your BLYNK_TEMPLATE_ID
#define BLYNK_TEMPLATE_NAME         "Quickstart Device"  // Change to your BLYNK_TEMPLATE_NAME
#define BLYNK_AUTH_TOKEN            "Token_testTEstTest" // Change to your BLYNK_AUTH_TOKEN

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

#include <Arduino.h>
#include <IRremoteESP8266.h>
#include <IRsend.h>
#include <ESP8266WiFi.h>
#include "Blynk/src/BlynkSimpleEsp8266.h"

// A/C
const uint16_t kIrLed_sharp_1 = 16;  // ESP8266 GPIO pin to use. 16 -> D0
const uint16_t kIrLed_sharp_2 = 4;  // ESP8266 GPIO pin to use. 4 -> D2
const uint16_t kIrLed_sharp_3 = 14;  // ESP8266 GPIO pin to use. 14 -> D5
const uint16_t kIrLed_sharp_4 = 12;  // ESP8266 GPIO pin to use. 12 -> D6
const uint16_t kIrLed_aqua = 5;  // ESP8266 GPIO pin to use. 5 -> D1

#include "ac_setupp.h"
// A/C

String days, hours, minutes, seconds, days_time;

// NTP Client Library
#include "NTPClient.h"
//#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

const long utcOffsetInSeconds = 25200;

// Setting tanggal menjadi nama hari
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

// Define NTP Client to get time
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "id.pool.ntp.org", utcOffsetInSeconds);
// NTP Client Library

#define RELAY 0 // relay connected to  GPIO0
const uint16_t kIrLed = 2;  // ESP8266 GPIO pin to use. 2 -> (D4).
IRsend irsend(kIrLed);  // Set the GPIO to be used to sending the message.
uint16_t onoffTV[71] = {8876, 4696,  516, 548,  538, 522,  514, 548,  542, 520,
                        514, 546,  540, 522,  540, 1680,  540, 522,  514, 1702,  516, 1702,  514, 1704,
                        514, 1704,  514, 1704,  514, 1704,  514, 548,  540, 1680,  514, 546,  544, 1674,
                        516, 546,  540, 520,  542, 1676,  514, 548,  514, 548,  514, 546,  540, 1678,  514,
                        546,  514, 1704,  540, 1676,  516, 546,  514, 1702,  514, 1704,  542, 1676,  514,
                        41838,  8876, 2292,  514

                       };

// Your WiFi credentials.
// Set password to "" for open networks.
bool not_connect = false;
char ssid_1[] = "SSID"; // your wifi ssid
char pass_1[] = "password"; // your wifi password
char ssid_2[] = "SSID Backup"; // your wifi-backup ssid
char pass_2[] = "password"; // your wifi-backup password
String strData;
int wifi = 0;

// save millis() val
unsigned long int millis_save = 0;

WidgetTerminal terminal(V3);
int menu_redraw_required = 0;

BlynkTimer timer;

void setup()
{
  Serial.begin(115200);

  //  Serial.println("setup");
  //  Serial.println("setup");

  //  if ((EEPROM.read(1) >= 100))
  //    update_eeprom(1, 0);
  //
  //  if (EEPROM.read(1) == 0)
  //  {
  Serial.println("================================================= SSID_1");
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid_1, pass_1);
  //  }
  //  else
  //  {
  //    Serial.println("================================================= SSID_2");
  //    Blynk.begin(BLYNK_AUTH_TOKEN, ssid_2, pass_2);
  //  }

  //  Serial.println("Try Connect Wifi1");
  setup_IR();
  // You can also specify server:
  //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, "blynk.cloud", 80);
  //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, IPAddress(192,168,1,100), 8080);

  // Setup a function to be called every second
  //timer.setInterval(1000L, myTimerEvent);

  // Setup AC
  ac_setup();

  // NTP Client
  timeClient.begin();
  time_update();

  //  Serial.println("setup done");
}

void loop()
{
  //  Serial.println("loop");
  Blynk.run();
  timer.run();
  CheckConnection();
  // You can inject your own code or combine it with other sketches.
  // Check other examples on how to communicate with Blynk. Remember
  // to avoid delay() function!
  //  Serial.println(millis());

  timeClient.update();
  time_update();

#if MODUL == RIGHT
  Blynk.virtualWrite(V1, days_time);

#endif

  if ((days == "Saturday") && (hours == "8" || hours == "08") && (minutes == "40") && (seconds == "10"))
#if MODUL == RIGHT
    Blynk.virtualWrite(V2, ac_all_on());

#else
    Blynk.virtualWrite(V0, ac_all_on());

#endif

  if ((days == "Friday") && (hours == "19") && (minutes == "20") && (seconds == "10"))
#if MODUL == RIGHT
    Blynk.virtualWrite(V2, ac_all_vesper());

#else
    Blynk.virtualWrite(V0, ac_all_vesper());

#endif

  //  else if ((days == "Wednesday") && (hours == "15") && (minutes == "56") && (seconds == "10"))
  //    Blynk.virtualWrite(V2, ac_all_on());

  if (millis() >= 600000) // 10min
  {
    //      Serial.println("Reset");
#if MODUL == RIGHT
    Blynk.virtualWrite(V2, "Restart system... Please wait...");

#else
    Blynk.virtualWrite(V0, "Restart system... Please wait...");

#endif

    EEPROM.end();
    ESP.restart();
  }
}

void time_update()
{
  days = daysOfTheWeek[timeClient.getDay()];
  hours = timeClient.getHours();
  minutes = timeClient.getMinutes();
  seconds = timeClient.getSeconds();
  days_time = String(days + ", " + hours + ":" + minutes + ":" + seconds);
}

void CheckConnection()
{
  if (!Blynk.connected())
  {
    //    if (EEPROM.read(1) == 0)
    //      update_eeprom(1, 1); // change to ssid_2
    //    else
    //      update_eeprom(1, 0); // change to ssid_1

    Blynk.begin(BLYNK_AUTH_TOKEN, ssid_1, pass_1);
    //    //    Serial.println("Not Connect");
    //
    //    if (millis() >= 30000)
    //    {
    //      //      Serial.println("Reset");

#if MODUL == RIGHT
    Blynk.virtualWrite(V2, "Restart system... Please wait...");

#else
    Blynk.virtualWrite(V0, "Restart system... Please wait...");

#endif

    EEPROM.end();
    ESP.restart();
  }
}
