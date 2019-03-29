byte batterie0[8] = {        //  Création d’un tableau de 8 octets nommé batterie0
  0b01110,                   //  caractère représentant une batterie vide
  0b11111,
  0b10001,
  0b10001,
  0b10001,
  0b10001,
  0b10001,
  0b11111
};
byte batterie1[8] = {        //  Création d’un tableau de 8 octets nommé batterie0
  0b01110,                   //  caractère représentant une batterie vide
  0b11111,
  0b10001,
  0b10001,
  0b10001,
  0b10001,
  0b11111,
  0b11111
};
byte batterie2[8] = {        //  Création d’un tableau de 8 octets nommé batterie0
  0b01110,                   //  caractère représentant une batterie vide
  0b11111,
  0b10001,
  0b10001,
  0b10001,
  0b11111,
  0b11111,
  0b11111
};
byte batterie3[8] = {        //  Création d’un tableau de 8 octets nommé batterie0
  0b01110,                   //  caractère représentant une batterie vide
  0b11111,
  0b10001,
  0b10001,
  0b11111,
  0b11111,
  0b11111,
  0b11111
};
byte batterie4[8] = {        //  Création d’un tableau de 8 octets nommé batterie0
  0b01110,                   //  caractère représentant une batterie vide
  0b11111,
  0b10001,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111
};
byte batterie5[8] = {        //  Création d’un tableau de 8 octets nommé batterie0
  0b01110,                   //  caractère représentant une batterie vide
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111
};

// A Compléter pour chaque caractère batterie1 à batterie5

void caractere(void)
{
  lcd.createChar(0, batterie0); //  Écriture en CGRAM du caractère représentant une batterie vide
  lcd.createChar(1, batterie1); //  Écriture en CGRAM du caractère représentant une batterie vide
  lcd.createChar(2, batterie2); //  Écriture en CGRAM du caractère représentant une batterie vide
  lcd.createChar(3, batterie3); //  Écriture en CGRAM du caractère représentant une batterie vide
  lcd.createChar(4, batterie4); //  Écriture en CGRAM du caractère représentant une batterie vide
  lcd.createChar(5, batterie5); //  Écriture en CGRAM du caractère représentant une batterie vide
}
