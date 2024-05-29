int pinUlt[2] = {2, 3};
int pinLed[5] = {5, 6, 7, 8, 9};
#define pinB1 10
#define pinB2 11
#define buz 4
#define ldr1 A0
#define minima 300

float tE = 0;
bool status1 = false;
bool status2 = false;





void setup() {
  Serial.begin(9600);

  pinMode(pinUlt[0], OUTPUT);
  digitalWrite(pinUlt[0], 0);
  pinMode(buz, OUTPUT);

  pinMode(pinUlt[1], INPUT);
  pinMode(pinB2, INPUT);
  delay(1000);
}

void loop() {

  if (digitalRead(pinB1) == 1 && status1 == false) {
    status1 = true;
    delay(100);
  }else if (digitalRead(pinB1) == 1 && status1 == true) {
    status1 = false;
    delay(100);
  }
  if (digitalRead(pinB2) == 1 && status2 == false) {
    status2 = true;
    delay(100);
  }else if (digitalRead(pinB2) == 1 && status2 == true) {
    status2 = false;
    delay(100);
  }

  if (status1 == true) {
    disparo();
    tE = pulseIn(pinUlt[1], HIGH);

    if (calculoCm(tE) < 30) {

      for(byte i = 0; i < 3; i++){
        digitalWrite(pinLed[i], 1);
        digitalWrite(pinLed[i-1], 0);
        tone(buz, 500);
        delay(200);
        tone(buz, 300);
        delay(200);
      }
      
    }

  }

  if (status2 == true) {
    if (analogRead(ldr1) < minima) {
      digitalWrite(pinLed[3], HIGH); 
      digitalWrite(pinLed[4], HIGH);
    } else {
      digitalWrite(pinLed[3], LOW); 
      digitalWrite(pinLed[4], LOW);
    }
    delay(200); 
  }

}

void disparo() {
  digitalWrite(pinUlt[0], 1);
  delayMicroseconds(10);
  digitalWrite(pinUlt[0], 0);
}

float calculoCm(float tM) {
  return (((tM * 0.000340) / 2) * 100);
}