#define pinoB 2
#define pinoL 3
#define opt 4
#define pinoF 5

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pinoB, OUTPUT);
  pinMode(pinoL, OUTPUT);
  pinMode(opt, INPUT);
  pinMode(pinoF, OUTPUT);
  delay(1000);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(opt) == 1){
    tone(pinoB, 523);
    digitalWrite(pinoL, 1);
    digitalWrite(pinoF, 0);
  }else{
    noTone(pinoB);
    digitalWrite(pinoL, 0);
    digitalWrite(pinoF, 1);
  }

}
