//Declaração das variáveis que representam os pinos dos leds
int ledAmarelo = 8;
int ledVermelho = 9;
int ledVerde = 10;
int ledVerde2 = 11;
int ledAmarelo2 = 12;
int ledVermelho2 = 13;

void setup() {

  //Definindo os tipos dos pinos
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo2, OUTPUT);
  pinMode(ledVermelho2, OUTPUT);
  pinMode(ledVerde2, OUTPUT);

  delay(1000);
}

void loop() {

  //definindo o estado natural das portas
  digitalWrite(ledAmarelo, 0);
  digitalWrite(ledVermelho, 0);
  digitalWrite(ledVerde, 0);
  digitalWrite(ledAmarelo2, 0);
  digitalWrite(ledVermelho2, 0);
  digitalWrite(ledVerde2, 0);

  //executando os semáforos
  digitalWrite(ledVerde, 1);
  digitalWrite(ledVermelho2, 1);
  delay(3000);
  digitalWrite(ledVerde, 0);
  digitalWrite(ledAmarelo, 1);
  delay(1500);
  digitalWrite(ledAmarelo, 0);
  digitalWrite(ledVermelho2, 0);
  digitalWrite(ledVermelho, 1);
  digitalWrite(ledVerde2, 1);
  delay(3000);
  digitalWrite(ledVerde2, 0);
  digitalWrite(ledAmarelo2, 1);
  delay(1500);
  digitalWrite(ledAmarelo2, 0);
  digitalWrite(ledVermelho, 0);
}
