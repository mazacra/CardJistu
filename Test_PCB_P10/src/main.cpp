#include <Arduino.h>
#include <stdio.h>

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

/*int Segment7(int chiffre){
  
  int segmentA = false;
  int segmentB = false;
  int segmentC = false;
  int segmentD = false;
  int segmentE = false;
  int segmentF = false;
  int segmentG = false;
  int segmentPoint = false;
  if (!(0 <= chiffre <= 9)){
    return -1;
  }

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

    case 1:
      segmentA = 1;
      segmentB = 0;
      segmentC = 0;
      segmentD = 1;
      segmentE = 1;
      segmentF = 1;
      segmentG = 1;
      segmentPoint = 0;

    case 2:
      segmentA = 0;
      segmentB = 0;
      segmentC = 1;
      segmentD = 0;
      segmentE = 0;
      segmentF = 1;
      segmentG = 0;
      segmentPoint = 0;

    case 3:
      segmentA = 0;
      segmentB = 0;
      segmentC = 0;
      segmentD = 0;
      segmentE = 1;
      segmentF = 1;
      segmentG = 0;
      segmentPoint = 0;   
  
    case 4:
      segmentA = 1;
      segmentB = 0;
      segmentC = 0;
      segmentD = 1;
      segmentE = 1;
      segmentF = 0;
      segmentG = 0;
      segmentPoint = 0;

    case 5:
      segmentA = 0;
      segmentB = 1;
      segmentC = 0;
      segmentD = 0;
      segmentE = 1;
      segmentF = 0;
      segmentG = 0;
      segmentPoint = 0; 

    case 6:
      segmentA = 0;
      segmentB = 1;
      segmentC = 0;
      segmentD = 0;
      segmentE = 0;
      segmentF = 0;
      segmentG = 0;
      segmentPoint = 0;

    case 7:
      segmentA = 0;
      segmentB = 0;
      segmentC = 0;
      segmentD = 1;
      segmentE = 1;
      segmentF = 1;
      segmentG = 1;
      segmentPoint = 0;

    case 8:
      segmentA = 0;
      segmentB = 0;
      segmentC = 0;
      segmentD = 0;
      segmentE = 0;
      segmentF = 0;
      segmentG = 0;
      segmentPoint = 0;
    
    case 9:
      segmentA = 0;
      segmentB = 0;
      segmentC = 0;
      segmentD = 0;
      segmentE = 1;
      segmentF = 0;
      segmentG = 0;
      segmentPoint = 0;

    digitalWrite(22, segmentA);
    digitalWrite(23, segmentB);
    digitalWrite(24, segmentC);
    digitalWrite(25, segmentPoint);
    digitalWrite(50, segmentE);
    digitalWrite(51, segmentD);
    digitalWrite(52, segmentF);
    digitalWrite(53, segmentG);

    Serial.print("valeur à afficher:");
    Serial.println(chiffre);
    return 0;  
  }
}*/

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
/*int x_depart;
int y_depart;
int z_depart;*/

/*void Accel(){
  /*
  int x_Accelerometer = A2;
  int y_Accelerometer = A3;
  int z_Accelerometer = A4;

  int X_Valeur = analogRead(x_Accelerometer);
  int Y_valeur = analogRead(y_Accelerometer);
  int Z_valeur = analogRead(z_Accelerometer);

  Serial.print("x:");
  Serial.println(X_Valeur);
  Serial.print("y:");
  Serial.println(Y_valeur);
  Serial.print("z:");
  Serial.println(Z_valeur);
  delay(1000);
  

  int x, y, z;
  //int x2,y2,z2;

  x = analogRead(A2);       // read analog input pin 0
  y = analogRead(A3);       // read analog input pin 1
  z = analogRead(A4);       // read analog input pin 2
  
  Serial.print("############################\n");
  /*Serial.print("valeur de x:");
  Serial.println(x*3.3/1023);
  Serial.print("valeur de y:");
  Serial.println(y*3.3/1023);
  Serial.print("valeur de z:");
  Serial.println(z*3.3/1023);

  Serial.print("valeur de x2:");
  Serial.println(x);
  Serial.print("valeur de y2:");
  Serial.println(y);
  Serial.print("valeur de z2:");
  Serial.println(z);
  //if ((x != 0) and (y != 0) and (z != 0)){
    int dx = x_depart - x;
    int dy = y_depart - y;
    int dz = z_depart - z;

    Serial.println(dx);
    Serial.println(dy);
    Serial.println(dz);
    if (dx < -10) {
      Serial.println("mouvement x vers le bas");
    }else if (dx > 10){
      Serial.println("mouvement x vers le haut");
    }
    else
      Serial.println("Aucun mouvement x");

    if (dy < -10) {
      Serial.println("mouvement y vers le bas");
    }else if (dy > 10){
      Serial.println("mouvement y vers le haut");
    }
    else
      Serial.println("Aucun mouvement y");

    if (dz < -10) {
      Serial.println("mouvement z vers le bas");
    }else if (dz > 10){
      Serial.println("mouvement z vers le haut");
    }
    else
      Serial.println("Aucun mouvement z");
 // }

  /*Serial.print("accelerations are x, y, z: ");
  Serial.print(x, DEC);    // print the acceleration in the X axis
  Serial.print(" ");       // prints a space between the numbers
  Serial.print(y, DEC);    // print the acceleration in the Y axis
  Serial.print(" ");       // prints a space between the numbers
  Serial.println(z, DEC);  // print the acceleration in the Z axis
  delay(100);              // wait 100ms for next reading
  x2 = x;
  y2 = y;
  z2 = z;
  Serial.print("valeur de x2:");
  Serial.println(x2);
  Serial.print("valeur de y2:");
  Serial.println(y2);
  Serial.print("valeur de z2:");
  Serial.println(z2);
}*/

void Accel()
{
  int delait = 100;
  int x_depart = analogRead(A2);
  int y_depart = analogRead(A3);
  int z_depart = analogRead(A4);
  int i = 0;
  /*
  Serial.print("x depart :");
  Serial.println(x_depart);

  Serial.print("y depart :");
  Serial.println(y_depart);

  Serial.print("z depart :");
  Serial.println(z_depart);
  //*/
  while(i < 3) //Mettre un break pour sortir de la boucle
  {
    /*
    Serial.print("x depart:");
    Serial.println(x_depart);
    Serial.print("y depart:");
    Serial.println(y_depart);
    Serial.print("z depart:");
    Serial.println(z_depart);
    */

    int x = analogRead(A2);
    int y = analogRead(A3);
    int z = analogRead(A4);
    /*
    Serial.print("x:");
    Serial.println(x);
    Serial.print("y:");
    Serial.println(y);
    Serial.print("z:");
    Serial.println(z);
    //*/
    //difference
    int dx = x_depart - x;
    int dy = y_depart - y;
    int dz = z_depart - z;
    /*
    Serial.println(dx);
    Serial.println(dy);
    Serial.println(dz);
    //*/
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
  //pinMode(36, OUTPUT); //test
  //test
  /*x_depart = analogRead(A2);
  y_depart = analogRead(A3);
  z_depart = analogRead(A4);
  Serial.print("x depart :");
  Serial.println(x_depart);

  Serial.print("y depart :");
  Serial.println(y_depart);

  Serial.print("z depart :");
  Serial.println(z_depart);*/
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
  /*digitalWrite(52, HIGH);
  Serial.println("Allumer");
  delay(3000);
  digitalWrite(52, LOW);
  Serial.println("Fermer");
  delay(3000);*/

/*
for(int i =0; i < 10; i++)
{
  Segment7(i);
  delay(1000);
}
//*/
}
