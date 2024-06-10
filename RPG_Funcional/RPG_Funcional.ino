//Definição das portas
#define botP 10
#define bot20 11
#define bot12 12
#define bot8 13
#define bot6 A1
#define bot4 A2
#define ledH A3
#define ledV A4
#define buz A5
//Definição das variáveis de apoio
int conta;
int pers = 0;
int HV = 0;
int VV = 0;
int numH = 0;
int numV = 0;
int cont = 0;

//Lista de sequências de LEDs para formar os números 0-19
byte displaySeteSeg[20][8] = {

{ 0, 0, 0, 0, 0, 0, 1, 1 }, //0
{ 1, 0, 0, 1, 1, 1, 1, 1 }, //1
{ 0, 0, 1, 0, 0, 1, 0, 1 }, //2
{ 0, 0, 0, 0, 1, 1, 0, 1 }, //3
{ 1, 0, 0, 1, 1, 0, 0, 1 }, //4
{ 0, 1, 0, 0, 1, 0, 0, 1 }, //5 
{ 0, 1, 0, 0, 0, 0, 0, 1 }, //6 
{ 0, 0, 0, 1, 1, 1, 1, 1 }, //7 
{ 0, 0, 0, 0, 0, 0, 0, 1 }, //8
{ 0, 0, 0, 0, 1, 0, 0, 1 }, //9
{ 0, 0, 0, 0, 0, 0, 1, 0 }, //0.
{ 1, 0, 0, 1, 1, 1, 1, 0 }, //1.
{ 0, 0, 1, 0, 0, 1, 0, 0 }, //2.
{ 0, 0, 0, 0, 1, 1, 0, 0 }, //3.
{ 1, 0, 0, 1, 1, 0, 0, 0 }, //4.
{ 0, 1, 0, 0, 1, 0, 0, 0 }, //5.
{ 0, 1, 0, 0, 0, 0, 0, 0 }, //6.
{ 0, 0, 0, 1, 1, 1, 1, 0 }, //7.
{ 0, 0, 0, 0, 0, 0, 0, 0 }, //8.
{ 0, 0, 0, 0, 1, 0, 0, 0 }, //9.

};

//Lista de carcterísticas dos personagens
int statusPers[8][5] = {

  { 0, 0, 0, 0, 0 },    //Player 0
  { -1, 2, 1, -2, 1 },  //Guerreiro
  { 0, -2, 1, 2, -1 },  //Mago
  { 0, 0, 2, 0, 1 },    //Arqueiro
  { -2, -1, 0, 1, 2 },  //Clérigo
  { 2, 0, 1, -1, -2 },  //Ladrão
  { 1, 2, 0, 2, 2 },    //Dragão
  { 2, 0, 2, 2, -1 },   //Necromante

};

void setup() {
  //Definição dos pinos do display
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  //Definição dos outros pinos
  pinMode(bot12, INPUT);
  pinMode(bot8, INPUT);
  pinMode(bot6, INPUT);
  pinMode(bot4, INPUT);
  Serial.begin(9600);
  //Comando para deixar a função Random aleatória
  randomSeed(analogRead(A0));
}

void loop() {
  //-------------------------------------------------------INICIO DO LOOP----------------------------------------------------------------------

  //Código para seleção de personagem
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
    HV = pers;
    ligaSegmentosDisplay(numH);
    cont += 1;
    delay(500);

  } else if (digitalRead(bot20) != 0 && pers > 5) {

    randomDado(20);
    numV = conta;
    VV = pers;
    ligaSegmentosDisplay(numV);
    cont += 1;
    delay(500);
  }

  //Decidindo o número maior
  if (cont >= 2) {
    cont = 0;

    if (numH > numV || numH == 0) {  // Herói com o maior
	    pers = HV;
      ligaSegmentosDisplay(numH);
      analogWrite(ledH, 255);
      analogWrite(ledV, 0);
      Serial.println("O HEROI rodou um numero maior!");
      musicaPlay(1);
      delay(1000);

    } else if (numV > numH || numV == 0) {  // Vilão com o maior
	    pers = VV;
      ligaSegmentosDisplay(numV);
      analogWrite(ledH, 0);
      analogWrite(ledV, 255);
      Serial.println("O VILAO rodou um numero maior!");
      musicaPlay(2);
      delay(1000);

    } else {  // Números iguais
	    pers = 0;
      ligaSegmentosDisplay(0);
      analogWrite(ledV, 255);
      analogWrite(ledH, 255);
      Serial.println("Os numeros sao iguais!");
      delay(1000);
    }
  }

  //Girando um dado de 12 lados:
  if (digitalRead(bot12) != 0) {
    randomDado(12);
    ligaSegmentosDisplay(conta);
    if (conta == 0) {
      Serial.println("D12 CRITICO!");
    }
    delay(500);
    if (conta == 0) {
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
    if (conta == 0) {
      Serial.println("D8 CRITICO!");
    }
    delay(500);
    if (conta == 0) {
      conta = 8;
    }
    conta += statusPers[pers][3];
    Serial.print("Dano: ");
    Serial.println(conta);
  }

  //Girando um dado de 6 lados:
  if (analogRead(bot6) == 1023) {
    randomDado(6);
    ligaSegmentosDisplay(conta);
    if (conta == 0) {
      Serial.println("D6 CRITICO!");
    }
    delay(500);
    if (conta == 0) {
      conta = 6;
    }
    conta += statusPers[pers][0];
    Serial.print("Dano: ");
    Serial.println(conta);
  }

  //Girando um dado de 4 lados:
  if (analogRead(bot4) == 1023) {
    randomDado(4);
    ligaSegmentosDisplay(conta);
    if (conta == 0) {
      Serial.println("D4 CRITICO!");
    }
    delay(500);
    if (conta == 0) {
      conta = 4;
    }
    conta += statusPers[pers][2];
    Serial.print("Dano: ");
    Serial.println(conta);
  }

  noTone(buz);
  digitalWrite(ledH, 0);
  digitalWrite(ledV, 0);
}
//-------------------------------------------------------FIM DO LOOP-----------------------------------------------------------------------------------------
void ligaSegmentosDisplay(byte digito) {  //função para acionar o display com o digito correspondente

  byte pino = 2;

  //Liga os segmentos de acordo com o digito correspondente
  for (byte contadorSegmentos = 0; contadorSegmentos < 8; ++contadorSegmentos) {
    digitalWrite(pino, displaySeteSeg[digito][contadorSegmentos]);
    ++pino;
  }
}

void randomDado(byte numDado) {  //Função para rodar e exibir um número aleatório

  conta = random(numDado);  //aleatório

  if (conta == numDado) {  //Se passar de 20 reseta o display para 0
    conta = 0;
    ligaSegmentosDisplay(conta);
  } else {  //Se não mostra no display o próximo número
    ligaSegmentosDisplay(conta);
  }
}

void musicaPlay(byte numMus) {
  if (numMus == 1) {
    tone(buz, 524);
    delay(375);
    tone(buz, 660);
    delay(125);
    tone(buz, 784);
    delay(250);
    tone(buz, 660);
    delay(250);
    tone(buz, 1048);
    delay(375);
    noTone(buz);
  } else if (numMus == 2) {
    tone(buz, 660);
    delay(375);
    tone(buz, 622);
    delay(375);
    tone(buz, 588);
    delay(375);
    tone(buz, 554);
    delay(750);
  }
}