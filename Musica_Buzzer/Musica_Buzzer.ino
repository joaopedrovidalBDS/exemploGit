#define pinoB 2
#define pinoS 3

void setup() {
  // put your setup code here, to run once:
  pinMode(pinoB, OUTPUT);
  pinMode(pinoS, INPUT);
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(pinoS == 1){
    // Fá, lá, si
    tone(pinoB, 174);
    delay(125);
    noTone(pinoB);
    delay(125);

    tone(pinoB, 220);
    delay(125);
    noTone(pinoB);
    delay(125);

    tone(pinoB, 247);
    delay(250);

    //Fá, lá, si
    tone(pinoB, 174);
    delay(125);
    noTone(pinoB);
    delay(125);

    tone(pinoB, 220);
    delay(125);
    noTone(pinoB);
    delay(125);

    tone(pinoB, 247);
    delay(250);

    //Fá, lá, si, mi, ré
    tone(pinoB, 174);
    delay(250);

    tone(pinoB, 220);
    delay(125);
    noTone(pinoB);
    delay(125);

    tone(pinoB, 247);
    delay(125);
    noTone(pinoB);
    delay(125);

    tone(pinoB, 330);
    delay(125);
    noTone(pinoB);
    delay(125);

    tone(pinoB, 295);
    delay(250);

    //Si, dó, si, sol, mi
    tone(pinoB, 247);
    delay(125);
    noTone(pinoB);
    delay(125);

    tone(pinoB, 261);
    delay(125);
    noTone(pinoB);
    delay(125);

    tone(pinoB, 247);
    delay(250);

    tone(pinoB, 196);
    delay(125);
    noTone(pinoB);
    delay(125);

    tone(pinoB, 165);
    delay(1125);

    //Ré, mi, sol, mi
    tone(pinoB, 147);
    delay(125);

    tone(pinoB, 165);
    delay(125);
    noTone(pinoB);
    delay(125);

    tone(pinoB, 196);
    delay(125);
    noTone(pinoB);
    delay(125);

    tone(pinoB, 165);
    delay(2000);
  }
}
