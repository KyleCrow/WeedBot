//MAIN
#include "sensor_battery_liquid.h"
#include "sensor_rgb.h"
#include "sensor_spray.h"
#include "sensor_ultrasonic.h"
#include "path_correction.h"
#define PotentiometerPin 0
// Raphael pin
const int relayPin = 8;

float ultrasonic_measure;
bool weed_presence = 0;
bool breakk = false; // cette variable permet au système de spray du desherbant de temporiser
int i = 0;
/*float Batterie;                      //Variable du niveau de batterie (%) #Adeline
bool Desherbant;                     //Variable du niveau de désherbant #Adeline
bool Herbe;                          //Variable de la détection de mavaises herbes #Olivier*/
 

void setup() {
  Serial.begin(9600);
  setup_path_correction();
  setup_rgb();
  setup_battery_liquid();
  setup_spray(relayPin);
  }


void loop() {

  //Maxime
  ultrasonic_measure = srf08_mesure(ultrasonic_measure);
  Serial.println(ultrasonic_measure);

  //Matthieu
  pathCorrection(ultrasonic_measure);

  //Raphael
  if (breakk) {
    i++;
    if (i>=43) {
      breakk=false;
      i=0;
      digitalWrite(relayPin, LOW);
    }
  } else {
    breakk = spray(relayPin, 100, 100, weed_presence, breakk); // les valeurs de niveau de batterie et de desherbant ont été mises a 100 pour des raisons de test
  }

  //Olivier
  weed_presence = get_rgb(weed_presence);
  Serial.println(weed_presence);

  //Adeline
  loop_battery_liquid();
}

