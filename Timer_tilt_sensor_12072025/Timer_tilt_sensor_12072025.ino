const int ts = 13;
const int startTimer = 0;
unsigned long currentTime = 0;
unsigned long preTime = 0;
const int switchTime = 1000;
int led = 2;
int preSwitch = 0;
int switchState = 0;


void setup() {

  for(int x = 2; x<6; x++){
    pinMode(x,OUTPUT);
  }

  pinMode(8, INPUT);
  Serial.begin(9600);
}

void loop() {
  currentTime = millis();
  if (currentTime - preTime> switchTime) {
    preTime = currentTime;
    digitalWrite(led, HIGH);
    led++;
  }
  switchState = digitalRead(ts);
  Serial.print(switchState);
  if (switchState != preSwitch){
    currentTime = 0;
    led = 2;
    for (int y = 2; y < 6; y++){
      digitalWrite(y, LOW);
    }
  }
}
