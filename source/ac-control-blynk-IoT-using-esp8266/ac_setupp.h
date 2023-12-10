#pragma once

#define RIGHT 0
#define LEFT 1

#define MODUL RIGHT

#include <Arduino.h>
#include <IRremoteESP8266.h>
#include <IRsend.h>
#include <ir_Gree.h>
#include <ir_Haier.h>
#include <EEPROM.h>

/*
  uint8_t data_ac_sharp_1[3] = {0, 0, 0}; // index 0 buat off-on, index 1 buat derajat temp, index 2 buat turbo off-on
  Change to EEPROM addr 10, 11, 12

  uint8_t data_ac_sharp_2[3] = {0, 0, 0}; // index 0 buat off-on, index 1 buat derajat temp, index 2 buat turbo off-on
  Change to EEPROM addr 20, 21, 22

  uint8_t data_ac_sharp_3[3] = {0, 0, 0}; // index 0 buat off-on, index 1 buat derajat temp, index 2 buat turbo off-on
  Change to EEPROM addr 30, 31, 32

  uint8_t data_ac_aqua[3] = {0, 0, 0}; // index 0 buat off-on, index 1 buat derajat temp, index 2 buat turbo off-on
  Change to EEPROM addr 40, 41, 42
*/

#if MODUL == RIGHT
String ac_ac = "R";

#else
String ac_ac = "L";

#endif

#define sharp_1 0
#define sharp_2 1
#define sharp_3 2
#define aqua_ac 3
#define sharp_4 4

/*
  const uint16_t kIrLed_sharp_1 = 0;  // ESP8266 GPIO pin to use. 0 -> D3
  const uint16_t kIrLed_sharp_2 = 16;  // ESP8266 GPIO pin to use. 16 -> D0
  const uint16_t kIrLed_sharp_3 = 5;  // ESP8266 GPIO pin to use. 5 -> D1
  const uint16_t kIrLed_aqua = 4;  // ESP8266 GPIO pin to use. 4 -> D2
*/

IRGreeAC ac_sharp_1(kIrLed_sharp_1);  // Set the GPIO to be used for sending messages.
IRGreeAC ac_sharp_2(kIrLed_sharp_2);  // Set the GPIO to be used for sending messages.
IRGreeAC ac_sharp_3(kIrLed_sharp_3);  // Set the GPIO to be used for sending messages.
IRGreeAC ac_sharp_4(kIrLed_sharp_4);  // Set the GPIO to be used for sending messages.
IRHaierACYRW02 ac_aqua(kIrLed_aqua);  // Set the GPIO to be used for sending messages.

void update_eeprom(int addr, int val)
{
  if (EEPROM.read(addr) != val) EEPROM.write(addr, val);
}

void eeprom_check()
{
  if ((EEPROM.read(10) >= 100) || (EEPROM.read(20) >= 100) || (EEPROM.read(30) >= 100) || (EEPROM.read(40) >= 100) || (EEPROM.read(50) >= 100))
  {
    update_eeprom(10, 0);
    update_eeprom(20, 0);
    update_eeprom(30, 0);
    update_eeprom(40, 0);
    update_eeprom(50, 0);
  }

  if ((EEPROM.read(11) >= 100) || (EEPROM.read(21) >= 100) || (EEPROM.read(31) >= 100) || (EEPROM.read(41) >= 100) || (EEPROM.read(51) >= 100))
  {
    update_eeprom(11, 0);
    update_eeprom(21, 0);
    update_eeprom(31, 0);
    update_eeprom(41, 0);
    update_eeprom(51, 0);
  }

  if ((EEPROM.read(12) >= 100) || (EEPROM.read(22) >= 100) || (EEPROM.read(32) >= 100) || (EEPROM.read(42) >= 100) || (EEPROM.read(52) >= 100))
  {
    update_eeprom(12, 0);
    update_eeprom(22, 0);
    update_eeprom(32, 0);
    update_eeprom(42, 0);
    update_eeprom(52, 0);
  }
}

