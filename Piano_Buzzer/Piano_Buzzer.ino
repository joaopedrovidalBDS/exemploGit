#define pinoB 2
#define pinoL 3
#define A 4
#define B 5
#define C 6
#define D 7
#define E 8
#define F 9
#define G 10

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pinoB, OUTPUT);
  pinMode(pinoL, OUTPUT);
  pinMode(A, INPUT);
  pinMode(B, INPUT);
  pinMode(C, INPUT);
  pinMode(D, INPUT);
  pinMode(E, INPUT);
  pinMode(F, INPUT);
  pinMode(G, INPUT);
  delay(1000);

}

void loop() {
  // put your main code here, to run repeatedly:


}