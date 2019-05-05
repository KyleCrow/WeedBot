# WeedBot
Ce projet a été réalisé en classe de Terminale STI2D et évalué par nos professeurs pour le bac. <br/>
c'est un robot désherbant: son but est d'aider les agents d'entretien à désherber l'herbe qui pousse au bord des trottoirs.<br/>
<br/>
/!\ ATTENTION ce projet est encore en développement et l'état actuel du code n'est pas forcément fonctionnel ! <br/>

# Organisation technique
Le fichier principal est nommé "WeedBot.ino". <br/>

Section __Adeline__: <br/>
+ capteur_batterie_liquide.h<br/>
Cette bibliothèque gère l'afficheur LCD pour indiquer le niveau de la batterie et le niveau de liquide désherbant.<br/>
+ caractere.h
Cette bibliothèque contient les définitions des différents caractères représentants les états de la batterie.

Section __Raphaël__:<br/>
+ capteur_spray.h<br/>
Cette bibliothèque gère la fonction qui va actionner la pompe et asperger les mauvaises herbes de produit désherbant.<br/>

Section __Maxime__:<br/>
+ capteur_ultrason.h<br/>
Cette bibliothèque gère la communication avec le capteur SRF02 et donne l'espace entre le robot et le trottoir.<br/>

Section __Olivier__: <br/>
+ capteur_rgb.h<br/>
Cette bibliothèque gère la communication avec le capteur RGB et détecte la présence d'herbe.<br/>

Section __Matthieu__: <br/>
+ WeedBot.ino<br/>
C'est le programme principal, qui appelle toutes les autres bibliothèques.<br/>
+ correction_trajectoire.h<br/>
Cette bibliothèque gère le déplacement du robot de manière à suivre la bordure du trottoir.<br/>
+ bluetooth.h<br/>
Cette bibliothèque gère la communication avec l'application WeedBotController.<br/> https://github.com/KyleCrow/WeedBotController
