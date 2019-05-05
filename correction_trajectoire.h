#define L_IN_Positive 1   
#define L_IN_Negative 6    
#define R_IN_Positive 7    
#define R_IN_Negative 9    
#define R_EN 10  
#define L_EN 11 

#define Kp 1
#define Kd 4
#define Kr 3

#define consigne 15
#define defaut 145

int erreur=0;
int erreur_precedente;
int integral=0;
int derivee;
int sortie;

void setup_path_correction() {
  pinMode(L_IN_Positive,OUTPUT);
  pinMode(L_IN_Negative,OUTPUT);
  pinMode(R_IN_Positive,OUTPUT);
  pinMode(R_IN_Negative,OUTPUT);
  pinMode(L_EN,OUTPUT); 
  pinMode(R_EN,OUTPUT);

  digitalWrite(L_IN_Positive,1);
  digitalWrite(L_IN_Negative,0);
  digitalWrite(R_IN_Positive,1);
  digitalWrite(R_IN_Negative,0);
  analogWrite(L_EN,0);
  analogWrite(R_EN,0);
}

void pathCorrection(float ultrasonic_measure, bool array[3]) {
  if ((array[0] && array[1])==1 && array[2]==0) { //verifie la presence de batterie et de liquide et la non presence d'herbe
  
  erreur_precedente=abs(erreur);
  erreur = ultrasonic_measure-consigne;
  derivee = erreur-erreur_precedente;
  derivee = abs(derivee);
  sortie = Kp*abs(erreur) + Kd*derivee + defaut;
  
  Serial.print("Erreur precedente: ");
  Serial.println(erreur_precedente);
  Serial.print("Erreur: ");
  Serial.println(erreur);
  Serial.print("Derivee: ");
  Serial.println(Kd*derivee);
  Serial.print("Sortie: ");
  Serial.println(sortie);
  Serial.print("Autre roue: ");
  Serial.println(defaut-(abs(erreur)*Kr));
  
  Serial.print("Correction: ");
  if (erreur>1) {
    analogWrite(R_EN,defaut-(abs(erreur)*Kr));
    analogWrite(L_EN,sortie);
    Serial.println("DROITE");
  }else if (erreur<(-1)) {
    analogWrite(L_EN,defaut-(abs(erreur)*Kr));
    analogWrite(R_EN,sortie);
    Serial.println("GAUCHE");
  }
    else {
      analogWrite(L_EN,defaut);
      analogWrite(R_EN,defaut);
      Serial.println("MILIEU");
    }
  
}  else {
  analogWrite(L_EN,0);
  analogWrite(R_EN,0);
  Serial.println("STOP");
}}
