/*
Projeto para controlar um rele de 4 canais, atraves de um APP de celular

Os comandos para acionar cada rele, sera respectivamente o envio do numero correspondente.

*/


// inclusao da biblioteca que controla o modulo bluetooth
#include <SoftwareSerial.h>
// definindo as posicoes dos pinos na board conforme imagem do projeto.
#define RELAY1  7 // (amarelo)
#define RELAY2  6 // (verde)
#define RELAY3  5 // (laranja)
#define RELAY4  4 // (ciano)
SoftwareSerial bluetooth(11, 10); // RX (rosa) , TX (marrom)

int incomingByte; // variavel que recebera os comandos por bluetooth
// definindo a inicializacao dos controladores de cada rele
int rele_ctrl_1 = 0;
int rele_ctrl_2 = 0;
int rele_ctrl_3 = 0;
int rele_ctrl_4 = 0;

void setup() {
  // inicializando cada rele e o modulo bluetooth
  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);
  pinMode(RELAY3, OUTPUT);
  pinMode(RELAY4, OUTPUT);
  bluetooth.begin(9600);
}

void loop()
{

  if (bluetooth.available() > 0) {
    incomingByte = bluetooth.read();

    // controlando o comportamento do rele 1
    if (incomingByte == '1') {
      if (rele_ctrl_1 == 0) { // quando o controlador esta em 0 (desligado), ligar o rele e trocar o status do controlador para 1 (ligado)
        digitalWrite(RELAY1, HIGH);
        rele_ctrl_1 = 1;
      }
      else {
        digitalWrite(RELAY1, LOW);
        rele_ctrl_1 = 0;
      }
    }
    
    // controlando o comportamento do rele 2
    if (incomingByte == '2') {
      if (rele_ctrl_2 == 0) { 
        digitalWrite(RELAY2, HIGH);
        rele_ctrl_2 = 1;
      }
      else {
        digitalWrite(RELAY2, LOW);
        rele_ctrl_2 = 0;
      }
    }
    
    // controlando o comportamento do rele 3
    if (incomingByte == '3') {
      if (rele_ctrl_3 == 0) { 
        digitalWrite(RELAY3, HIGH);
        rele_ctrl_3 = 1;
      }
      else {
        digitalWrite(RELAY3, LOW);
        rele_ctrl_3 = 0;
      }
    }
    
    // controlando o comportamento do rele 4
    if (incomingByte == '4') {
      if (rele_ctrl_4 == 0) { 
        digitalWrite(RELAY4, HIGH);
        rele_ctrl_4 = 1;
      }
      else {
        digitalWrite(RELAY4, LOW);
        rele_ctrl_4 = 0;
      }
    }
    
    
  }

}
