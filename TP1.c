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
  int cible;
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
  int mini;
  int maxi;
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
  int choixMonstre2;
  int choixMonstre3;
  int choixMonstre4;
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
  int continuer = 0;
//Choix du nombre d'ennemis
  printf("Combien d'ennemis voulez-vous affronter ? (Entre 1 et 4 ennemis possibles.)\n");
  scanf("%d", &nbreEnnemis);
  while (nbreEnnemis < 1 || nbreEnnemis > 4) {
    scanf("%d", &nbreEnnemis);
  }
    if (nbreEnnemis == 1) {
      printf("Vous avez choisit d'affonter un seul ennemis. Auriez-vous peur ?\n");
//Choix de l'ennemi si 1 seul choisit
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

        //Choix si 2 ennemis choisit

    } else if (nbreEnnemis == 2) {
      printf("Vous avez choisit d'affonter deux ennemis.\n");
      printf("Quel monstres souhaitez-vous affronter ?\n");
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
        printf("Choisissez le deuxieme monstre.\n");
          while (choixMonstre2 < 0 || choixMonstre2 > 4) {
              scanf("%d", &choixMonstre2);
            }
              if (choixMonstre2 == 0) {
                printf("Preparez-vous aussi a affronter le %s\n", soldat.nomMonstre);
                monstres2 = soldat;
              } else if (choixMonstre2 == 1) {
                printf("Preparez-vous aussi a affronter l'%s\n", abeille.nomMonstre);
                monstres2 = abeille;
              } else if (choixMonstre2 == 2) {
                printf("Preparez-vous aussi a affronter le %s\n", flan.nomMonstre);
                monstres2 = flan;
              } else if (choixMonstre2 == 3) {
                printf("Preparez-vous aussi a affronter le %s\n", morbol.nomMonstre);
                monstres2 = morbol;
              } else if (choixMonstre2 == 4) {
                printf("Preparez-vous aussi a affronter la %s\n", wyverne.nomMonstre);
                monstres2 = wyverne;
              }

              //Choix si ennemis x3

    } else if (nbreEnnemis == 3) {
      printf("Vous avez choisit d'affonter trois ennemis. Vous etes temeraires ?\n");
      printf("Quel monstres souhaitez-vous affronter ?\n");
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
          printf("Choisissez le deuxieme monstre.\n");
            while (choixMonstre2 < 0 || choixMonstre2 > 4) {
                scanf("%d", &choixMonstre2);
              }
                if (choixMonstre2 == 0) {
                  printf("Preparez-vous aussi a affronter le %s\n", soldat.nomMonstre);
                  monstres2 = soldat;
                } else if (choixMonstre2 == 1) {
                  printf("Preparez-vous aussi a affronter l'%s\n", abeille.nomMonstre);
                  monstres2 = abeille;
                } else if (choixMonstre2 == 2) {
                  printf("Preparez-vous aussi a affronter le %s\n", flan.nomMonstre);
                  monstres2 = flan;
                } else if (choixMonstre2 == 3) {
                  printf("Preparez-vous aussi a affronter le %s\n", morbol.nomMonstre);
                  monstres2 = morbol;
                } else if (choixMonstre2 == 4) {
                  printf("Preparez-vous aussi a affronter la %s\n", wyverne.nomMonstre);
                  monstres2 = wyverne;
                }
                  printf("Choisissez le troisieme monstre.\n");
                  printf("%d\n", choixMonstre3);
                    scanf("%d", &choixMonstre3);
                    while (choixMonstre3 < 0 || choixMonstre3 > 4) {
                        scanf("%d", &choixMonstre3);
                      }
                        if (choixMonstre3 == 0) {
                          printf("Preparez-vous aussi a affronter le %s\n", soldat.nomMonstre);
                          monstres3 = soldat;
                        } else if (choixMonstre3 == 1) {
                          printf("Preparez-vous aussi a affronter l'%s\n", abeille.nomMonstre);
                          monstres3 = abeille;
                        } else if (choixMonstre3 == 2) {
                          printf("Preparez-vous aussi a affronter le %s\n", flan.nomMonstre);
                          monstres3 = flan;
                        } else if (choixMonstre3 == 3) {
                          printf("Preparez-vous aussi a affronter le %s\n", morbol.nomMonstre);
                          monstres3 = morbol;
                        } else if (choixMonstre3 == 4) {
                          printf("Preparez-vous aussi a affronter la %s\n", wyverne.nomMonstre);
                          monstres3 = wyverne;
                        }



    } else if (nbreEnnemis == 4) {
      printf("Vous avez choisit d'affonter quatre ennemis. Bon courage.\n");
      printf("Quel monstres souhaitez-vous affronter ?\n");
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
            printf("Choisissez le deuxieme monstre.\n");
              while (choixMonstre2 < 0 || choixMonstre2 > 4) {
                  scanf("%d", &choixMonstre2);
                }
                  if (choixMonstre2 == 0) {
                    printf("Preparez-vous aussi a affronter le %s\n", soldat.nomMonstre);
                    monstres2 = soldat;
                  } else if (choixMonstre2 == 1) {
                    printf("Preparez-vous aussi a affronter l'%s\n", abeille.nomMonstre);
                    monstres2 = abeille;
                  } else if (choixMonstre2 == 2) {
                    printf("Preparez-vous aussi a affronter le %s\n", flan.nomMonstre);
                    monstres2 = flan;
                  } else if (choixMonstre2 == 3) {
                    printf("Preparez-vous aussi a affronter le %s\n", morbol.nomMonstre);
                    monstres2 = morbol;
                  } else if (choixMonstre2 == 4) {
                    printf("Preparez-vous aussi a affronter la %s\n", wyverne.nomMonstre);
                    monstres2 = wyverne;
                  }
                    printf("Choisissez le troisieme monstre.\n");
                    scanf("%d", &choixMonstre3);
                      while (choixMonstre3 < 0 || choixMonstre3 > 4) {
                          scanf("%d", &choixMonstre3);
                        }
                          if (choixMonstre3 == 0) {
                            printf("Et votre troisieme adversaire sera le %s\n", soldat.nomMonstre);
                            monstres3 = soldat;
                          } else if (choixMonstre3 == 1) {
                            printf("Et votre troisieme adversaire sera l'%s\n", abeille.nomMonstre);
                            monstres3 = abeille;
                          } else if (choixMonstre3 == 2) {
                            printf("Et votre troisieme adversaire sera le %s\n", flan.nomMonstre);
                            monstres3 = flan;
                          } else if (choixMonstre3 == 3) {
                            printf("Et votre troisieme adversaire sera le %s\n", morbol.nomMonstre);
                            monstres3 = morbol;
                          } else if (choixMonstre3 == 4) {
                            printf("Et votre troisieme adversaire sera la %s\n", wyverne.nomMonstre);
                            monstres3 = wyverne;
                          }

                              printf("Choisissez le dernier monstre.\n");
                              scanf("%d", &choixMonstre4);
                                while (choixMonstre4 < 0 || choixMonstre4 > 4) {
                                    scanf("%d", &choixMonstre4);
                                  }
                                    if (choixMonstre4 == 0) {
                                      printf("Et votre dernier adversaire sera le %s\n", soldat.nomMonstre);
                                      monstres4 = soldat;
                                    } else if (choixMonstre4 == 1) {
                                      printf("Et votre dernier adversaire sera l'%s\n", abeille.nomMonstre);
                                      monstres4 = abeille;
                                    } else if (choixMonstre4 == 2) {
                                      printf("Et votre dernier adversaire sera le %s\n", flan.nomMonstre);
                                      monstres4 = flan;
                                    } else if (choixMonstre4 == 3) {
                                      printf("Et votre dernier adversaire sera le %s\n", morbol.nomMonstre);
                                      monstres4 = morbol;
                                    } else if (choixMonstre4 == 4) {
                                      printf("Et votre dernier adversaire sera la %s\n", wyverne.nomMonstre);
                                      monstres4 = wyverne;
                                    }
                          }










