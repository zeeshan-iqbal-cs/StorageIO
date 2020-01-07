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

void loop(){

}