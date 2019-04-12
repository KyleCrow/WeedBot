//Partie de Raphael: Conditions de pulvérisation

#define relayPin 8

bool breakk = false; // cette variable permet au système de spray du desherbant de temporiser
int i=0;

void setup_spray() 
{
pinMode(relayPin, OUTPUT);          //Le relais est configuré pour les signaux de sortie
}

void spray (bool array[3])
{
if (breakk) {
    i++;
    if (i>=43) {
      breakk=false;
      i=0;
      digitalWrite(relayPin, LOW);
    }
  } else {
  if ((array[0]!=0) && (array[1]!=0) && (array[2]!=0))     //Si une mauvaise herbe a été détecté et que les niveaux de batterie et de désherbant sont suffisants 
 {
  digitalWrite(relayPin, HIGH);      //Le relais actionne la pompe
  breakk = true;
  
 }
 else                                //Si aucune mauvaise herbe n'a été détecté ou que l'un des niveaux de batterie ou de désherbant sont insuffisants  
 {
  digitalWrite(relayPin, LOW);       //Le relais n'actionne pas la pompe
  breakk = false;       
 }
}
}

