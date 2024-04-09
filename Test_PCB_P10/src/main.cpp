#include <Arduino.h>
#include <stdio.h>
#include <ArduinoJson.h>
#include <LiquidCrystal_I2C.h>

#define BAUD 9600

#define LED_ROUGE 45
#define LED_JAUNE 43
#define LED_VERT 41
#define LED_BLEU 39

volatile bool shouldSend_ = false;  // Drapeau prêt à envoyer un message
volatile bool shouldRead_ = false;
LiquidCrystal_I2C lcd(0x27, 20, 4);
int cptJoystick;
bool btnPressed;
int compt = 0;

void serialEvent() { shouldRead_ = true; }

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

void PrintElement(int element){
  switch (element)
  {
  case 0:
    lcd.print("Feu");
    break;
  case 1:
    lcd.print("Eau");
    break;
  case 2:
    lcd.print("neige");
    break;
  default:
    break;
  }
}

void PrintCouleur(int couleur){
  switch (couleur)
  {
  case 0:
    lcd.print("Jaune");
    break;
  case 1:
    lcd.print("Rouge");
    break;
  case 2:
    lcd.print("Vert");
    break;
  case 3:
    lcd.print("Bleu");
    break;
  default:
    break;
  }
}

// put function definitions here:
char* Bouton() {
  if(!btnPressed){
    if(!digitalRead(38)){
      btnPressed = true;
      return "On";
    }
  }else{
    if(digitalRead(38)){
        btnPressed = false;
    }
  }

  return "";
}

