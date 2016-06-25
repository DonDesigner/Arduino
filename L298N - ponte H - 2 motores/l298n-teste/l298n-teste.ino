/*Pinagem do Arduino */

//Motor A
int IN1 = 2;
int IN2 = 4;
int velocidadeA = 3;


//Variavel auxilidade
int velocidade=0;

//Inicinando PINOS
void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(velocidadeA, OUTPUT);
}

void loop() {
  /*Exemplo de velocidade no MotorA*/
  //Sentido Horario
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  //Potência ALTA
  analogWrite(velocidadeA, 230);

  //Potência MEDIA
  analogWrite(velocidadeA, 150);

  //Potência BAIXA
  analogWrite(velocidadeA, 80);




}
