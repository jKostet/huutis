// motor control pins
int leftMotorForward = 3;
int leftMotorBackward = 9;
int rightMotorForward = 11;
int rightMotorBackward = 10;

int speaker = 14;
int mic = 16;

boolean moved = false;

// adjust these according to testing and space
int low = 200;  // for beep
int med = 400;  // for two higher beeps 
int high = 600; // drive!

// adjust how long robot goes each drive!
int driveMs = 100;

void setup() { 
  // put your setup code here, to run once:
  pinMode(leftMotorForward, OUTPUT);
  pinMode(leftMotorBackward, OUTPUT);
  pinMode(rightMotorForward, OUTPUT);
  pinMode(rightMotorBackward, OUTPUT);
  
  pinMode(speaker, OUTPUT);
  pinMode(mic, INPUT);

  delay(300);
  
  Serial.begin(9600);
}

void loop() {

  if (moved) {
    delay(100);
    moved = false;
    return;
  }
  
  int vol = (int) analogRead(16);
  Serial.println(vol);
  delay(10);

  if (vol > high) {
    tone(speaker, 500, 50);
    delay(100);
    //noTone();
    move(driveMs, 200, 0, 200, 0);
    moved = true;
    move(10, 0, 0, 0, 0);
    
  } else if (vol > med) {
    tone(speaker, 400, 100);
    moved = true;
    
  } else if (vol > low) {
    tone(speaker, 300, 200);
    moved = true;
  }
 
}

void move(int time, int lF, int lB, int rF, int rB) {
  analogWrite(leftMotorForward, lF);
  analogWrite(leftMotorBackward, lB);
  analogWrite(rightMotorForward, rF);
  analogWrite(rightMotorBackward, rB);
  delay(time);

  //Serial.begin(9600);
}
