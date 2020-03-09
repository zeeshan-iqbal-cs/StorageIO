#include <StorageIO.h>

void setup(){
    Serial.begin(9600);
    delay(2000);

    while(! Serial);
    Serial.println("Starting");

    StorageIO rom;
    rom.begin();

    // Writing Strings
    rom.reposition();           // move to start of EEPROM
    rom.writeNextString("Hello ");
    rom.writeNextString("World");
}

void loop(){}
