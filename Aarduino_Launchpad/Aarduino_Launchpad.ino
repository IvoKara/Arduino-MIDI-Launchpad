int latchPin = 8;
int dataPin = 9;
int clockPin = 7;

byte current = 0;  
byte previous = 0;

byte mainPitch = 50;

void setup() 
{
  Serial.begin(115200);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT); 
  pinMode(dataPin, INPUT);
}

void loop() 
{
  digitalWrite(latchPin, HIGH);
  delayMicroseconds(0.01);
  digitalWrite(latchPin, LOW);

  current = shiftIn(dataPin, clockPin);
  if(current != previous)
  {
    SendNotes();
  }
  
  previous = current;

  delay(50);
}

byte shiftIn(int myDataPin, int myClockPin) 
{ 
  int temp = 0;
  byte myDataIn = 0;

  pinMode(myClockPin, OUTPUT);
  pinMode(myDataPin, INPUT);
  
  for (int i = 7; i >= 0; i--)
  {
    digitalWrite(myClockPin, LOW);
    delayMicroseconds(0.02);
    temp = digitalRead(myDataPin);
    if(temp) 
    {
      myDataIn = myDataIn | (1 << i);
    }
    digitalWrite(myClockPin, HIGH);
  }
  return myDataIn;
}
 
void MidiNoteOn(int pitch)
{
    Serial.write(0x90);
    Serial.write(pitch);
    Serial.write(100);
}

void MidiNoteOff(int pitch)
{
    Serial.write(0x80);
    Serial.write(pitch);
    Serial.write(100);
}

void SendNotes()
{
  int diff = previous ^ current;

  /*Serial.print("previous: ");
  Serial.println(previous, BIN);
  Serial.print("current: ");
  Serial.println(current, BIN);
  Serial.print("diff(xor): ");
  Serial.println(diff, BIN);*/
  
  //noteon
  for(int i = 0; i < 8; i++)
  {
    if((current & diff) & (1 << i))
    {
      MidiNoteOn(mainPitch + i);
    }
  }

  //noteoff
  for(int i = 0; i < 8; i++)
  {
    if((previous & diff) & (1 << i))
    {
      MidiNoteOff(mainPitch + i);
    }
  }
}

