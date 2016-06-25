/*********************************
Autor: Fernando Krein Pinheiro
Data: 18/08/2011
Linguagem: C (Wiring)
========= IMPORTANTE ===========
O código esta livre para usar,
citar e compartilhar desde que
mantida sua fonte e seu autor.
Obrigado.
********************************/
 
int ledPin13 =  13; // v
int ledPin11 =  11; // z
int ledPin9  =  9;  // l
int ledPin7  =  7;  // a
 
void setup()   {
 
  Serial.begin(9600);
 
  pinMode(ledPin13, OUTPUT);
  pinMode(ledPin11, OUTPUT);
  pinMode(ledPin9, OUTPUT);
  pinMode(ledPin7, OUTPUT);
 
}
 
void loop()
{
  char caracter;
  caracter = Serial.read();


  //se pressionado "v" liga o led verde
  if(caracter == 'v')
  {
    int val = digitalRead(ledPin13); // le o valor na entrada
    if (val == LOW) // se valor está em zero( tecla pressionada)
    {
      digitalWrite(ledPin13, HIGH); // Liga LED indicando tecla pressionada
    }
    else
    {
      digitalWrite(ledPin13, LOW); // Desliga LED indicando tecla solta
    }
  }

  if(caracter == 'z')
  {
    int val = digitalRead(ledPin11); // le o valor na entrada
    if (val == LOW) // se valor está em zero( tecla pressionada)
    {
      digitalWrite(ledPin11, HIGH); // Liga LED indicando tecla pressionada
    }
    else
    {
      digitalWrite(ledPin11, LOW); // Desliga LED indicando tecla solta
    }
  }


 
  //S pressionado "l" liga o led laranja
  if(caracter == 'l')
  {
    int val = digitalRead(ledPin9); // le o valor na entrada
    if (val == LOW) // se valor está em zero( tecla pressionada)
    {
      digitalWrite(ledPin9, HIGH); // Liga LED indicando tecla pressionada
    }
    else
    {
      digitalWrite(ledPin9, LOW); // Desliga LED indicando tecla solta
    }
  }



  
  //Se pressionado "a" liga o led amarelo
  if(caracter == 'a')
  {
    int val = digitalRead(ledPin7); // le o valor na entrada
    if (val == LOW) // se valor está em zero( tecla pressionada)
    {
      digitalWrite(ledPin7, HIGH); // Liga LED indicando tecla pressionada
    }
    else
    {
      digitalWrite(ledPin7, LOW); // Desliga LED indicando tecla solta
    }
  }

  //INVERTE OS LED's
  if(caracter == 'm')
  {
    int val1 = digitalRead(ledPin7); // le o valor na entrada
    int val2 = digitalRead(ledPin9); // le o valor na entrada
    int val3 = digitalRead(ledPin11); // le o valor na entrada
    int val4 = digitalRead(ledPin13); // le o valor na entrada
    
    if (val1 == LOW) // se valor está em zero( tecla pressionada)
    {
      digitalWrite(ledPin7, HIGH); // Liga LED indicando tecla pressionada
    }
    else
    {
      digitalWrite(ledPin7, LOW); // Desliga LED indicando tecla solta
    }

    if (val2 == LOW) // se valor está em zero( tecla pressionada)
    {
      digitalWrite(ledPin9, HIGH); // Liga LED indicando tecla pressionada
    }
    else
    {
      digitalWrite(ledPin9, LOW); // Desliga LED indicando tecla solta
    }

    if (val3 == LOW) // se valor está em zero( tecla pressionada)
    {
      digitalWrite(ledPin11, HIGH); // Liga LED indicando tecla pressionada
    }
    else
    {
      digitalWrite(ledPin11, LOW); // Desliga LED indicando tecla solta
    }

    if (val4 == LOW) // se valor está em zero( tecla pressionada)
    {
      digitalWrite(ledPin13, HIGH); // Liga LED indicando tecla pressionada
    }
    else
    {
      digitalWrite(ledPin13, LOW); // Desliga LED indicando tecla solta
    }

    //LIGA TODOS OU APAGA TODOS
  if(caracter == 't')
  {
    int val1 = digitalRead(ledPin7); // le o valor na entrada
    int val2 = digitalRead(ledPin9); // le o valor na entrada
    int val3 = digitalRead(ledPin11); // le o valor na entrada
    int val4 = digitalRead(ledPin13); // le o valor na entrada
    
    if (val1 == LOW && val2 == LOW && val3 == LOW && val4 == LOW ) // se valor está em zero( tecla pressionada)
    {
      digitalWrite(ledPin7, HIGH); 
      digitalWrite(ledPin9, HIGH);
      digitalWrite(ledPin11, HIGH);
      digitalWrite(ledPin13, HIGH);
    }
    else
    {
      digitalWrite(ledPin7, LOW); 
      digitalWrite(ledPin9, LOW);
      digitalWrite(ledPin11, LOW);
      digitalWrite(ledPin13, LOW);
    }
  }

   
  }
}
  

