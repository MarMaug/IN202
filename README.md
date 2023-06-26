# IN202
Arduino code for course IN202 at ENSTA Paris

PROGRAMME :
  - Allume la LED bleue (4) lorsque le bouton est appuyé
  - Détecte les clics courts, longs, et très longs
  - Modifie le comportement de la LED blanche (12) suivant la longueur des clics :
        courts     -> intensité augmente puis décroît continuellement
        longs      -> si on était en train de croître, on décroît et inversemement
        très longs -> on passe en mode clignotement
  - Modifie le comportement de la LED interne : allumée si l'intensité de la 12 Decrease, éteinte si Increase
  - Affiche quand le bouton est pressé, quand il est relâché et le type d'appui (avec intervalle de temps correspondant)

 MONTAGE :
  - Bouton entre le ground et la pin 2
  - LED bleue entre le bouton côté ground et la pin 4
  - LED blanche entre la pin 12 et le ground
