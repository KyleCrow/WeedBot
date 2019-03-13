//MAIN
#include "sensor_battery_liquid.h"
#include "sensor_rgb.h"
#include "sensor_spray.h"
#include "sensor_ultrasonic.h"

#define L_IN_Positive 2   
#define L_IN_Negative 4    
#define R_IN_Positive 6    
#define R_IN_Negative 7    
#define L_EN 3           
#define R_EN 5
 

void setup() {
  pinMode(L_IN_Positive,OUTPUT);
  pinMode(L_IN_Negative,OUTPUT);
  pinMode(R_IN_Positive,OUTPUT);
  pinMode(R_IN_Negative,OUTPUT);
  pinMode(L_EN,OUTPUT); 
  pinMode(R_EN,OUTPUT);

  digitalWrite(L_IN_Positive,0);
  digitalWrite(L_IN_Negative,1);
  digitalWrite(R_IN_Positive,0);
  digitalWrite(R_IN_Negative,1);
  analogWrite(L_EN,255);
  analogWrite(R_EN,255);


}

void loop() {

}

