//Partie de Raphael: Conditions de pulvérisation
const int relayPin= 8;               //Le relais sera placé sur la broche D5
float Batterie;                      //Variable du niveau de batterie (%)
bool Desherbant;                     //Variable du niveau de désherbant
bool Herbe;                          //Variable de la détection de mavaises herbes

void setup() 
{
 pinMode(relayPin, OUTPUT);          //Le relais est configuré pour les signaux de sortie
}

void loop() 
{
 if ((B!=0) && (D!=0) && (H!=0))     //Si une mauvaise herbe a été détecté et que les niveaux de batterie et de désherbant sont suffisants 
 {
  digitalWrite(relayPin, HIGH);      //Le relais actionne la pompe
  delay(3000);
  digitalWrite(relayPin, LOW);
 }
 else                                //Si aucune mauvaise herbe n'a été détecté ou que l'un des niveaux de batterie ou de désherbant sont insuffisants  
 {
  digitalWrite(relayPin, LOW);       //Le relais n'actionne pas la pompe        
 }
}
