#include <StorageIO.h>

void setup(){
    Serial.begin(9600);
    delay(2000);

    while(! Serial);
    Serial.println("Starting");

    StorageIO rom;
    rom.begin();

    // Reading data
    rom.reposition();
    String hello = rom.readNextString();
    String world = rom.readreadNextString();


    // Print the data on the Serial console
    Serial.print(hello);
    Serial.println(world);
    Serial.println("End");
}

void loop(){}
