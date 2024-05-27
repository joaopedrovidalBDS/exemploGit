int conta;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  conta = random(0,21);
  Serial.println(conta);
  delay(1000);

}
