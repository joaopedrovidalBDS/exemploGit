//Declaração das variáveis das notas, pesos, denominador e média:
float N1, N2, N3, P1, P2, P3, D, M;


void setup() {
  // Coloque seu código de setup aqui, para rodar uma vez:

  //Iniciando a comunicação com o Monitor Serial:
  Serial.begin(9600);
  delay(1000);

  //Atribuição de valores artificiais:
  N1 = 5.5;
  N2 = 2;
  N3 = 9.3;
  P1 = 7;
  P2 = 10;
  P3 = 3.3;

  //Definindo o Denominador:
  D = P1 + P2 + P3;

  //Checando se será uma divisão por zero:
  if (D == 0) {
    Serial.print("Impossível dividir por zero!");
  } else {
    //Caso contrário, processe a média ponderada:
    M = (N1 * P1) + (N2 * P2) + (N3 * P3) / D;
  }
}

void loop() {
  // Coloque seu código principal aqui, para rodar repetidamente:

  //Escrevendo o resultado na tela, se ele for possível:

  if (D == 0) {
    Serial.println("Impossível calcular a média ponderada.");  // Mostra a frase no monitor
    delay(1000);                                               // Espera 1 segundo antes de seguir o loop
  } else {
    Serial.print("O seu resultado é: ");  // Mostra a frase no monitor
    Serial.print(M);                      // Mostra o valor da soma
    Serial.println(". ");                 // ln = Muda o cursor de linha
    delay(1000);                          // Espera 1 segundo antes de seguir o loop
  }
}
