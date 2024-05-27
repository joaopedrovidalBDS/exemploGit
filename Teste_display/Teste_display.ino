//Definindo as portas necessárias
#define botP 10
#define bot20 11
#define bot12 12
#define bot8 13
#define bot6 A1
#define bot4 A2
#define ledH A3
#define ledV A4
#define buz A5
//Definindo variaveis auxiliares
int conta;  //
int pers = 0;
int numH = 0;
int numV = 0;
int cont = 0;

//Define a matriz dos números no display
byte displaySeteSeg[20][8] = {

  { 1, 1, 1, 1, 1, 1, 0, 0 },  //DIGITO 0
  { 0, 1, 1, 0, 0, 0, 0, 0 },  //DIGITO 1
  { 1, 1, 0, 1, 1, 0, 1, 0 },  //DIGITO 2
  { 1, 1, 1, 1, 0, 0, 1, 0 },  //DIGITO 3
  { 0, 1, 1, 0, 0, 1, 1, 0 },  //DIGITO 4
  { 1, 0, 1, 1, 0, 1, 1, 0 },  //DIGITO 5
  { 1, 0, 1, 1, 1, 1, 1, 0 },  //DIGITO 6
  { 1, 1, 1, 0, 0, 0, 0, 0 },  //DIGITO 7
  { 1, 1, 1, 1, 1, 1, 1, 0 },  //DIGITO 8
  { 1, 1, 1, 1, 0, 1, 1, 0 },  //DIGITO 9
  { 1, 1, 1, 1, 1, 1, 0, 1 },  //DIGITO 0.
  { 0, 1, 1, 0, 0, 0, 0, 1 },  //DIGITO 1.
  { 1, 1, 0, 1, 1, 0, 1, 1 },  //DIGITO 2.
  { 1, 1, 1, 1, 0, 0, 1, 1 },  //DIGITO 3.
  { 0, 1, 1, 0, 0, 1, 1, 1 },  //DIGITO 4.
  { 1, 0, 1, 1, 0, 1, 1, 1 },  //DIGITO 5.
  { 1, 0, 1, 1, 1, 1, 1, 1 },  //DIGITO 6.
  { 1, 1, 1, 0, 0, 0, 0, 1 },  //DIGITO 7.
  { 1, 1, 1, 1, 1, 1, 1, 1 },  //DIGITO 8.
  { 1, 1, 1, 1, 0, 1, 1, 1 },  //DIGITO 9.

};

//Define a matriz dos status dos personagens
int statusPers[8][5] = {
  
  {0, 0, 0, 0, 0},    //Player 0
  {-1, 2, 1, -2, 1}, //Guerreiro
  {0, -2, 1, 2, -1}, //Mago
  {0, 0, 2, 0, 1},   //Arqueiro
  {-2, -1, 0, 1, 2}, //Clérigo
  {2, 0, 1, -1, -2}, //Ladrão
  {1, 2, 0, 2, 2},   //Dragão
  {2, 0, 2, 2, -1},  //Necromante

};

void setup() {
  //Re-aleatorizando o random
  randomSeed(analogRead(A0));
  //Definindo pinos como saída
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  //Definindo os botões como entrada
  pinMode(botP, INPUT);
  pinMode(bot20, INPUT);

  Serial.begin(9600);
  //Inicializa display com número 0
  conta = 0;
  ligaSegmentosDisplay(conta);
}
//-------------------------------------------------------INICIO DO LOOP----------------------------------------------------------------------
void loop() {
  //Contador para avançar personagem:
  if (digitalRead(botP) != 0) {
    pers += 1;
    if (pers > 7) {
      pers = 1;
    }
    ligaSegmentosDisplay(pers);
    delay(500);
  }

  //Rodando o número aleatório:
  if (digitalRead(bot20) != 0 && pers < 6) {

    randomDado(20);
    numH = conta;
    ligaSegmentosDisplay(numH);
    cont += 1;
    delay(500);

  } else if (digitalRead(bot20) != 0 && pers > 5) {

    randomDado(20);
    numV = conta;
    ligaSegmentosDisplay(numV);
    cont += 1;
    delay(500);
  }

  //Girando um dado de 12 lados:
  if (digitalRead(bot12) != 0) {
    randomDado(12);
    ligaSegmentosDisplay(conta);
    if (conta == 0){
      Serial.println("D12 CRITICO!");
    }
    delay(500);
    if (conta == 0){
      conta = 12;
    }
    conta += statusPers[pers][1];
    Serial.print("Dano: ");
    Serial.println(conta);
  }

  //Girando um dado de 8 lados:
  if (digitalRead(bot8) != 0) {
    randomDado(8);
    ligaSegmentosDisplay(conta);
    if (conta == 0){
      Serial.println("D8 CRITICO!");
    }
    delay(500);
    if (conta == 0){
      conta = 8;
    }
    conta += statusPers[pers][3];
    Serial.print("Dano: ");
    Serial.println(conta);
  }

  //Girando um dado de 6 lados:
  if (analogRead(bot6) != 0) {
    randomDado(6);
    ligaSegmentosDisplay(conta);
    if (conta == 0){
      Serial.println("D6 CRITICO!");
    }
    delay(500);
    if (conta == 0){
      conta = 6;
    }
    conta += statusPers[pers][0];
    Serial.print("Dano: ");
    Serial.println(conta);
  }

    //Girando um dado de 4 lados:
  if (analogRead(bot4) != 0) {
    randomDado(4);
    ligaSegmentosDisplay(conta);
    if (conta == 0){
      Serial.println("D4 CRITICO!");
    }
    delay(500);
    if (conta == 0){
      conta = 4;
    }
    conta += statusPers[pers][2];
    Serial.print("Dano: ");
    Serial.println(conta);
  }

  //Decidindo o número maior
  if (cont >= 2) {
    cont = 0;

    if (numH > numV) { // Herói com o maior
      ligaSegmentosDisplay(numH);
      analogWrite(ledH, 255);
      analogWrite(ledV, 0);
      Serial.println("O HEROI rodou um numero maior!");
      tone(buz, 523);
      delay(1000);

    } else if (numV > numH) { // Vilão com o maior
      ligaSegmentosDisplay(numV);
      analogWrite(ledH, 0);
      analogWrite(ledV, 255);
      Serial.println("O VILAO rodou um numero maior!");
      tone(buz, 823);
      delay(1000);

    } else {  // Números iguais
      ligaSegmentosDisplay(0);
      analogWrite(ledV, 255);
      analogWrite(ledH, 255);
      Serial.println("Os numeros sao iguais!");
      delay(1000);
    }
  }
  //Apaga os leds se acenderam na comparação
  noTone(buz);
  analogWrite(ledH, 0);
  analogWrite(ledV, 0);
}
//-------------------------------------------------------FIM DO LOOP----------------------------------------------------------------------
void ligaSegmentosDisplay(byte digito) {  //função para acionar o display com o digito correspondente

  byte pino = 2;

  //Liga os segmentos de acordo com o digito correspondente
  for (byte contadorSegmentos = 0; contadorSegmentos < 8; ++contadorSegmentos) {
    digitalWrite(pino, displaySeteSeg[digito][contadorSegmentos]);
    ++pino;
  }
}

void randomDado(byte numDado) { //Função para rodar e exibir um número aleatório

  conta = random(numDado);  //aleatório

  if (conta == numDado) {  //Se passar de 20 reseta o display para 0
    conta = 0;
    ligaSegmentosDisplay(conta);
  } else {  //Se não mostra no display o próximo número
    ligaSegmentosDisplay(conta);
  }
}