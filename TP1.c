#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

// Fonction capacites monstres
//    int capacites1Soldat(int compteur, char* nomMonstre, char* nomHeros, int herosAttaque){
//      // Sappe, pendant 3 tours, le héros voit son attaque divisée par 2
//      compteur = 3;
//      printf("%s utilise Sappe !\n", nomMonstre);
//      printf("L'attaque de %s est divisee par 2 pendant 3 tours\n", nomHeros);
//      while (compteur > 0) {
//        herosAttaque = herosAttaque/2;
//      }
//    }
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

struct monstres_t {
  char* nomMonstre;
  int pvMonstre;
  int attaqueMonstre;
  int pmMonstre;
  int poisonMonstre;
  int attaqueOuDefenseDuMonstre;
  int cibleAleatoireMonstre;
};

typedef struct monstres_t monstres;

struct capacitesMonstres_t {
  char* nomCapacites;
  int degats;
  int compteurCapacites;
  int coutPm;
};

typedef struct capacitesMonstres_t capacitesMonstres;
// capacités
// combattre plusieurs monstres en même temps
// système d'xp

void Color(int t,int f)
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,f*16+t);
}

int main(void){

    int continuer = 0;
while (continuer == 0) {

  int nbreAntidote =5;

  int nbreEnnemis;

  persos guts = {"Guts", 50, 5, 50, 0, 100}; // 100 pour que le tour de jeu ne soit pas impacté par l'input du joueur.
  persos casca = {"Casca", 50, 5, 50, 0, 100};
  persos griffith = {"Griffith", 50, 5, 50, 0, 100};
  persos uvin = {"Uvin", 50, 5, 50, 0, 100};

  int choixMonstre;
  monstres monstres1;
  monstres monstres2;
  monstres monstres3;
  monstres monstres4;
  monstres soldat = {"Soldat", 50, 5, 50, 0, 100};
  monstres abeille = {"Abeille", 25, 8, 0, 100};
  monstres flan = {"Flan", 40, 6, 100, 100};
  monstres morbol = {"Morbol", 70, 3, 150, 100};
  monstres wyverne = {"Wyverne", 100, 10, 30, 100};

//  capacitesMonstres sappe ={"Sappe", 0, 0, 10};

  int FinPartie = 0;


  printf("Quel monstre souhaitez-vous affronter ?\n");
  printf("0 pour le soldat // 1 pour l'abeille // 2 pour le flan // 3 pour le morbol // 4 pour la wyverne.\n");
  scanf("%d", &choixMonstre);
  while (choixMonstre < 0 || choixMonstre > 4) {
      scanf("%d", &choixMonstre);
    }
    if (choixMonstre == 0) {
      printf("Preparez-vous a affronter le %s\n", soldat.nomMonstre);
      monstres1 = soldat;
    } else if (choixMonstre == 1) {
      printf("Preparez-vous a affronter l'%s\n", abeille.nomMonstre);
      monstres1 = abeille;
    } else if (choixMonstre == 2) {
      printf("Preparez-vous a affronter le %s\n", flan.nomMonstre);
      monstres1 = flan;
    } else if (choixMonstre == 3) {
      printf("Preparez-vous a affronter le %s\n", morbol.nomMonstre);
      monstres1 = morbol;
    } else if (choixMonstre == 4) {
      printf("Preparez-vous a affronter la %s\n", wyverne.nomMonstre);
      monstres1 = wyverne;
    }
Sleep(1000);
system("cls");

// Tant que personne n'a plus de PV faire :
    while (FinPartie == 0) {
Color(15,0);
      // Changement des consignes si le monstre est déjà empoisonné ou non.
        if (monstres1.poisonMonstre == 1) {
        printf("Choisissez d'attaquer ou de defendre, 0 pour attaquer, 1 pour defendre, 3 pour utiliser un antidote.\n");
      } else {
        printf("Choisissez d'attaquer ou de defendre, 0 pour attaquer, 1 pour defendre, 2 pour utiliser le sort Poison, 3 pour utiliser un antidote.\n");
      }


      // Demander à l'utilisateur d'entrer la commande voulue.
      if (guts.pv >0) {
        printf("Que dois faire %s ?\n", guts.nom);
        scanf("%d", &guts.attaqueOuDefense);
      }
      if (casca.pv >0) {
        printf("Que dois faire %s ?\n", casca.nom);
        scanf("%d", &casca.attaqueOuDefense);
      }
      if (griffith.pv >0) {
        printf("Que dois faire %s ?\n", griffith.nom);
        scanf("%d", &griffith.attaqueOuDefense);
      }
      if (uvin.pv >0) {
        printf("Que dois faire %s ?\n", uvin.nom);
        scanf("%d", &uvin.attaqueOuDefense);
      }

int MAX;
int MIN;
      //aléatoire du monstre
      if (monstres1.pmMonstre >= 15) {
        MAX = 2, MIN = 0;
        srand(time(NULL));
          monstres1.attaqueOuDefenseDuMonstre = (rand() %(MAX - MIN + 1)) + MIN;
      }
       // Si Guts est déja empoisonné ou si les PM du monstre sont inférieur à 15, le monstre ne peut plus utiliser poison.
      if ((guts.poison == 1 && casca.poison == 1 && griffith.poison == 1 && uvin.poison == 1) || (monstres1.pmMonstre < 15)) {
        MAX = 1, MIN = 0;
            while (monstres1.attaqueOuDefenseDuMonstre == 2) {
              srand(time(NULL));
              monstres1.attaqueOuDefenseDuMonstre = (rand() %(MAX - MIN + 1)) + MIN;
          }
      }

      // Cible aléatoire du/des monstres
      int MAX2 = 3, MIN2 = 0;
      srand(time(NULL));
      monstres1.cibleAleatoireMonstre = (rand() %(MAX2 - MIN2 + 1)) + MIN2;

printf("%d\n", monstres1.attaqueOuDefenseDuMonstre);
// Si monstre defend attaque/4
      if (monstres1.attaqueOuDefenseDuMonstre == 1) {
        guts.attaque = guts.attaque/4;
        casca.attaque = casca.attaque/4;
        griffith.attaque = griffith.attaque/4;
        uvin.attaque = uvin.attaque/4;
      }

      // Tour de Guts
  Color(1,0);
      if (guts.attaqueOuDefense == 0) {
        printf("Guts choisit d'attaquer\n");
        printf("Guts attaque !\n");
        if ( monstres1.attaqueOuDefenseDuMonstre == 1) {
          printf("%s se defend et reduit les degats !\n", monstres1.nomMonstre);
        }
        printf("%s subit %d degats\n", monstres1.nomMonstre, guts.attaque);
        monstres1.pvMonstre = monstres1.pvMonstre-guts.attaque;
        printf("Il reste %d PV au monstre !\n", monstres1.pvMonstre);
            if (monstres1.pvMonstre <= 0){
              printf("%s meurt\n", monstres1.nomMonstre);
              FinPartie = 1;
            }
     }

      if (guts.attaqueOuDefense == 1) {
        printf("Guts se defend et reduit les degats\n");
          if (monstres1.cibleAleatoireMonstre == 0) {
          monstres1.attaqueMonstre = monstres1.attaqueMonstre/4;
          } else {
          monstres1.attaqueMonstre = monstres1.attaqueMonstre;
        }
      }

      if (guts.attaqueOuDefense == 2) {

          printf("Guts utilise le sort poison !\n");
          printf("Le monstre est empoisonne.\n");
          guts.pm = guts.pm -15;
          printf("Il reste %d PM a Guts\n", guts.pm);
          monstres1.poisonMonstre = 1;
      }


      if (guts.attaqueOuDefense == 3) {
        printf("Guts se soigne du poison.\n");
        guts.poison = 0;
        nbreAntidote = nbreAntidote-1;
        printf("Il vous reste %d antidote.\n", nbreAntidote);
      }

// Tour Casca
Color(2,0);
      if (casca.attaqueOuDefense == 0) {
        printf("Casca choisit d'attaquer\n");
        printf("Casca attaque !\n");
        if ( monstres1.attaqueOuDefenseDuMonstre == 1) {
          printf("%s se defend et reduit les degats !\n", monstres1.nomMonstre);
        }
        printf("%s subit %d degats\n",monstres1.nomMonstre, casca.attaque);
        monstres1.pvMonstre = monstres1.pvMonstre-casca.attaque;
        printf("Il reste %d PV au %s !\n", monstres1.pvMonstre, monstres1.nomMonstre);
            if (monstres1.pvMonstre <= 0){
              printf("%s meurt\n", monstres1.nomMonstre);
              FinPartie = 1;
            }
      }

      if (casca.attaqueOuDefense == 1) {
        printf("Casca se defend et reduit les degats\n");
          if (monstres1.cibleAleatoireMonstre == 1) {
          monstres1.attaqueMonstre = monstres1.attaqueMonstre/4;
          } else {
          monstres1.attaqueMonstre = monstres1.attaqueMonstre;
        }
      }

      if (casca.attaqueOuDefense == 2) {

          printf("Casca utilise le sort poison !\n");
          printf("%s est empoisonne.\n", monstres1.nomMonstre);
          guts.pm = guts.pm -15;
          printf("Il reste %d PM a Casca\n", casca.pm);
          monstres1.poisonMonstre = 1;
      }


      if (casca.attaqueOuDefense == 3) {
        printf("Casca se soigne du poison.\n");
        casca.poison = 0;
        nbreAntidote = nbreAntidote-1;
        printf("Il vous reste %d antidote.\n", nbreAntidote);
      }

// Tour Griffith
Color(3,0);
      if (griffith.attaqueOuDefense == 0) {
        printf("Griffith choisit d'attaquer\n");
        printf("Griffith attaque !\n");
        if ( monstres1.attaqueOuDefenseDuMonstre == 1) {
          printf("%s se defend et reduit les degats !\n", monstres1.nomMonstre);
        }
        printf("%s subit %d degats\n",monstres1.nomMonstre, griffith.attaque);
        monstres1.pvMonstre = monstres1.pvMonstre-griffith.attaque;
        printf("Il reste %d PV au %s !\n", monstres1.pvMonstre, monstres1.nomMonstre);
            if (monstres1.pvMonstre <= 0){
              printf("%s meurt\n", monstres1.nomMonstre);
              FinPartie = 1;
            }
      }

      if (griffith.attaqueOuDefense == 1) {
        printf("Griffith se defend et reduit les degats\n");
          if (monstres1.cibleAleatoireMonstre == 2) {
          monstres1.attaqueMonstre = monstres1.attaqueMonstre/4;
          } else {
          monstres1.attaqueMonstre = monstres1.attaqueMonstre;
        }
      }

      if (griffith.attaqueOuDefense == 2) {

          printf("Griffith utilise le sort poison !\n");
          printf("%s est empoisonne.\n", monstres1.nomMonstre);
          guts.pm = guts.pm -15;
          printf("Il reste %d PM a Griffith\n", griffith.pm);
          monstres1.poisonMonstre = 1;
      }


      if (griffith.attaqueOuDefense == 3) {
        printf("Griffith se soigne du poison.\n");
        griffith.poison = 0;
        nbreAntidote = nbreAntidote-1;
        printf("Il vous reste %d antidote.\n", nbreAntidote);
      }

// Tour Uvin
Color(4,0);
      if (uvin.attaqueOuDefense == 0) {
        printf("Uvin choisit d'attaquer\n");
        printf("Uvin attaque !\n");
        if ( monstres1.attaqueOuDefenseDuMonstre == 1) {
          printf("%s se defend et reduit les degats !\n", monstres1.nomMonstre);
        }
        printf("%s subit %d degats\n",monstres1.nomMonstre, uvin.attaque);
        monstres1.pvMonstre = monstres1.pvMonstre-uvin.attaque;
        printf("Il reste %d PV au %s !\n", monstres1.pvMonstre, monstres1.nomMonstre);
            if (monstres1.pvMonstre <= 0){
              printf("%s meurt\n", monstres1.nomMonstre);
              FinPartie = 1;
            }
      }

      if (uvin.attaqueOuDefense == 1) {
        printf("Uvin se defend et reduit les degats\n");
          if (monstres1.cibleAleatoireMonstre == 2) {
          monstres1.attaqueMonstre = monstres1.attaqueMonstre/4;
          } else {
          monstres1.attaqueMonstre = monstres1.attaqueMonstre;
        }
      }

      if (uvin.attaqueOuDefense == 2) {

          printf("Uvin utilise le sort poison !\n");
          printf("%s est empoisonne.\n", monstres1.nomMonstre);
          uvin.pm = uvin.pm -15;
          printf("Il reste %d PM a Uvin\n", uvin.pm);
          monstres1.poisonMonstre = 1;
      }


      if (uvin.attaqueOuDefense == 3) {
        printf("Uvin se soigne du poison.\n");
        uvin.poison = 0;
        nbreAntidote = nbreAntidote-1;
        printf("Il vous reste %d antidote.\n", nbreAntidote);
      }

// Tour du monstre
Color(5,0);
      if (monstres1.attaqueOuDefenseDuMonstre == 0) {
        printf("%s attaque !\n", monstres1.nomMonstre);
          if (monstres1.cibleAleatoireMonstre == 0) {
            printf("Guts subit %d degats\n", monstres1.attaqueMonstre);
            guts.pv = guts.pv-monstres1.attaqueMonstre;
            printf("Il reste %d PV a Guts !\n", guts.pv);
                  if (guts.pv <= 0) {
                    printf("Guts decede.\n");
                  }
          } else if (monstres1.cibleAleatoireMonstre == 1) {
            printf("Casca subit %d degats\n", monstres1.attaqueMonstre);
            casca.pv = casca.pv-monstres1.attaqueMonstre;
            printf("Il reste %d PV a Casca !\n", casca.pv);
                  if (casca.pv <= 0) {
                    printf("Casca decede.\n");
                  }
          } else if (monstres1.cibleAleatoireMonstre == 2) {
            printf("Griffith subit %d degats\n", monstres1.attaqueMonstre);
            griffith.pv = griffith.pv-monstres1.attaqueMonstre;griffith;
            printf("Il reste %d PV a Griffith !\n", griffith.pv);
                  if (griffith.pv <= 0) {
                    printf("Griffith decede.\n");
                  }
          } else if (monstres1.cibleAleatoireMonstre == 3) {
            printf("Uvin subit %d degats\n", monstres1.attaqueMonstre);
            uvin.pv = uvin.pv-monstres1.attaqueMonstre;griffith;
            printf("Il reste %d PV a Uvin !\n", uvin.pv);
                  if (uvin.pv <= 0) {
                    printf("Uvin decede.\n");
                    }
          }

      }

      if ( monstres1.attaqueOuDefenseDuMonstre == 1) {
        printf("%s se defend.\n", monstres1.nomMonstre);
      }
// Attaque poison du monstre
      if (monstres1.attaqueOuDefenseDuMonstre == 2) {
        if (monstres1.pmMonstre > 0) {
          printf("%s utilise Poison\n", monstres1.nomMonstre);
            if (monstres1.cibleAleatoireMonstre == 0) {
              if (guts.pv > 0 && guts.poison == 0) {
                printf("Guts est empoisonne !\n");
                monstres1.pmMonstre = monstres1.pmMonstre-15;
                guts.poison = 1;
                printf("Il reste %d PM au %s.\n", monstres1.pmMonstre, monstres1.nomMonstre);
            } else {
                while ((monstres1.cibleAleatoireMonstre != 1) || (monstres1.cibleAleatoireMonstre !=2) || (monstres1.cibleAleatoireMonstre !=3)) {
                    monstres1.cibleAleatoireMonstre = (rand() %(MAX2 - MIN2 + 1)) + MIN2;
                }
          }
        } else if (monstres1.cibleAleatoireMonstre == 1) {
            if (casca.pv > 0 && casca.poison == 0) {
              printf("Casca est empoisonne !\n");
              monstres1.pmMonstre = monstres1.pmMonstre-15;
              casca.poison = 1;
              printf("Il reste %d PM au %s.\n", monstres1.pmMonstre, monstres1.nomMonstre);
            } else {
                while ((monstres1.cibleAleatoireMonstre != 0) || (monstres1.cibleAleatoireMonstre !=2) || (monstres1.cibleAleatoireMonstre !=3)) {
                    monstres1.cibleAleatoireMonstre = (rand() %(MAX2 - MIN2 + 1)) + MIN2;
                }
          }
        } else if (monstres1.cibleAleatoireMonstre == 2) {
            if (griffith.pv > 0 && griffith.poison == 0) {
              printf("Griffith est empoisonne !\n");
              monstres1.pmMonstre = monstres1.pmMonstre-15;
              griffith.poison = 1;
              printf("Il reste %d PM au %s.\n", monstres1.pmMonstre, monstres1.nomMonstre);
            } else {
                while ((monstres1.cibleAleatoireMonstre != 0) || (monstres1.cibleAleatoireMonstre !=1) || (monstres1.cibleAleatoireMonstre !=3)) {
                    monstres1.cibleAleatoireMonstre = (rand() %(MAX2 - MIN2 + 1)) + MIN2;
                  }
            }
          } else if (monstres1.cibleAleatoireMonstre == 3) {
              if (uvin.pv > 0 && uvin.poison == 0) {
                printf("Uvin est empoisonne !\n");
                monstres1.pmMonstre = monstres1.pmMonstre-15;
                uvin.poison = 1;
                printf("Il reste %d PM au %s.\n", monstres1.pmMonstre, monstres1.nomMonstre);
              } else {
                  while ((monstres1.cibleAleatoireMonstre != 0) || (monstres1.cibleAleatoireMonstre !=1) || (monstres1.cibleAleatoireMonstre !=2)) {
                      monstres1.cibleAleatoireMonstre = (rand() %(MAX2 - MIN2 + 1)) + MIN2;
                  }
            }
          }


    }
  }


// Capacites Speciales monstres
//      if (monstres1.attaqueOuDefenseDuMonstre == 3) {
//          if (monstres1.nomMonstre == "Soldat") {
//            scanf("%d", &monstres1.cibleAleatoireMonstre);
//              if (monstres1.cibleAleatoireMonstre == 0) {
//                  capacites1Soldat(sappe.compteurCapacites, monstres1.nomMonstre, guts.nom, guts.attaque);
//              } else if (monstres1.cibleAleatoireMonstre == 1) {
//                  capacites1Soldat(sappe.compteurCapacites, monstres1.nomMonstre, casca.nom, casca.attaque);
//              } else if (monstres1.cibleAleatoireMonstre == 2) {
//                  capacites1Soldat(sappe.compteurCapacites, monstres1.nomMonstre, griffith.nom, griffith.attaque);
//              } else if (monstres1.cibleAleatoireMonstre == 3) {
//                  capacites1Soldat(sappe.compteurCapacites, monstres1.nomMonstre, uvin.nom, uvin.attaque);
//              }
//          }
//
//}




        // Effet du poison
        if (monstres1.poisonMonstre == 1) {
          printf("%s subit des degats du poison.\n", monstres1.nomMonstre);
          monstres1.pvMonstre = monstres1.pvMonstre - 2;
          printf("Il reste %d PV au %s !\n", monstres1.pvMonstre, monstres1.nomMonstre);
                if (monstres1.pvMonstre <= 0){
                  printf("%s meurt\n", monstres1.nomMonstre);
                  FinPartie = 1;

                }
        }
Color(1,0);
        if (guts.poison == 1) {
          printf("Guts subit les degats du poison !\n");
          guts.pv = guts.pv-3;
          printf("Il reste %d PV a Guts.\n", guts.pv);
              if (guts.pv <= 0) {
                printf("Guts decede.\n");
                  if (casca.pv <= 0 && griffith.pv <= 0 && uvin.pv <= 0) {
                    printf("Votre equipe est decedee.\n");
                    FinPartie = 1;

                  }
            }
      }
Color(2,0);
        if (casca.poison == 1) {
          printf("Casca subit les degats du poison !\n");
          casca.pv = casca.pv-3;
          printf("Il reste %d PV a Casca.\n", casca.pv);
              if (casca.pv <= 0) {
                printf("Casca decede.\n");
                  if (guts.pv <= 0 && griffith.pv <= 0 && uvin.pv <= 0) {
                    printf("Votre equipe est decedee.\n");
                    FinPartie = 1;

                  }
            }
      }
Color(3,0);
        if (griffith.poison == 1) {
          printf("Griffith subit les degats du poison !\n");
          griffith.pv = griffith.pv-3;
          printf("Il reste %d PV a Griffith.\n", griffith.pv);
              if (griffith.pv <= 0) {
                printf("Griffith decede.\n");
                  if (guts.pv <= 0 && casca.pv <= 0 && uvin.pv <= 0) {
                    printf("Votre equipe est decedee.\n");
                    FinPartie = 1;

                  }
              }
        }
Color(4,0);
        if (uvin.poison == 1) {
          printf("Uvin subit les degats du poison !\n");
          uvin.pv = uvin.pv-3;
          printf("Il reste %d PV a Uvin.\n", uvin.pv);
              if (uvin.pv <= 0) {
                printf("Uvin decede.\n");
                  if (guts.pv <= 0 && griffith.pv <= 0 && casca.pv <= 0) {
                    printf("Votre equipe est decedee.\n");
                    FinPartie = 1;


                  }
            }
      }


    //    monstres1.attaqueMonstre = monstres1.attaqueMonstre;
        guts.attaque = 5;
    //    guts.attaqueOuDefense = 100;
        if (guts.pm != 50) {
          guts.pm = guts.pm+1;
        }
        casca.attaque = 5;
    //    casca.attaqueOuDefense = 100;
        if (casca.pm != 50) {
          casca.pm = casca.pm+1;
        }
        griffith.attaque = 5;
    //    griffith.attaqueOuDefense = 100;
        if (griffith.pm != 50) {
          griffith.pm = griffith.pm+1;
        }
        uvin.attaque = 5;
  //      uvin.attaqueOuDefense = 100;
        if (uvin.pm != 50) {
          uvin.pm = uvin.pm+1;
        }

    //    if (sappe.compteurCapacites > 0) {
    //      sappe.compteurCapacites = sappe.compteurCapacites -1;
    //    }
Color(15,0);
        printf(" \n");
        printf(" \n");
        printf("%s : %dPV, %dPM", guts.nom, guts.pv, guts.pm); if (guts.poison == 1) { printf("      Poison"); }  printf("                             %s : %dPV, %dPM", monstres1.nomMonstre, monstres1.pvMonstre, monstres1.pmMonstre); if (monstres1.poisonMonstre == 1) { printf("      Poison\n"); } else { printf("\n");}
        printf("%s : %dPV, %dPM", casca.nom, casca.pv, casca.pm); if (casca.poison == 1) { printf("     Poison\n"); } else { printf("\n"); }
        printf("%s : %dPV, %dPM", griffith.nom, griffith.pv, griffith.pm); if (griffith.poison == 1) { printf("    Poison\n"); } else { printf("\n"); }
        printf("%s : %dPV, %dPM", uvin.nom, uvin.pv, uvin.pm); if (uvin.poison == 1) { printf("     Poison\n"); } else { printf("\n"); }
        printf("====================================================================================\n");
        printf("\n");

}
    printf("Souhaitez-vous rejouer/continuer l'aventure. 0 pour continuer, 1 pour arreter\n");
      scanf("%d", &continuer);
        if (continuer == 1){
          printf("Merci d'avoir jouer\n");
            return 0;
    }


}
}
