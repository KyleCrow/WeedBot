# WeedBot
Ce projet a été réalisé en classe de Terminale STI2D et évalué par nos professeurs pour le bac. <br/>
c'est un robot désherbant: son but est d'aider les agents d'entretien à nettoyer l'herbe qui pousse au bord des trottoirs.<br/>

# Organisation technique
Le fichier principal est nommé "WeedBot.ino". <br/>

Section __Adeline__: <br/>
+ sensor_battery_liquid.h<br/>
Cette bibliothèque gère l'afficheur LCD pour indiquer le niveau de la batterie et le niveau de liquide désherbant.<br/>

Section __Raphaël__:<br/>
+ sensor_spray.h<br/>
Cette bibliothèque gère la fonction qui va actionner la pompe et asperger les mauvaises herbes de produit désherbant.<br/>

Section __Maxime__:
+ sensor_ultrasonic.h<br/>
Cette bibliothèque gère la communication avec le capteur SRF02 et donne l'espace entre le robot et le trottoir.<br/>

Section __Olivier__: <br/>
+ sensor_rgb.h<br/>
Cette bibliothèque gère la communication avec le capteur RGB et détecte la présence d'herbe.<br/>

Section __Matthieu__: <br/>
+ WeedBot.ino<br/>
C'est le programme principal, qui appelle toutes les autres bibliothèques, et gère le déplacement du robot de manière à suivre la bordure du trottoir.
