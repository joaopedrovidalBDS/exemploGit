//Constantes para armazenamento dos pinos trig e echo
#define trig 2  //pino usado para disparar os pulsos sensor
#define echo 3  //pino usado para ler a saída do sensor

//Variável para guardar o tempo da onda
float tempoEcho = 0.0;

//Valores baseados na velocidade do som
float veloSoms = 340.0;      // Metros por segundo
float veloSomMs = 0.000340;  //Metros por microssegundos

void setup() {
  Serial.begin(9600);

  //Configuração do modo do pino trig como saida e inicio com sinal 0
  pinMode(trig, OUTPUT);
  digitalWrite(trig, 0);

  //Configuração do modo do pino echo como entrada
  pinMode(echo, INPUT);

  delay(1000);
}

void loop() {
  //Envia pulso para disparar sensor
  disparaUltrassonico();
  //Mede o tempo de duração do sinal do pino de leitura (em us)
  tempoEcho = pulseIn(echo, HIGH);
  Serial.print("Distancia em metros: ");
  Serial.println(calculaDistancia(tempoEcho));
  Serial.print("Distancia em centimetros: ");
  Serial.println(calculaDistancia(tempoEcho) * 100);
  delay(500);
}

//Definindo funções:--------------------------------------------------------------------------------------------------------------------

//Função de disparar o sensor (pulso trigger):
void disparaUltrassonico() {
  //Para fazer o ultrassonico enviar um pulso é necessário enviar para o pino trig um sinal 1(HIGH) com pelo menos 10us(microssegundos).
  digitalWrite(trig, 1);
  delayMicroseconds(10);
  digitalWrite(trig, 0);
}

//Função de calcular a distância:
float calculaDistancia(float tempoMicros) {
  return ((tempoMicros * veloSomMs) / 2);
}
