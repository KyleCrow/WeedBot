//Partie de Olivier: Capteur de couleur
//definitions des ports
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
	pinMode(OE, OUTPUT);
	digitalWrite(OE, LOW);
}

bool get_rgb() 
{
	digitalWrite(S2, LOW);
	digitalWrite(S3, LOW);
	frequency = pulseIn(sensorOut, LOW);
	delay(100);
	
	if (frequency > 200 && frequency < 400)
	{   
			digitalWrite(S2, HIGH);
			digitalWrite(S3, HIGH);
			frequency = pulseIn(sensorOut, LOW);
			delay(100);
			
			if (frequency > 250 && frequency < 700)
			{
					digitalWrite(S2, LOW);
					digitalWrite(S3, HIGH);
					frequency = pulseIn(sensorOut, LOW);
					delay(100);
					
					if (frequency > 400 && frequency < 700)
					{
							return 1;
					}
					 
					else
					{
							return 0;
					}
			}
			
			else
			{
					 return 0;
			}
	 }
	 else
	 {
			return 0;
	 }
	 
}
