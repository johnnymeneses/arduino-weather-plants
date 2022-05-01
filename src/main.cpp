#include <Arduino.h>

 
#define pino_sinal_analogico A0
#define pino_led_vermelho 5
#define pino_led_verde 7
 
int valor_analogico;


void setupComponentes(){
  pinMode(pino_sinal_analogico, INPUT);
  pinMode(pino_led_vermelho, OUTPUT);
  pinMode(pino_led_verde, OUTPUT);
}

void apagaleds()
{
  digitalWrite(pino_led_vermelho, LOW);
  digitalWrite(pino_led_verde, LOW);
}

void leituraPlanta(){

//Le o valor do pino A0 do sensor
  valor_analogico = analogRead(pino_sinal_analogico);
 
  //Mostra o valor da porta analogica no serial monitor
  Serial.print("Porta analogica: ");
  Serial.print(valor_analogico);
 
  //Solo umido, acende o led verde
  if (valor_analogico > 0 && valor_analogico < 400)
  {
    Serial.println(" Status: Solo umido");
    apagaleds();
    digitalWrite(pino_led_verde, HIGH);
  }
 
  //Solo seco, acende led vermelho
  if (valor_analogico > 800 && valor_analogico < 1024)
  {
    Serial.println(" Status: Solo seco");
    apagaleds();
    digitalWrite(pino_led_vermelho, HIGH);
  }
  delay(100);

}




void setup()
{
  Serial.begin(9600);
  setupComponentes();
  
}
 
void loop()
{
  leituraPlanta();
}
 

