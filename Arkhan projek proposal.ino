#include "BluetoothSerial.h"
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif
#define relay 15
BluetoothSerial SerialBT;
String Data;
void setup() {
  Serial.begin(115200);
    SerialBT.begin("ESP32 BT MONSTERCHIP"); //Bluetooth device name
      Serial.println("The device started, now you can pair it with bluetooth!");
        pinMode(relay, OUTPUT);
        }
        void loop() {
          while (SerialBT.available() > 0) {
              char c = SerialBT.read();
                  Data += c;
                    }
                      if (Data.length() > 0) {
                          Serial.println(Data);
                              if (Data == "relay nyala") {
                                    digitalWrite(relay, 1);
                                        }
                                            else if (Data == "relay mati") {
                                                  digitalWrite(relay, 0);
                                                      }
                                                          Data = "";
                                                            }
                                                              delay(20);
                                                              }
                                                              