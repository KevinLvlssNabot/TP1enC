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

    while (pvMonstre > 0 && pvGuts > 0) {


        if (poisonMonstre == 1) {
        printf("Choisissez d'attaquer ou de defendre, 0 pour attaquer, 1 pour defendre.\n");
      } else {
        printf("Choisissez d'attaquer ou de defendre, 0 pour attaquer, 1 pour defendre, 2 pour utiliser le sort Poison.\n");
      }

      scanf("%d", &attaqueOuDefense);


      int MAX = 2, MIN = 0;
      srand(time(NULL));
      int attaqueOuDefenseDuMonstre = (rand() %(MAX - MIN + 1)) + MIN;
      // test rand  printf("%d\n", attaqueOuDefenseDuMonstre);

      if (pmMonstre <= 0 || poisonGuts == 1) {
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
      };

      if (attaqueOuDefense == 1) {
        printf("Guts se defend et reduit les degats\n");
        attaqueMonstre = attaqueMonstre/4;
      };

      if (attaqueOuDefense == 2) {
        printf("Guts utilise le sort poison !\n");
        printf("Le monstre est empoisonne.\n");
        pmGuts = pmGuts-15;
        printf("Il reste %d PM a Guts\n", pmGuts);
        poisonMonstre = 1;
      }

      if (pvMonstre == 0){
        printf("Le monstre meurt\n");
        return 0;
      }


      if (attaqueOuDefenseDuMonstre == 0) {
        printf("Le monstre attaque !\n");
        printf("Guts possede %d PV\n", pvGuts);
        printf("Guts subit %d degats\n", attaqueMonstre);
        pvGuts = pvGuts-attaqueMonstre;
        printf("Il reste %d PV a Guts !\n", pvGuts);
      }

      if (attaqueOuDefenseDuMonstre == 2 && pmMonstre > 0) {
        printf("Le monstre utilise Poison\n");
        printf("Guts est empoisonne !\n");
        pmMonstre = pmMonstre-15;
        poisonGuts = 1;
        printf("Il reste %d PM au monstre.\n", pmMonstre);
      } else if (pmMonstre <= 0) {
        printf("Le monstre possede %d PM et ne peut pas utiliser Poison.\n", pmMonstre);
      }

        if (pvGuts == 0) {
          printf("Guts decede.\n");
          return 0;
        }
        // Effet du poison
        if (poisonMonstre == 1) {
          printf("Le monstre subit des degats du poison.\n");
          pvMonstre = pvMonstre - 2;
          printf("Il reste %d PV au monstre !\n", pvMonstre);
        }
        if (poisonGuts == 1) {
          printf("Guts subit les degats du poison !\n");
          pvGuts = pvGuts-3;
          printf("Il reste %d PV a Guts.\n", pvGuts);
        }
        attaqueMonstre = 4;
        attaqueGuts = 5;
        pmGuts = pmGuts+1;

    }

    return 0;

}
