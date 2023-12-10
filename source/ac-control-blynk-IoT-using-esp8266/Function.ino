String temp_v3;

String IRremote(String inputStr)
{
  if (inputStr == "reset" || inputStr == "r")
  {
#if MODUL == RIGHT
    Blynk.virtualWrite(V2, "Restart system... Please wait...");

#else
    Blynk.virtualWrite(V0, "Restart system... Please wait...");

#endif

    EEPROM.end();
    ESP.restart();
    return String("Restart ESP");
  }

  else if (inputStr == "u")
    return String("U: " + ac_ac + "-> " + ac_update(1, 1, 1, 1, 1, 0));

  else if (inputStr == "ac_all_16")
    return ac_all_16();

  else if (inputStr == "ac_all_17")
    return ac_all_17();

  else if (inputStr == "ac_all_18")
    return ac_all_18();

  else if (inputStr == "ac_all_19")
    return ac_all_19();

  else if (inputStr == "ac_all_20")
    return ac_all_20();

  else if (inputStr == "ac_all_21")
    return ac_all_21();

  else if (inputStr == "ac_all_22")
    return ac_all_22();

  else if (inputStr == "ac_all_24")
    return ac_all_24();

  else if (inputStr == "ac_all_on")
  {
    String notif = ac_all_on();
    Blynk.logEvent(notif);
    return notif;
  }
  else if (inputStr == "ac_all_off")
    return ac_all_off();

  else if (inputStr == "ac_all_potluck")
    return ac_all_potluck();

  else if (inputStr == "ac_all_kelas")
    return ac_all_kelas();

  else if (inputStr == "ac_all_pa")
    return ac_all_pa();

  else if (inputStr == "ac_all_rabumalam")
    return ac_all_rabumalam();

  else if (inputStr == "ac_all_vesper")
    return ac_all_vesper();

  //////////////////////////////////////////

  else if (inputStr == "ac0_turbo_on")
    return ac0_turbo_on();

  else if (inputStr == "ac1_turbo_on")
    return ac1_turbo_on();

  else if (inputStr == "ac2_turbo_on")
    return ac2_turbo_on();

  else if (inputStr == "ac3_turbo_on")
    return ac3_turbo_on();

  else if (inputStr == "ac4_turbo_on")
    return ac4_turbo_on();

  else if (inputStr == "ac_all_turbo_on")
    return ac_all_turbo_on();

  else if (inputStr == "ac0_turbo_off")
    return ac0_turbo_off();

  else if (inputStr == "ac1_turbo_off")
    return ac1_turbo_off();

  else if (inputStr == "ac2_turbo_off")
    return ac2_turbo_off();

  else if (inputStr == "ac3_turbo_off")
    return ac3_turbo_off();

  else if (inputStr == "ac4_turbo_off")
    return ac4_turbo_off();

  else if (inputStr == "ac_all_turbo_off")
    return ac_all_turbo_off();

  //////////////////////////////////////////

#if MODUL == RIGHT
  else if (inputStr == "ac_r0_off")
    return ac_1_2_3_4_5(-1, -1, -1, -1, 0, 0);

  else if (inputStr == "ac_r1_off")
    return ac_1_2_3_4_5(0, -1, -1, -1, -1, 0);

  else if (inputStr == "ac_r2_off")
    return ac_1_2_3_4_5(-1, 0, -1, -1, -1, 0);

  else if (inputStr == "ac_r3_off")
    return ac_1_2_3_4_5(-1, -1, 0, -1, -1, 0);

  else if (inputStr == "ac_r4_off")
    return ac_1_2_3_4_5(-1, -1, -1, 0, -1, 0);

  else if (inputStr == "ac_r0_on")
    return ac_1_2_3_4_5(-1, -1, -1, -1, 22, 0);

  else if (inputStr == "ac_r1_on")
    return ac_1_2_3_4_5(22, -1, -1, -1, -1, 0);

  else if (inputStr == "ac_r2_on")
    return ac_1_2_3_4_5(-1, 22, -1, -1, -1, 0);

  else if (inputStr == "ac_r3_on")
    return ac_1_2_3_4_5(-1, -1, 22, -1, -1, 0);

  else if (inputStr == "ac_r4_on")
    return ac_1_2_3_4_5(-1, -1, -1, 22, -1, 0);

  //////////////////////////////////////////

  else if (inputStr == "ac_r0_16")
    return ac_1_2_3_4_5(-1, -1, -1, -1, 16, 0);

  else if (inputStr == "ac_r0_18")
    return ac_1_2_3_4_5(-1, -1, -1, -1, 18, 0);

  else if (inputStr == "ac_r0_20")
    return ac_1_2_3_4_5(-1, -1, -1, -1, 20, 0);

  else if (inputStr == "ac_r0_22")
    return ac_1_2_3_4_5(-1, -1, -1, -1, 22, 0);

  else if (inputStr == "ac_r0_24")
    return ac_1_2_3_4_5(-1, -1, -1, -1, 24, 0);


  else if (inputStr == "ac_r1_16")
    return ac_1_2_3_4_5(16, -1, -1, -1, -1, 0);

  else if (inputStr == "ac_r1_18")
    return ac_1_2_3_4_5(18, -1, -1, -1, -1, 0);

  else if (inputStr == "ac_r1_20")
    return ac_1_2_3_4_5(20, -1, -1, -1, -1, 0);

  else if (inputStr == "ac_r1_22")
    return ac_1_2_3_4_5(22, -1, -1, -1, -1, 0);

  else if (inputStr == "ac_r1_24")
    return ac_1_2_3_4_5(24, -1, -1, -1, -1, 0);


  else if (inputStr == "ac_r2_16")
    return ac_1_2_3_4_5(-1, 16, -1, -1, -1, 0);

  else if (inputStr == "ac_r2_18")
    return ac_1_2_3_4_5(-1, 18, -1, -1, -1, 0);

  else if (inputStr == "ac_r2_20")
    return ac_1_2_3_4_5(-1, 20, -1, -1, -1, 0);

  else if (inputStr == "ac_r2_22")
    return ac_1_2_3_4_5(-1, 22, -1, -1, -1, 0);

  else if (inputStr == "ac_r2_24")
    return ac_1_2_3_4_5(-1, 24, -1, -1, -1, 0);


  else if (inputStr == "ac_r3_16")
    return ac_1_2_3_4_5(-1, -1, 16, -1, -1, 0);

  else if (inputStr == "ac_r3_18")
    return ac_1_2_3_4_5(-1, -1, 18, -1, -1, 0);

  else if (inputStr == "ac_r3_20")
    return ac_1_2_3_4_5(-1, -1, 20, -1, -1, 0);

  else if (inputStr == "ac_r3_22")
    return ac_1_2_3_4_5(-1, -1, 22, -1, -1, 0);

  else if (inputStr == "ac_r3_24")
    return ac_1_2_3_4_5(-1, -1, 24, -1, -1, 0);


  else if (inputStr == "ac_r4_16")
    return ac_1_2_3_4_5(-1, -1, -1, 16, -1, 0);

  else if (inputStr == "ac_r4_18")
    return ac_1_2_3_4_5(-1, -1, -1, 18, -1, 0);

  else if (inputStr == "ac_r4_20")
    return ac_1_2_3_4_5(-1, -1, -1, 20, -1, 0);

  else if (inputStr == "ac_r4_22")
    return ac_1_2_3_4_5(-1, -1, -1, 22, -1, 0);

  else if (inputStr == "ac_r4_24")
    return ac_1_2_3_4_5(-1, -1, -1, 24, -1, 0);

  else
  {
    String inputStr = "Wrong command";
    Serial.println(inputStr);

    return inputStr;
  }

  //////////////////////////////////////////

#else
  else if (inputStr == "ac_l0_off")
    return ac_1_2_3_4_5(-1, -1, -1, -1, 0, 0);

  else if (inputStr == "ac_l2_off")
    return ac_1_2_3_4_5(0, -1, -1, -1, -1, 0);

  else if (inputStr == "ac_l1_off")
    return ac_1_2_3_4_5(-1, 0, -1, -1, -1, 0);

  else if (inputStr == "ac_l3_off")
    return ac_1_2_3_4_5(-1, -1, 0, -1, -1, 0);

  else if (inputStr == "ac_l4_off")
    return ac_1_2_3_4_5(-1, -1, -1, 0, -1, 0);

  else if (inputStr == "ac_l0_on")
    return ac_1_2_3_4_5(-1, -1, -1, -1, 22, 0);

  else if (inputStr == "ac_l2_on")
    return ac_1_2_3_4_5(22, -1, -1, -1, -1, 0);

  else if (inputStr == "ac_l1_on")
    return ac_1_2_3_4_5(-1, 22, -1, -1, -1, 0);

  else if (inputStr == "ac_l3_on")
    return ac_1_2_3_4_5(-1, -1, 22, -1, -1, 0);

  else if (inputStr == "ac_l4_on")
    return ac_1_2_3_4_5(-1, -1, -1, 22, -1, 0);

  //////////////////////////////////////////

  else if (inputStr == "ac_l0_16")
    return ac_1_2_3_4_5(-1, -1, -1, -1, 16, 0);

  else if (inputStr == "ac_l0_18")
    return ac_1_2_3_4_5(-1, -1, -1, -1, 18, 0);

  else if (inputStr == "ac_l0_20")
    return ac_1_2_3_4_5(-1, -1, -1, -1, 20, 0);

  else if (inputStr == "ac_l0_22")
    return ac_1_2_3_4_5(-1, -1, -1, -1, 22, 0);

  else if (inputStr == "ac_l0_24")
    return ac_1_2_3_4_5(-1, -1, -1, -1, 24, 0);


  else if (inputStr == "ac_l2_16")
    return ac_1_2_3_4_5(16, -1, -1, -1, -1, 0);

  else if (inputStr == "ac_l2_18")
    return ac_1_2_3_4_5(18, -1, -1, -1, -1, 0);

  else if (inputStr == "ac_l2_20")
    return ac_1_2_3_4_5(20, -1, -1, -1, -1, 0);

  else if (inputStr == "ac_l2_22")
    return ac_1_2_3_4_5(22, -1, -1, -1, -1, 0);

  else if (inputStr == "ac_l2_24")
    return ac_1_2_3_4_5(24, -1, -1, -1, -1, 0);


  else if (inputStr == "ac_l1_16")
    return ac_1_2_3_4_5(-1, 16, -1, -1, -1, 0);

  else if (inputStr == "ac_l1_18")
    return ac_1_2_3_4_5(-1, 18, -1, -1, -1, 0);

  else if (inputStr == "ac_l1_20")
    return ac_1_2_3_4_5(-1, 20, -1, -1, -1, 0);

  else if (inputStr == "ac_l1_22")
    return ac_1_2_3_4_5(-1, 22, -1, -1, -1, 0);

  else if (inputStr == "ac_l1_24")
    return ac_1_2_3_4_5(-1, 24, -1, -1, -1, 0);


  else if (inputStr == "ac_l3_16")
    return ac_1_2_3_4_5(-1, -1, 16, -1, -1, 0);

  else if (inputStr == "ac_l3_18")
    return ac_1_2_3_4_5(-1, -1, 18, -1, -1, 0);

  else if (inputStr == "ac_l3_20")
    return ac_1_2_3_4_5(-1, -1, 20, -1, -1, 0);

  else if (inputStr == "ac_l3_22")
    return ac_1_2_3_4_5(-1, -1, 22, -1, -1, 0);

  else if (inputStr == "ac_l3_24")
    return ac_1_2_3_4_5(-1, -1, 24, -1, -1, 0);


  else if (inputStr == "ac_l4_16")
    return ac_1_2_3_4_5(-1, -1, -1, 16, -1, 0);

  else if (inputStr == "ac_l4_18")
    return ac_1_2_3_4_5(-1, -1, -1, 18, -1, 0);

  else if (inputStr == "ac_l4_20")
    return ac_1_2_3_4_5(-1, -1, -1, 20, -1, 0);

  else if (inputStr == "ac_l4_22")
    return ac_1_2_3_4_5(-1, -1, -1, 22, -1, 0);

  else if (inputStr == "ac_l4_24")
    return ac_1_2_3_4_5(-1, -1, -1, 24, -1, 0);

  else
  {
    String inputStr = "Wrong command";
    Serial.println(inputStr);

    return inputStr;
  }

#endif
}

void setup_IR()
{
  irsend.begin();
#if ESP8266
  Serial.begin(115200, SERIAL_8N1, SERIAL_TX_ONLY);
#else  // ESP8266
  Serial.begin(115200, SERIAL_8N1);
#endif  // ESP8266
}

void RemotetvON()
{
  Serial.println("TV On Off");
  irsend.sendRaw(onoffTV, 71, 38);  // Send a raw data capture at 38kHz.
}
