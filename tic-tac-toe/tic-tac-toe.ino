struct ledCoord_t {int anode; int cathode;};
typedef struct ledCoord_t led;

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
  Serial.begin(9600);
  // lights up the first led at start 
  LightUp();
}

void loop() 
{
  if(digitalRead(movePin) == LOW)  //if pressed light up next 
  {
    LightUp();
  }
}

led next(led current)
{
  led next;
  if(currnet.anode == 3)
  {
    current.anode = 0;
    if(current.cathode == 3)
    {
      current.cathode = 0;
    }
    next.cathode = current.cathode + 1;
  }
  next.anode = current.anode + 1;
  return next;
}

void LightUp(led current)
{
  ClearAll();
  switch(current.cathode)
  {
    case 1: current.cathode = cathodePin1; break;
    case 2: current.cathode = cathodePin2; break;
    case 3: current.cathode = cathodePin3; break;
    default: Serial.println("ERR: incorrect led Coord (cathode)");
  }
  switch(current.anode)
  {
    case 1: current.anode = anodePin1; break;
    case 2: current.anode = anodePin2; break;
    case 3: current.anode = anodePin3; break;
    default: Serial.println("ERR: incorrect led Coord (anode)");
  }
  digitalWrite(current.cathode, LOW);
  digitalWrite(current.anode, HIGH);
}

void ClearAll()
{
  digitalWrite(cathodePin1, HIGH);
  digitalWrite(cathodePin2, HIGH);
  digitalWrite(cathodePin3, HIGH);    
}
