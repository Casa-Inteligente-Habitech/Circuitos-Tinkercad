//Gás
const int mq135 = A0;
const int buzzer = 11;
int contador = 0;

void alarme_dois_tons() {
int freqAlta = 2000;
int freqBaixa = 800;
int duracaoTom = 250;
tone(buzzer, freqAlta, duracaoTom);
delay(duracaoTom);
tone(buzzer, freqBaixa, duracaoTom);
delay(duracaoTom);
}
  
void verificarVazamentoDeGas(){
  
int estadoMQ135 = analogRead(mq135);
  
if (estadoMQ135 > 700) {
while (contador == 0) {
Serial.println("Detectamos que há vazamento de gás, iremos acionar o alarme em:");
Serial.println("3");
delay(1000);
Serial.println("2");
delay(1000);
Serial.println("1");
delay(1000);
contador = 1;
}
alarme_dois_tons();
}
}

//LUZ
const int led = 8;
const int pir = 2;
int m;
  
//Campainha
int buzzerC = 12;
int botaoC = 3;
//Porta
  #include <Servo.h>
Servo motor;
int botaoP = 4;

  
  
void setup()
{// LUZ
  pinMode(led, OUTPUT);
  pinMode(pir, INPUT);
  
  //Campainha
  Serial.begin(9600);
  pinMode(botaoC, INPUT);
  pinMode(buzzerC, OUTPUT);
  
  //Porta
  Serial.begin(9600);
  pinMode(botaoP, INPUT);
  motor.attach(13);
  motor.write(0);
  //Gás
  Serial.begin(9600);
  pinMode(mq135, INPUT); //
  pinMode(buzzer, OUTPUT); //

  Serial.println("Calibrando o sensor PIR...");
  Serial.println("Por favor, não se mova na frente do sensor.");
  delay(10000);
  Serial.println("Sensor PIR calibrado e pronto!");
}



  
  
void loop()
{// LUZ
  m = digitalRead(pir);
  if(m){
    digitalWrite(led,HIGH);
  }else{
  	digitalWrite(led,LOW);
  }
  
  //Campainha
  int estadoBC = digitalRead(botaoC);
  Serial.println(estadoBC);
  
  if(estadoBC == 1){
  	tone(buzzerC, 700, 500);
  }
  
  //Porta
  int estadoBP = digitalRead(botaoP);
  Serial.println(estadoBP);
  
  if(estadoBP == 1){
  	motor.write(90);
    delay(5000);
  }else {
    motor.write(0);
  }
  
  //Gás
  verificarVazamentoDeGas();
}