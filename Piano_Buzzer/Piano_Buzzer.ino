#define pinoB 2
#define Ba 8
#define Bb 9
#define Bc 3
#define Bd 4
#define Be 5
#define Bf 6
#define Bg 7
#define Bc2 10

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pinoB, OUTPUT);
  pinMode(Ba, INPUT);
  pinMode(Bb, INPUT);
  pinMode(Bc, INPUT);
  pinMode(Bd, INPUT);
  pinMode(Be, INPUT);
  pinMode(Bf, INPUT);
  pinMode(Bg, INPUT);
  pinMode(Bc2, INPUT);
  delay(1000);
}

void loop() {
  /*// put your main code here, to run repeatedly:
  //-------------------------Dó-----------------
  if (digitalRead(Bc) == 1) {
    tone(pinoB, 523);
  } else {
    noTone(pinoB);
  }
  //-------------------------Ré-----------------
  if (digitalRead(Bd) == 1) {
    tone(pinoB, 587);
  } else {
    noTone(pinoB);
  }
  //-------------------------Mi-----------------
  if (digitalRead(Be) == 1) {
    tone(pinoB, 659);
  } else {
    noTone(pinoB);
  }
  //-------------------------Fá-----------------
  if (digitalRead(Bf) == 1) {
    tone(pinoB, 698);
  } else {
    noTone(pinoB);
  }
  //-------------------------Sol----------------
  if (digitalRead(Bg) == 1) {
    tone(pinoB, 783);
  } else {
    noTone(pinoB);
  }
  //-------------------------Lá-----------------
  if (digitalRead(Ba) == 1) {
    tone(pinoB, 880);
  } else {
    noTone(pinoB);
  }
  //-------------------------Si-----------------
  if (digitalRead(Bb) == 1) {
    tone(pinoB, 987);
  } else {
    noTone(pinoB);
  }*/

  if (digitalRead(Ba) == 1) {
    tone(pinoB, 440);
  } else if (digitalRead(Bb) == 1) {
    tone(pinoB, 497);
  } else if (digitalRead(Bc) == 1) {
    tone(pinoB, 261);
  } else if (digitalRead(Bd) == 1) {
    tone(pinoB, 294);
  } else if (digitalRead(Be) == 1) {
    tone(pinoB, 329);
  } else if (digitalRead(Bf) == 1) {
    tone(pinoB, 349);
  } else if (digitalRead(Bg) == 1) {
    tone(pinoB, 392);
  }else if(digitalRead(Bc2)){
    tone(pinoB, 523);
  }else{
    noTone(pinoB);
  }
  delay(50);
}
