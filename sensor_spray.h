//Partie de Raphael: Conditions de pulvérisation
const int relayPin= 8;              // Le relais sera placé sur la broche D5


void setup_spray(int relayPin) 
{
pinMode(relayPin, OUTPUT);          //Le relais est configuré pour les signaux de sortie
 
}

bool spray (int relayPin, float Batterie, float Desherbant, bool Herbe, bool breakk)
{
  if ((Batterie!=0) && (Desherbant!=0) && (Herbe!=0))     //Si une mauvaise herbe a été détecté et que les niveaux de batterie et de désherbant sont suffisants 
 {
  digitalWrite(relayPin, HIGH);      //Le relais actionne la pompe
  return true;
  
 }
 else                                //Si aucune mauvaise herbe n'a été détecté ou que l'un des niveaux de batterie ou de désherbant sont insuffisants  
 {
  digitalWrite(relayPin, LOW);       //Le relais n'actionne pas la pompe
  return false;        
 }
}

