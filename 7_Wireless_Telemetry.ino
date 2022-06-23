void setupWiFi(){
  if(enableWiFi==1){
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, wifipass);
    if(WiFi.waitForConnectResult() != WL_CONNECTED) {
      Serial.println("WiFi connection Failed! ");
    }
    else{
      Serial.println("> WiFi connected.");
      Serial.print("> IP address: ");
      Serial.println(WiFi.localIP());
      WIFI = 1;
    }
  }
}

void setupOTA(){
  if(enableWiFi==1 && enableOTA==1){
  // Port defaults to 3232
  // ArduinoOTA.setPort(3232);

  // Hostname defaults to esp3232-[MAC]
  // ArduinoOTA.setHostname("myesp32");

  // No authentication by default
  // ArduinoOTA.setPassword("admin");

  // Password can be set with it's md5 value as well
  // MD5(admin) = 21232f297a57a5a743894a0e4a801fc3
  // ArduinoOTA.setPasswordHash("21232f297a57a5a743894a0e4a801fc3");

  ArduinoOTA
    .onStart([]() {
      String type;
      if (ArduinoOTA.getCommand() == U_FLASH)
        type = "sketch";
      else // U_SPIFFS
        type = "filesystem";

      // NOTE: if updating SPIFFS this would be the place to unmount SPIFFS using SPIFFS.end()
      Serial.println("Start updating " + type);
    })
    .onEnd([]() {
      Serial.println("\nEnd");
    })
    .onProgress([](unsigned int progress, unsigned int total) {
      Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
    })
    .onError([](ota_error_t error) {
      Serial.printf("Error[%u]: ", error);
      if (error == OTA_AUTH_ERROR) Serial.println("Auth Failed");
      else if (error == OTA_BEGIN_ERROR) Serial.println("Begin Failed");
      else if (error == OTA_CONNECT_ERROR) Serial.println("Connect Failed");
      else if (error == OTA_RECEIVE_ERROR) Serial.println("Receive Failed");
      else if (error == OTA_END_ERROR) Serial.println("End Failed");
    });

  ArduinoOTA.begin();
  }
}
  
void Wireless_Telemetry(){
  
  ////////// WIFI TELEMETRY ////////// 
  if(enableWiFi==1){
    int LED1, LED2, LED3, LED4;                      //Declare LED brightness variable 
    if(buckEnable==1)      {LED1=200;}else{LED1=0;}  //BATTERY CHARGING STATUS
    if(batteryPercent>=99 ){LED2=200;}else{LED2=0;}  //FULL CHARGE STATUS
    if(batteryPercent<=10) {LED3=200;}else{LED3=0;}  //LOW BATTERY STATUS
    if(IUV==0)             {LED4=200;}else{LED4=0;}  //PV INPUT PRESENCE STATUS

//    Blynk.run();  
//    Blynk.virtualWrite(1,powerInput); 
//    Blynk.virtualWrite(2,batteryPercent);
//    Blynk.virtualWrite(3,voltageInput);    
//    Blynk.virtualWrite(4,currentInput);   
//    Blynk.virtualWrite(5,voltageOutput); 
//    Blynk.virtualWrite(6,currentOutput); 
//    Blynk.virtualWrite(7,temperature); 
//    Blynk.virtualWrite(8,Wh/1000); 
//    Blynk.virtualWrite(9,energySavings);       
//    Blynk.virtualWrite(10,LED1);               //LED - Battery Charging Status
//    Blynk.virtualWrite(11,LED2);               //LED - Full Battery Charge Status
//    Blynk.virtualWrite(12,LED3);               //LED - Low Battery Charge Status
//    Blynk.virtualWrite(13,LED4);               //LED - PV Harvesting
    
//    Blynk.virtualWrite(14,voltageBatteryMin);  //Minimum Battery Voltage (Read & Write)
//    Blynk.virtualWrite(15,voltageBatteryMax);  //Maximum Battery Voltage (Read & Write)
//    Blynk.virtualWrite(16,currentCharging);    //Charging Current  (Read & Write)
//    Blynk.virtualWrite(17,electricalPrice);    //Electrical Price  (Write)
  }
} 
