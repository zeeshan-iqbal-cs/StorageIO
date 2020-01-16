#include <StorageIO.h>

void setup(){
    Serial.begin(9600);
    delay(2000);
    while(! Serial);

    Serial.println("Starting");

    StorageIO rom;
    rom.begin();
    rom.writeNextString("Hello ");
    rom.writeNextString("World");

    rom.reposition();
    Serial.print(rom.readNextString());
    Serial.println(rom.readNextString());
    Serial.println("End");
}

void loop(){

}
