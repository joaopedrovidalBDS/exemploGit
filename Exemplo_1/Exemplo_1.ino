//Declaração das variáveis das notas, pesos, denominador e média:
float S, NS;


void setup() {
  // Coloque seu código de setup aqui, para rodar uma vez:

  //Iniciando a comunicação com o Monitor Serial:
  Serial.begin(9600);
  delay(1000);
}

void loop() {
  // Coloque seu código principal aqui, para rodar repetidamente:

  Serial.print("Digite seu salario antigo: ");
  S = aguardaEntradaN();
  Serial.println(S);

 NS = S * 125/100;

  //Mostra a nota ao usuário:
  Serial.print("Seu novo salario e: ");
  Serial.println(NS);
}

//Criando uma função chamada aguardaEntradaN
float aguardaEntradaN() {
  while (!Serial.available()) {
    //Aguarda o input no terminal
  }
  while (!isdigit(Serial.peek()) && Serial.peek() != '.') {
    //Enquanto próximo algarismo não for digito e o próximo digito não for .

    Serial.read();
    while (!Serial.available()) {
      
    }
  }

  //Retornar o valor digitado no terminal em tipo float
  return Serial.parseFloat();
}
