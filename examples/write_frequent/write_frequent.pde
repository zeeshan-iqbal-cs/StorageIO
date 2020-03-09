#include <StorageIO.h>

/*
* Number of commits on EEPROM are limited.
* By default StorageIO writes data and commits it.
* If you don't want to commit every write:
*   pass a false flag like this.
*   rom.writeNextString("Your String", false);
*   rom.commit(); to commit all writes. if you will not do this,
*   nothing will be saved
*/


void setup(){
    Serial.begin(9600);
    delay(2000);

    while(! Serial);
    Serial.println("Starting");

    StorageIO rom;
    rom.begin();

    // Writing Strings
    rom.reposition();           // move to start of EEPROM
    rom.writeNextString("Hello", false);
    rom.writeNextString("World", false);
    rom.writeNextString("I'm not", false);
    rom.writeNextString("saved yet", false);

    rom.commit();  // now and saved
}

void loop(){}
