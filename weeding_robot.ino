//MAIN
#include "sensor_battery_liquid.h"
#include "sensor_rgb.h"
#include "sensor_spray.h"
#include "sensor_ultrasonic.h"

#define L_IN_Positive 8   
#define L_IN_Negative 9    
#define R_IN_Positive 6    
#define R_IN_Negative 7    
#define L_EN 3           
#define R_EN 5
#define PotentiometerPin 0

float ultrasonic_measure;
/*float Batterie;                      //Variable du niveau de batterie (%) #Adeline
bool Desherbant;                     //Variable du niveau de désherbant #Adeline
bool Herbe;                          //Variable de la détection de mavaises herbes #Olivier*/
 

void setup() {
  Serial.begin(9600);
  pinMode(L_IN_Positive,OUTPUT);
  pinMode(L_IN_Negative,OUTPUT);
  pinMode(R_IN_Positive,OUTPUT);
  pinMode(R_IN_Negative,OUTPUT);
  pinMode(L_EN,OUTPUT); 
  pinMode(R_EN,OUTPUT);
  pinMode(PotentiometerPin, INPUT);

  digitalWrite(L_IN_Positive,1);
  digitalWrite(L_IN_Negative,0);
  digitalWrite(R_IN_Positive,1);
  digitalWrite(R_IN_Negative,0);
  analogWrite(L_EN,0);
  analogWrite(R_EN,0);
  
  setup_spray(); //init sensor_spray
  //setup_ultrasonic(); //init sensor_ultrasonic


}

void loop() {
  
  ultrasonic_measure = analogRead(PotentiometerPin);
  Serial.println(ultrasonic_measure);
}

