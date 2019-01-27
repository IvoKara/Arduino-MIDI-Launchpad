int movePin = 6;
int selectPin = 7;
int cathodePin1 = 8;
int cathodePin2 = 12;
int cathodePin3 = 13;
int anodePin1 = 11;
int anodePin2 = 10;
int anodePin3 = 9;
void setup() 
{
  pinMode(movePin, INPUT_PULLUP);
  pinMode(selectPin, INPUT_PULLUP);
  pinMode(anodePin1, OUTPUT);
  pinMode(anodePin2, OUTPUT);
  pinMode(anodePin3, OUTPUT);
  pinMode(cathodePin1, OUTPUT);
  pinMode(cathodePin2, OUTPUT);
  pinMode(cathodePin3, OUTPUT);
}

void loop() 
{
  digitalWrite(cathodePin1, LOW);
  digitalWrite(cathodePin2, HIGH);
  digitalWrite(cathodePin3, HIGH);
  delay(50);
  digitalWrite(anodePin1, HIGH);
  delay(250);
}
