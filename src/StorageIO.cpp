/*
  StorageIO.cpp - Library for storing data in ESP8266's EEPROM easily.
  Created by Zeeshan Iqbal, January 6, 2020.
  Released into the public domain.
*/

#include "EEPROM.h"
#include "Arduino.h"
#include "StorageIO.h"


void StorageIO::begin(const int SIZE, bool debugFlag){
  this->debug = debugFlag;

  position = 0;
  size = SIZE;
  EEPROM.begin(SIZE);
}


void StorageIO::clear(){
  position = 0;

  for (int i = 0; i < size; i++){
    delay(100);
    EEPROM.write(i, 0);
  }

  EEPROM.commit();
}


String StorageIO::readNextString(){
  String data;
  char tempC = 's';
  while (true){
    if (tempC == 0)
      break;
    if (position >= size)
      break;
    tempC = EEPROM.read(position++);
    data += tempC;
    delay(100);
  }
  // After that iterator will be standing after NULL
  return data;
}


void StorageIO::writeNextString(String s, bool commit){

  for (int i = 0; i < s.length(); i++)
    EEPROM.write(position++, s[i]);

  EEPROM.write(position++, 0);

  if (commit){
    if (this->debug)
      Serial.println("Commiting the changes on storage");
    this->commit();
  }
}
