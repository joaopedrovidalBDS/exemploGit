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

  Serial.print("Digite a nota 1: ");
  N1 = aguardaEntrada();
  Serial.println(N1);

  Serial.print("Digite a nota 2: ");
  N2 = aguardaEntrada();
  Serial.println(N2);

  Serial.print("Digite a nota 3: ");
  N3 = aguardaEntrada();
  Serial.println(N3);

  Serial.print("Digite o peso 1: ");
  P1 = aguardaEntrada();
  Serial.println(P1);

  Serial.print("Digite o peso 2: ");
  P2 = aguardaEntrada();
  Serial.println(P2);

  Serial.print("Digite o peso 3: ");
  P3 = aguardaEntrada();
  Serial.println(P3);

  //Cálculo do denominador:
  D = P1 + P2 + P3;

  //Cálculo da média ponderada:
  M = (N1 * P1 + N2 * P2 + N3 * P3) / D;

  //Mostra a nota ao usuário:
  Serial.print("Sua media ponderada total e: ");
  Serial.println(M, 1);


}

//Criando uma função chamada aguardaEntrada
    float aguardaEntrada(){
    while (!Serial.available()) {
      //Aguarda o input no terminal
    }

    //Retornar o valor digitado no terminal em tipo float
    return Serial.parseFloat();
  }
