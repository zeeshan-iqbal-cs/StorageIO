/*
  StorageIO.h - Library for storing data in ESP8266's EEPROM easily.
  Created by Zeeshan Iqbal, January 6, 2020.
  Released into the public domain.
*/

#ifndef StorageIO_h
#define StorageIO_h

#include <Arduino.h>
#include <EEPROM.h>

class StorageIO{
private:
  bool debug;
  int static const DEFAULT_SIZE_OF_EEPROM = 512;
  int position;
  int size;
public:

  void begin(const int SIZE = 512, bool debugFlag = false);
  void reposition(){this->position = 0;}

  void clear();

  String readNextString();
  void writeNextString(String s, bool commit = true);
  void commit() {
    if (this->debug)
      Serial.println("Comitting changes on EEPROM");
    EEPROM.commit();
    
    delay(2000);
  }
};
#endif