void Del(int del)
{
  switch (del)
  {
  case 0:
    digitalWrite(LED_VERT, LOW);
    digitalWrite(LED_BLEU, LOW);
    digitalWrite(LED_ROUGE, LOW);
    digitalWrite(LED_JAUNE, HIGH);
    break;
  case 1:
    digitalWrite(LED_VERT, LOW);
    digitalWrite(LED_BLEU, LOW);
    digitalWrite(LED_ROUGE, HIGH);
    digitalWrite(LED_JAUNE, LOW);
    break;
  case 2:
    digitalWrite(LED_VERT, HIGH);
    digitalWrite(LED_BLEU, LOW);
    digitalWrite(LED_ROUGE, LOW);
    digitalWrite(LED_JAUNE, LOW);
    break;
  case 3:
    digitalWrite(LED_VERT, LOW);
    digitalWrite(LED_BLEU, HIGH);
    digitalWrite(LED_ROUGE, LOW);
    digitalWrite(LED_JAUNE, LOW);
    break;
  default:
    break;
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
      segmentPoint = 0;
      break;

    case 1:
    
      segmentB = 0;
      segmentC = 0;
      segmentPoint = 0;
      break;

    case 2:
      segmentA = 0;
      segmentB = 0;
      segmentD = 0;
      segmentE = 0;
      segmentG = 0;
      segmentPoint = 0;
      break;

    case 3:
      segmentA = 0;
      segmentB = 0;
      segmentC = 0;
      segmentD = 0;
      segmentG = 0;
      segmentPoint = 0;
      break;   
  
    case 4:
      segmentB = 0;
      segmentC = 0;
      segmentF = 0;
      segmentG = 0;
      segmentPoint = 0;
      break;

    case 5:
      segmentA = 0;
      segmentC = 0;
      segmentD = 0;
      segmentF = 0;
      segmentG = 0;
      segmentPoint = 0; 
      break;

    case 6:
      segmentA = 0;
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
    digitalWrite(51, segmentB);
    digitalWrite(50, segmentC);
    digitalWrite(53, segmentPoint);
    digitalWrite(24, segmentE);
    digitalWrite(25, segmentD);
    digitalWrite(22, segmentF);
    digitalWrite(23, segmentG);

    //Serial.print("valeur à afficher:");
    //Serial.println(chiffre);
 return 1; 
}

char* Joystick(){
  int lastCpt = cptJoystick;

  int x_Axispin = A0;
  int y_Axispin = A1;

  int xValue = analogRead(x_Axispin);
  int yValue = analogRead(y_Axispin);
  int haut = 758;
  int bas = 256;

  if(xValue<bas and yValue<bas)
  {
    if(cptJoystick > 0)
      cptJoystick = 0;
    cptJoystick--;

    if(cptJoystick == -1 || (cptJoystick % 2 == 0 && cptJoystick < 0))
      return "jd";
  }

  if(xValue<bas and yValue>=bas and yValue<=haut)
  {
    if(cptJoystick > 0)
      cptJoystick = 0;
    cptJoystick--;

    if(cptJoystick == -1 || (cptJoystick % 2 == 0 && cptJoystick < 0))
      return "jd";
  }

  if(xValue<bas and yValue>haut)
  {
    if(cptJoystick > 0)
      cptJoystick = 0;
    cptJoystick--;

    if(cptJoystick == -1 || (cptJoystick % 2 == 0 && cptJoystick < 0))
      return "jd";
  }

  /*if(xValue>=bas and xValue<=haut and yValue<bas)
  {
    if(cptJoystick > 0)
      cptJoystick = 0;
    cptJoystick--;

    if(cptJoystick == -1 || (cptJoystick % 2 == 0 && cptJoystick < 0))
      return "jb";
  }*/

  /*if(xValue>=bas and xValue<=haut and yValue>haut)
  {
    if(cptJoystick < 0)
      cptJoystick = 0;
    cptJoystick++;

    if(cptJoystick == 1 || (cptJoystick % 2 == 0 && cptJoystick > 0))
      return "jh";
  }*/

  if(xValue>haut and yValue<bas)
  {
    if(cptJoystick < 0)
      cptJoystick = 0;
    cptJoystick++;

    if(cptJoystick == 1 || (cptJoystick % 2 == 0 && cptJoystick > 0))
      return "jg";
  }

  if(xValue>haut and yValue>=bas and yValue<=haut)
  {
    if(cptJoystick < 0)
      cptJoystick = 0;
    cptJoystick++;

    if(cptJoystick == 1 || (cptJoystick % 2 == 0 && cptJoystick > 0))
      return "jg";
  }

  if(xValue>haut and yValue>haut)
  {
    if(cptJoystick < 0)
      cptJoystick = 0;
    cptJoystick++;

    if(cptJoystick == 1 || (cptJoystick % 2 == 0 && cptJoystick > 0))
      return "jg";
  }

  if(cptJoystick == lastCpt)
    cptJoystick = 0;

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

void readMsg()  //ajouter les output des del
{
  // Lecture du message Json
  StaticJsonDocument<500> doc;
  JsonVariant parse_msg;

  // Lecture sur le port Seriel
  DeserializationError error = deserializeJson(doc, Serial);
  shouldRead_ = false;

  // Si erreur dans le message
  if (error) {
    Serial.print("deserialize() failed: ");
    Serial.println(error.c_str());
    return;
  }
  
  parse_msg = doc["Element"];
  if (!parse_msg.isNull())
  {
    int element = doc["Element"].as<int>();
    int couleur = doc["Couleur"].as<int>();
    int valeur = doc["Valeur"].as<int>();

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(valeur);

    lcd.setCursor(0,1);
    PrintElement(element);

    lcd.setCursor(0,2);
    PrintCouleur(couleur);
  }else{
    parse_msg = doc["led"];
    if (!parse_msg.isNull()) {
      // mettre la led a la valeur doc["led"]
      //digitalWrite(pinLED,doc["led"].as<bool>());
      Del(doc["led"].as<int>());
    }
    parse_msg = doc["power"];
    if (!parse_msg.isNull()) {
      // mettre la led a la valeur doc["led"]
      //digitalWrite(pinLED,doc["led"].as<bool>());
      Segment7(doc["power"].as<int>());
    }
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

  //LED
  pinMode(LED_ROUGE, OUTPUT);
  pinMode(LED_JAUNE, OUTPUT);
  pinMode(LED_VERT, OUTPUT);
  pinMode(LED_BLEU, OUTPUT);
  //pinMode(LED_ROUGE, OUTPUT);

  lcd.init();
  lcd.backlight();

  cptJoystick = 0;
  btnPressed = false;
}

void loop() {
  char* J = Joystick();
  char* A = Accel();
  char* B = Bouton();

  if(J != "" || A != "" || B != "")
    shouldSend_ = true;

  if(shouldSend_){
    sendMsg(J, A, B);
  }
  if(shouldRead_){
    readMsg();
  }
}
