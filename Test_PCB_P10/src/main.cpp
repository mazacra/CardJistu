#include <Arduino.h>
#include <stdio.h>
#include <ArduinoJson.h>

#define BAUD 9600

volatile bool shouldSend_ = false;  // Drapeau prêt à envoyer un message

void sendMsg() {
  StaticJsonDocument<500> doc;
  // Elements du message
  doc["time"] = millis();

  // Serialisation
  serializeJson(doc, Serial);

  // Envoie
  Serial.println();
  shouldSend_ = false;
}

int compt = 0;
// put function definitions here:
bool Bouton() {

  /*bool dernier_etat = false;
  bool bouton = digitalRead(38);
  Serial.println("9");
  if (bouton != dernier_etat){
    bouton = !bouton;
  }else{
    dernier_etat = bouton;
  }
  if (bouton){
    Serial.println("le bouton est relevé");
  }else{
        Serial.println("le bouton est enfoncé");
  }
  //return bouton;*/
  //Serial.println(digitalRead(38));
  bool bouton = digitalRead(38);
  if(digitalRead(38)){
    Serial.println("le bouton est relevé");
    return 1;
  }else{
    Serial.println("le bouton est enfoncé");
    return 0;
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
    Serial.println("sortie");
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

void Joystick(){

  int x_Axispin = A0;
  int y_Axispin = A1;

  int xValue = analogRead(x_Axispin);
  int yValue = analogRead(y_Axispin);
  int haut = 758;
  int bas = 256;

  if(xValue<bas and yValue<bas)
    Serial.println("bas droite");
  if(xValue<bas and yValue>=bas and yValue<=haut)
    Serial.println("droite");
  if(xValue<bas and yValue>haut)
    Serial.println("haut droite");
  if(xValue>=bas and xValue<=haut and yValue<bas)
    Serial.println("bas");
  if(xValue>=bas and xValue<=haut and yValue>haut)
    Serial.println("haut");
  if(xValue>haut and yValue<bas)
    Serial.println("bas gauche");
  if(xValue>haut and yValue>=bas and yValue<=haut)
    Serial.println("gauche");
  if(xValue>haut and yValue>haut)
    Serial.println("haut gauche");

 /* Serial.print("x:");
  Serial.println(xValue);
  Serial.print("y:");
  Serial.println(yValue);*/
  delay(500);
}


void Accel()
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
      Serial.println(dx);
      Serial.println("mouvement x vers le bas");
      //*/
      delay(delait);
      break;
    }else if (dx > 40){
      //*
      Serial.println(dx);
      Serial.println("mouvement x vers le haut");
      //*/
      delay(delait);
      break;
    }

    if (dy < -40) {
      //*
      Serial.println(dy);
      Serial.println("mouvement y vers le bas");
      //*/
      delay(delait);
      break;
    }else if (dy > 40){
      //*
      Serial.println(dy);
      Serial.println("mouvement y vers le haut");
      //*/
      delay(delait);
      break;
    }

    if (dz < -40) {
      //*
      Serial.println(dz);
      Serial.println("mouvement z vers le bas");
      //*/
      delay(delait);
      break;
    }else if (dz > 30){
      //*
      Serial.println(dz);
      Serial.println("mouvement z vers le haut");
      //*/
      delay(delait);
      break;
    }
      x_depart = x;
      y_depart = y;
      z_depart = z;

    delay(100);
    i++;
    //Serial.println(i);
  }
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
/*void setup() {
  Serial.begin(9600);
  pinMode(38, INPUT);
  pinMode(22, OUTPUT); //A
  pinMode(23, OUTPUT);
  pinMode(24, OUTPUT);
  pinMode(25, OUTPUT);
  pinMode(50, OUTPUT);
  pinMode(51, OUTPUT);
  pinMode(52, OUTPUT);
  pinMode(53, OUTPUT);

}*/
void loop() {
  //bool etat = Bouton();
  if(!digitalRead(38)){
    Serial.println("le bouton est enfoncé");
    compt++;
  }

  if (compt > 9)
    compt = 0;
  Joystick();
  Accel();
  Segment7(compt);

  if(shouldSend_){
    sendMsg();
  }
}
