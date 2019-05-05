//Partie de Olivier: Capteur de couleur
#define S2 4
#define S3 5
#define sensorOut 2
#define OE 3


int frequency = 0;

void setup_rgb() 
{
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  //pinMode(OE, OUTPUT);
//  pinMode(LED, OUTPUT);
  digitalWrite(OE, LOW);
  //digitalWrite(LED, LOW);
  //Serial.begin(9600);
}

bool get_rgb() 
{
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  frequency = pulseIn(sensorOut, LOW);
  //Serial.print("R= ");
  //Serial.print(frequency);
  //Serial.print(" ");
  delay(100);
  
  if (frequency > 200 && frequency < 400)
  {   
      digitalWrite(S2, HIGH);
      digitalWrite(S3, HIGH);
      frequency = pulseIn(sensorOut, LOW);
      //Serial.print("G= "); 
      //Serial.print(frequency);
      //Serial.print(" ");
      delay(100);
      
      if (frequency > 250 && frequency < 700)
      {
          digitalWrite(S2, LOW);
          digitalWrite(S3, HIGH);
          frequency = pulseIn(sensorOut, LOW);
          //Serial.print("B= ");
          //Serial.print(frequency);
          //Serial.println(" ");
          delay(100);
          
          if (frequency > 400 && frequency < 700)
          {
              return 1;
              //digitalWrite(LED, HIGH);
          }
           
          else
          {
              return 0;
              //digitalWrite(LED, LOW);
          }
      }
      
      else
      {
           return 0;
           //digitalWrite(LED, LOW);
      }
   }
   else
   {
      return 0;
      //digitalWrite(LED, LOW);
   }
   
}
