#define ShiftOut 8
#define Clock 12
// when Control is H input is loaded by parallel inputs
// when Control is L the shift is allowed
#define Control 13

//asynchronous 
void Load()
{
  digitalWrite(Control, HIGH);
  delay(50);
  digitalWrite(Control, LOW);
  delay(50);
}

void ShiftByOne()
{
  digitalWrite(Clock, HIGH);
  delay(50);
  digitalWrite(Clock, LOW);
  delay(50);
}

void setup()
{
  pinMode(ShiftOut, INPUT);
  pinMode(Clock, OUTPUT);
  pinMode(Control, OUTPUT);
  Serial.begin(9600);
  Load();
  Serial.print("Shift Data: ");
}

int count = 0;
void loop()
{
  if(count < 8)
  {
    Serial.print(digitalRead(ShiftOut));
    ShiftByOne();
    count++;
  }
}
