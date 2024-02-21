//Declaração de variáveis de entrada
int N1;
int N2;
int N3;

//Declaração da variável de saída
int S;

void setup() {
  // coloque seu codigo de setup aqui, para rodar uma vez:

  //Iniciando a comunicação com o Monitor Serial
  Serial.begin(9600);

  // Variável recebe valor:
  N1 = 1;
  N2 = 2;
  N3 = 3;
  S = 0;

  //Processamento das entradas:
  S = N1 + N2 + N3;
}

void loop() {
  // coloque seu codigo principal aqui, para rodar repetidamente:

  //Escrevendo o resultado na tela:
  Serial.print("O seu resultado é: "); // Mostra a frase no monitor
  Serial.print(S); // Mostra o valor da soma
  Serial.println(". "); // ln = Muda o cursor de linha
  delay(1000); // Espera 1 segundo antes de seguir o loop
}
