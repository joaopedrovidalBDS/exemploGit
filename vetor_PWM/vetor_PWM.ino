#define but 2
#define ldr A0
byte ledPins[4] = { 3, 5, 9, 10 };

byte buttonState = 0;
byte posLedSorteado = 0;
byte piscadasTotais = 2;
int tempoPiscada = 300;
int ldrValue = 0;


void setup() {
  

  pinMode(ldr, INPUT);
  pinMode(but, INPUT);

  //Configurando os pinos que estão no vetor
  for (byte i = 0; i < 4; i++ ) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], 0);
  }
}

void loop() {
  randomSeed(A5);
  buttonState = digitalRead(but);
  ldrValue = analogRead(ldr);

  if (buttonState == 1) {
    digitalWrite(ledPins[posLedSorteado], 0);
    posLedSorteado = random(4);

    for (byte i1 = 0; i1 < piscadasTotais; i1++ ) {
      for(byte i2 = 0; i2 < 4; i2++) {
        digitalWrite(ledPins[i2], 1);
        delay(tempoPiscada);
        digitalWrite(ledPins[i2], 0);
        delay(tempoPiscada);
      }
    }

    for (byte i = 0; i < 4; i++) {
      if (i == posLedSorteado) {
        analogWrite(ledPins[i], map(ldrValue, 0, 1023, 0, 254));
        break;
      }
      else{
        
        digitalWrite(ledPins[i], 1);
        delay(tempoPiscada);
        digitalWrite(ledPins[i], 0);
        delay(tempoPiscada);
    }
    }

  }
}
