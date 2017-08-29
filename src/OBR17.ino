#include "Servo.h"
#include "Motor.h"
#include "Encoder.h"






// VARS CARRINHO
int const VELOCIDADE_MAX = 40;
int const VELOCIDADE_SEGUIR = 50;
int const VELOCIDADE_90 = 40;
int const VELOCIDADE_90_FRENTE = 40;
int const DISTANCIA_MAX = 30;
int const VELOCIDADE_90_WHILE = 40;



// ENCODER ROSA
int const PIN_ENCODER_ROSA = 40;
Encoder erosa(PIN_ENCODER_ROSA);

// ENCODER VERMELHO
int const PIN_ENCODER_VERMELHO = 41;
Encoder evermelho(PIN_ENCODER_VERMELHO);

// ENCODER VERDE
int const PIN_ENCODER_VERDE = 42;
Encoder everde(PIN_ENCODER_VERDE);

// ENCODER AZUL
int const PIN_ENCODER_AZUL = 43;
Encoder eazul(PIN_ENCODER_AZUL);



// MOTOR ROSA
int const PIN_PWN_ROSA = 5;
int const PIN_IN1_ROSA = 44;
int const PIN_IN2_ROSA = 46;
Motor mrosa(PIN_PWN_ROSA, PIN_IN1_ROSA, PIN_IN2_ROSA);

// MOTOR VERMELHO
int const PIN_PWN_VERMELHO = 4;
int const PIN_IN1_VERMELHO = 48;
int const PIN_IN2_VERMELHO = 50;
Motor mvermelho(PIN_PWN_VERMELHO, PIN_IN1_VERMELHO, PIN_IN2_VERMELHO);

// MOTOR VERDE
int const PIN_PWN_VERDE = 6;
int const PIN_IN1_VERDE = 45;
int const PIN_IN2_VERDE = 47;
Motor mverde(PIN_PWN_VERDE, PIN_IN1_VERDE, PIN_IN2_VERDE);

// MOTOR AZUL
int const PIN_PWN_AZUL = 7;
int const PIN_IN1_AZUL = 49;
int const PIN_IN2_AZUL = 51;
Motor mazul(PIN_PWN_AZUL, PIN_IN1_AZUL, PIN_IN2_AZUL);



// SERVO ROSA
int const PIN_SERVO_ROSA = 2;
Servo s_rosa;

// SERVO VERMELHO
int const PIN_SERVO_VERMELHO = 3;
Servo s_vermelho;

// SERVO VERDE
int const PIN_SERVO_VERDE = 8;
Servo s_verde;

// SERVO AZUL
int const PIN_SERVO_AZUL = 9;
Servo s_azul;



// SENSORES LUMINOSIDADES
int const s1 = A1;
int const s2 = A2;
int const s3 = A3;
int const s4 = A4;
int const s5 = A5;
int l1 = 0;
int l2 = 0;
int l3 = 0;
int l4 = 0;
int l5 = 0;



// ULTRASONICOS FRENTE
int const ULTRASONICO_PRINCIPAL_TRIGGER = 36;
int const ULTRASONICO_PRINCIPAL_ECHO = 37;

int const ULTRASONICO_FRENTE_ESQUERDA_TRIGGER = 31;
int const ULTRASONICO_FRENTE_ESQUERDA_ECHO = 30;

int const ULTRASONICO_FRENTE_DIREITA_TRIGGER = 29;
int const ULTRASONICO_FRENTE_DIREITA_ECHO = 28;


// ULTRASONICO ESQUERDA ROBO
int const ULTRASONICO_ESQUERDA_TRIGGER = 34;
int const ULTRASONICO_ESQUERDA_ECHO = 35;


// ULTRASONICO DIREITA ROBO
int const ULTRASONICO_DIREITA_TRIGGER = 33;
int const ULTRASONICO_DIREITA_ECHO = 32;





int estado;


