#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int main(void){

  int pvGuts = 50;
  int pvMonstre = 50;
  int attaqueGuts = 5;
  int attaqueMonstre = 4;
  int attaqueOuDefense;

    while (pvMonstre > 0 && pvGuts > 0) {
      printf("Choisissez d'attaquer ou de defendre, 0 pour attaquer, 1 pour defendre\n");
      scanf("%d", &attaqueOuDefense);

      const int MAX = 1, MIN = 0;
      srand(time(NULL));
      int attaqueOuDefenseDuMonstre = (rand() %(MAX - MIN + 1)) + MIN;;
      // test rand  printf("%d\n", attaqueOuDefenseDuMonstre);
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


        if (pvGuts == 0) {
          printf("Guts decede.\n");
          return 0;
        }
        attaqueMonstre = 4;
        attaqueGuts = 5;
    }


return 0;

}
