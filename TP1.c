#include <stdio.h>



int main(){

  int pvGuts = 50;
  int pvMonstre = 50;
  int attaqueGuts = 5;

    printf("Guts attaque !\n");
    printf("Le monstre possede %d\n", pvMonstre);
    printf("Le monstre subit %d degats\n", attaqueGuts);
    pvMonstre = pvMonstre-attaqueGuts;
    printf("Il reste %d PV au monstre !\n", pvMonstre);





return 0;
}
