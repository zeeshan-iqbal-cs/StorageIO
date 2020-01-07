/*
  StorageIO.cpp - Library for storing data in ESP8266's EEPROM easily.
  Created by Zeeshan Iqbal, January 6, 2020.
  Released into the public domain.
*/

#include "EEPROM.h"
#include "StorageIO.h"
#include  <String.h>


StorageIO::StorageIO(const int SIZE){
  position = 0;
  Serial.println(position);
  EEPROM.begin(SIZE);
}


StorageIO::StorageIO(){
  EEPROM.begin(DEFAULT_SIZE_OF_EEPROM);
  position = 0;
}


char * StorageIO::readNextString(){

  int i = 0;
  char c;

  while(true){
    c = EEPROM.read(i + position);
    if (c == 0) break;
    i++;
  }
  
  char * data = new char[i + 1];
  
  for(int j = 0; j <= i; j++)        // Read string including NULL
    data[j] = EEPROM.read(position++);

  // After that iterator will be standing after NULL
  return data;
}


void StorageIO::writeNextString(String s){

  for (int i = 0; i < s.length(); i++)
    EEPROM.write(position++, s[i]);
  
  EEPROM.write(position++, 0);
  EEPROM.commit();
}