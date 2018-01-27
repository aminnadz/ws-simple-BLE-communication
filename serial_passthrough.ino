#include <Arduino.h>                       

void setup() {
  SerialUSB.begin(115200);                  /*Initialize USB serial*/
  
  while (!SerialUSB) {                      /*Wait for initialization to end*/
    ;
  }
  
  Serial2.begin(115200);                    /*Initialize Bluetooth Serial*/
  
  while (!Serial2) {                        /*Wait for initialization to end*/
    ;
  }
  
  pinMode(LED_BUILTIN, OUTPUT);             /*Initialize pin for GREEN (D13) led*/
}

void loop() {
    if (Serial2.available())                /*Serial PassThrough Loop*/
      SerialUSB.write(Serial2.read());      /*Read the Bluetooth response and send to USB*/
       
    if (SerialUSB.available())              
      Serial2.write(SerialUSB.read());      /*Read USB command and send to Bluetooth*/
}
