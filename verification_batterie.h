

void affichageAvec0(float valeur)
{
  if(valeur<10)
  {
    lcd.print("00");
  }
  else if(valeur<100)
  {
    lcd.print("0");
  }
  lcd.print(valeur);
}

void batterie(void){

// Mesure tension batterie

  valeurBrute = analogRead(analogPin);     
  tensionBatterie = (valeurBrute * q) / k;

// Pourcentage

   if (tensionBatterie < 6)
  {
    pourcentage = 0;
    //    Serial.println("Alternative 1");
  }
  else if (tensionBatterie < 7.3)
  {
    pourcentage = (8.3333 * tensionBatterie) - 50;
    //    Serial.println("Alternative 2");
  }
  else if (tensionBatterie < 7.94)
  {
    pourcentage = (111.06 * tensionBatterie) - 800.88;
    //    Serial.println("Alternative 3");
  }
  else if (tensionBatterie < 8.4)
  {
    pourcentage = (43.233 * tensionBatterie) - 263.65;
    //    Serial.println("Alternative 4");
  }
  else
  {
    pourcentage = 100;
  
  }


// Affichage

  bleu = 0;
  vert = 2.55 * pourcentage;
  rouge = -2.55 * pourcentage + 255;
  lcd.setRGB(rouge, vert, bleu) ;
  lcd.setCursor(1, 1);
  lcd.print("Charge: ");
  affichageAvec0(pourcentage);
  lcd.print("%");

  lcd.setCursor(0,1);    // Position du pictogramme batterie en bas à gauche du LCD
  if (pourcentage < 10)
  {
    lcd.write((unsigned char)0);         // Affichage du pictogramme batterie0 : Batterie vide
  }
  else if (pourcentage < 30)
  {
    lcd.write(1);
  }
  else if (pourcentage < 50)
  {
    lcd.write(2);
  }
  else if (pourcentage < 70)
  {
    lcd.write(3);
  }
  else if (pourcentage < 90)
  {
    lcd.write(4);
  }
  else
  {
    lcd.write(5);        
  }
  
}