Sleep(2000);
system("cls");

// Tant que personne n'a plus de PV faire :
    while (FinPartie == 0) {
Color(15,0);
      // Changement des consignes si le monstre est déjà empoisonné ou non.
        if (monstres1.poisonMonstre == 1 && monstres2.poisonMonstre == 1 && monstres3.poisonMonstre == 1 && monstres4.poisonMonstre == 1) {
        printf("Choisissez d'attaquer ou de defendre, 0 pour attaquer, 1 pour defendre, 3 pour utiliser un antidote.\n");
      } else if (monstres1.poisonMonstre == 1 && monstres2.poisonMonstre == 1 && monstres3.poisonMonstre == 1 && monstres4.poisonMonstre == 1 && (nbreAntidote == 0)) {
        printf("Choisissez d'attaquer ou de defendre, 0 pour attaquer, 1 pour defendre.\n");
      } else if (nbreAntidote == 0) {
        printf("Choisissez d'attaquer ou de defendre, 0 pour attaquer, 1 pour defendre, 2 pour utiliser le sort Poison.\n");
      }{
        printf("Choisissez d'attaquer ou de defendre, 0 pour attaquer, 1 pour defendre, 2 pour utiliser le sort Poison, 3 pour utiliser un antidote.\n");
      }


      // Demander à l'utilisateur d'entrer la commande voulue.
      if (guts.pv >0) {
        printf("Que dois faire %s ?\n", guts.nom);
        scanf("%d", &guts.attaqueOuDefense);
          if (guts.attaqueOuDefense == 0 || guts.attaqueOuDefense == 2){
            if (nbreEnnemis == 2) {
              printf("Choisissez la cible pour %s, 1 pour %s, 2 pour %s.\n", guts.nom, monstres1.nomMonstre, monstres2.nomMonstre);
              scanf("%d", &guts.cible);
            }
                if (nbreEnnemis == 3) {
                  printf("Choisissez la cible pour %s, 1 pour %s, 2 pour %s, 3 pour %s.\n", guts.nom, monstres1.nomMonstre, monstres2.nomMonstre, monstres3.nomMonstre);
                  scanf("%d", &guts.cible);
                }
                    if (nbreEnnemis == 4) {
                      printf("Choisissez la cible pour %s, 1 pour %s, 2 pour %s, 3 pour %s, 4 pour %s.\n", guts.nom, monstres1.nomMonstre, monstres2.nomMonstre, monstres3.nomMonstre, monstres4.nomMonstre);
                      scanf("%d", &guts.cible);
                    } else if (nbreEnnemis == 1) {
                      guts.cible = 1;
                    }
        }
      }

      if (casca.pv >0) {
        printf("Que dois faire %s ?\n", casca.nom);
        scanf("%d", &casca.attaqueOuDefense);
          if (casca.attaqueOuDefense == 0 || casca.attaqueOuDefense == 2) {
            if (nbreEnnemis == 2) {
              printf("Choisissez la cible pour %s, 1 pour %s, 2 pour %s.\n", casca.nom, monstres1.nomMonstre, monstres2.nomMonstre);
              scanf("%d", &casca.cible);
            }
                if (nbreEnnemis == 3) {
                  printf("Choisissez la cible pour %s, 1 pour %s, 2 pour %s, 3 pour %s.\n", casca.nom, monstres1.nomMonstre, monstres2.nomMonstre, monstres3.nomMonstre);
                  scanf("%d", &casca.cible);
                }
                    if (nbreEnnemis == 4) {
                      printf("Choisissez la cible pour %s, 1 pour %s, 2 pour %s, 3 pour %s, 4 pour %s.\n", casca.nom, monstres1.nomMonstre, monstres2.nomMonstre, monstres3.nomMonstre, monstres4.nomMonstre);
                      scanf("%d", &casca.cible);
                    } else if (nbreEnnemis == 1) {
                      casca.cible = 1;
                    }
          }
      }

      if (griffith.pv >0) {
        printf("Que dois faire %s ?\n", griffith.nom);
        scanf("%d", &griffith.attaqueOuDefense);
          if (griffith.attaqueOuDefense == 0 || griffith.attaqueOuDefense == 2) {
            if (nbreEnnemis == 2) {
              printf("Choisissez la cible pour %s, 1 pour %s, 2 pour %s.\n", griffith.nom, monstres1.nomMonstre, monstres2.nomMonstre);
              scanf("%d", &griffith.cible);
            }
                if (nbreEnnemis == 3) {
                  printf("Choisissez la cible pour %s, 1 pour %s, 2 pour %s, 3 pour %s.\n", griffith.nom, monstres1.nomMonstre, monstres2.nomMonstre, monstres3.nomMonstre);
                  scanf("%d", &griffith.cible);
                }
                    if (nbreEnnemis == 4) {
                      printf("Choisissez la cible pour %s, 1 pour %s, 2 pour %s, 3 pour %s, 4 pour %s.\n", griffith.nom, monstres1.nomMonstre, monstres2.nomMonstre, monstres3.nomMonstre, monstres4.nomMonstre);
                      scanf("%d", &griffith.cible);
                    } else if (nbreEnnemis == 1) {
                      griffith.cible = 1;
                    }
        }
      }

      if (uvin.pv >0) {
        printf("Que dois faire %s ?\n", uvin.nom);
        scanf("%d", &uvin.attaqueOuDefense);
          if (uvin.attaqueOuDefense == 0 || uvin.attaqueOuDefense == 2) {
            if (nbreEnnemis == 2) {
              printf("Choisissez la cible pour %s, 1 pour %s, 2 pour %s.\n", uvin.nom, monstres1.nomMonstre, monstres2.nomMonstre);
              scanf("%d", &uvin.cible);
            }
                if (nbreEnnemis == 3) {
                  printf("Choisissez la cible pour %s, 1 pour %s, 2 pour %s, 3 pour %s.\n", uvin.nom, monstres1.nomMonstre, monstres2.nomMonstre, monstres3.nomMonstre);
                  scanf("%d", &uvin.cible);
                }
                    if (nbreEnnemis == 4) {
                      printf("Choisissez la cible pour %s, 1 pour %s, 2 pour %s, 3 pour %s, 4 pour %s.\n", uvin.nom, monstres1.nomMonstre, monstres2.nomMonstre, monstres3.nomMonstre, monstres4.nomMonstre);
                      scanf("%d", &uvin.cible);
                    } else if (nbreEnnemis == 1) {
                      uvin.cible = 1;
                    }
          }
      }

int MAX;
int MIN;
      //aléatoire du monstre1
    if (monstres1.pvMonstre > 0){
      if (monstres1.pmMonstre >= 15) {
        monstres1.maxi = 2, monstres1.mini = 0;
        srand(time(NULL));
          monstres1.attaqueOuDefenseDuMonstre = (rand() %(monstres1.maxi - monstres1.mini + 1)) + monstres1.mini;
      }
       // Si Guts est déja empoisonné ou si les PM du monstre sont inférieur à 15, le monstre ne peut plus utiliser poison.
      if ((guts.poison == 1 && casca.poison == 1 && griffith.poison == 1 && uvin.poison == 1) || (monstres1.pmMonstre < 15)) {
        monstres1.maxi = 1, monstres1.mini = 0;
            while (monstres1.attaqueOuDefenseDuMonstre == 2) {
              srand(time(NULL));
              monstres1.attaqueOuDefenseDuMonstre = (rand() %(monstres1.maxi - monstres1.mini + 1)) + monstres1.mini;
          }
      }
    }
              //aléatoire du monstre2
            if ((nbreEnnemis > 1) && (monstres2.pvMonstre > 0)){
              if (monstres2.pmMonstre >= 15) {
                monstres2.maxi = 2, monstres2.mini = 0;
                srand(time(NULL));
                  monstres2.attaqueOuDefenseDuMonstre = (rand() %(monstres2.maxi - monstres2.mini + 1)) + monstres2.mini;
              }
               // Si Guts est déja empoisonné ou si les PM du monstre sont inférieur à 15, le monstre ne peut plus utiliser poison.
              if ((guts.poison == 1 && casca.poison == 1 && griffith.poison == 1 && uvin.poison == 1) || (monstres2.pmMonstre < 15)) {
                monstres2.maxi = 1, monstres2.mini = 0;
                    while (monstres2.attaqueOuDefenseDuMonstre == 2) {
                      srand(time(NULL));
                      monstres2.attaqueOuDefenseDuMonstre = (rand() %(monstres2.maxi - monstres2.mini + 1)) + monstres2.mini;
                  }
              }
            }
                        //aléatoire du monstre3
                      if ((nbreEnnemis > 2) && (monstres3.pvMonstre > 0)){
                        if (monstres3.pmMonstre >= 15) {
                          monstres3.maxi = 2, monstres3.mini = 0;
                          srand(time(NULL));
                            monstres3.attaqueOuDefenseDuMonstre = (rand() %(monstres3.maxi - monstres3.mini + 1)) + monstres2.mini;
                        }
                         // Si Guts est déja empoisonné ou si les PM du monstre sont inférieur à 15, le monstre ne peut plus utiliser poison.
                        if ((guts.poison == 1 && casca.poison == 1 && griffith.poison == 1 && uvin.poison == 1) || (monstres3.pmMonstre < 15)) {
                          monstres3.maxi = 1, monstres3.mini = 0;
                              while (monstres3.attaqueOuDefenseDuMonstre == 2) {
                                srand(time(NULL));
                                monstres3.attaqueOuDefenseDuMonstre = (rand() %(monstres3.maxi - monstres3.mini + 1)) + monstres3.mini;
                            }
                        }
                      }
                                    //aléatoire du monstre4
                                  if ((nbreEnnemis == 4) && (monstres4.pvMonstre > 0)){
                                    if (monstres4.pmMonstre >= 15) {
                                      monstres4.maxi = 2, monstres4.mini = 0;
                                      srand(time(NULL));
                                        monstres4.attaqueOuDefenseDuMonstre = (rand() %(monstres4.maxi - monstres4.mini + 1)) + monstres4.mini;
                                    }
                                     // Si Guts est déja empoisonné ou si les PM du monstre sont inférieur à 15, le monstre ne peut plus utiliser poison.
                                    if ((guts.poison == 1 && casca.poison == 1 && griffith.poison == 1 && uvin.poison == 1) || (monstres4.pmMonstre < 15)) {
                                      monstres4.maxi = 1, monstres4.mini = 0;
                                          while (monstres4.attaqueOuDefenseDuMonstre == 2) {
                                            srand(time(NULL));
                                            monstres4.attaqueOuDefenseDuMonstre = (rand() %(monstres4.maxi - monstres4.mini + 1)) + monstres4.mini;
                                        }
                                    }
                                  }



      // Cible aléatoire du/des monstres
      int MAX2 = 3, MIN2 = 0;
      srand(time(NULL));
    if (monstres1.pvMonstre > 0){
      monstres1.cibleAleatoireMonstre = (rand() %(MAX2 - MIN2 + 1)) + MIN2;
    }
    if ((nbreEnnemis > 1) && (monstres2.pvMonstre > 0)){
      monstres2.cibleAleatoireMonstre = (rand() %(MAX2 - MIN2 + 1)) + MIN2;
    }
    if ((nbreEnnemis) > 2 && (monstres3.pvMonstre > 0)){
      monstres3.cibleAleatoireMonstre = (rand() %(MAX2 - MIN2 + 1)) + MIN2;
    }
    if ((nbreEnnemis) > 3 && (monstres4.pvMonstre > 0)){
      monstres4.cibleAleatoireMonstre = (rand() %(MAX2 - MIN2 + 1)) + MIN2;
    }



// Si monstre defend attaque/4
      if (monstres1.attaqueOuDefenseDuMonstre == 1) {
        if (guts.cible == 1) {
          guts.attaque = guts.attaque/4;
        }
        if (casca.cible == 1) {
          casca.attaque = casca.attaque/4;
        }
        if (griffith.cible == 1) {
          griffith.attaque = griffith.attaque/4;
        }
        if (uvin.cible == 1) {
          uvin.attaque = uvin.attaque/4;
        }
      }

        if (monstres2.attaqueOuDefenseDuMonstre == 1) {
          if (guts.cible == 2) {
            guts.attaque = guts.attaque/4;
          }
          if (casca.cible == 2) {
            casca.attaque = casca.attaque/4;
          }
          if (griffith.cible == 2) {
            griffith.attaque = griffith.attaque/4;
          }
          if (uvin.cible == 2) {
            uvin.attaque = uvin.attaque/4;
          }
        }

          if (monstres3.attaqueOuDefenseDuMonstre == 1) {
            if (guts.cible == 3) {
              guts.attaque = guts.attaque/4;
            }
            if (casca.cible == 3) {
              casca.attaque = casca.attaque/4;
            }
            if (griffith.cible == 3) {
              griffith.attaque = griffith.attaque/4;
            }
            if (uvin.cible == 3) {
              uvin.attaque = uvin.attaque/4;
            }
          }

            if (monstres4.attaqueOuDefenseDuMonstre == 1) {
              if (guts.cible == 4) {
                guts.attaque = guts.attaque/4;
              }
              if (casca.cible == 4) {
                casca.attaque = casca.attaque/4;
              }
              if (griffith.cible == 4) {
                griffith.attaque = griffith.attaque/4;
              }
              if (uvin.cible == 4) {
                uvin.attaque = uvin.attaque/4;
              }
            }

      // Tour de Guts
  Color(1,0);
      if (guts.attaqueOuDefense == 0) {
        printf("Guts choisit d'attaquer\n");
        if (guts.cible == 1) {
          printf("Guts attaque %s!\n", monstres1.nomMonstre);
            if ( monstres1.attaqueOuDefenseDuMonstre == 1) {
              printf("%s se defend et reduit les degats !\n", monstres1.nomMonstre);
            }

            printf("%s subit %d degats\n", monstres1.nomMonstre, guts.attaque);
            monstres1.pvMonstre = monstres1.pvMonstre-guts.attaque;
            printf("Il reste %d PV au %s !\n", monstres1.pvMonstre, monstres1.nomMonstre);
                if (monstres1.pvMonstre <= 0){
                  printf("%s meurt\n", monstres1.nomMonstre);
                }
        } else

          if (guts.cible == 2) {
            printf("Guts attaque %s!\n", monstres2.nomMonstre);
            if ( monstres2.attaqueOuDefenseDuMonstre == 1) {
              printf("%s se defend et reduit les degats !\n", monstres2.nomMonstre);
            }

            printf("%s subit %d degats\n", monstres2.nomMonstre, guts.attaque);
            monstres2.pvMonstre = monstres2.pvMonstre-guts.attaque;
            printf("Il reste %d PV au %s !\n", monstres2.pvMonstre, monstres2.nomMonstre);
                if (monstres2.pvMonstre <= 0){
                  printf("%s meurt\n", monstres2.nomMonstre);
                }
          } else

              if (guts.cible == 3) {
                printf("Guts attaque %s!\n", monstres3.nomMonstre);
                if ( monstres3.attaqueOuDefenseDuMonstre == 1) {
                  printf("%s se defend et reduit les degats !\n", monstres3.nomMonstre);
                }

                printf("%s subit %d degats\n", monstres3.nomMonstre, guts.attaque);
                monstres3.pvMonstre = monstres3.pvMonstre-guts.attaque;
                printf("Il reste %d PV au %s !\n", monstres3.pvMonstre, monstres3.nomMonstre);
                    if (monstres3.pvMonstre <= 0){
                      printf("%s meurt\n", monstres3.nomMonstre);
                    }
              } else

                  if (guts.cible == 4) {
                    printf("Guts attaque %s!\n", monstres4.nomMonstre);
                    if ( monstres4.attaqueOuDefenseDuMonstre == 1) {
                      printf("%s se defend et reduit les degats !\n", monstres4.nomMonstre);
                    }

                    printf("%s subit %d degats\n", monstres4.nomMonstre, guts.attaque);
                    monstres4.pvMonstre = monstres4.pvMonstre-guts.attaque;
                    printf("Il reste %d PV au %s !\n", monstres4.pvMonstre, monstres4.nomMonstre);
                        if (monstres4.pvMonstre <= 0){
                          printf("%s meurt\n", monstres4.nomMonstre);
                        }
                  }

     }
// DEFENSE
      if (guts.attaqueOuDefense == 1) {
        printf("Guts se defend et reduit les degats\n");
          if (monstres1.cibleAleatoireMonstre == 0) {
          monstres1.attaqueMonstre = monstres1.attaqueMonstre/4;
          } else {
          monstres1.attaqueMonstre = monstres1.attaqueMonstre;
        }
            if (monstres2.cibleAleatoireMonstre == 0) {
            monstres2.attaqueMonstre = monstres2.attaqueMonstre/4;
            } else {
            monstres2.attaqueMonstre = monstres2.attaqueMonstre;
          }
              if (monstres3.cibleAleatoireMonstre == 0) {
              monstres3.attaqueMonstre = monstres3.attaqueMonstre/4;
              } else {
              monstres3.attaqueMonstre = monstres3.attaqueMonstre;
            }
                if (monstres4.cibleAleatoireMonstre == 0) {
                monstres4.attaqueMonstre = monstres4.attaqueMonstre/4;
                } else {
                monstres4.attaqueMonstre = monstres4.attaqueMonstre;
              }
      }

      if (guts.attaqueOuDefense == 2) {
        if (guts.pm < 15) {
          printf("Que dois faire %s ?\n", guts.nom);
          scanf("%d", &guts.attaqueOuDefense);
        }
          if (guts.cible == 1) {
            printf("Guts utilise le sort poison !\n");
            printf("%s est empoisonne.\n", monstres1.nomMonstre);
            guts.pm = guts.pm -15;
            printf("Il reste %d PM a Guts\n", guts.pm);
            monstres1.poisonMonstre = 1;
          }
              if (guts.cible == 2) {
                printf("Guts utilise le sort poison !\n");
                printf("%s est empoisonne.\n", monstres2.nomMonstre);
                guts.pm = guts.pm -15;
                printf("Il reste %d PM a Guts\n", guts.pm);
                monstres2.poisonMonstre = 1;
              }
                if (guts.cible == 3) {
                  printf("Guts utilise le sort poison !\n");
                  printf("%s est empoisonne.\n", monstres3.nomMonstre);
                  guts.pm = guts.pm -15;
                  printf("Il reste %d PM a Guts\n", guts.pm);
                  monstres3.poisonMonstre = 1;
                }
                    if (guts.cible == 4) {
                      printf("Guts utilise le sort poison !\n");
                      printf("%s est empoisonne.\n", monstres4.nomMonstre);
                      guts.pm = guts.pm -15;
                      printf("Il reste %d PM a Guts\n", guts.pm);
                      monstres4.poisonMonstre = 1;
                    }
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
        if (casca.cible == 1) {
          printf("Casca attaque %s!\n", monstres1.nomMonstre);
            if ( monstres1.attaqueOuDefenseDuMonstre == 1) {
              printf("%s se defend et reduit les degats !\n", monstres1.nomMonstre);
            }

            printf("%s subit %d degats\n", monstres1.nomMonstre, casca.attaque);
            monstres1.pvMonstre = monstres1.pvMonstre-casca.attaque;
            printf("Il reste %d PV au %s !\n", monstres1.pvMonstre, monstres1.nomMonstre);
                if (monstres1.pvMonstre <= 0){
                  printf("%s meurt\n", monstres1.nomMonstre);
                }
        }

          if (casca.cible == 2) {
            printf("Casca attaque %s!\n", monstres2.nomMonstre);
            if ( monstres2.attaqueOuDefenseDuMonstre == 1) {
              printf("%s se defend et reduit les degats !\n", monstres2.nomMonstre);
            }

            printf("%s subit %d degats\n", monstres2.nomMonstre, casca.attaque);
            monstres2.pvMonstre = monstres2.pvMonstre-casca.attaque;
            printf("Il reste %d PV au %s !\n", monstres2.pvMonstre, monstres2.nomMonstre);
                if (monstres2.pvMonstre <= 0){
                  printf("%s meurt\n", monstres2.nomMonstre);
                }
          }

              if (casca.cible == 3) {
                printf("Casca attaque %s!\n", monstres3.nomMonstre);
                if ( monstres3.attaqueOuDefenseDuMonstre == 1) {
                  printf("%s se defend et reduit les degats !\n", monstres3.nomMonstre);
                }

                printf("%s subit %d degats\n", monstres3.nomMonstre, casca.attaque);
                monstres3.pvMonstre = monstres3.pvMonstre-casca.attaque;
                printf("Il reste %d PV au %s !\n", monstres3.pvMonstre, monstres3.nomMonstre);
                    if (monstres3.pvMonstre <= 0){
                      printf("%s meurt\n", monstres3.nomMonstre);
                    }
              }

                  if (casca.cible == 4) {
                    printf("Casca attaque %s!\n", monstres4.nomMonstre);
                    if ( monstres4.attaqueOuDefenseDuMonstre == 1) {
                      printf("%s se defend et reduit les degats !\n", monstres4.nomMonstre);
                    }

                    printf("%s subit %d degats\n", monstres4.nomMonstre, casca.attaque);
                    monstres4.pvMonstre = monstres4.pvMonstre-casca.attaque;
                    printf("Il reste %d PV au %s !\n", monstres4.pvMonstre, monstres4.nomMonstre);
                        if (monstres4.pvMonstre <= 0){
                          printf("%s meurt\n", monstres4.nomMonstre);
                        }
                  }
      }

      if (casca.attaqueOuDefense == 1) {
        printf("Casca se defend et reduit les degats\n");
        if (monstres1.cibleAleatoireMonstre == 1) {
        monstres1.attaqueMonstre = monstres1.attaqueMonstre/4;
        } else {
        monstres1.attaqueMonstre = monstres1.attaqueMonstre;
      }
          if (monstres2.cibleAleatoireMonstre == 1) {
          monstres2.attaqueMonstre = monstres2.attaqueMonstre/4;
          } else {
          monstres2.attaqueMonstre = monstres2.attaqueMonstre;
        }
            if (monstres3.cibleAleatoireMonstre == 1) {
            monstres3.attaqueMonstre = monstres3.attaqueMonstre/4;
            } else {
            monstres3.attaqueMonstre = monstres3.attaqueMonstre;
          }
              if (monstres4.cibleAleatoireMonstre == 1) {
              monstres4.attaqueMonstre = monstres4.attaqueMonstre/4;
              } else {
              monstres4.attaqueMonstre = monstres4.attaqueMonstre;
            }
      }

      if (casca.attaqueOuDefense == 2) {
        if (casca.pm < 15) {
          printf("Que dois faire %s ?\n", casca.nom);
          scanf("%d", &casca.attaqueOuDefense);
        }

        if (casca.cible == 1) {
          printf("Casca utilise le sort poison !\n");
          printf("%s est empoisonne.\n", monstres1.nomMonstre);
          casca.pm = casca.pm -15;
          printf("Il reste %d PM a casca\n", casca.pm);
          monstres1.poisonMonstre = 1;
        }
            if (casca.cible == 2) {
              printf("Casca utilise le sort poison !\n");
              printf("%s est empoisonne.\n", monstres2.nomMonstre);
              casca.pm = casca.pm -15;
              printf("Il reste %d PM a casca\n", casca.pm);
              monstres2.poisonMonstre = 1;
            }
              if (casca.cible == 3) {
                printf("Casca utilise le sort poison !\n");
                printf("%s est empoisonne.\n", monstres3.nomMonstre);
                casca.pm = casca.pm -15;
                printf("Il reste %d PM a Casca\n", casca.pm);
                monstres3.poisonMonstre = 1;
              }
                  if (casca.cible == 4) {
                    printf("Casca utilise le sort poison !\n");
                    printf("%s est empoisonne.\n", monstres4.nomMonstre);
                    casca.pm = casca.pm -15;
                    printf("Il reste %d PM a casca\n", casca.pm);
                    monstres4.poisonMonstre = 1;
                  }
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
        if (griffith.cible == 1) {
          printf("Griffith attaque %s!\n", monstres1.nomMonstre);
            if ( monstres1.attaqueOuDefenseDuMonstre == 1) {
              printf("%s se defend et reduit les degats !\n", monstres1.nomMonstre);
            }

            printf("%s subit %d degats\n", monstres1.nomMonstre, griffith.attaque);
            monstres1.pvMonstre = monstres1.pvMonstre-griffith.attaque;
            printf("Il reste %d PV au %s !\n", monstres1.pvMonstre, monstres1.nomMonstre);
                if (monstres1.pvMonstre <= 0){
                  printf("%s meurt\n", monstres1.nomMonstre);
                }
        }

          if (griffith.cible == 2) {
            printf("Griffith attaque %s!\n", monstres2.nomMonstre);
            if ( monstres2.attaqueOuDefenseDuMonstre == 1) {
              printf("%s se defend et reduit les degats !\n", monstres2.nomMonstre);
            }

            printf("%s subit %d degats\n", monstres2.nomMonstre, griffith.attaque);
            monstres2.pvMonstre = monstres2.pvMonstre-griffith.attaque;
            printf("Il reste %d PV au %s !\n", monstres2.pvMonstre, monstres2.nomMonstre);
                if (monstres2.pvMonstre <= 0){
                  printf("%s meurt\n", monstres2.nomMonstre);
                }
          }

              if (griffith.cible == 3) {
                printf("Griffith attaque %s!\n", monstres3.nomMonstre);
                if ( monstres3.attaqueOuDefenseDuMonstre == 1) {
                  printf("%s se defend et reduit les degats !\n", monstres3.nomMonstre);
                }

                printf("%s subit %d degats\n", monstres3.nomMonstre, griffith.attaque);
                monstres3.pvMonstre = monstres3.pvMonstre-griffith.attaque;
                printf("Il reste %d PV au %s !\n", monstres3.pvMonstre, monstres3.nomMonstre);
                    if (monstres3.pvMonstre <= 0){
                      printf("%s meurt\n", monstres3.nomMonstre);
                    }
              }

                  if (griffith.cible == 4) {
                    printf("Griffith attaque %s!\n", monstres4.nomMonstre);
                    if ( monstres4.attaqueOuDefenseDuMonstre == 1) {
                      printf("%s se defend et reduit les degats !\n", monstres4.nomMonstre);
                    }

                    printf("%s subit %d degats\n", monstres4.nomMonstre, griffith.attaque);
                    monstres4.pvMonstre = monstres4.pvMonstre-griffith.attaque;
                    printf("Il reste %d PV au %s !\n", monstres4.pvMonstre, monstres4.nomMonstre);
                        if (monstres4.pvMonstre <= 0){
                          printf("%s meurt\n", monstres4.nomMonstre);
                        }
                  }
      }

      if (griffith.attaqueOuDefense == 1) {
        printf("Griffith se defend et reduit les degats\n");
        if (monstres1.cibleAleatoireMonstre == 2) {
        monstres1.attaqueMonstre = monstres1.attaqueMonstre/4;
        } else {
        monstres1.attaqueMonstre = monstres1.attaqueMonstre;
      }
          if (monstres2.cibleAleatoireMonstre == 2) {
          monstres2.attaqueMonstre = monstres2.attaqueMonstre/4;
          } else {
          monstres2.attaqueMonstre = monstres2.attaqueMonstre;
        }
            if (monstres3.cibleAleatoireMonstre == 2) {
            monstres3.attaqueMonstre = monstres3.attaqueMonstre/4;
            } else {
            monstres3.attaqueMonstre = monstres3.attaqueMonstre;
          }
              if (monstres4.cibleAleatoireMonstre == 2) {
              monstres4.attaqueMonstre = monstres4.attaqueMonstre/4;
              } else {
              monstres4.attaqueMonstre = monstres4.attaqueMonstre;
            }
      }

      if (griffith.attaqueOuDefense == 2) {

        if (griffith.pm < 15) {
          printf("Que dois faire %s ?\n", griffith.nom);
          scanf("%d", &griffith.attaqueOuDefense);
        }

        if (griffith.cible == 1) {
          printf("Griffith utilise le sort poison !\n");
          printf("%s est empoisonne.\n", monstres1.nomMonstre);
          griffith.pm = griffith.pm -15;
          printf("Il reste %d PM a griffith\n", griffith.pm);
          monstres1.poisonMonstre = 1;
        }
            if (griffith.cible == 2) {
              printf("Griffith utilise le sort poison !\n");
              printf("%s est empoisonne.\n", monstres2.nomMonstre);
              griffith.pm = griffith.pm -15;
              printf("Il reste %d PM a griffith\n", griffith.pm);
              monstres2.poisonMonstre = 1;
            }
              if (griffith.cible == 3) {
                printf("Griffith utilise le sort poison !\n");
                printf("%s est empoisonne.\n", monstres3.nomMonstre);
                griffith.pm = griffith.pm -15;
                printf("Il reste %d PM a griffith\n", griffith.pm);
                monstres3.poisonMonstre = 1;
              }
                  if (griffith.cible == 4) {
                    printf("Griffith utilise le sort poison !\n");
                    printf("%s est empoisonne.\n", monstres4.nomMonstre);
                    griffith.pm = griffith.pm -15;
                    printf("Il reste %d PM a griffith\n", griffith.pm);
                    monstres4.poisonMonstre = 1;
                  }
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
        if (uvin.cible == 1) {
          printf("Uvin attaque %s!\n", monstres1.nomMonstre);
            if ( monstres1.attaqueOuDefenseDuMonstre == 1) {
              printf("%s se defend et reduit les degats !\n", monstres1.nomMonstre);
            }

            printf("%s subit %d degats\n", monstres1.nomMonstre, uvin.attaque);
            monstres1.pvMonstre = monstres1.pvMonstre-uvin.attaque;
            printf("Il reste %d PV au %s !\n", monstres1.pvMonstre, monstres1.nomMonstre);
                if (monstres1.pvMonstre <= 0){
                  printf("%s meurt\n", monstres1.nomMonstre);
                }
        }

          if (uvin.cible == 2) {
            printf("Uvin attaque %s!\n", monstres2.nomMonstre);
            if ( monstres2.attaqueOuDefenseDuMonstre == 1) {
              printf("%s se defend et reduit les degats !\n", monstres2.nomMonstre);
            }

            printf("%s subit %d degats\n", monstres2.nomMonstre, uvin.attaque);
            monstres2.pvMonstre = monstres2.pvMonstre-uvin.attaque;
            printf("Il reste %d PV au %s !\n", monstres2.pvMonstre, monstres2.nomMonstre);
                if (monstres2.pvMonstre <= 0){
                  printf("%s meurt\n", monstres2.nomMonstre);
                }
          }

              if (uvin.cible == 3) {
                printf("Uvin attaque %s!\n", monstres3.nomMonstre);
                if ( monstres3.attaqueOuDefenseDuMonstre == 1) {
                  printf("%s se defend et reduit les degats !\n", monstres3.nomMonstre);
                }

                printf("%s subit %d degats\n", monstres3.nomMonstre, uvin.attaque);
                monstres3.pvMonstre = monstres3.pvMonstre-uvin.attaque;
                printf("Il reste %d PV au %s !\n", monstres3.pvMonstre, monstres3.nomMonstre);
                    if (monstres3.pvMonstre <= 0){
                      printf("%s meurt\n", monstres3.nomMonstre);
                    }
              }

                  if (uvin.cible == 4) {
                    printf("Uvin attaque %s!\n", monstres4.nomMonstre);
                    if ( monstres4.attaqueOuDefenseDuMonstre == 1) {
                      printf("%s se defend et reduit les degats !\n", monstres4.nomMonstre);
                    }

                    printf("%s subit %d degats\n", monstres4.nomMonstre, uvin.attaque);
                    monstres4.pvMonstre = monstres4.pvMonstre-uvin.attaque;
                    printf("Il reste %d PV au %s !\n", monstres4.pvMonstre, monstres4.nomMonstre);
                        if (monstres4.pvMonstre <= 0){
                          printf("%s meurt\n", monstres4.nomMonstre);
                        }
                  }
      }

      if (uvin.attaqueOuDefense == 1) {
        printf("Uvin se defend et reduit les degats\n");
        if (monstres1.cibleAleatoireMonstre == 3) {
        monstres1.attaqueMonstre = monstres1.attaqueMonstre/4;
        } else {
        monstres1.attaqueMonstre = monstres1.attaqueMonstre;
      }
          if (monstres2.cibleAleatoireMonstre == 3) {
          monstres2.attaqueMonstre = monstres2.attaqueMonstre/4;
          } else {
          monstres2.attaqueMonstre = monstres2.attaqueMonstre;
        }
            if (monstres3.cibleAleatoireMonstre == 3) {
            monstres3.attaqueMonstre = monstres3.attaqueMonstre/4;
            } else {
            monstres3.attaqueMonstre = monstres3.attaqueMonstre;
          }
              if (monstres4.cibleAleatoireMonstre == 3) {
              monstres4.attaqueMonstre = monstres4.attaqueMonstre/4;
              } else {
              monstres4.attaqueMonstre = monstres4.attaqueMonstre;
            }
      }

      if (uvin.attaqueOuDefense == 2) {
        if (uvin.pm < 15) {
          printf("Que dois faire %s ?\n", uvin.nom);
          scanf("%d", &uvin.attaqueOuDefense);
        }

        if (uvin.cible == 1) {
        printf("Uvin utilise le sort poison !\n");
        printf("%s est empoisonne.\n", monstres1.nomMonstre);
        uvin.pm = uvin.pm -15;
        printf("Il reste %d PM a Uvin\n", uvin.pm);
        monstres1.poisonMonstre = 1;
      }
          if (uvin.cible == 2) {
            printf("Uvin utilise le sort poison !\n");
            printf("%s est empoisonne.\n", monstres2.nomMonstre);
            uvin.pm = uvin.pm -15;
            printf("Il reste %d PM a Uvin\n", uvin.pm);
            monstres2.poisonMonstre = 1;
          }
            if (uvin.cible == 3) {
              printf("Uvin utilise le sort poison !\n");
              printf("%s est empoisonne.\n", monstres3.nomMonstre);
              uvin.pm = uvin.pm -15;
              printf("Il reste %d PM a Uvin\n", uvin.pm);
              monstres3.poisonMonstre = 1;
            }
                if (uvin.cible == 4) {
                  printf("Uvin utilise le sort poison !\n");
                  printf("%s est empoisonne.\n", monstres4.nomMonstre);
                  uvin.pm = uvin.pm -15;
                  printf("Il reste %d PM a Uvin\n", uvin.pm);
                  monstres4.poisonMonstre = 1;
                }
      }


      if (uvin.attaqueOuDefense == 3) {
        printf("Uvin se soigne du poison.\n");
        uvin.poison = 0;
        nbreAntidote = nbreAntidote-1;
        printf("Il vous reste %d antidote.\n", nbreAntidote);
      }

// Tour du monstre
Color(5,0);
if (monstres1.pvMonstre > 0){
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
}

// Tour monstre2
if (nbreEnnemis > 1 && monstres2.pvMonstre > 0){
          if (monstres2.attaqueOuDefenseDuMonstre == 0) {
            printf("%s attaque !\n", monstres2.nomMonstre);
              if (monstres2.cibleAleatoireMonstre == 0) {
                printf("Guts subit %d degats\n", monstres2.attaqueMonstre);
                guts.pv = guts.pv-monstres2.attaqueMonstre;
                printf("Il reste %d PV a Guts !\n", guts.pv);
                      if (guts.pv <= 0) {
                        printf("Guts decede.\n");
                      }
              } else if (monstres2.cibleAleatoireMonstre == 1) {
                printf("Casca subit %d degats\n", monstres2.attaqueMonstre);
                casca.pv = casca.pv-monstres2.attaqueMonstre;
                printf("Il reste %d PV a Casca !\n", casca.pv);
                      if (casca.pv <= 0) {
                        printf("Casca decede.\n");
                      }
              } else if (monstres2.cibleAleatoireMonstre == 2) {
                printf("Griffith subit %d degats\n", monstres2.attaqueMonstre);
                griffith.pv = griffith.pv-monstres2.attaqueMonstre;griffith;
                printf("Il reste %d PV a Griffith !\n", griffith.pv);
                      if (griffith.pv <= 0) {
                        printf("Griffith decede.\n");
                      }
              } else if (monstres2.cibleAleatoireMonstre == 3) {
                printf("Uvin subit %d degats\n", monstres2.attaqueMonstre);
                uvin.pv = uvin.pv-monstres2.attaqueMonstre;griffith;
                printf("Il reste %d PV a Uvin !\n", uvin.pv);
                      if (uvin.pv <= 0) {
                        printf("Uvin decede.\n");
                        }
              }

          }

          if ( monstres2.attaqueOuDefenseDuMonstre == 1) {
            printf("%s se defend.\n", monstres2.nomMonstre);
          }
          // Attaque poison du monstre
          if (monstres2.attaqueOuDefenseDuMonstre == 2) {
            if (monstres2.pmMonstre > 0) {
              printf("%s utilise Poison\n", monstres2.nomMonstre);
                if (monstres2.cibleAleatoireMonstre == 0) {
                  if (guts.pv > 0 && guts.poison == 0) {
                    printf("Guts est empoisonne !\n");
                    monstres2.pmMonstre = monstres2.pmMonstre-15;
                    guts.poison = 1;
                    printf("Il reste %d PM au %s.\n", monstres2.pmMonstre, monstres2.nomMonstre);
                } else {
                    while ((monstres2.cibleAleatoireMonstre != 1) || (monstres2.cibleAleatoireMonstre !=2) || (monstres2.cibleAleatoireMonstre !=3)) {
                        monstres2.cibleAleatoireMonstre = (rand() %(MAX2 - MIN2 + 1)) + MIN2;
                    }
              }
            } else if (monstres2.cibleAleatoireMonstre == 1) {
                if (casca.pv > 0 && casca.poison == 0) {
                  printf("Casca est empoisonne !\n");
                  monstres2.pmMonstre = monstres2.pmMonstre-15;
                  casca.poison = 1;
                  printf("Il reste %d PM au %s.\n", monstres2.pmMonstre, monstres2.nomMonstre);
                } else {
                    while ((monstres2.cibleAleatoireMonstre != 0) || (monstres2.cibleAleatoireMonstre !=2) || (monstres2.cibleAleatoireMonstre !=3)) {
                        monstres2.cibleAleatoireMonstre = (rand() %(MAX2 - MIN2 + 1)) + MIN2;
                    }
              }
            } else if (monstres2.cibleAleatoireMonstre == 2) {
                if (griffith.pv > 0 && griffith.poison == 0) {
                  printf("Griffith est empoisonne !\n");
                  monstres2.pmMonstre = monstres2.pmMonstre-15;
                  griffith.poison = 1;
                  printf("Il reste %d PM au %s.\n", monstres2.pmMonstre, monstres2.nomMonstre);
                } else {
                    while ((monstres2.cibleAleatoireMonstre != 0) || (monstres2.cibleAleatoireMonstre !=1) || (monstres2.cibleAleatoireMonstre !=3)) {
                        monstres2.cibleAleatoireMonstre = (rand() %(MAX2 - MIN2 + 1)) + MIN2;
                      }
                }
              } else if (monstres2.cibleAleatoireMonstre == 3) {
                  if (uvin.pv > 0 && uvin.poison == 0) {
                    printf("Uvin est empoisonne !\n");
                    monstres2.pmMonstre = monstres2.pmMonstre-15;
                    uvin.poison = 1;
                    printf("Il reste %d PM au %s.\n", monstres2.pmMonstre, monstres2.nomMonstre);
                  } else {
                      while ((monstres2.cibleAleatoireMonstre != 0) || (monstres2.cibleAleatoireMonstre !=1) || (monstres2.cibleAleatoireMonstre !=2)) {
                          monstres2.cibleAleatoireMonstre = (rand() %(MAX2 - MIN2 + 1)) + MIN2;
                      }
                }
              }


          }
          }
}
// Tour monstre3
if (nbreEnnemis > 2 && monstres3.pvMonstre > 0){
          if (monstres3.attaqueOuDefenseDuMonstre == 0) {
            printf("%s attaque !\n", monstres3.nomMonstre);
              if (monstres3.cibleAleatoireMonstre == 0) {
                printf("Guts subit %d degats\n", monstres3.attaqueMonstre);
                guts.pv = guts.pv-monstres3.attaqueMonstre;
                printf("Il reste %d PV a Guts !\n", guts.pv);
                      if (guts.pv <= 0) {
                        printf("Guts decede.\n");
                      }
              } else if (monstres3.cibleAleatoireMonstre == 1) {
                printf("Casca subit %d degats\n", monstres3.attaqueMonstre);
                casca.pv = casca.pv-monstres3.attaqueMonstre;
                printf("Il reste %d PV a Casca !\n", casca.pv);
                      if (casca.pv <= 0) {
                        printf("Casca decede.\n");
                      }
              } else if (monstres3.cibleAleatoireMonstre == 2) {
                printf("Griffith subit %d degats\n", monstres3.attaqueMonstre);
                griffith.pv = griffith.pv-monstres3.attaqueMonstre;griffith;
                printf("Il reste %d PV a Griffith !\n", griffith.pv);
                      if (griffith.pv <= 0) {
                        printf("Griffith decede.\n");
                      }
              } else if (monstres3.cibleAleatoireMonstre == 3) {
                printf("Uvin subit %d degats\n", monstres3.attaqueMonstre);
                uvin.pv = uvin.pv-monstres3.attaqueMonstre;griffith;
                printf("Il reste %d PV a Uvin !\n", uvin.pv);
                      if (uvin.pv <= 0) {
                        printf("Uvin decede.\n");
                        }
              }

          }

          if ( monstres3.attaqueOuDefenseDuMonstre == 1) {
            printf("%s se defend.\n", monstres3.nomMonstre);
          }
    // Attaque poison du monstre
          if (monstres3.attaqueOuDefenseDuMonstre == 2) {
            if (monstres3.pmMonstre > 0) {
              printf("%s utilise Poison\n", monstres3.nomMonstre);
                if (monstres3.cibleAleatoireMonstre == 0) {
                  if (guts.pv > 0 && guts.poison == 0) {
                    printf("Guts est empoisonne !\n");
                    monstres3.pmMonstre = monstres3.pmMonstre-15;
                    guts.poison = 1;
                    printf("Il reste %d PM au %s.\n", monstres3.pmMonstre, monstres3.nomMonstre);
                } else {
                    while ((monstres3.cibleAleatoireMonstre != 1) || (monstres3.cibleAleatoireMonstre !=2) || (monstres3.cibleAleatoireMonstre !=3)) {
                        monstres3.cibleAleatoireMonstre = (rand() %(MAX2 - MIN2 + 1)) + MIN2;
                    }
              }
            } else if (monstres3.cibleAleatoireMonstre == 1) {
                if (casca.pv > 0 && casca.poison == 0) {
                  printf("Casca est empoisonne !\n");
                  monstres3.pmMonstre = monstres3.pmMonstre-15;
                  casca.poison = 1;
                  printf("Il reste %d PM au %s.\n", monstres3.pmMonstre, monstres3.nomMonstre);
                } else {
                    while ((monstres3.cibleAleatoireMonstre != 0) || (monstres3.cibleAleatoireMonstre !=2) || (monstres3.cibleAleatoireMonstre !=3)) {
                        monstres3.cibleAleatoireMonstre = (rand() %(MAX2 - MIN2 + 1)) + MIN2;
                    }
              }
            } else if (monstres3.cibleAleatoireMonstre == 2) {
                if (griffith.pv > 0 && griffith.poison == 0) {
                  printf("Griffith est empoisonne !\n");
                  monstres3.pmMonstre = monstres3.pmMonstre-15;
                  griffith.poison = 1;
                  printf("Il reste %d PM au %s.\n", monstres3.pmMonstre, monstres3.nomMonstre);
                } else {
                    while ((monstres3.cibleAleatoireMonstre != 0) || (monstres3.cibleAleatoireMonstre !=1) || (monstres3.cibleAleatoireMonstre !=3)) {
                        monstres3.cibleAleatoireMonstre = (rand() %(MAX2 - MIN2 + 1)) + MIN2;
                      }
                }
              } else if (monstres3.cibleAleatoireMonstre == 3) {
                  if (uvin.pv > 0 && uvin.poison == 0) {
                    printf("Uvin est empoisonne !\n");
                    monstres3.pmMonstre = monstres3.pmMonstre-15;
                    uvin.poison = 1;
                    printf("Il reste %d PM au %s.\n", monstres3.pmMonstre, monstres3.nomMonstre);
                  } else {
                      while ((monstres3.cibleAleatoireMonstre != 0) || (monstres3.cibleAleatoireMonstre !=1) || (monstres3.cibleAleatoireMonstre !=2)) {
                          monstres3.cibleAleatoireMonstre = (rand() %(MAX2 - MIN2 + 1)) + MIN2;
                      }
                }
              }


        }
      }
}
// Tour monstre4
if (nbreEnnemis == 4 && monstres4.pvMonstre > 0){
      if (monstres4.attaqueOuDefenseDuMonstre == 0) {
        printf("%s attaque !\n", monstres4.nomMonstre);
          if (monstres4.cibleAleatoireMonstre == 0) {
            printf("Guts subit %d degats\n", monstres4.attaqueMonstre);
            guts.pv = guts.pv-monstres4.attaqueMonstre;
            printf("Il reste %d PV a Guts !\n", guts.pv);
                  if (guts.pv <= 0) {
                    printf("Guts decede.\n");
                  }
          } else if (monstres4.cibleAleatoireMonstre == 1) {
            printf("Casca subit %d degats\n", monstres4.attaqueMonstre);
            casca.pv = casca.pv-monstres4.attaqueMonstre;
            printf("Il reste %d PV a Casca !\n", casca.pv);
                  if (casca.pv <= 0) {
                    printf("Casca decede.\n");
                  }
          } else if (monstres4.cibleAleatoireMonstre == 2) {
            printf("Griffith subit %d degats\n", monstres4.attaqueMonstre);
            griffith.pv = griffith.pv-monstres4.attaqueMonstre;griffith;
            printf("Il reste %d PV a Griffith !\n", griffith.pv);
                  if (griffith.pv <= 0) {
                    printf("Griffith decede.\n");
                  }
          } else if (monstres4.cibleAleatoireMonstre == 3) {
            printf("Uvin subit %d degats\n", monstres4.attaqueMonstre);
            uvin.pv = uvin.pv-monstres4.attaqueMonstre;griffith;
            printf("Il reste %d PV a Uvin !\n", uvin.pv);
                  if (uvin.pv <= 0) {
                    printf("Uvin decede.\n");
                    }
          }

      }

      if ( monstres4.attaqueOuDefenseDuMonstre == 1) {
        printf("%s se defend.\n", monstres4.nomMonstre);
      }
// Attaque poison du monstre
      if (monstres4.attaqueOuDefenseDuMonstre == 2) {
        if (monstres4.pmMonstre > 0) {
          printf("%s utilise Poison\n", monstres4.nomMonstre);
            if (monstres4.cibleAleatoireMonstre == 0) {
              if (guts.pv > 0 && guts.poison == 0) {
                printf("Guts est empoisonne !\n");
                monstres4.pmMonstre = monstres4.pmMonstre-15;
                guts.poison = 1;
                printf("Il reste %d PM au %s.\n", monstres4.pmMonstre, monstres4.nomMonstre);
            } else {
                while ((monstres4.cibleAleatoireMonstre != 1) || (monstres4.cibleAleatoireMonstre !=2) || (monstres4.cibleAleatoireMonstre !=3)) {
                    monstres4.cibleAleatoireMonstre = (rand() %(MAX2 - MIN2 + 1)) + MIN2;
                }
          }
        } else if (monstres4.cibleAleatoireMonstre == 1) {
            if (casca.pv > 0 && casca.poison == 0) {
              printf("Casca est empoisonne !\n");
              monstres4.pmMonstre = monstres4.pmMonstre-15;
              casca.poison = 1;
              printf("Il reste %d PM au %s.\n", monstres4.pmMonstre, monstres4.nomMonstre);
            } else {
                while ((monstres4.cibleAleatoireMonstre != 0) || (monstres4.cibleAleatoireMonstre !=2) || (monstres4.cibleAleatoireMonstre !=3)) {
                    monstres4.cibleAleatoireMonstre = (rand() %(MAX2 - MIN2 + 1)) + MIN2;
                }
          }
        } else if (monstres4.cibleAleatoireMonstre == 2) {
            if (griffith.pv > 0 && griffith.poison == 0) {
              printf("Griffith est empoisonne !\n");
              monstres4.pmMonstre = monstres4.pmMonstre-15;
              griffith.poison = 1;
              printf("Il reste %d PM au %s.\n", monstres4.pmMonstre, monstres4.nomMonstre);
            } else {
                while ((monstres4.cibleAleatoireMonstre != 0) || (monstres4.cibleAleatoireMonstre !=1) || (monstres4.cibleAleatoireMonstre !=3)) {
                    monstres4.cibleAleatoireMonstre = (rand() %(MAX2 - MIN2 + 1)) + MIN2;
                  }
            }
          } else if (monstres4.cibleAleatoireMonstre == 3) {
              if (uvin.pv > 0 && uvin.poison == 0) {
                printf("Uvin est empoisonne !\n");
                monstres4.pmMonstre = monstres4.pmMonstre-15;
                uvin.poison = 1;
                printf("Il reste %d PM au %s.\n", monstres4.pmMonstre, monstres4.nomMonstre);
              } else {
                  while ((monstres4.cibleAleatoireMonstre != 0) || (monstres4.cibleAleatoireMonstre !=1) || (monstres4.cibleAleatoireMonstre !=2)) {
                      monstres4.cibleAleatoireMonstre = (rand() %(MAX2 - MIN2 + 1)) + MIN2;
                  }
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

                }
        }
            if (monstres2.poisonMonstre == 1) {
              printf("%s subit des degats du poison.\n", monstres2.nomMonstre);
              monstres2.pvMonstre = monstres2.pvMonstre - 2;
              printf("Il reste %d PV au %s !\n", monstres2.pvMonstre, monstres2.nomMonstre);
                    if (monstres2.pvMonstre <= 0){
                      printf("%s meurt\n", monstres2.nomMonstre);

                    }
            }
                if (monstres3.poisonMonstre == 1) {
                  printf("%s subit des degats du poison.\n", monstres3.nomMonstre);
                  monstres3.pvMonstre = monstres3.pvMonstre - 2;
                  printf("Il reste %d PV au %s !\n", monstres3.pvMonstre, monstres3.nomMonstre);
                        if (monstres3.pvMonstre <= 0){
                          printf("%s meurt\n", monstres3.nomMonstre);

                        }
                }
                    if (monstres4.poisonMonstre == 1) {
                      printf("%s subit des degats du poison.\n", monstres4.nomMonstre);
                      monstres4.pvMonstre = monstres4.pvMonstre - 2;
                      printf("Il reste %d PV au %s !\n", monstres4.pvMonstre, monstres4.nomMonstre);
                            if (monstres4.pvMonstre <= 0){
                              printf("%s meurt\n", monstres4.nomMonstre);

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

// Condition de fin de combat
    if (nbreEnnemis == 1 && monstres1.pvMonstre <= 0) {
        FinPartie =1;
    }
      if (nbreEnnemis == 2 && (monstres1.pvMonstre && monstres2.pvMonstre == 0)) {
        FinPartie =1;
      }
          if (nbreEnnemis == 3 && (monstres1.pvMonstre && monstres2.pvMonstre && monstres3.pvMonstre == 0)) {
            FinPartie =1;
          }
              if (nbreEnnemis == 4 && (monstres1.pvMonstre && monstres2.pvMonstre && monstres3.pvMonstre && monstres4.pvMonstre == 0)) {
                FinPartie =1;
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
        printf("%s : %dPV, %dPM", casca.nom, casca.pv, casca.pm); if (casca.poison == 1) { printf("     Poison\n"); } else { printf("\n"); } if (nbreEnnemis > 1){ printf("                             %s : %dPV, %dPM", monstres2.nomMonstre, monstres2.pvMonstre, monstres2.pmMonstre); if (monstres2.poisonMonstre == 1) { printf("      Poison\n"); } else { printf("\n");}}
        printf("%s : %dPV, %dPM", griffith.nom, griffith.pv, griffith.pm); if (griffith.poison == 1) { printf("    Poison\n"); } else { printf("\n"); } if (nbreEnnemis > 2){ printf("                             %s : %dPV, %dPM", monstres3.nomMonstre, monstres3.pvMonstre, monstres3.pmMonstre); if (monstres3.poisonMonstre == 1) { printf("      Poison\n"); } else { printf("\n");}}
        printf("%s : %dPV, %dPM", uvin.nom, uvin.pv, uvin.pm); if (uvin.poison == 1) { printf("     Poison\n"); } else { printf("\n"); } if(nbreEnnemis == 4){ printf("                             %s : %dPV, %dPM", monstres4.nomMonstre, monstres4.pvMonstre, monstres4.pmMonstre); if (monstres4.poisonMonstre == 1) { printf("      Poison\n"); } else { printf("\n");}}
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
