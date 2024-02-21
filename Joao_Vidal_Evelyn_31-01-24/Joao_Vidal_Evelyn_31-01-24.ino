
//declaração das variáveis salário e novo salário decimais
float S, NS;

void setup() {
  // coloque seu codigo de setup aqui, para rodar uma vez:

  S = -800;
  NS = 0;

  //Verificando o valor do salário com a condicional
  if (S <= 500 && S > 0) {  //Início da condicional

    //Processamento do novo salário
    NS = 1.2 * S;

  }  //Fim da condicional
  else if (S > 500) {

    NS = 1.1 * S;
  } else {
    NS = 0;
  }

  //Iniciando a comunicação com o Monitor Serial
  Serial.begin(9600);
}

void loop() {
  // coloque seu codigo principal aqui, para rodar repetidamente:

  //Escrevendo a mensagem na tela:
  //Serial.println("Hoje é o último dia do mês de Janeiro! ");  //Mostra a frase no monitor

  if(NS == 0){

    Serial.println("Erro no sistema. O usuário, devido ao contrato assinado, será cobrado no valor de R$7000. Conectando com sua conta bancária em");
    delay(3000);
    Serial.println("3");
    delay(1000);
    Serial.println("2");
    delay(1000);
    Serial.println("1");
    delay(1000);
    Serial.println("lololololol");
    delay(2000);
  
  }else {
  Serial.print("Novo salário: ");         //Mostra parte da resposta
  Serial.println(NS);                     //Mostra o valor
  Serial.println("-------------------");  //Gráfico somente
  delay(1000);                            //Espera 1 segundo antes de seguir o loop
  }

}
