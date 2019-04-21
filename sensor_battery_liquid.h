//Partie de Adeline
//includes
#include "caractere.h"

//definitions
#define pinNiveauHaut 13
#define pinNiveauBas 12
#define analogPin 3
#include <Wire.h>
#include "rgb_lcd.h"
rgb_lcd lcd ;

// Initialisation variables verification liquide
bool reservoirH = 0;
bool reservoirL = 0;

//Initialisation variables batterie
unsigned int valeurBrute = 0;              
float tensionBatterie = 0;                 
const float  VmaxCAN = 5.0;               
const float  q = VmaxCAN / 1023;          
const float  k = VmaxCAN / 8.4;         
float pourcentage = 0;                     
unsigned char rouge = 0 ;                
unsigned char vert  = 0 ;              
unsigned char bleu  = 0 ;
int result;

// Initialisation caracteres batterie
  void caractere(void) {
  lcd.createChar(0, batterie0); //  �criture en CGRAM du caract�re repr�sentant une batterie vide
  lcd.createChar(1, batterie1); //  �criture en CGRAM du caract�re repr�sentant une batterie vide
  lcd.createChar(2, batterie2); //  �criture en CGRAM du caract�re repr�sentant une batterie vide
  lcd.createChar(3, batterie3); //  �criture en CGRAM du caract�re repr�sentant une batterie vide
  lcd.createChar(4, batterie4); //  �criture en CGRAM du caract�re repr�sentant une batterie vide
  lcd.createChar(5, batterie5); //  �criture en CGRAM du caract�re repr�sentant une batterie vide
}

//setup function
void setup_battery_liquid() {
  pinMode (pinNiveauHaut,INPUT_PULLUP);
  pinMode (pinNiveauBas, INPUT_PULLUP);
  lcd.begin(16, 2);
  lcd.setRGB(rouge, vert, bleu) ;
  caractere();
}

//LIQUIDE
int liquide(void){ 
    reservoirH = digitalRead (pinNiveauHaut );
    reservoirL = !digitalRead (pinNiveauBas);
    lcd.clear();
    if(reservoirH && reservoirL){
      lcd.write("Reservoir Plein");
      return 1;
    }
     else if  (!reservoirH && reservoirL){
      lcd.write("Pas plein");
      return 1;
      }else if (!reservoirH && !reservoirL){
        lcd.write("Ajouter Desherb.");
        return 0;
        }else{
      lcd.write("erreur");
      return 0;
     }
  
  }



// BATTERIE

void affichageAvec0(float valeur) {
  if(valeur<10)
  {
    lcd.print("00");
  }
  else if(valeur<100)
  {
    lcd.print("0");
  }
  lcd.print(valeur);
}

int batterie(void){

// Mesure tension batterie

  valeurBrute = analogRead(analogPin);     
  tensionBatterie = (valeurBrute * q) / k;

// Pourcentage

   if (tensionBatterie < 6)
  {
    pourcentage = 0;
    return 0;
    //    Serial.println("Alternative 1");
  }
  else if (tensionBatterie < 7.3)
  {
    pourcentage = (8.3333 * tensionBatterie) - 50;
    return 0;
    //    Serial.println("Alternative 2");
  }
  else if (tensionBatterie < 7.94)
  {
    pourcentage = (111.06 * tensionBatterie) - 800.88;
    return 2;
    //    Serial.println("Alternative 3");
  }
  else if (tensionBatterie < 8.4)
  {
    pourcentage = (43.233 * tensionBatterie) - 263.65;
    return 2;
    //    Serial.println("Alternative 4");
  }
  else
  {
    pourcentage = 100;
  
  }

}
void Affichage(){

  bleu = 0;
  vert = 2.55 * pourcentage;
  rouge = -2.55 * pourcentage + 255;
  lcd.setRGB(rouge, vert, bleu) ;
  lcd.setCursor(1, 1);
  lcd.print("Charge: ");
  affichageAvec0(pourcentage);
  lcd.print("%");

  lcd.setCursor(0,1);    // Position du pictogramme batterie en bas � gauche du LCD
  if (pourcentage < 10)
  {
    lcd.write((unsigned char)0);         // Affichage du pictogramme batterie0 : Batterie vide
  }
  else if (pourcentage < 30)
  {
    lcd.write(1);
  }
  else if (pourcentage < 50)
  {
    lcd.write(2);
  }
  else if (pourcentage < 70)
  {
    lcd.write(3);
  }
  else if (pourcentage < 90)
  {
    lcd.write(4);
  }
  else
  {
    lcd.write(5);        
  }
  
}

//loop function
int loop_battery_liquid() {
  result = liquide() + batterie();
  Affichage();
  return result;
}
