void liquide(void){ 
    reservoirH = digitalRead (pinNiveauHaut );
    reservoirL = !digitalRead (pinNiveauBas);
    lcd.clear();
    if(reservoirH && reservoirL){
      lcd.write("Reservoir Plein");
    }
     else if  (!reservoirH && reservoirL){
      lcd.write("Pas plein");
      }else if (!reservoirH && !reservoirL){
        lcd.write("Ajouter Desherb.");
        desherbant = 1;
        }else{
      lcd.write("erreur");
     }
  
  }
