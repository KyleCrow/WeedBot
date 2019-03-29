
void setup_battery_liquid() {
  pinMode (pinNiveauHaut,INPUT_PULLUP);
  pinMode (pinNiveauBas, INPUT_PULLUP);
  lcd.begin(16, 2);
  lcd.setRGB(rouge, vert, bleu) ;
  caractere();
}

void loop_battery_liquid() {
  liquide();
  batterie();

}