void printStateAC(int ac)
{
  if (ac == 0)
  {
    // Display the settings.
    Serial.println("SHARP_1 A/C remote is in the following state:");
    Serial.printf("  %s\n", ac_sharp_1.toString().c_str());
    // Display the encoded IR sequence.
    unsigned char* ir_code = ac_sharp_1.getRaw();
    Serial.print("IR Code: 0x");
    for (uint8_t i = 0; i < kGreeStateLength; i++)
      Serial.printf("%02X", ir_code[i]);
    Serial.println();
  }

  if (ac == 1)
  {
    Serial.println("SHARP_2 A/C remote is in the following state:");
    Serial.printf("  %s\n", ac_sharp_2.toString().c_str());
    // Display the encoded IR sequence.
    unsigned char* ir_code = ac_sharp_2.getRaw();
    Serial.print("IR Code: 0x");
    for (uint8_t i = 0; i < kGreeStateLength; i++)
      Serial.printf("%02X", ir_code[i]);
    Serial.println();
  }

  if (ac == 2)
  {
    Serial.println("SHARP_3 A/C remote is in the following state:");
    Serial.printf("  %s\n", ac_sharp_3.toString().c_str());
    // Display the encoded IR sequence.
    unsigned char* ir_code = ac_sharp_3.getRaw();
    Serial.print("IR Code: 0x");
    for (uint8_t i = 0; i < kGreeStateLength; i++)
      Serial.printf("%02X", ir_code[i]);
    Serial.println();
  }

  if (ac == 3)
  {
    Serial.println("AQUA A/C remote is in the following state:");
    Serial.printf("  %s\n", ac_aqua.toString().c_str());
    // Display the encoded IR sequence.
    unsigned char* ir_code = ac_aqua.getRaw();
    Serial.print("IR Code: 0x");
    for (uint8_t i = 0; i < kGreeStateLength; i++)
      Serial.printf("%02X", ir_code[i]);
    Serial.println();
  }

  if (ac == 4)
  {
    Serial.println("SHARP_4 A/C remote is in the following state:");
    Serial.printf("  %s\n", ac_sharp_4.toString().c_str());
    // Display the encoded IR sequence.
    unsigned char* ir_code = ac_sharp_4.getRaw();
    Serial.print("IR Code: 0x");
    for (uint8_t i = 0; i < kGreeStateLength; i++)
      Serial.printf("%02X", ir_code[i]);
    Serial.println();
  }
}

