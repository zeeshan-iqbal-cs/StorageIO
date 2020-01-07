# StorageIO (ESP8266)
It is very important to save WiFi setting (SSID/Password) and server address in permanent so it can autometically reconnect with WiFi on next start.

StorageIO class provide an easy interface for EEPROM. 

# Example

```
#include <StorageIO.h>

void setup(){

    Serial.begin(9600);
    while(! Serial);

    StorageIO rom;
    rom.writeNextString("Hello ");
    rom.writeNextString("World");
    
    rom.reposition();
    Serial.print(rom.readNextString());
    Serial.println(rom.readNextString());
}

void loop(){}

```

*Note: Try to minimize the number of writes on EEPROM because it reduces its life*