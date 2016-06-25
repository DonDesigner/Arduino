

/*
 * Ponte H + Motor de Passo + Botões esqueda/direita
 * + contador de voltas: Assim q atingir o nº de voltas ele desenrola
 *
 *  Diego Fernandes
 *  13/03/2016
 *  Motor de passo utilizado m35sp-8p
 */


#include <LiquidCrystal.h>

const int botaoHorario  = 2;
const int botaoAntiHorario  = 3;

LiquidCrystal lcd(13, 12, 7, 6, 5, 4) ;

int IN1 = 8;
int IN2 = 9;
int IN3 = 10;
int IN4 = 11;


int estadoBtnHorario = 0;
int estadoBtnAntiHorario = 0;
int pinoAtual = 8;

int voltasAtual = 0;
int voltasTotal = 0;
int paraUmaVolta = 40;

int tempo = 15;

void setup() {
  lcd.begin(16,2); //Inicia o LCD com dimensões 16x2
  lcd.setCursor(0,0);
  lcd.print("Iniciando...");
  lcd.setCursor(0,1);
  lcd.print("Projeto ROBO");
  
  pinMode(botaoHorario, INPUT);
  pinMode(botaoAntiHorario, INPUT);
  
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
 // Serial.begin(9600);
  
}

void loop() {

  estadoBtnHorario = digitalRead(botaoHorario);
  estadoBtnAntiHorario = digitalRead(botaoAntiHorario);
   
  if(estadoBtnHorario ==  HIGH || estadoBtnAntiHorario == HIGH)
  {
    digitalWrite(IN1, 0);
    digitalWrite(IN2, 0);
    digitalWrite(IN3, 0);
    digitalWrite(IN4, 0);

    if(estadoBtnHorario == HIGH)
    {
       pinoAtual++;       
    }
    else if(estadoBtnAntiHorario)
    {
       pinoAtual--;
    }
    
    if(pinoAtual > 11)
    {
      pinoAtual = 8;
    } else if(pinoAtual < 8)
    {
      pinoAtual = 11;
    }

    if(voltasAtual == paraUmaVolta)
    {
      voltasAtual=0;
      voltasTotal++;
    } else
    {
      voltasAtual++;
    }

    if(voltasTotal == 3)
    {
      
      int voltas = (3 * paraUmaVolta) / 4 ;
      lcd.setCursor(0,0);
      lcd.print("Atingiu 3 Voltas:");
      lcd.setCursor(0,1);
      lcd.print(voltas);
      for(int x = 0; x < voltas ; x++)
      {

        if(estadoBtnHorario == HIGH)
        {
          for(int p=11; p>7; p--)
          {
            digitalWrite(IN1, 0);
            digitalWrite(IN2, 0);
            digitalWrite(IN3, 0);
            digitalWrite(IN4, 0);
            
            digitalWrite(p, 1);
            delay(tempo);

            lcd.setCursor(5,1);
            lcd.print("p:");
            lcd.setCursor(8,1);
            lcd.print(p);
          }
        } else {
          for(int p=8; p<12; p++
          
          )
          {
            digitalWrite(IN1, 0);
            digitalWrite(IN2, 0);
            digitalWrite(IN3, 0);
            digitalWrite(IN4, 0);
            
            digitalWrite(p, 1);
            delay(tempo);
            
            lcd.setCursor(5,1);
            lcd.print("p:");
            lcd.setCursor(8,1);
            lcd.print(p);
          }
        }
        
        lcd.setCursor(12,1);
        lcd.print("x:");
        lcd.setCursor(15,1);
        lcd.print(x);
      }
      voltasTotal = 0;
    }

    lcd.setCursor(0,0);
    lcd.print("pA:");
    lcd.setCursor(0,1);
    lcd.print(pinoAtual);

    lcd.setCursor(4,0);
    lcd.print("vA:");
    lcd.setCursor(4,1);
    lcd.print(voltasAtual);

    lcd.setCursor(8,0);
    lcd.print("To:");
    lcd.setCursor(8,1);
    lcd.print(voltasTotal);


    
    digitalWrite(pinoAtual, 1);
    delay(tempo);
  }
  
}


