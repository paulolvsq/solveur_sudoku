#include <stdio.h>
#include "functions.h"

int grille[9][9] = {
  {0,0,9,7,0,8,3,0,0},
  {0,2,0,6,0,0,0,4,0},
  {0,0,0,0,0,9,0,0,7},
  {0,0,8,4,0,5,6,9,0},
  {0,6,0,0,0,0,0,0,1},
  {0,0,0,0,0,0,0,0,0},
  {0,0,0,0,8,0,0,0,0},
  {0,9,0,0,2,0,4,0,3},
  {0,7,4,5,6,0,0,0,0},
};

int main(){
  printf("Grille non resolue : \n");
  afficher_jeu(grille);
  if(resoudre2(grille, 0)){
	printf("Grille resolue : \n");
	afficher_jeu(grille);
  }
  else{
	printf("Erreur\n");
  }
  return 0;
}

	  
