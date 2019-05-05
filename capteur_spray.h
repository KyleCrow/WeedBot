//Partie de Raphael: Conditions de pulvérisation
//definitions des ports
#define relayPin 8

bool pause = false;//Cette variable permet au système de spray du desherbant de temporiser
int i=0;
int Time;

void setup_spray() 
{
pinMode(relayPin, OUTPUT);//Le relais est configuré pour les signaux de sortie
}

void spray (bool array[5], int *nombreProjections)
{
	if (pause==false && (array[0] && array[1] && array[2])==1)//Si une mauvaise herbe a été détecté et que les niveaux de batterie et de désherbant sont suffisants 
 {
	  digitalWrite(relayPin, HIGH);//Le relais actionne la pompe
	  pause = true;
	  Time = millis();
 }
 else if (pause==true)//Si aucune mauvaise herbe n'a été détecté ou que l'un des niveaux de batterie ou de désherbant sont insuffisants  
 {
  if (millis()-Time==3000) {
      pause=false;
      digitalWrite(relayPin, LOW);  //Le relais n'actionne pas la pompe
      nombreProjections=nombreProjections+1;
    }
 }

}
