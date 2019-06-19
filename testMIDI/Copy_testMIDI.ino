#include <MIDI.h>

#define Button 7
#define Led 8

byte Pitch = 51;

MIDI_CREATE_DEFAULT_INSTANCE();

void setup()
{
  MIDI.begin();
  Serial.begin(115200);
  pinMode(Button, INPUT_PULLUP);
  pinMode(Led, OUTPUT);
}

void loop() 
{
  readButton();
}

int Previous = HIGH;
void readButton()
{
  int Status = digitalRead(Button);
  
  if(Status == LOW && Status != Previous)
  {
    digitalWrite(Led, HIGH);
    Serial.write(0x90);
    Serial.write(51);
    Serial.write(100);
    //MIDI.sendNoteOn(1, 51, 100);
  }
  
  if(Status == HIGH && Status != Previous)
  {
    digitalWrite(Led, LOW);

    Serial.write(0x80);
    Serial.write(51);
    Serial.write(0);
    //MIDI.sendNoteOff(1, 51, 100);
  }
  
  Previous = Status;

  delay(50);
}
