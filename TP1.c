#include <stdio.h>



int main(){

  int pvGuts = 50;
  int pvMonstre = 50;
  int attaqueGuts = 5;
  int attaqueMonstre = 4;

while (pvMonstre > 0 && pvGuts > 0) {
  printf("Guts attaque !\n");
  printf("Le monstre possede %d PV\n", pvMonstre);
  printf("Le monstre subit %d degats\n", attaqueGuts);
  pvMonstre = pvMonstre-attaqueGuts;
  printf("Il reste %d PV au monstre !\n", pvMonstre);
  if (pvMonstre == 0){
    printf("Le monstre meurt\n");
    return 0;
  }
  printf("Le monstre attaque !\n");
  printf("Guts possede %d PV\n", pvGuts);
  printf("Guts subit %d degats\n", attaqueMonstre);
  pvGuts = pvGuts-attaqueMonstre;
  printf("Il reste %d PV a Guts !\n", pvGuts);
    if (pvGuts == 0) {
      printf("Guts decede.\n");
      return 0;
    }
}

//    printf("Guts attaque !\n");
//    printf("Le monstre possede %d\n", pvMonstre);
//    printf("Le monstre subit %d degats\n", attaqueGuts);
//    pvMonstre = pvMonstre-attaqueGuts;
//    printf("Il reste %d PV au monstre !\n", pvMonstre);





return 0;
}
