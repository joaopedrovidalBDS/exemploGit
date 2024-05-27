//Declaração do array exemplo 1
//int vetor[5];  // Tamanho do Vetor = 5

//Exemplo 2
int vetor[5] = { 15, 18, 23, 80, 17 };  // Tamanho do Vetor = 5

byte leds[] = { 2, 3, 4 };

void setup() {
  //Definição dos tipos dos pinos dos leds
  for (byte i = 0; i < 3; i++) {
    pinMode(leds[i], OUTPUT);
  }

  Serial.begin(9600);

  //Inicializando o array com alguns valores
  for (byte i = 0; i < 5; i++) {
    vetor[i] = i * 10;
  }
}

void loop() {

  //Exibindo os valores do vetor
  for (byte i = 0; i < 5; i++) {
    Serial.print(i);
    Serial.print(": ");
    Serial.println(vetor[i]);

    if (i < 3) {

      for (byte p = 0; p < 5; p++) {
        digitalWrite(leds[i], 1);
        delay(500);
        digitalWrite(leds[i], 0);
        delay(500);
      }
    }
  }
  delay(1000);
}
