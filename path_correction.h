#define L_IN_Positive 1   
#define L_IN_Negative 6    
#define R_IN_Positive 7    
#define R_IN_Negative 9    
#define L_EN 10           
#define R_EN 11

int order = 0;
int preceding_ultrasonic_measure;
const float target = 15;
int correction;


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
  correction = abs(ultrasonic_measure-target)*4;
  
  Serial.print(" ");
  Serial.print(correction);

  if (ultrasonic_measure = preceding_ultrasonic_measure) {
    order = 2;
  } else {
    order = 1;
  }

  switch (order) {
    case 0 : preceding_ultrasonic_measure=ultrasonic_measure;
    order=1;
    break;
    case 1 : if (correction>4) {
       if (ultrasonic_measure-target>0) {
          analogWrite(R_EN,128);
          analogWrite(L_EN,128-correction);
          Serial.println(" RIGHT");
       }else if (ultrasonic_measure-target<0) {
          analogWrite(L_EN,128);
          analogWrite(R_EN,128-correction-12); //3*4
          Serial.println(" LEFT");
       }
    } else {
      analogWrite(L_EN,128);
      analogWrite(R_EN,128);
      Serial.println("middle");
    }

              break;
     case 2 : analogWrite(R_EN,128);
              analogWrite(L_EN,128-correction);
              break;
  }
  
}
