#include <Arduino.h>
#include <stdio.h>
#include <ArduinoJson.h>

#define BAUD 9600

volatile bool shouldSend_ = false;  // Drapeau prêt à envoyer un message

void sendMsg(char* J, char* A, char* B) {
  StaticJsonDocument<500> doc;
  // Elements du message
  doc["bouton"] = B;
  doc["JoyStick"] = J;
  doc["accel"] = A;

  // Serialisation
  serializeJson(doc, Serial);

  // Envoie
  Serial.println();
  shouldSend_ = false;
}

int compt = 0;
// put function definitions here:
char* Bouton() {
  bool bouton = digitalRead(38);
  if(digitalRead(38)){
    //Serial.println("le bouton est relevé");
    return "";
  }else{
    while (!digitalRead(38))
    {
      /* code */
    }
    
    //Serial.println("le bouton est enfoncé");
    return "On";
  }
}


int Segment7(int chiffre){
  
  int segmentA = 1;
  int segmentB = 1;
  int segmentC = 1;
  int segmentD = 1;
  int segmentE = 1;
  int segmentF = 1;
  int segmentG = 1;
  int segmentPoint = 1;
  //Serial.println(chiffre);
  if (!(0 <= chiffre && chiffre <= 9)){
    //Serial.println("sortie");
    return 0;
  }
  //Serial.println(chiffre);

  switch(chiffre){
    case 0:
    
      segmentA = 0;
      segmentB = 0;
      segmentC = 0;
      segmentD = 0;
      segmentE = 0;
      segmentF = 0;
      segmentG = 1;
      segmentPoint = 0;
      break;

    case 1:
    
      segmentA = 1;
      segmentB = 0;
      segmentC = 0;
      segmentD = 1;
      segmentE = 1;
      segmentF = 1;
      segmentG = 1;
      segmentPoint = 0;
      break;

    case 2:
      segmentA = 0;
      segmentB = 0;
      segmentC = 1;
      segmentD = 0;
      segmentE = 0;
      segmentF = 1;
      segmentG = 0;
      segmentPoint = 0;
      break;

    case 3:
      segmentA = 0;
      segmentB = 0;
      segmentC = 0;
      segmentD = 0;
      segmentE = 1;
      segmentF = 1;
      segmentG = 0;
      segmentPoint = 0;
      break;   
  
    case 4:
      segmentA = 1;
      segmentB = 0;
      segmentC = 0;
      segmentD = 1;
      segmentE = 1;
      segmentF = 0;
      segmentG = 0;
      segmentPoint = 0;
      break;

    case 5:
      segmentA = 0;
      segmentB = 1;
      segmentC = 0;
      segmentD = 0;
      segmentE = 1;
      segmentF = 0;
      segmentG = 0;
      segmentPoint = 0; 
      break;

    case 6:
      segmentA = 0;
      segmentB = 1;
      segmentC = 0;
      segmentD = 0;
      segmentE = 0;
      segmentF = 0;
      segmentG = 0;
      segmentPoint = 0;
      break;

    case 7:
      segmentA = 0;
      segmentB = 0;
      segmentC = 0;
      segmentD = 1;
      segmentE = 1;
      segmentF = 1;
      segmentG = 1;
      segmentPoint = 0;
      break;

    case 8:
      segmentA = 0;
      segmentB = 0;
      segmentC = 0;
      segmentD = 0;
      segmentE = 0;
      segmentF = 0;
      segmentG = 0;
      segmentPoint = 0;
      break;
    
    case 9:
      segmentA = 0;
      segmentB = 0;
      segmentC = 0;
      segmentD = 0;
      segmentE = 1;
      segmentF = 0;
      segmentG = 0;
      segmentPoint = 0;
      break;
  }
    digitalWrite(52, segmentA);
    digitalWrite(22, segmentB);
    digitalWrite(24, segmentC);
    digitalWrite(50, segmentPoint);
    digitalWrite(51, segmentE);
    digitalWrite(25, segmentD);
    digitalWrite(53, segmentF);
    digitalWrite(23, segmentG);

    //Serial.print("valeur à afficher:");
    //Serial.println(chiffre);
 return 1; 
}

