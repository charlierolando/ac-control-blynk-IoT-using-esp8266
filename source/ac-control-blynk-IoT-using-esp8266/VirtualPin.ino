// This function is called every time the Virtual Pin 0 state changes
BLYNK_WRITE(V4)
{
  // Set incoming value from pin V0 to a variable
  int value = param.asInt();
  if (value == 1)
    digitalWrite(RELAY, LOW);
  else
    digitalWrite(RELAY, HIGH);
  // Update state
  Blynk.virtualWrite(V1, value);
  Serial.println(value);
}

BLYNK_WRITE(V3)
{
  menu_redraw_required = 1;
  strData = param.asStr();
  Serial.print("param.asStr()= ");
  Serial.println(param.asStr());
  Serial.print("pinValueV0[WRITEV]= ");
  Serial.println(strData);
  temp_v3 = strData;

#if MODUL == RIGHT
  Blynk.virtualWrite(V2, IRremote(strData));

#else
  Blynk.virtualWrite(V0, IRremote(strData));

#endif

}

// This function is called every time the device is connected to the Blynk.Cloud
BLYNK_CONNECTED()
{
  // Change Web Link Button message to "Congratulations!"
  //Blynk.setProperty(V3, "offImageUrl", "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations.png");
  //Blynk.setProperty(V3, "onImageUrl",  "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations_pressed.png");
  //Blynk.setProperty(V3, "url", "https://docs.blynk.io/en/getting-started/what-do-i-need-to-blynk/how-quickstart-device-was-made");
}

// This function sends Arduino's uptime every second to Virtual Pin 2.
void myTimerEvent()
{
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  
#if MODUL == RIGHT
  Blynk.virtualWrite(V2, millis() / 1000);

#else
  Blynk.virtualWrite(V0, millis() / 1000);

#endif

}
