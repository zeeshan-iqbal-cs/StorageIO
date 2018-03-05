#define DEFAULT_SIZE_OF_EEPROM 512

class StorageIO{
private:
  int position;
public:
  StorageIO();
  StorageIO(const int SIZE);
  void reposition(){this->position = 0;}
  char * readNextString();
  void writeNextString(String s);
};

StorageIO::StorageIO(const int SIZE){
  Serial.println("Here");
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
     
    if(c == NULL)
      break;
    
    i++;
  }
  
  char * data = new char[i + 1];
  
  for(int j = 0; j <= i; j++)        // Read string including NULL
    data[j] = EEPROM.read(position++);

  // After that iterator will be standing after NULL
  return data;
}

void StorageIO::writeNextString(String s){

  for (int i = 0; i < s.length(); i++){
   EEPROM.write(position++, s[i]);
  }
  EEPROM.write(position++, NULL);
  
  EEPROM.commit();
}
