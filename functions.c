#include <stdio.h>

void afficher_jeu(int jeu[9][9]){
  int i, j;
  for(i = 0; i < 9; i++){
    if(i % 3 == 0){
      printf("-------------------------\n");
    }
    for(j = 0; j < 9; j++){
      if(j % 3 == 0){
        printf("| %d ", jeu[i][j]);
      }
      else if(j == 8){
        printf("%d |", jeu[i][j]);
      }
      else{
        printf("%d ", jeu[i][j]);
      }
    }
    printf("\n");
  }
  printf("-------------------------\n");
}

int verif_ligne(int jeu[9][9], int ligne, int chiffre){ //on v�rifie sur les lignes
  int i;
  for(i = 0; i < 9; i++){
    if(jeu[ligne][i] == chiffre) return 0;
  }
  return 1;
}

int verif_colonne(int jeu[9][9], int colonne, int chiffre){ //on v�rifie sur les colonnes 
  int i;
  for(i = 0; i < 9; i++){
    if(jeu[i][colonne] == chiffre) return 0;
  }
  return 1;
}

int verif_bloc(int jeu[9][9], int ligne, int colonne, int chiffre){ //on v�rifie sur le bloc 
  int n_ligne = (ligne / 3) * 3;
  int n_colonne = (colonne / 3) * 3;
  int i, j;
  for(i = n_ligne; i < n_ligne + 3; i++){
    for(j = n_colonne; j < n_colonne + 3; j++){
      if(jeu[i][j] == chiffre) return 0;
    }
  }
  return 1;
}

int resoudre2(int jeu[9][9], int position){ //fonction r�cursive qui va r�soudre la grille 
  if(position == 81){ //cas d'arr�t : on atteint la derni�re case de la grille 
    return 1; //on renvoie vrai 
  }
  int ligne = position / 9; //on r�cup�re ligne et colonne avec la division enti�re 
  int colonne = position % 9;
  if(jeu[ligne][colonne] != 0){ 
    return resoudre2(jeu, position + 1); //on v�rifie sur chaque position si on a un 0 pour le compl�ter 
  }
  int chiffre;
  for(chiffre = 1; chiffre < 10; chiffre++){ //pour chaque chiffre on v�rifie si on peut le placer � telle position
    if((verif_ligne(jeu, ligne, chiffre)) && (verif_colonne(jeu, colonne, chiffre)) && (verif_bloc(jeu, ligne, colonne, chiffre))){
      jeu[ligne][colonne] = chiffre; //on met le chiffre � la place dans la grille 
      if(resoudre2(jeu, position + 1)){ //si elle est bonne � la position d'apr�s alors elle est bonne 
        return 1;
      }
    }
  }
  jeu[ligne][colonne] = 0; //sinon on remet la case � 0
  return 0;
}

int resoudre(int jeu[9][9], int i, int j){ //fonction r�cursive qui va r�soudre la grille 
  if(j == 9){
    i++;
    j = 0; 
  }
  if((i == 9) && (j == 0)){
    return 1;
  }
  if(jeu[i][j] != 0){ 
    return resoudre(jeu, i, j + 1); //on v�rifie sur chaque position si on a un 0 pour le compl�ter 
  }
  int chiffre;
  for(chiffre = 1; chiffre < 10; chiffre++){ //pour chaque chiffre on v�rifie si on peut le placer � telle position
    if((verif_ligne(jeu, i, chiffre)) && (verif_colonne(jeu, j, chiffre)) && (verif_bloc(jeu, i, j, chiffre))){
      jeu[i][j] = chiffre; //on met le chiffre � la place dans la grille 
      if(resoudre(jeu, i, j + 1)){ //si elle est bonne � la position d'apr�s alors elle est bonne 
        return 1;
      }
    }
  }
  jeu[i][j] = 0; //sinon on remet la case � 0
  return 0;
}
