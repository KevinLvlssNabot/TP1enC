#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int main(void){

  int pvGuts = 50;
  int pvMonstre = 50;
  int attaqueGuts = 5;
  int attaqueMonstre = 4;
  int attaqueOuDefense;
  int pmGuts = 50;
  int poisonMonstre;
  int pmMonstre = 50;
  int poisonGuts;
  int nbreAntidote =5;

// Tant que personne n'a plus de PV faire :
    while (pvMonstre != 0 || pvGuts != 0) {

      // Changement des consignes si le monstre est déjà empoisonné ou non.
        if isateur d'entrer la commande voulue.
      scanf("%d", &attaqueOuDefense);

      //aléatoire du monstre
      int MAX = 2, MIN = 0;
      srand(time(NULL));
      int attaqueOuDefenseDuMonstre = (rand() %(MAX - MIN + 1)) + MIN;
       printf("%d\n", attaqueOuDefenseDuMonstre);
       // Si Guts est déja empoisonné ou si les PM du monstre sont inférieur à 15, le monstre ne peut plus utiliser poison.
      if (poisonGuts == 1 || pmMonstre < 15) {
        MAX = 1;
        attaqueOuDefenseDuMonstre = (rand() %(MAX - MIN + 1)) + MIN;
      }


      if ( attaqueOuDefenseDuMonstre == 1) {
        attaqueGuts = attaqueGuts/4;
      }


      if (attaqueOuDefense == 0) {
        printf("Guts choisit d'attaquer\n");
        printf("Guts attaque !\n");
        if ( attaqueOuDefenseDuMonstre == 1) {
          printf("Le monstre se defend et reduit les degats !\n");
        }
        printf("Le monstre possede %d PV\n", pvMonstre);
        printf("Le monstre subit %d degats\n", attaqueGuts);
        pvMonstre = pvMonstre-attaqueGuts;
        printf("Il reste %d PV au monstre !\n", pvMonstre);
            if (pvMonstre <= 0){
              printf("Le monstre meurt\n");
              return 0;
            }
      }

      if (attaqueOuDefense == 1) {
        printf("Guts se defend et reduit les degats\n");
        attaqueMonstre = attaqueMonstre/4;
      }

      if (attaqueOuDefense == 2) {

          printf("Guts utilise le sort poison !\n");
          printf("Le monstre est empoisonne.\n");
          pmGuts = pmGuts-15;
          printf("Il reste %d PM a Guts\n", pmGuts);
          poisonMonstre = 1;
      }


      if (attaqueOuDefense == 3) {
        printf("Guts se soigne du poison.\n");
        poisonGuts = 0;
        nbreAntidote = nbreAntidote-1;
        printf("Il vous reste %d antidote.\n", nbreAntidote);
      }



      if (attaqueOuDefenseDuMonstre == 0) {
        printf("Le monstre attaque !\n");
        printf("Guts possede %d PV\n", pvGuts);
        printf("Guts subit %d degats\n", attaqueMonstre);
        pvGuts = pvGuts-attaqueMonstre;
        printf("Il reste %d PV a Guts !\n", pvGuts);
              if (pvGuts <= 0) {
                printf("Guts decede.\n");
                return 0;
              }
      }

      if (attaqueOuDefenseDuMonstre == 2) {
        if (pmMonstre > 0) {
          printf("Le monstre utilise Poison\n");
          printf("Guts est empoisonne !\n");
          pmMonstre = pmMonstre-15;
          poisonGuts = 1;
          printf("Il reste %d PM au monstre.\n", pmMonstre);
        }

    }


        // Effet du poison
        if (poisonMonstre == 1) {
          printf("Le monstre subit des degats du poison.\n");
          pvMonstre = pvMonstre - 2;
          printf("Il reste %d PV au monstre !\n", pvMonstre);
                if (pvMonstre <= 0){
                  printf("Le monstre meurt\n");
                  return 0;
                }
        }

        if (poisonGuts == 1) {
          printf("Guts subit les degats du poison !\n");
          pvGuts = pvGuts-3;
          printf("Il reste %d PV a Guts.\n", pvGuts);
              if (pvGuts <= 0) {
                printf("Guts decede.\n");
                return 0;
              }
        }

        attaqueMonstre = 4;
        attaqueGuts = 5;
        if (pmGuts != 50) {
          pmGuts = pmGuts+1;
        }
        printf(" \n");
        printf(" \n");
        printf("Guts : %dPV, %dPM, Monstre : %dPV, %dPM\n", pvGuts, pmGuts, pvMonstre, pmMonstre);
        printf("=========================================\n");
        printf("\n");
}
    return 0;

}
