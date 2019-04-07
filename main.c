#include <stdio.h>
#include <time.h>
#include "functions.h"
#define NB_GRILLES 3

int main(){
  char nom_fichier[255];
  FILE *f = NULL;
  FILE *res = NULL;
  res = fopen("grilles_resolues/res.txt", "a");
  int nb_fichiers;
  int grille[9][9];
  clock_t t1, t2;
  float temps;
  t1 = clock();
  for(nb_fichiers = 1; nb_fichiers <= NB_GRILLES; nb_fichiers++){
    sprintf(nom_fichier, "grilles/grille%d.txt", nb_fichiers);
    f = fopen(nom_fichier, "r");
    if(!f){
      fprintf(stderr, "Erreur : fichier vide ou inexistant.\n");
    }
    else{
      int i, j, n; //i et j compteurs, n valeur que l'on met dans la grille
      for(i = 0; i < 9; i++){
        for(j = 0; j < 9; j++){
          fscanf(f, "%d", &grille[i][j]);
        }
      }
      if(resoudre2(grille, 0)){
        //printf("Grille resolue : \n");
        //afficher_jeu(grille);
        for(i = 0; i < 9; i++){
          if(i % 3 == 0){
            fprintf(res, "-------------------------\n");
          }
          for(j = 0; j < 9; j++){
            if(j % 3 == 0){
              fprintf(res, "| %d ", grille[i][j]);
            }
            else if(j == 8){
              fprintf(res, "%d |", grille[i][j]);
            }
            else{
              fprintf(res, "%d ", grille[i][j]);
            }
          }
          fprintf(res, "\n");
        }
        fprintf(res, "-------------------------\n\n\n");
      }
      else{
        printf("Erreur\n");
      }
      fclose(f);
    }
  }
  fclose(res);
  t2 = clock();
  temps = (float) (t2-t1)/CLOCKS_PER_SEC; //calcul du temps d'execution
  printf("Temps d'execution : %f secondes.\n", temps);
  return 0;
}