void ac_setup() {
  EEPROM.begin(512); // Eeprom esp8266 example
  eeprom_check(); // check value eeprom

#if MODUL == RIGHT
  Blynk.virtualWrite(V2, "System on... Send command...");

#else
  Blynk.virtualWrite(V0, "System on... Send command...");

#endif

  ac_sharp_1.begin();
  //  ac_sharp_1.setFan(3); // 1
  ac_sharp_1.setMode(kGreeCool);
  ac_sharp_1.setSwingVertical(true, kGreeSwingAuto);
  //  ac_sharp_1.setXFan(true);
  ac_sharp_1.setLight(true);
  ac_sharp_1.setSleep(false);

  ac_sharp_2.begin();
  //  ac_sharp_2.setFan(3); // 1
  ac_sharp_2.setMode(kGreeCool);
  ac_sharp_2.setSwingVertical(true, kGreeSwingAuto);
  //  ac_sharp_2.setXFan(true);
  ac_sharp_2.setLight(true);
  ac_sharp_2.setSleep(false);

  ac_sharp_3.begin();
  //  ac_sharp_3.setFan(3); // 1
  ac_sharp_3.setMode(kGreeCool);
  ac_sharp_3.setSwingVertical(true, kGreeSwingAuto);
  //  ac_sharp_3.setXFan(true);
  ac_sharp_3.setLight(true);
  ac_sharp_3.setSleep(false);

  ac_aqua.begin();
  //  ac_aqua.setFan(3); // 1
  ac_aqua.setMode(kHaierAcYrw02Cool); // kHaierAcYrw02Cool // kGreeAuto, kGreeDry, kGreeCool, kGreeFan, kGreeHeat
  ac_aqua.setSwingV(kHaierAcYrw02SwingVAuto); // kHaierAcYrw02SwingVOff // kHaierAcYrw02SwingVAuto // kHaierAcYrw02SwingVTop // kHaierAcYrw02SwingVMiddle // kHaierAcYrw02SwingVBottom // kHaierAcYrw02SwingVDown
  //  ac_aqua.setFan(true);
  //    ac_aqua.setLight(true);
  ac_aqua.setSleep(false);

  ac_sharp_4.begin();
  //  ac_sharp_4.setFan(3); // 1
  ac_sharp_4.setMode(kGreeCool);
  ac_sharp_4.setSwingVertical(true, kGreeSwingAuto);
  //  ac_sharp_4.setXFan(true);
  ac_sharp_4.setLight(true);
  ac_sharp_4.setSleep(false);

  Serial.begin(115200);
  delay(200);

  // Set up what we want to send. See ir_Gree.cpp for all the options.
  // Most things default to off.
  Serial.println("Default state of the remote.");
  for (int i = 0; i <= 4; i++)
    printStateAC(i); // print info all A/C
  Serial.println("Setting desired state for A/C.");

#if MODUL == RIGHT
  Blynk.virtualWrite(V2, String(String("Ready... R-> 0: " + String((EEPROM.read(51) * EEPROM.read(50))))
                                + String(", 1: " + String((EEPROM.read(11) * EEPROM.read(10))))
                                + String(", 2: " + String((EEPROM.read(41) * EEPROM.read(40))))
                                + String(", 3: " + String((EEPROM.read(21) * EEPROM.read(20))))
                                + String(", 4: " + String((EEPROM.read(31) * EEPROM.read(30))))));

#else
  Blynk.virtualWrite(V0, String(String("Ready... L-> 0: " + String((EEPROM.read(51) * EEPROM.read(50))))
                                + String(", 1: " + String((EEPROM.read(41) * EEPROM.read(40))))
                                + String(", 2: " + String((EEPROM.read(11) * EEPROM.read(10))))
                                + String(", 3: " + String((EEPROM.read(21) * EEPROM.read(20))))
                                + String(", 4: " + String((EEPROM.read(31) * EEPROM.read(30))))));

#endif

  /*
    ac_sharp_1.on();
    ac_sharp_1.off();
    ac_sharp_1.setFan(1);
    // kGreeAuto, kGreeDry, kGreeCool, kGreeFan, kGreeHeat
    ac_sharp_1.setMode(kGreeCool);
    ac_sharp_1.setTemp(20);  // 16-30C
    ac_sharp_1.setSwingVertical(true, kGreeSwingAuto);
    ac_sharp_1.setXFan(false);
    ac_sharp_1.setLight(false);
    ac_sharp_1.setSleep(false);
    ac_sharp_1.setTurbo(false);
  */
}

