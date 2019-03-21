#include <stdio.h>
#include <time.h>
#include "functions.h"

int grille[9][9] = { //mise en forme selon la grille de sudokua
  {1, 0, 0,    0, 0, 7,    0, 9, 0},
  {0, 3, 0,    0, 2, 0,    0, 0 ,8},
  {0, 0, 9,    6, 0, 0,    5, 0 ,0},

  {0, 0, 5,    3, 0, 0,    9, 0, 0},
  {0, 1, 0,    0, 8, 0,    0, 0, 2},
  {6, 0, 0,    0, 0, 4,    0, 0, 0},

  {3, 0, 0,    0, 0, 0,    0, 1, 0},
  {0, 4, 0,    0, 0, 0,    0, 0, 7},
  {0, 0, 7,    0, 0, 0,    3, 0, 0},
};

int main(){
  printf("Grille non resolue : \n");
  afficher_jeu(grille);
  clock_t t1, t2;
  float temps;
  t1 = clock();
  if(resoudre2(grille, 0)){
    printf("Grille resolue : \n");
    afficher_jeu(grille);
  }
  else{
    printf("Erreur\n");
  }
  t2 = clock();
  temps = (float) (t2-t1)/CLOCKS_PER_SEC; //calcul du temps d'execution
  printf("Temps d'execution : %f secondes.\n", temps);
  return 0;
}

