//Constantes dos pinos dos componentes
#define botao 2
#define ldr A0
#define led 3
#define buzzer 4

//Variável do estado do botao
bool status = false;

void setup() {
  //Definição do modo dos pinos
  pinMode(botao, INPUT);
  pinMode(ldr, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);

  //Iniciando o serial monitor
  Serial.begin(9600);
  delay(1000);
  //Fim do setup
}

void loop() {
  // Teste do led

  // digitalWrite(led, 1);
  // delay(200);
  // digitalWrite(led, 0);
  // delay(200);

  //Teste do buzzer

  // tone(buzzer, 523);
  // delay(200);
  // noTone(buzzer);
  // delay(200);

  //Teste do botão

  // Serial.print("Sinal do Botao: ");
  // Serial.println(digitalRead(botao));
  // Serial.print("Sinal do LDR: ");
  // Serial.println(analogRead(ldr));

  //Verificar qual a situação de aperto do botão (armar ou desarmar)

  if (digitalRead(botao) == 1 && status == false) {
    //O alarme está desarmado
    //Atualizando a variável de controle
    status = true;
  }  //fim do if
  else if (digitalRead(botao) == 1 && status == true) {
    //O alarme está armado
    //Atualizando a variável da controle
    status = false;

    //piscar o led e buzzer por 10 vezes, simbolizando o sinal de desarme do alarme
    digitalWrite(led, 1);
    tone(buzzer, 523);
    delay(200);
    digitalWrite(led, 0);
    noTone(buzzer)
    delay(200);

    digitalWrite(led, 1);
    tone(buzzer, 523);
    delay(200);
    digitalWrite(led, 0);
    noTone(buzzer)
    delay(200);

    digitalWrite(led, 1);
    tone(buzzer, 523);
    delay(200);
    digitalWrite(led, 0);
    noTone(buzzer)
    delay(200);

    digitalWrite(led, 1);
    tone(buzzer, 523);
    delay(200);
    digitalWrite(led, 0);
    noTone(buzzer)
    delay(200);

    digitalWrite(led, 1);
    tone(buzzer, 523);
    delay(200);
    digitalWrite(led, 0);
    noTone(buzzer)
    delay(200);

    digitalWrite(led, 1);
    tone(buzzer, 523);
    delay(200);
    digitalWrite(led, 0);
    noTone(buzzer)
    delay(200);

    digitalWrite(led, 1);
    tone(buzzer, 523);
    delay(200);
    digitalWrite(led, 0);
    noTone(buzzer)
    delay(200);

    digitalWrite(led, 1);
    tone(buzzer, 523);
    delay(200);
    digitalWrite(led, 0);
    noTone(buzzer)
    delay(200);

    digitalWrite(led, 1);
    tone(buzzer, 523);
    delay(200);
    digitalWrite(led, 0);
    noTone(buzzer)
    delay(200);

    digitalWrite(led, 1);
    tone(buzzer, 523);
    delay(200);
    digitalWrite(led, 0);
    noTone(buzzer)
    delay(200);
  }  //fim do else

  if (status == true) {
    if (analogRead(ldr) < 950) {
      //Acender o led e ligar o buzzer se a luz estiver fraca
      digitalWrite(led, 1);
      tone(buzzer, 523);

    }  //fim do if analog
    else {
      //Apagar led e desligar o buzzer se a luz estiver forte
      digitalWrite(led, 0);
      noTone(buzzer);

    }  //fim do else analog

  }  //fim do if status
  else {
    //desliga tudo
    digitalWrite(led, 0);
    noTone(buzzer);

  }            //fim do else status
  delay(300);  //delay estratégico para execução do sistema

}  //fim do loop