String ac_update(bool ac1, bool ac2, bool ac3, bool ac4, bool ac5, double delay_)
{
#if MODUL == RIGHT
  Blynk.virtualWrite(V2, "Updating... Please wait...");

#else
  Blynk.virtualWrite(V0, "Updating... Please wait...");

#endif

  // Set AC on/off
  if (EEPROM.read(10))
  {
    ac_sharp_1.on();
    ac_sharp_1.setFan(3); // 1
    ac_sharp_1.setXFan(true);
  }
  else
  {
    ac_sharp_1.off();
    ac_sharp_1.setFan(0); // 1
    ac_sharp_1.setXFan(false);
  }

  // Set AC on/off
  if (EEPROM.read(20))
  {
    ac_sharp_2.on();
    ac_sharp_2.setFan(3); // 1
    ac_sharp_2.setXFan(true);
  }
  else
  {
    ac_sharp_2.off();
    ac_sharp_2.setFan(0); // 1
    ac_sharp_2.setXFan(false);
  }

  // Set AC on/off
  if (EEPROM.read(30))
  {
    ac_sharp_3.on();
    ac_sharp_3.setFan(3); // 1
    ac_sharp_3.setXFan(true);
  }
  else
  {
    ac_sharp_3.off();
    ac_sharp_3.setFan(0); // 1
    ac_sharp_3.setXFan(false);
  }

  // Set AC on/off
  if (EEPROM.read(40))
  {
    ac_aqua.on();
    ac_aqua.setFan(true);
  }
  else
  {
    ac_aqua.off();
    ac_aqua.setFan(false);
  }

  // Set AC on/off
  if (EEPROM.read(50))
  {
    ac_sharp_4.on();
    ac_sharp_4.setFan(3); // 1
    ac_sharp_4.setXFan(true);
  }
  else
  {
    ac_sharp_4.off();
    ac_sharp_4.setFan(0); // 1
    ac_sharp_4.setXFan(false);
  }

  // Set Temp
  if (EEPROM.read(11) == 0 || (EEPROM.read(11) >= 16 && EEPROM.read(11) <= 30))
    ac_sharp_1.setTemp(EEPROM.read(11));  // 16-30C

  // Set Temp
  if (EEPROM.read(21) == 0 || (EEPROM.read(21) >= 16 && EEPROM.read(21) <= 30))
    ac_sharp_2.setTemp(EEPROM.read(21));  // 16-30C

  // Set Temp
  if (EEPROM.read(31) == 0 || (EEPROM.read(31) >= 16 && EEPROM.read(31) <= 30))
    ac_sharp_3.setTemp(EEPROM.read(31));  // 16-30C

  // Set Temp
  if (EEPROM.read(41) == 0 || (EEPROM.read(41) >= 16 && EEPROM.read(41) <= 30))
    ac_aqua.setTemp(EEPROM.read(41));  // 16-30C

  // Set Temp
  if (EEPROM.read(51) == 0 || (EEPROM.read(51) >= 16 && EEPROM.read(51) <= 30))
    ac_sharp_4.setTemp(EEPROM.read(51));  // 16-30C


  // Set Turbo Mode
  ac_sharp_1.setTurbo((bool)EEPROM.read(12));

  // Set Turbo Mode
  ac_sharp_2.setTurbo((bool)EEPROM.read(22));

  // Set Turbo Mode
  ac_sharp_3.setTurbo((bool)EEPROM.read(32));

  // Set Turbo Mode
  ac_aqua.setTurbo((bool)EEPROM.read(42));

  // Set Turbo Mode
  ac_sharp_4.setTurbo((bool)EEPROM.read(52));

  //  if (ac1 && ac2 && ac3 && ac4)
  //  {
  //    ac_sharp_1.send();
  //    delay(5000);
  //    ac_sharp_2.send();
  //    delay(5000);
  //    ac_sharp_3.send();
  //    delay(5000);
  //    ac_aqua.send();
  //    delay(5000);
  //  }
  //
  //  else
  //  {

  delay_ = delay_ * 1000;

  if (ac1)
  {
    ac_sharp_1.send();
    delay(delay_);
  }
  if (ac2)
  {
    ac_aqua.send();
    delay(delay_);
  }
  if (ac3)
  {
    ac_sharp_2.send();
    delay(delay_);
  }
  if (ac4)
  {
    ac_sharp_3.send();
    delay(delay_);
  }
  if (ac5)
  {
    ac_sharp_4.send();
    delay(delay_);
  }
  //}

  printStateAC(sharp_1); // 0 sharp_1
  printStateAC(sharp_2); // 1 sharp_2
  printStateAC(sharp_3); // 2 sharp_3
  printStateAC(aqua_ac); // 3 aqua
  printStateAC(sharp_4); // 4 sharp_4

  /*
    return String(String("1: " + String((EEPROM.read(11) * EEPROM.read(10))))
                  + String(", 2: " + String((EEPROM.read(41) * EEPROM.read(40))))
                  + String(", 3: " + String((EEPROM.read(21) * EEPROM.read(20))))
                  + String(", 4: " + String((EEPROM.read(31) * EEPROM.read(30))))
                  + String(", 0: " + String((EEPROM.read(51) * EEPROM.read(50)))));
  */

#if MODUL == LEFT
  return String(String("0: " + String((EEPROM.read(51) * EEPROM.read(50))))
                + String(", 1: " + String((EEPROM.read(41) * EEPROM.read(40))))
                + String(", 2: " + String((EEPROM.read(11) * EEPROM.read(10))))
                + String(", 3: " + String((EEPROM.read(21) * EEPROM.read(20))))
                + String(", 4: " + String((EEPROM.read(31) * EEPROM.read(30)))));

#else
  return String(String("0: " + String((EEPROM.read(51) * EEPROM.read(50))))
                + String(", 1: " + String((EEPROM.read(11) * EEPROM.read(10))))
                + String(", 2: " + String((EEPROM.read(41) * EEPROM.read(40))))
                + String(", 3: " + String((EEPROM.read(21) * EEPROM.read(20))))
                + String(", 4: " + String((EEPROM.read(31) * EEPROM.read(30)))));

#endif
}

