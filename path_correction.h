#define L_IN_Positive 8   
#define L_IN_Negative 9    
#define R_IN_Positive 10    
#define R_IN_Negative 7    
#define L_EN 3           
#define R_EN 5

bool order = 0;
float preceding_ultrasonic_measure;

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

void pathCorrection(float ultrasonic_measure) {
  switch (order) {
    case 0 :  preceding_ultrasonic_measure=ultrasonic_measure;
              order=1;
              break;
    case 1 :  
    
              break;
  }
}
