//Declaração da constante que armazena o pino do Push Button
#define pinoB 8
#define pinoL 10

//Declaração da variável booleana de estado do Push Button
bool status = false;

void setup() {
  //Definir a modalidade do pino
  pinMode(pinoB, INPUT);
  pinMode(pinoL, OUTPUT);
  Serial.begin(9600);
  delay(1000);
}

void loop() {
   if(digitalRead(pinoB) == 1 && status == false){
    
    Serial.println("Botao apertado = ON");
    //Mudando o estado do botão
    status = true;
    digitalWrite(pinoL, 1);
    Serial.println("Led Aceso");
   } else if(digitalRead(pinoB) == 1 && status == true){
    
    Serial.println("Botao desligado = OFF");
    //Mudando o estado do botão
    status = false;
    digitalWrite(pinoL, 0);
    Serial.println("Led Desligado");

   }
  //Lendo o pino digital através da constante
  delay(500);
}