void setup()
{




  pinMode(25, OUTPUT);

  pinMode(37, INPUT);
  pinMode(36, OUTPUT);

  pinMode(ULTRASONICO_PRINCIPAL_TRIGGER, OUTPUT);
  pinMode(ULTRASONICO_PRINCIPAL_ECHO, INPUT);

  pinMode(ULTRASONICO_FRENTE_ESQUERDA_ECHO, INPUT);
  pinMode(ULTRASONICO_FRENTE_ESQUERDA_TRIGGER, OUTPUT);

  pinMode(ULTRASONICO_FRENTE_DIREITA_ECHO, INPUT);
  pinMode(ULTRASONICO_FRENTE_DIREITA_TRIGGER, OUTPUT);

  pinMode(ULTRASONICO_ESQUERDA_ECHO, INPUT);
  pinMode(ULTRASONICO_ESQUERDA_TRIGGER, OUTPUT);

  pinMode(ULTRASONICO_DIREITA_ECHO, INPUT);
  pinMode(ULTRASONICO_DIREITA_TRIGGER, OUTPUT);


  s_rosa.attach(PIN_SERVO_ROSA);
  s_vermelho.attach(PIN_SERVO_VERMELHO);
  s_verde.attach(PIN_SERVO_VERDE);
  s_azul.attach(PIN_SERVO_AZUL);

  s_rosa.write(120);
  s_vermelho.write(95);
  s_verde.write(155);
  s_azul.write(60);

  Serial.begin(9600);
}

void loop()
{
  digitalWrite(25, LOW);
  s_vermelho.write(95);
  
  lerLuz();
  estado = setEstado();
  Serial.println(estado);

  switch (estado)
  {
    case 1: //TUDO BRANCO
      s_verde.write(155);
      s_azul.write(60);
      forward();
      break;

    case 2: //SENSOR DA ESQUERDA VENDO PRETO
      left();
      break;

    case 3: // SENSOR DA DIREITA VENDO PRETO
      right();
      break;

    case 4: //90 GRAUS ESQUERDA
      m(0,0);
      esquerda90();
      break;

    case 5: // 90 GRAUS DIREITA
    m(0,0);
      //delay(1000);
      direita90();
      break;

    case 6: //VERDE ESQUERDA
      //stop();
      //delay(3000);
      //verde_esq();
      break;

    case 7: // VERDE DIREITA
      //verde_dir();
      break;

    case 8: // OBSTACULO
      obstaculo();
      break;

    case 9: // BOLINHA
      //bolinha();
      break;
  }
}


int setEstado()
{
  lerLuz();
  
  
  //if (cor_esq()) return 6;
  //if (VERDE_DIREITA) { }

  if (verOBS()) return 8;
  
  else if (l1 < 400 && l2 < 400) return 4;
  else if (l4 < 400 && l5 < 400) return 5;
  else if (l2 < 400) return 2;
  else if (l4 < 400) return 3;
  else if (l2 > 400 && l4 > 400) return 1;
}



void obstaculo()
{
  backwards();

  delay(400);

  mrosa.vel(-40);
  mvermelho.vel(70);
  mverde.vel(-45);
  mazul.vel(45);

  delay(700);

  forward();
  delay(850);

  mrosa.vel(40);
  mvermelho.vel(-100);
  mverde.vel(50);
  mazul.vel(-40);
  delay(600);


  mrosa.vel(60);
  mvermelho.vel(65);
  mverde.vel(65);
  mazul.vel(55);

  delay(850);
  


  mrosa.vel(40);
  mvermelho.vel(-100);
  mverde.vel(50);
  mazul.vel(-40);
  delay(600);

  forward();
  delay(200);
  lerLuz();
  while(l3 < 400) lerLuz();
  while(l3 > 400) lerLuz();
  delay(100);
  stop();
  delay(2000);

  mrosa.vel(-40);
  mvermelho.vel(70);
  mverde.vel(-45);
  mazul.vel(45);

  lerLuz();
  while (l3 > 400) lerLuz();

}


