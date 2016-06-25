//***********************************
//Projeto Temperatura da Sala e dos Servidores, com dados salvos em um MICROSD
//01 - Os dados podem ser enviados em tempo real por serial atravez de um comando
//02 - Os dados podem ser acessados (enviados) do MICROSD para um servidor que enterpretará esses dados para gerar um gráfico
//03 - Atravaz da Serial pode-se alterar os valores de Alerta das Temperaturas
//***********************************
// Diego Fernandes - 26/03/2016 - Beta01
// 01 - DHT11
// 02 - LM35
// 01 - MICROSD Adapter +cartão de 2gb
// LED Informativos

//Sendo:
//v = Variavel
//s = Temperatura da 'Sala'
//h = Humidade da 'Sala'
//a = Temperatura do Servidor 'A'
//b = Temperatura do Servidor 'B'
//d = Data e Hora do evento


#include <DHT.h>
#include <SPI.h>
#include <SD.h>

#define DHTPIN A1
#define DHTTYPE DHT11


//*** Inicar DEVICES/SHIELDS
DHT dht(DHTPIN, DHTTYPE);
File myFile;

const int chipSelect = 10; //Tipo de Leitor e Cartão SD


//*** Variaveis
float h = dht.readHumidity();
float s = dht.readTemperature();
float a; //Servidor 'A'
float b; //Servidor 'B'
int d;   //Data e Hora
char c; //comandos

void setup() 
{
  Serial.begin(9600);
  dht.begin();

     if(iniciaSDCard())
    {
      Serial.println("MicroSD Ok");
    }
 
}

//***********************************************************************
void loop() 
{
  /*if(isnan(s) || isnan(h))
  {
    Serial.println("Falha na leitura do Sensor DHT11");
  }
  else
  {
    String msg = enviarJSON();
    if(msg != NULL)
    {
     Serial.println(msg);
    }
*/
  
  /* }*/
  delay(500);
}

//*********************************************************************
String enviarJSON()
{
  //Ao final a mensagem deve ter o seguinte formato (JSON)
  //{"v":{"s":23,"h":35, "a":45, "b":46, "d":9999999}}
 
  String msg;

  msg = "{\"v\":{\"s\":";
  msg = msg + s;
  msg = msg + ",\"h\":";
  msg = msg + h;
  msg = msg + ",\"a\":";
  msg = msg + a;
  msg = msg + ",\"b\":";
  msg = msg + b;
  msg = msg + ",\"d\":";
  msg = msg + d;
  msg = msg + "}}";  
  return msg;
}

bool iniciaSDCard()
{
   if(!SD.begin(10))
  {
    Serial.println("Falha na inicialização do MICROSD");
    return false;
  }

  myFile = SD.open("bd.txt", FILE_WRITE);

  if(myFile)
  {
    Serial.print("Escrevendo...");
    myFile.println("testando 1, 2, 3");

    myFile.close();
    Serial.println("Dados já escrito");
  } else {
    Serial.println("A - Erro ao abrir o arquivo BD.TXT ");
  }

  //Abrir novamente
  myFile = SD.open("bd.txt");
  if(myFile)
  {
    Serial.println("Re abrindo BD.TXT:");

    while (myFile.available())
    {
      Serial.write(myFile.read());
    }

    myFile.close();
    
  } else {
    Serial.println("B - Erro ao abrir o arquivo BD.TXT");
  }

  
}

//*********************************************************************
void salvarSD()
{
  
}