char* Joystick(){

  int x_Axispin = A0;
  int y_Axispin = A1;

  int xValue = analogRead(x_Axispin);
  int yValue = analogRead(y_Axispin);
  int haut = 758;
  int bas = 256;

  if(xValue<bas and yValue<bas)
  {
    //Serial.println("bas droite");
    return "jbd";
  }

  if(xValue<bas and yValue>=bas and yValue<=haut)
  {
    //Serial.println("droite");
    return "jd";
  }

  if(xValue<bas and yValue>haut)
  {
    //Serial.println("haut droite");
    return "jhd";
  }

  if(xValue>=bas and xValue<=haut and yValue<bas)
  {
    //Serial.println("bas");
    return "jb";
  }

  if(xValue>=bas and xValue<=haut and yValue>haut)
  {
    //Serial.println("haut");
    return "jh";
  }

  if(xValue>haut and yValue<bas)
  {
    //Serial.println("bas gauche");
    return "jbg";
  }

  if(xValue>haut and yValue>=bas and yValue<=haut)
  {
    //Serial.println("gauche");
    return "jg";
  }

  if(xValue>haut and yValue>haut)
  {
    //Serial.println("haut gauche");
    return "jhg";
  }

 /* Serial.print("x:");
  Serial.println(xValue);
  Serial.print("y:");
  Serial.println(yValue);*/
  delay(500);

  return "";
}


char* Accel()
{
  int delait = 100;
  int x_depart = analogRead(A2);
  int y_depart = analogRead(A3);
  int z_depart = analogRead(A4);
  int i = 0;

  while(i < 3) //Mettre un break pour sortir de la boucle
  {

    int x = analogRead(A2);
    int y = analogRead(A3);
    int z = analogRead(A4);

    //difference
    int dx = x_depart - x;
    int dy = y_depart - y;
    int dz = z_depart - z;
    
    if (dx < -40) {
      //*
      //Serial.println(dx);
      //Serial.println("mouvement x vers le bas");
      //*/
      delay(delait);
      return "mxb";
      break;
    }else if (dx > 40){
      //*
      //Serial.println(dx);
      //Serial.println("mouvement x vers le haut");
      //*/
      delay(delait);
      return "mxh";
      break;
    }

    if (dy < -40) {
      //*
      //Serial.println(dy);
      //Serial.println("mouvement y vers le bas");
      //*/
      delay(delait);
      return "myb";
      break;
    }else if (dy > 40){
      //*
      //Serial.println(dy);
      //Serial.println("mouvement y vers le haut");
      //*/
      delay(delait);
      return "myh";
      break;
    }

    if (dz < -40) {
      //*
      //Serial.println(dz);
      //Serial.println("mouvement z vers le bas");
      //*/
      delay(delait);
      return "mzb";
      break;
    }else if (dz > 30){
      //*
      //Serial.println(dz);
      //Serial.println("mouvement z vers le haut");
      //*/
      delay(delait);
      return "mzh";
      break;
    }
      x_depart = x;
      y_depart = y;
      z_depart = z;

    delay(100);
    i++;
    //Serial.println(i);
  }

  return "";
}  


void setup() {
  Serial.begin(9600);
  pinMode(38, INPUT);
  //7 segment
  pinMode(52, OUTPUT); //A
  pinMode(22, OUTPUT); //B
  pinMode(24, OUTPUT); //C
  pinMode(50, OUTPUT); //points
  pinMode(51, OUTPUT); //E
  pinMode(25, OUTPUT); //D
  pinMode(53, OUTPUT); //F
  pinMode(23, OUTPUT); //G
}

void loop() {
  //bool etat = Bouton();
  if(!digitalRead(38)){
    //Serial.println("le bouton est enfoncé");
    compt++;
  }

  if (compt > 9)
    compt = 0;

  char* J = Joystick();
  //char* A = Accel();
  char* A = "";
  char* B = Bouton();

  if(J != "" || A != "" || B != "")
    shouldSend_ = true;

  Segment7(compt);

  if(shouldSend_){
    sendMsg(J, A, B);
  }
}
