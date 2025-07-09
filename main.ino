#include "HX711.h" //importando biblioteca HX711

HX711 scale; //declarando scale

// declarando pinos e variaveis úteis

//HX711
const int pinSCK = A0; // pino SDK ligado a entrada A0
const int pinDT = A1; //pino DT ligado a entrada A1
float peso = 0; // status do peso 

//Botão
const int pinBot = A2; //pino de entrada botão
int statusBot = 0; //status botão

//Led
const int pinR = A3; //pino de entrada led vermelho
const int pinG = A4; //pino de entrada led verde

void setup() {
  Serial.begin(9600);
  Serial.println("inicializando.");

  scale.begin(pinDT, pinSCK); //inicializa escala

  scale.set_scale(420); //2kg = 840 inicializa calibração

  scale.tare(); //inicializa tara

  scale.tare(); //zerando o peos

  pinMode(pinBot, INPUT_PULLUP); //inicializa botão

  //inicializa led
  pinMode(pinR, OUTPUT);
  pinMode(pinG, OUTPUT);

  
  //liga led
  digitalWrite(pinR, HIGH); 
  delay(500);
  digitalWrite(pinG, HIGH); 
  delay(500);
  
  //desliga led
  digitalWrite(pinR, LOW); 
  delay(500);
  digitalWrite(pinG, LOW);
  Serial.println("pronto.");
}


void loop() {
  statusBot = digitalRead(pinBot); //definindo status do botão

  //condição de botão pressinado para nova tara
  if (statusBot == LOW) {
    Serial.println("nova tara.");
    scale.tare();
  }
  
  
  peso = scale.get_units(); //definindo variavel do peso usado na estrutura do led
  int pesoInt = (int)floor(peso); //transformando status do peso em inteiro

  //condições de avisos
  switch (pesoInt){
    case 1:
      digitalWrite(pinR, HIGH); //ascende o led
      delay(200);
      digitalWrite(pinR, LOW); //apaga o led
      delay(200);
      Serial.println("1 ovo"); // aviso de peso limite ultrapassado
      break;

    case 2:
      digitalWrite(pinR, HIGH); //ascende o led
      delay(500);
      Serial.println("2 ovos"); // aviso de peso limite ultrapassado
      break;

    case 3:
      digitalWrite(pinR, HIGH); //ascende o led
      delay(500);
      Serial.println("3 ovos"); // aviso de peso limite ultrapassado
      break;

    case 4:
      digitalWrite(pinR, HIGH); //ascende o led
      delay(500);
      Serial.println("4 ovos"); // aviso de peso limite ultrapassado
      break;

    case 5:
      digitalWrite(pinG, HIGH); //ascende o led
      digitalWrite(pinR, HIGH);
      delay(200);
      digitalWrite(pinG, LOW); //apaga o led
      digitalWrite(pinR, LOW);
      delay(200);
      Serial.println("5 ovos"); // aviso de peso limite ultrapassado
      break;

    case 6:
      digitalWrite(pinG, HIGH); //ascende o 
      digitalWrite(pinR, HIGH);
      delay(500);
      Serial.println("6 ovos"); // aviso de peso limite ultrapassado
      break;

    case 7:
      digitalWrite(pinG, HIGH); //ascende o led
      digitalWrite(pinR, HIGH);
      delay(500);
      Serial.println("7 ovos"); // aviso de peso limite ultrapassado
      break;

    case 8:
      digitalWrite(pinG, HIGH); //ascende o led
      digitalWrite(pinR, HIGH);
      delay(500);
      Serial.println("8 ovos"); // aviso de peso limite ultrapassado
      break;

    case 9:
      digitalWrite(pinG, HIGH); //ascende o led
      delay(200);
      digitalWrite(pinG, LOW); //apaga o led
      delay(200);
      Serial.println("9 ovos"); // aviso de peso limite ultrapassado
      break;

    case 10:
      digitalWrite(pinG, HIGH); //ascende o led
      delay(500);
      Serial.println("10 ovos"); // aviso de peso limite ultrapassado
      break;

    case 11:
      digitalWrite(pinG, HIGH); //ascende o led
      delay(500);
      Serial.println("11 ovos"); // aviso de peso limite ultrapassado
      break;

    case 12:
      digitalWrite(pinG, HIGH); //ascende o led
      delay(500);
      Serial.println("12 ovos"); // aviso de peso limite ultrapassado
      break;


    default:
      Serial.println("notificação de falta de recurso");
      digitalWrite(pinR, HIGH); //ascende led
      delay(200);
      digitalWrite(pinR, LOW); //apaga led
      delay(500);
      break;
  
  }
}
