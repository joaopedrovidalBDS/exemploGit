//Declaração das variáveis das notas, pesos, denominador e média:
float N1, N2, N3, P1, P2, P3, D, M;


void setup() {
  // Coloque seu código de setup aqui, para rodar uma vez:

  //Iniciando a comunicação com o Monitor Serial:
  Serial.begin(9600);
  delay(1000);
}

void loop() {
  // Coloque seu código principal aqui, para rodar repetidamente:
  Serial.println("Digite a nota 1: ");
  while(Serial.available() == 0) {
    //Aguarda o input no terminal
    
  }
  N1 = Serial.parseFloat();

  Serial.println("Digite a nota 2: ");
  while(Serial.available() == 0) {
    //Aguarda o input no terminal
    
  }
  N2 = Serial.parseFloat();

  Serial.println("Digite a nota 3: ");
  while(Serial.available() == 0) {
    //Aguarda o input no terminal
    
  }
  N3 = Serial.parseFloat();

  Serial.println("Digite o peso 1: ");
  while(Serial.available() == 0) {
    //Aguarda o input no terminal
    
  }
  P1 = Serial.parseFloat();

  Serial.println("Digite o peso 2: ");
  while(Serial.available() == 0) {
    //Aguarda o input no terminal
    
  }
  P2 = Serial.parseFloat();

  Serial.println("Digite o peso 3: ");
  while(Serial.available() == 0) {
    //Aguarda o input no terminal
    
  }
  P3 = Serial.parseFloat();

  //Cálculo do denominador:
  D = P1 + P2 + P3;

  //Cálculo da média ponderada:
  M = (N1 * P1 + N2 * P2 + N3 * P3) / D;

  //Mostra a nota ao usuário:
  Serial.print("Sua média ponderada total é: ");
  Serial.println(M);

}
