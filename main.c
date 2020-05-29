#include <stdio.h>
#include <time.h>
#include "functions.h"
#define NB_GRILLES 19

int main(){

  char nom_fichier[255];
  FILE *f = NULL;
  FILE *res = NULL;
  int nb_fichiers;
  int grille[9][9];
  clock_t t1, t2;
  float temps;

  t1 = clock();
  res = fopen("grilles_resolues/res.txt", "a");
  //pour tous les fichiers -> on a le nombre de grilles en define
  for(nb_fichiers = 1; nb_fichiers <= NB_GRILLES; nb_fichiers++){
	//on va les chercher dans le bon dossier
    sprintf(nom_fichier, "grilles/grille%d.txt", nb_fichiers);
    f = fopen(nom_fichier, "r"); //on les ouvre

    if(!f){ //si le fichier est vide ou n'existe pas 
      fprintf(stderr, "Erreur : fichier vide ou inexistant.\n");
    }

    else{ //sinon on remplit la grille avec le contenu du fichier 

	  int i, j;

      for(i = 0; i < 9; i++){
        for(j = 0; j < 9; j++){
          fscanf(f, "%d", &grille[i][j]);
        }
      }
	  //s'il est possible de résoudre la grille on la met à la suite dans un fichier res		
      if(resoudre2(grille, 0)){

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

      else{ //sinon on met une erreur
        printf("Erreur\n");
      }
      fclose(f); //on n'oublie pas de fermer le fichier courant
    }

  }

  fclose(res); //on n'oublie pas de fermer le fichier res
  t2 = clock();
  temps = (float) (t2-t1)/CLOCKS_PER_SEC; //calcul du temps d'execution
  printf("Temps d'exécution : %f secondes.\n", temps);

  return 0;
}

