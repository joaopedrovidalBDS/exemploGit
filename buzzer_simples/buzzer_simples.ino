#define pinoB 2
#define pinoL 3
bool status = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pinoB, OUTPUT);
  pinMode(pinoL, OUTPUT);
  delay(1000);

}

void loop() {
  // put your main code here, to run repeatedly:
    tone(pinoB, 523);
    digitalWrite(pinoL, 1);
    delay(1000);
    digitalWrite(pinoB, 0);
    digitalWrite(pinoL, 0);
    delay(1000);
}
