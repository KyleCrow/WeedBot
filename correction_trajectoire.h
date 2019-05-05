//Partie de Matthieu: correction de la trajectoire
//definitions des ports
#define L_IN_Positive 6     
#define R_IN_Positive 7     
#define R_EN 10  
#define L_EN 11 

//definitions des coefficients
#define Kp 1  //Coefficient de la correction proportionnelle
#define Kd 4  //Coefficient de la correction dérivée
#define Kr 3

//definitions des parametres
#define consigne 15
#define defaut 145

int erreur=0;
int erreur_precedente;
int derivee;
int sortie;

void setup_correction_trajectoire() {
  pinMode(L_IN_Positive,OUTPUT);
  pinMode(R_IN_Positive,OUTPUT);
  pinMode(L_EN,OUTPUT); 
  pinMode(R_EN,OUTPUT);

  digitalWrite(L_IN_Positive,1);
  digitalWrite(R_IN_Positive,1);
  analogWrite(L_EN,0);
  analogWrite(R_EN,0);
}

void pathCorrection(float mesure_ultrason, bool array[5], int vitesseManuelle) {
//    Batterie liquide bluetooth        présence herbe
 if ((array[0]&array[1]&array[3]&array[4])==1 && array[2]==0) { //verifie les conditions
  //PD
  erreur_precedente=abs(erreur);  //On enregistre la valeur précédente de l'erreur
  erreur = mesure_ultrason-consigne;  //On calcule l'erreur: c'est la différence entre la distance actuelle et la consigne
  derivee = abs(erreur-erreur_precedente); //On effectue la dérivée (tendance du déplacement du robot)
  sortie = Kp*abs(erreur) + Kd*derivee + defaut;  //On additionne la vitesse de base à la dérivée et la proportionnelle

  //Conditions de correction, avec une  marge d'erreur de 1, donc la consigne est entre 14 et 16
  if (erreur>1) { //Si l'erreur est positive, le robot est trop loin et on tourne à droite
	analogWrite(R_EN,defaut-(abs(erreur)*Kr));
	analogWrite(L_EN,sortie);
  }else if (erreur<(-1)) {  //Si l'erreur est négative, le robot est trop près et on tourne à gauche 
	analogWrite(L_EN,defaut-(abs(erreur)*Kr));
	analogWrite(R_EN,sortie);
  }
	else {  //Si on est dans la marge de 14 a 16cm, on laisse le robot aller tout droit
	  analogWrite(L_EN,defaut);
	  analogWrite(R_EN,defaut);
	}
  
} else if ((array[0]&array[1]&array[3])==1 && (array[2]&array[4])==0) { // Si les conditions precedentes sont remplies mais que la correction de trajectoire est désactivée
    analogWrite(L_EN,vitesseManuelle);
    analogWrite(R_EN,vitesseManuelle);
} else { //Si les conditions ne sont pas remplies le robot s'arrête
  analogWrite(L_EN,0);
  analogWrite(R_EN,0);
}

}
