//MAIN
#include "sensor_battery_liquid.h"
#include "sensor_rgb.h"
#include "sensor_spray.h"
#include "sensor_ultrasonic.h"
#include "path_correction.h"

int ultrasonic_measure;
int battery_liquid=0;
bool conditions[3];  //0->Batterie 1->Liquide 2->Herbe
/*float Batterie;                      //Variable du niveau de batterie (%) #Adeline
bool Desherbant;                     //Variable du niveau de désherbant #Adeline
bool Herbe;                          //Variable de la détection de mavaises herbes #Olivier*/
 

void setup() {
  Serial.begin(9600);
  setup_battery_liquid();
  setup_rgb();
  setup_spray();
  setup_path_correction();
  setup_ultrasonic();
  }


void loop() {

  //Maxime
  ultrasonic_measure = srf08_mesure();
  Serial.print(ultrasonic_measure);

  //Matthieu
  pathCorrection(ultrasonic_measure);

  //Adeline
  battery_liquid = loop_battery_liquid();
   switch(battery_liquid) {
    case 0 : conditions[0]=0;
             conditions[1]=0;
    break;
    case 1 : conditions[0]=0;
             conditions[1]=1;
    break;
    case 2 : conditions[0]=1;
             conditions[1]=0;
    break;
    case 3 : conditions[0]=1;
             conditions[1]=1;
    break;
  }

  //Olivier
  conditions[2] = get_rgb();

  //Raphael
  spray(conditions, breakk);  
}

