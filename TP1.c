#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ajout 3 persos
struct persos_t {
  char* nom;
  int pv;
  int attaque;
  int pm;
  int poison;
  int attaqueOuDefense;
};

typedef struct persos_t persos;
// capacités
// combattre différents monstres
// combattre plusieurs monstres en même temps
// système d'xp

int main(void){

//  int pvGuts = 50;
  int pvMonstre = 50;
//  int attaqueGuts = 5;
  int attaqueMonstre = 4;
//  int attaqueOuDefense; int attaqueOuDefenseCasca; int attaqueOuDefenseGriffith; int attaqueOuDefenseUvin;
//  int pmGuts = 50;
  int poisonMonstre;
  int pmMonstre = 50;
//  int poisonGuts; int poisonCasca; int poisonGriffith; int poisonUvin;
  int nbreAntidote =5;

  persos guts = {"Guts", 50, 5, 50, 0};
  persos casca = {"Casca", 50, 5, 50, 0};
  persos griffith = {"Griffith", 50, 5, 50, 0};
  persos uvin = {"Uvin", 50, 5, 50, 0};

// Tant que personne n'a plus de PV faire :
    while (pvMonstre != 0 || guts.pv != 0) {

      // Changement des consignes si le monstre est déjà empoisonné ou non.
        if (poisonMonstre == 1) {
        printf("Choisissez d'attaquer ou de defendre, 0 pour attaquer, 1 pour defendre, 3 pour utiliser un antidote.\n");
      } else {
        printf("Choisissez d'attaquer ou de defendre, 0 pour attaquer, 1 pour defendre, 2 pour utiliser le sort Poison, 3 pour utiliser un antidote.\n");
      }
      // Demander à l'utilisateur d'entrer la commande voulue.
      scanf("%d", &guts.attaqueOuDefense);
      scanf("%d", &casca.attaqueOuDefense);
      scanf("%d", &griffith.attaqueOuDefense);
      scanf("%d", &uvin.attaqueOuDefense);

      //aléatoire du monstre
      int MAX = 2, MIN = 0;
      srand(time(NULL));
      int attaqueOuDefenseDuMonstre = (rand() %(MAX - MIN + 1)) + MIN;
       // Si Guts est déja empoisonné ou si les PM du monstre sont inférieur à 15, le monstre ne peut plus utiliser poison.
      if (guts.poison == 1 || pmMonstre < 15) {
        MAX = 1;
        attaqueOuDefenseDuMonstre = (rand() %(MAX - MIN + 1)) + MIN;
      }


      if ( attaqueOuDefenseDuMonstre == 1) {
        guts.attaque = guts.attaque/4;
        casca.attaque = casca.attaque/4;
        griffith.attaque = griffith.attaque/4;
        uvin.attaque = uvin.attaque/4;
      }


      if (guts.attaqueOuDefense == 0) {
        printf("Guts choisit d'attaquer\n");
        printf("Guts attaque !\n");
        if ( attaqueOuDefenseDuMonstre == 1) {
          printf("Le monstre se defend et reduit les degats !\n");
        }
        printf("Le monstre possede %d PV\n", pvMonstre);
        printf("Le monstre subit %d degats\n", guts.attaque);
        pvMonstre = pvMonstre-guts.attaque;
        printf("Il reste %d PV au monstre !\n", pvMonstre);
            if (pvMonstre <= 0){
              printf("Le monstre meurt\n");
              return 0;
            }
      }

      if (guts.attaqueOuDefense == 1) {
        printf("Guts se defend et reduit les degats\n");
        attaqueMonstre = attaqueMonstre/4;
      }

      if (guts.attaqueOuDefense == 2) {

          printf("Guts utilise le sort poison !\n");
          printf("Le monstre est empoisonne.\n");
          guts.pm = guts.pm -15;
          printf("Il reste %d PM a Guts\n", guts.pm);
          poisonMonstre = 1;
      }


      if (guts.attaqueOuDefense == 3) {
        printf("Guts se soigne du poison.\n");
        guts.poison = 0;
        nbreAntidote = nbreAntidote-1;
        printf("Il vous reste %d antidote.\n", nbreAntidote);
      }

// Tour Casca
      if (casca.attaqueOuDefense == 0) {
        printf("Casca choisit d'attaquer\n");
        printf("Casca attaque !\n");
        if ( attaqueOuDefenseDuMonstre == 1) {
          printf("Le monstre se defend et reduit les degats !\n");
        }
        printf("Le monstre possede %d PV\n", pvMonstre);
        printf("Le monstre subit %d degats\n", casca.attaque);
        pvMonstre = pvMonstre-casca.attaque;
        printf("Il reste %d PV au monstre !\n", pvMonstre);
            if (pvMonstre <= 0){
              printf("Le monstre meurt\n");
              return 0;
            }
      }

      if (casca.attaqueOuDefense == 1) {
        printf("Casca se defend et reduit les degats\n");
        attaqueMonstre = attaqueMonstre/4;
      }

      if (casca.attaqueOuDefense == 2) {

          printf("Casca utilise le sort poison !\n");
          printf("Le monstre est empoisonne.\n");
          guts.pm = guts.pm -15;
          printf("Il reste %d PM a Casca\n", casca.pm);
          poisonMonstre = 1;
      }


      if (casca.attaqueOuDefense == 3) {
        printf("Casca se soigne du poison.\n");
        casca.poison = 0;
        nbreAntidote = nbreAntidote-1;
        printf("Il vous reste %d antidote.\n", nbreAntidote);
      }

// Tour Griffith
      if (griffith.attaqueOuDefense == 0) {
        printf("Griffith choisit d'attaquer\n");
        printf("Griffith attaque !\n");
        if ( attaqueOuDefenseDuMonstre == 1) {
          printf("Le monstre se defend et reduit les degats !\n");
        }
        printf("Le monstre possede %d PV\n", pvMonstre);
        printf("Le monstre subit %d degats\n", griffith.attaque);
        pvMonstre = pvMonstre-griffith.attaque;
        printf("Il reste %d PV au monstre !\n", pvMonstre);
            if (pvMonstre <= 0){
              printf("Le monstre meurt\n");
              return 0;
            }
      }

      if (griffith.attaqueOuDefense == 1) {
        printf("Griffith se defend et reduit les degats\n");
        attaqueMonstre = attaqueMonstre/4;
      }

      if (griffith.attaqueOuDefense == 2) {

          printf("Griffith utilise le sort poison !\n");
          printf("Le monstre est empoisonne.\n");
          guts.pm = guts.pm -15;
          printf("Il reste %d PM a Griffith\n", griffith.pm);
          poisonMonstre = 1;
      }


      if (griffith.attaqueOuDefense == 3) {
        printf("Griffith se soigne du poison.\n");
        griffith.poison = 0;
        nbreAntidote = nbreAntidote-1;
        printf("Il vous reste %d antidote.\n", nbreAntidote);
      }

// Tour Uvin
      if (uvin.attaqueOuDefense == 0) {
        printf("Uvin choisit d'attaquer\n");
        printf("Uvin attaque !\n");
        if ( attaqueOuDefenseDuMonstre == 1) {
          printf("Le monstre se defend et reduit les degats !\n");
        }
        printf("Le monstre possede %d PV\n", pvMonstre);
        printf("Le monstre subit %d degats\n", uvin.attaque);
        pvMonstre = pvMonstre-uvin.attaque;
        printf("Il reste %d PV au monstre !\n", pvMonstre);
            if (pvMonstre <= 0){
              printf("Le monstre meurt\n");
              return 0;
            }
      }

      if (uvin.attaqueOuDefense == 1) {
        printf("Uvin se defend et reduit les degats\n");
        attaqueMonstre = attaqueMonstre/4;
      }

      if (uvin.attaqueOuDefense == 2) {

          printf("Uvin utilise le sort poison !\n");
          printf("Le monstre est empoisonne.\n");
          uvin.pm = uvin.pm -15;
          printf("Il reste %d PM a Uvin\n", uvin.pm);
          poisonMonstre = 1;
      }


      if (uvin.attaqueOuDefense == 3) {
        printf("Uvin se soigne du poison.\n");
        uvin.poison = 0;
        nbreAntidote = nbreAntidote-1;
        printf("Il vous reste %d antidote.\n", nbreAntidote);
      }


      if (attaqueOuDefenseDuMonstre == 0) {
        printf("Le monstre attaque !\n");
        printf("Guts possede %d PV\n", guts.pv);
        printf("Guts subit %d degats\n", attaqueMonstre);
        guts.pv = guts.pv-attaqueMonstre;
        printf("Il reste %d PV a Guts !\n", guts.pv);
              if (uvin.pv <= 0) {
                printf("Uvin decede.\n");
                return 0;
              }
      }

      if ( attaqueOuDefenseDuMonstre == 1) {
        printf("Le monstre se defend.\n");
      }

      if (attaqueOuDefenseDuMonstre == 2) {
        if (pmMonstre > 0) {
          printf("Le monstre utilise Poison\n");
          printf("Guts est empoisonne !\n");
          pmMonstre = pmMonstre-15;
          guts.poison = 1;
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

        if (guts.poison == 1) {
          printf("Guts subit les degats du poison !\n");
          guts.pv = guts.pv-3;
          printf("Il reste %d PV a Guts.\n", guts.pv);
              if (guts.pv <= 0) {
                printf("Guts decede.\n");
                  if (casca.pv <= 0 && griffith.pv <= 0 && uvin.pv <= 0) {
                    printf("Votre equipe est decedee.\n");
                    return 0;
                  }
            }
      }
        if (casca.poison == 1) {
          printf("Casca subit les degats du poison !\n");
          casca.pv = casca.pv-3;
          printf("Il reste %d PV a Casca.\n", casca.pv);
              if (casca.pv <= 0) {
                printf("Casca decede.\n");
                  if (guts.pv <= 0 && griffith.pv <= 0 && uvin.pv <= 0) {
                    printf("Votre equipe est decedee.\n");
                    return 0;
                  }
            }
      }

        if (griffith.poison == 1) {
          printf("Griffith subit les degats du poison !\n");
          griffith.pv = griffith.pv-3;
          printf("Il reste %d PV a Griffith.\n", griffith.pv);
              if (griffith.pv <= 0) {
                printf("Griffith decede.\n");
                  if (guts.pv <= 0 && casca.pv <= 0 && uvin.pv <= 0) {
                    printf("Votre equipe est decedee.\n");
                    return 0;
                  }
              }
        }

        if (uvin.poison == 1) {
          printf("Uvin subit les degats du poison !\n");
          uvin.pv = uvin.pv-3;
          printf("Il reste %d PV a Uvin.\n", uvin.pv);
              if (uvin.pv <= 0) {
                printf("Uvin decede.\n");
                  if (guts.pv <= 0 && griffith.pv <= 0 && casca.pv <= 0) {
                    printf("Votre equipe est decedee.\n");
                    return 0;
                  }
            }
      }


        attaqueMonstre = 4;
        guts.attaque = 5;
        if (guts.pm != 50) {
          guts.pm = guts.pm+1;
        }
        casca.attaque = 5;
        if (casca.pm != 50) {
          casca.pm = casca.pm+1;
        }
        griffith.attaque = 5;
        if (griffith.pm != 50) {
          griffith.pm = griffith.pm+1;
        }
        uvin.attaque = 5;
        if (uvin.pm != 50) {
          uvin.pm = uvin.pm+1;
        }
        printf(" \n");
        printf(" \n");
        printf("%s : %dPV, %dPM", guts.nom, guts.pv, guts.pm);
        printf("%s : %dPV, %dPM", casca.nom, casca.pv, casca.pm);
        printf("%s : %dPV, %dPM", griffith.nom, griffith.pv, griffith.pm);
        printf("%s : %dPV, %dPM", uvin.nom, uvin.pv, uvin.pm);
        printf("Le monstre : %dPV, %dPM", pvMonstre, pmMonstre);
        printf("=========================================\n");
        printf("\n");

}
    return 0;

}
