#include <stdio.h>



int main(){

  int pvGuts = 50;
  int pvMonstre = 50;
  int attaqueGuts = 5;

while (pvMonstre != 0) {
  printf("Guts attaque !\n");
  printf("Le monstre possede %d PV.\n", pvMonstre);
  printf("Le monstre subit %d degats\n", attaqueGuts);
  pvMonstre = pvMonstre-attaqueGuts;
  printf("Il reste %d PV au monstre !\n", pvMonstre);
}
  //  printf("Guts attaque !\n");
  //  printf("Le monstre possede %d\n", pvMonstre);
  //  printf("Le monstre subit %d degats\n", attaqueGuts);
  //  pvMonstre = pvMonstre-attaqueGuts;
  //  printf("Il reste %d PV au monstre !\n", pvMonstre);

return 0;
}