String ac_1_2_3_4_5(int ac1, int ac2, int ac3, int ac4, int ac5, double delay_)
{
  bool ac1_ = 0, ac2_ = 0, ac3_ = 0, ac4_ = 0, ac5_ = 0;

  if (ac1 > 0)
  {
    ac1_ = 1;
    update_eeprom(10, 1);
    update_eeprom(11, ac1);
  }
  else if (ac1 == 0)
  {
    ac1_ = 1;
    update_eeprom(10, 0); update_eeprom(11, 0);
  }

  if (ac2 > 0)
  {
    ac2_ = 1;
    update_eeprom(40, 1);
    update_eeprom(41, ac2);
  }
  else if (ac2 == 0)
  {
    ac2_ = 1;
    update_eeprom(40, 0); update_eeprom(41, 0);
  }

  if (ac3 > 0)
  {
    ac3_ = 1;
    update_eeprom(20, 1);
    update_eeprom(21, ac3);
  }
  else if (ac3 == 0)
  {
    ac3_ = 1;
    update_eeprom(20, 0); update_eeprom(21, 0);
  }

  if (ac4 > 0)
  {
    ac4_ = 1;
    update_eeprom(30, 1);
    update_eeprom(31, ac4);
  }
  else if (ac4 == 0)
  {
    ac4_ = 1;
    update_eeprom(30, 0); update_eeprom(31, 0);
  }

  if (ac5 > 0)
  {
    ac5_ = 1;
    update_eeprom(50, 1);
    update_eeprom(51, ac5);
  }
  else if (ac5 == 0)
  {
    ac5_ = 1;
    update_eeprom(50, 0); update_eeprom(51, 0);
  }

  return String("U: " + ac_ac + "-> " + ac_update(ac1_, ac2_, ac3_, ac4_, ac5_, delay_));
}

String ac_all(bool val1, int val2, bool val3)
{
  // index 0 buat off-on, index 1 buat derajat temp, index 2 buat turbo off-on
  update_eeprom(30, val1); update_eeprom(20, val1); update_eeprom(10, val1); update_eeprom(40, val1);
  update_eeprom(31, val2); update_eeprom(21, val2); update_eeprom(11, val2); update_eeprom(41, val2);
  update_eeprom(32, val3); update_eeprom(22, val3); update_eeprom(12, val3); update_eeprom(42, val3);

#if MODUL == LEFT
  update_eeprom(50, val1);
  update_eeprom(51, val2);
  update_eeprom(52, val3);

#endif

  return String(ac_ac + "-> " + ac_update(1, 1, 1, 1, 1, 3)); // Update // Send data to IR and give info about ac temp
}

String ac_all_24()
{
  return ac_all(true, 24, false);
}

String ac_all_22()
{
  return ac_all(true, 22, false);
}

String ac_all_21()
{
  return ac_all(true, 21, false);
}

String ac_all_20()
{
  return ac_all(true, 20, false);
}

String ac_all_19()
{
  return ac_all(true, 19, false);
}

