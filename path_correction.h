#define L_IN_Positive 1   
#define L_IN_Negative 6    
#define R_IN_Positive 7    
#define R_IN_Negative 9    
#define R_EN 10 //L_EN sur la carte 
#define L_EN 11 //R_EN sur la carte

#define Kp 1
#define Ki 1
#define Kd 1

const float consigne = 15;

int erreur=0;
int erreur_precedente;
int integral=0;
int derivee;
int sortie;
int defaut=128;


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
  analogWrite(L_EN,255);
  analogWrite(R_EN,255);
}

void pathCorrection(float ultrasonic_measure) {
  erreur_precedente=erreur;
  erreur = abs(ultrasonic_measure-consigne);

  integral = integral+erreur;
  derivee = erreur-erreur_precedente;
  sortie = Kp*erreur + Ki*integral + Kd*derivee + defaut;
  
  Serial.print(" ");
  Serial.print(erreur);
  if (erreur>1) {
    analogWrite(R_EN,defaut);
    analogWrite(L_EN,sortie);
    Serial.println(" DROITE");
  }else if (erreur<1) {
    analogWrite(L_EN,defaut);
    analogWrite(R_EN,sortie);
    Serial.println(" GAUCHE");
  }
    else {
      analogWrite(L_EN,defaut);
      analogWrite(R_EN,defaut);
      Serial.println("MILIEU");
    }
  
}
