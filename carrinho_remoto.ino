//83 para
//para a direita o bluetooth lê 82;
//para a esquerda 76
//para frente 70
//para trás 66
//119 desliga LED dianteiro
//87 liga o LED dianteiro
//117 desliga o LED traseiro
//85 liga o LED traseiro
//118 desliga a buzina
//86 liga a buzina
//120 desliga o pisca alerta
//88 liga o pisca alerta

#include <SoftwareSerial.h>
SoftwareSerial bluetooth(10, 11);
#define m1 4  //frente
#define m2 3  //tras
#define m3 8  //frente
#define m4 9  //tras

#define LED 7
#define buzzer 5

void parar() {
  digitalWrite(m1, LOW);
  digitalWrite(m2, LOW);
  digitalWrite(m3, LOW);
  digitalWrite(m4, LOW);
}

void tras() {
  digitalWrite(m1, LOW);
  digitalWrite(m2, HIGH);
  digitalWrite(m3, LOW);
  digitalWrite(m4, HIGH);
}

void frente() {
  digitalWrite(m1, HIGH);
  digitalWrite(m2, LOW);
  digitalWrite(m3, HIGH);
  digitalWrite(m4, LOW);
}
void direita() {
  digitalWrite(m1, HIGH);
  digitalWrite(m2, LOW);
  digitalWrite(m3, LOW);
  digitalWrite(m4, LOW);
}
void esquerda() {
  digitalWrite(m1, LOW);
  digitalWrite(m2, LOW);
  digitalWrite(m3, HIGH);
  digitalWrite(m4, LOW);
}

void buzina() {
  digitalWrite(buzzer, HIGH);
  /*delay(300);
  digitalWrite(buzzer, HIGH);
  delay(300);
  digitalWrite(buzzer, HIGH);
  delay(300);
  digitalWrite(buzzer, HIGH);
  delay(300);
  digitalWrite(buzzer, HIGH);
  delay(300);
  digitalWrite(buzzer, HIGH);
  delay(300);*/
}

void farol() {
   digitalWrite(LED, HIGH);
  }


void setup() {
  bluetooth.begin(9600);
  Serial.begin(9600);
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(m3, OUTPUT);
  pinMode(m4, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  int C = bluetooth.read();
  Serial.println(C);

  if (C == 83) {
    parar();
  }

  if (C == 82) {
    direita();
  }
  if (C == 76) {
    esquerda();
  }

  if (C == 70) {
    frente();
  }

  if (C == 66) {
    tras();
  }

  if (C == 86) {
    buzina();
  } else if (C == 118){
    digitalWrite(buzzer, LOW);
  }

  if (C == 87) {
    farol();
  } else if (C == 119){
    digitalWrite(LED, LOW);
  }
}
