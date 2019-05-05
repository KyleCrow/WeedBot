byte rBuffer[1];
byte sBuffer[4];
byte transmissionBuffer[2];
unsigned int data;
unsigned int projections=0;
bool motorState=1;
bool correctionState=1;
int r;
byte code=0;
bool isTransmitting=0;
int counter;
int vitesseManuelle=145;

void setupBlueToothConnection()
{
  Serial.begin(9600); //Set Bt shield BaudRate to default baud rate 9600
  Serial.print("AT+DEFAUT");
  delay(2000);
  Serial.print("AT+ROLES"); //set the bluetooth work in master mode
  delay(400);
  Serial.print("AT+PIN0000"); //set PIN to 0000
  delay(400);
  Serial.print("AT+NAMEWeedBot"); //set the bluetooth name as "bill_gates"
  delay(400);
  Serial.print("AT+DISC0"); //make the slave bluetooth inquirable 
  delay(2000); // This delay is required.
  Serial.print("AT+LED1");  //set the LED to be always off and on when device connected
  Serial.flush();      
}
void sendData(byte codeParam, unsigned int dataParam){

        
        Serial.write(0);
        if (data<=127) {
          sBuffer[0]=codeParam;
          sBuffer[1]=dataParam+1;
          Serial.write(sBuffer[0]);
          Serial.write(sBuffer[1]);
        } else {
        sBuffer[0]=code;
        sBuffer[1]=(dataParam&0xFF);
        sBuffer[2]=((dataParam&0xFF00)>>8);
        sBuffer[3]=((dataParam&0xFF0000)>>16);
        for (r=0; r<3;r++) {
          if (sBuffer[r]!=0) {
            Serial.write(sBuffer[r]);
          }
        }
    }
    Serial.write(0);
}

void setup_bluetooth() 
{ 
  setupBlueToothConnection(); 
} 

void loop_bluetooth(bool array[5], int nombreProjections) 
{ 
  if (Serial.available()>0) {
    Serial.readBytes(rBuffer, 1);
    if (rBuffer[0] == 255) {
      isTransmitting=!isTransmitting;
      counter=0;
      if (!isTransmitting) {
        switch (transmissionBuffer[0]) {
          case 22: vitesseManuelle=transmissionBuffer[1]+1;
          break;
        }
      }
    } else if (isTransmitting) {
      if (counter<=1){
      transmissionBuffer[counter]=rBuffer[0];
      counter=counter+1;
      } else {
        isTransmitting=0;
      }
    }else if (!isTransmitting){
     switch (rBuffer[0]) {
      case 10: code=10; 
      data = millis()/1000;
      break;
      case 11: code=rBuffer[0]; 
      data = array[3];
      break;
      case 12: code=rBuffer[0];
      data = array[4];
      break;
      case 13: code=rBuffer[0];
      data = array[1];
      break;
      case 14: code=rBuffer[0];
      data = array[0];
      break;
      case 15: code=rBuffer[0];
      data = nombreProjections;
      break;
      case 20: motorState = !motorState;
      break;
      case 21: correctionState=!correctionState;
      break;
     }
      if (code!=0) {
        sendData(code, data);
      }
      code=0;
    }
  }
    if(!array[0]) {
      sendData(14, 0);
    }

    if(!array[1]) {
      sendData(13, 0);
    }
    if (projections != nombreProjections){
      sendData(15, nombreProjections);
      projections = nombreProjections;
    }
    
    
}
   