String ac_all_18()
{
  return ac_all(true, 18, false);
}

String ac_all_17()
{
  return ac_all(true, 17, false);
}

String ac_all_16()
{
  return ac_all(true, 16, false);
}

String ac_all_on()
{
  return ac_all_22();
}

String ac_all_off()
{
  bool val1 = 0, val3 = 0;
  int val2 = 0;

  // index 0 buat off-on, index 1 buat derajat temp, index 2 buat turbo off-on
  update_eeprom(30, val1); update_eeprom(20, val1); update_eeprom(10, val1); update_eeprom(40, val1); update_eeprom(50, val1);
  update_eeprom(31, val2); update_eeprom(21, val2); update_eeprom(11, val2); update_eeprom(41, val2); update_eeprom(51, val2);
  update_eeprom(32, val3); update_eeprom(22, val3); update_eeprom(12, val3); update_eeprom(42, val3); update_eeprom(52, val3);

  return String(ac_ac + "-> " + ac_update(1, 1, 1, 1, 1, 0)); // Update // Send data to IR and give info about ac temp
}

String ac0_turbo_on()
{
  // index 0 buat off-on, index 1 buat derajat temp, index 2 buat turbo off-on
  update_eeprom(52, 1);

  return String(ac_ac + "-> " + ac_update(0, 0, 0, 0, 1, 0)); // Update // Send data to IR and give info about ac temp
}

String ac1_turbo_on()
{
  // index 0 buat off-on, index 1 buat derajat temp, index 2 buat turbo off-on
  update_eeprom(12, 1);

  return String(ac_ac + "-> " + ac_update(1, 0, 0, 0, 0, 0)); // Update // Send data to IR and give info about ac temp
}

String ac2_turbo_on()
{
  // index 0 buat off-on, index 1 buat derajat temp, index 2 buat turbo off-on
  update_eeprom(42, 1);

  return String(ac_ac + "-> " + ac_update(0, 1, 0, 0, 0, 0)); // Update // Send data to IR and give info about ac temp
}

String ac3_turbo_on()
{
  // index 0 buat off-on, index 1 buat derajat temp, index 2 buat turbo off-on
  update_eeprom(22, 1);

  return String(ac_ac + "-> " + ac_update(0, 0, 1, 0, 0, 0)); // Update // Send data to IR and give info about ac temp
}

String ac4_turbo_on()
{
  // index 0 buat off-on, index 1 buat derajat temp, index 2 buat turbo off-on
  update_eeprom(32, 1);

  return String(ac_ac + "-> " + ac_update(0, 0, 0, 1, 0, 0)); // Update // Send data to IR and give info about ac temp
}

String ac_all_turbo_on()
{
  // index 0 buat off-on, index 1 buat derajat temp, index 2 buat turbo off-on
  update_eeprom(32, 1); update_eeprom(22, 1); update_eeprom(12, 1); update_eeprom(42, 1);

  return String(ac_ac + "-> " + ac_update(1, 1, 1, 1, 1, 3)); // Update // Send data to IR and give info about ac temp
}

String ac0_turbo_off()
{
  // index 0 buat off-on, index 1 buat derajat temp, index 2 buat turbo off-on
  update_eeprom(52, 0);

  return String(ac_ac + "-> " + ac_update(0, 0, 0, 0, 1, 0)); // Update // Send data to IR and give info about ac temp
}

String ac1_turbo_off()
{
  // index 0 buat off-on, index 1 buat derajat temp, index 2 buat turbo off-on
  update_eeprom(12, 0);

  return String(ac_ac + "-> " + ac_update(1, 0, 0, 0, 0, 0)); // Update // Send data to IR and give info about ac temp
}

String ac2_turbo_off()
{
  // index 0 buat off-on, index 1 buat derajat temp, index 2 buat turbo off-on
  update_eeprom(42, 0);

  return String(ac_ac + "-> " + ac_update(0, 1, 0, 0, 0, 0)); // Update // Send data to IR and give info about ac temp
}

