#include <Wire.h>

const int adresseSRF08=124;

int reading = 0;
int value;

void srf08_mesure()
{

  // etape 1: ordonner au capteur de lire les echos
  Wire.beginTransmission(adresseSRF08); // transmettre au peripherique #112 (0x70)
  // l'adresse specifiee dans le datasheet est 224 (0xE0)
  // mais l'adressage i2c utilise les 7 bits haut donc c'est 112
  Wire.write(byte(0x00));      // place le pointeur de registre sur le registre de commande(0x00)
  Wire.write(byte(0x51));      // ordonne au capteur de mesurer en "pouces" (0x50)
  // on peut utiliser 0x51 pour les centimetres
  // on peut utiliser 0x52 pour des microsecondes
  // CF datasheet
  Wire.endTransmission();      // arrete la transmission

  // etape 2: attendre que le capteur mesure
  delay(70);                   // le datasheet suggère au moins 65 millisecondes

  // etape 3: ordonner au capteur de retourner une lecture particuliere
  Wire.beginTransmission(adresseSRF08); // transmettre au peripherique #112
  Wire.write(byte(0x02));      // place le pointeur de registre sur le registre echo #1 (0x02)
  Wire.endTransmission();      // arrete la transmission

  // etape 4: demander au capteur la mesure
  Wire.requestFrom(adresseSRF08, 2);    // demander 2 bytes au peripherique esclave #112

  // etape 5: recevoir les valeurs depuis le capteur
  if (2 <= Wire.available()) { // si 2 bytes sont recus
    reading = Wire.read();  // recevoir le byte haut (ecrit par dessus la precedente lecture)
    reading = reading << 8;    // décaler le byte haut pour que ce soit les 8 bits haut
    reading |= Wire.read(); // recoit le byte bas en tant que 8 bits du bas
  }


}

void setup_ultrasonic() 
{
  delay(1000);
}
void loop_ultrasonic()
{
    srf08_mesure();
    value=10*(reading-10);
    if (value<5)
    {
      value=5;
    }
    delay(value);

}