bool verOBS()
{
  if (ultraSonico(ULTRASONICO_PRINCIPAL_TRIGGER, ULTRASONICO_PRINCIPAL_ECHO) <= 8)
  {
    if (ultraSonico(ULTRASONICO_PRINCIPAL_TRIGGER, ULTRASONICO_PRINCIPAL_ECHO) <= 8)
    {
      if (ultraSonico(ULTRASONICO_PRINCIPAL_TRIGGER, ULTRASONICO_PRINCIPAL_ECHO) <= 8)
      {
        return true;
      }
    }
  }

  return false;
}


float ultraSonico(int portaTrigger, int portaEcho)
{
  digitalWrite(portaTrigger, LOW);
  delayMicroseconds(2);

    digitalWrite(portaTrigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(portaTrigger, LOW);

    return (pulseIn(portaEcho, HIGH) * 0.034)/2;
}


void esquerda90()
{
  if (l3 < 400)
  {
    forward();
    delay(250);
  }
  
  else
  {
    mrosa.vel(30);
    mvermelho.vel(45);
    mverde.vel(35);
    mazul.vel(35);

    delay(25);
    
    mrosa.vel(-50);
      mvermelho.vel(70);
      mverde.vel(-55);
      mazul.vel(45);
    //delay(30);
    while (l3 > 400) lerLuz();

    stop();
      
  }
}


void direita90()
{
  if (l3 < 400)
  {
    forward();
    delay(250);
  }
  
  else
  {

  
  mrosa.vel(50);
  mvermelho.vel(-70);
  mverde.vel(60);
  mazul.vel(-20);
  //delay(30);
  while (l3 > 400) lerLuz();

  stop();
    
  }
}


void correcao()
{
  m(0, 0);


  //delay(1000);

  while (l3 > 400)
  {
    lerLuz();

    if (l1 < 400 && l2 < 400) return NULL;
    else if (l4 < 400 && l5 < 400) return NULL;
    
    else if (estado == 3)
    {
      mrosa.vel(40);
      mvermelho.vel(-100);
      mverde.vel(50);
      mazul.vel(-50);
    }

    else if (estado == 2)
    {
      mrosa.vel(-40);
      mvermelho.vel(70);
      mverde.vel(-55);
      mazul.vel(45);
    }
    
  }
}


void right()
{
  mrosa.vel(45);
  mvermelho.vel(0);
  mverde.vel(50);
  mazul.vel(0);

  bool i = true;
  

    lerLuz();

    if (l3 > 400 && l4 < 400)
    {
      correcao();
      i = false;
    }

}


void left()
{
  mrosa.vel(0);
  mvermelho.vel(60);
  mverde.vel(0);
  mazul.vel(40);

  bool i = true;
  
 
    lerLuz();

    if (l3 > 400 && l4 < 400)
    {
      correcao();
      i = false;
    }

}


void forward()
{
  mrosa.vel(24);
  mvermelho.vel(34);

  mverde.vel(35);
  mazul.vel(22);
}


void backwards()
{
  mrosa.vel(-31);
  mvermelho.vel(-41);

  mverde.vel(-42);
  mazul.vel(-39);
}



void stop()
{
  mrosa.vel(0);
  mvermelho.vel(0);
  mverde.vel(0);
  mazul.vel(0);
}



void lerLuz()
{
  l1 = analogRead(s1);
  l2 = analogRead(s2);
  l3 = analogRead(s3);
  l4 = analogRead(s4);
  l5 = analogRead(s5);
}


void m(int vEsquerda, int vDireita)
{
  motors(vEsquerda, vDireita, vEsquerda, vDireita);
}


void motors(int v1, int v2, int v3, int v4)
{
  mrosa.vel(v1);
  mverde.vel(v3);
  mvermelho.vel(v2);
  mazul.vel(v4);
}

