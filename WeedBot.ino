//MAIN
#include "capteur_batterie_liquide.h"
#include "capteur_rgb.h"
#include "capteur_spray.h"
#include "capteur_ultrason.h"
#include "correction_trajectoire.h"
#include "bluetooth.h"

int mesure_ultrason;
int batterie_liquide=0;
int nombreProjections=0;
bool conditions[5];  //0->Batterie 1->Liquide 2->Herbe 3->commande moteurs bluetooth 4->commande correction bluetooth

void setup() {
  setup_correction_trajectoire();
  setup_bluetooth();
  setup_batterie_liquide();
  setup_rgb();
  setup_spray();
  setup_ultrasonic();
  }

void loop() {
  //Matthieu
  loop_bluetooth(conditions, nombreProjections);
  conditions[3]=motorState;
  conditions[4]=correctionState;
  //Adeline
  loop_batterie_liquide();
  conditions[0]=batterie;
  conditions[1]=liquide; 
  
  //Olivier
  conditions[2] = get_rgb();

  //Raphael
  spray(conditions);
  nombreProjections=nbProjections;

   //Maxime
  mesure_ultrason = srf08_mesure();

  //Matthieu
  pathCorrection(mesure_ultrason, conditions, vitesseManuelle);
  
}
