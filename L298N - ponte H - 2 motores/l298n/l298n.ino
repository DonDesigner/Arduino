/*Pinagem do Arduino */

//Motor A
int IN1 = 2;
int IN2 = 4;
int velocidadeA = 3;

//Motor B
int IN3 = 6;
int IN4 = 7;
int velocidadeB = 5;

//Variavel auxilidade
int velocidade=0;

//Inicinando PINOS
void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(velocidadeA, OUTPUT);
  pinMode(velocidadeB, OUTPUT);
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

  /*Exemplo de velocidade do MotoB*/
  //Sentido Horario
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  //velocidade de 0 a 255 "Aumentar"
  while(velocidadeB < 255){
    analogWrite(velocidadeB, velocidade);
    velocidade = velocidade + 10;
    delay(50);
  }

  //velocidade de 255 a 0 "Diminuir"
  while(velocidadeB > 0){
    analogWrite(velocidadeB, velocidade);
    velocidade = velocidade - 10;
    delay(50);
  }

}
