//Partie de Adeline: niveau de batterie et de liquide
//includes
#include "caractere.h"
#include "rgb_lcd.h"

//definitions des ports
#define pinNiveauHaut 13
#define pinNiveauBas 12
//#define analogPin 3

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

//Initialisation des variables de communication avec le programme principal
bool batterie = false;
bool liquide = false;

// Initialisation caracteres batterie
	void caractere(void) {
	lcd.createChar(0, batterie0); //  Ecriture en CGRAM du caractere repr�sentant une batterie vide
	lcd.createChar(1, batterie1); //  Ecriture en CGRAM du caractere representant une batterie vide
	lcd.createChar(2, batterie2); //  Ecriture en CGRAM du caractere representant une batterie vide
	lcd.createChar(3, batterie3); //  Ecriture en CGRAM du caractere representant une batterie vide
	lcd.createChar(4, batterie4); //  Ecriture en CGRAM du caractere representant une batterie vide
	lcd.createChar(5, batterie5); //  Ecriture en CGRAM du caractere representant une batterie vide
}

//setup function
void setup_batterie_liquide() {
	pinMode (pinNiveauHaut,INPUT_PULLUP);
	pinMode (pinNiveauBas, INPUT_PULLUP);
	lcd.begin(16, 2);
	lcd.setRGB(rouge, vert, bleu) ;
	caractere();
}

//LIQUIDE
void verif_liquide(){ 
		reservoirH = digitalRead (pinNiveauHaut);
		reservoirL = !digitalRead (pinNiveauBas);
		lcd.clear();
		if(reservoirH && reservoirL){
			lcd.write("Reservoir Plein");
			liquide=true;
		}
		 else if  (!reservoirH && reservoirL){
			lcd.write("Pas plein");
			liquide=true;
			}else if (!reservoirH && !reservoirL){
				lcd.write("Ajouter Desherb.");
				liquide=false;
				}else{
			lcd.write("erreur");
			liquide=false;
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

void verif_batterie(){

// Mesure tension batterie

	valeurBrute = 1023; //analogRead(analogPin)     
	tensionBatterie = (valeurBrute * q) / k;

// Pourcentage

	 if (tensionBatterie < 6)
	{
		pourcentage = 0;
		batterie=false;
		//    Serial.println("Alternative 1");
	}
	else if (tensionBatterie < 7.3)
	{
		pourcentage = (8.3333 * tensionBatterie) - 50;
		batterie=false;
		//    Serial.println("Alternative 2");
	}
	else if (tensionBatterie < 7.94)
	{
		pourcentage = (111.06 * tensionBatterie) - 800.88;
		batterie=true;
		//    Serial.println("Alternative 3");
	}
	else if (tensionBatterie < 8.4)
	{
		pourcentage = (43.233 * tensionBatterie) - 263.65;
		batterie=true;
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
void loop_batterie_liquide() {
  verif_batterie();
  verif_liquide();
	Affichage();
}