String ac3_turbo_off()
{
  // index 0 buat off-on, index 1 buat derajat temp, index 2 buat turbo off-on
  update_eeprom(22, 0);

  return String(ac_ac + "-> " + ac_update(0, 0, 1, 0, 0, 0)); // Update // Send data to IR and give info about ac temp
}

String ac4_turbo_off()
{
  // index 0 buat off-on, index 1 buat derajat temp, index 2 buat turbo off-on
  update_eeprom(32, 0);

  return String(ac_ac + "-> " + ac_update(0, 0, 0, 1, 0, 0)); // Update // Send data to IR and give info about ac temp
}

String ac_all_turbo_off()
{
  // index 0 buat off-on, index 1 buat derajat temp, index 2 buat turbo off-on
  update_eeprom(32, 0); update_eeprom(22, 0); update_eeprom(12, 0); update_eeprom(42, 0); update_eeprom(52, 0);

  return String(ac_ac + "-> " + ac_update(1, 1, 1, 1, 1, 0)); // Update // Send data to IR and give info about ac temp
}

String ac_all_kelas()
{
  // index 0 buat off-on, index 1 buat derajat temp, index 2 buat turbo off-on
  update_eeprom(20, 0); update_eeprom(50, 0);
  update_eeprom(40, 1); update_eeprom(10, 1); update_eeprom(30, 1);

  update_eeprom(31, 22); update_eeprom(21, 0); update_eeprom(11, 22); update_eeprom(41, 22); update_eeprom(51, 0);
  update_eeprom(32, 0); update_eeprom(22, 0); update_eeprom(12, 0); update_eeprom(42, 0); update_eeprom(52, 0);

  return String("Kelas: " + ac_ac + "-> " + ac_update(1, 1, 1, 1, 1, 3)); // Update // Send data to IR and give info about ac temp
}

String ac_all_pa()
{
  // index 0 buat off-on, index 1 buat derajat temp, index 2 buat turbo off-on
  update_eeprom(30, 0); update_eeprom(20, 0); update_eeprom(50, 0);
  update_eeprom(10, 1); update_eeprom(40, 1);

  update_eeprom(31, 0); update_eeprom(21, 0); update_eeprom(11, 22); update_eeprom(41, 22); update_eeprom(51, 0);
  update_eeprom(32, 0); update_eeprom(22, 0); update_eeprom(12, 0); update_eeprom(42, 0); update_eeprom(52, 0);

  return String("PA: " + ac_ac + "-> " + ac_update(1, 1, 1, 1, 1, 3)); // Update // Send data to IR and give info about ac temp
}

String ac_all_rabumalam()
{
  return ac_all_pa();
}

String ac_all_potluck()
{
  return ac_all_pa();
}

String ac_all_vesper()
{
#if MODUL == RIGHT
  // index 0 buat off-on, index 1 buat derajat temp, index 2 buat turbo off-on
  update_eeprom(10, 0); update_eeprom(20, 0);  update_eeprom(50, 0);
  update_eeprom(30, 1); update_eeprom(40, 1);

  update_eeprom(31, 22); update_eeprom(21, 0); update_eeprom(11, 0); update_eeprom(41, 22); update_eeprom(51, 0);
  update_eeprom(32, 0); update_eeprom(22, 0); update_eeprom(12, 0); update_eeprom(42, 0); update_eeprom(52, 0);

#else
  // index 0 buat off-on, index 1 buat derajat temp, index 2 buat turbo off-on
  update_eeprom(20, 0);
  update_eeprom(30, 1); update_eeprom(10, 1); update_eeprom(40, 1);  update_eeprom(50, 1);

  update_eeprom(31, 22); update_eeprom(21, 0); update_eeprom(11, 22); update_eeprom(41, 22); update_eeprom(51, 22);
  update_eeprom(32, 0); update_eeprom(22, 0); update_eeprom(12, 0); update_eeprom(42, 0); update_eeprom(52, 0);

#endif

  return String("Vesper: " + ac_ac + "-> " + ac_update(1, 1, 1, 1, 1, 3)); // Update // Send data to IR and give info about ac temp
}
