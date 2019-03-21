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

int verif_ligne(int jeu[9][9], int ligne, int chiffre){ //on vérifie sur les lignes
  int i;
  for(i = 0; i < 9; i++){
    if(jeu[ligne][i] == chiffre) return 0;
  }
  return 1;
}

int verif_colonne(int jeu[9][9], int colonne, int chiffre){ //on vérifie sur les colonnes 
  int i;
  for(i = 0; i < 9; i++){
    if(jeu[i][colonne] == chiffre) return 0;
  }
  return 1;
}

int verif_bloc(int jeu[9][9], int ligne, int colonne, int chiffre){ //on vérifie sur le bloc 
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

int resoudre2(int jeu[9][9], int position){ //fonction récursive qui va résoudre la grille 
  if(position == 81){ //cas d'arrêt : on atteint la dernière case de la grille 
    return 1; //on renvoie vrai 
  }
  int ligne = position / 9; //on récupère ligne et colonne avec la division entière 
  int colonne = position % 9;
  if(jeu[ligne][colonne] != 0){ 
    return resoudre2(jeu, position + 1); //on vérifie sur chaque position si on a un 0 pour le compléter 
  }
  int chiffre;
  for(chiffre = 1; chiffre < 10; chiffre++){ //pour chaque chiffre on vérifie si on peut le placer à telle position
    if((verif_ligne(jeu, ligne, chiffre)) && (verif_colonne(jeu, colonne, chiffre)) && (verif_bloc(jeu, ligne, colonne, chiffre))){
      jeu[ligne][colonne] = chiffre; //on met le chiffre à la place dans la grille 
      if(resoudre2(jeu, position + 1)){ //si elle est bonne à la position d'après alors elle est bonne 
        return 1;
      }
    }
  }
  jeu[ligne][colonne] = 0; //sinon on remet la case à 0
  return 0;
}

int resoudre(int jeu[9][9], int i, int j){ //fonction récursive qui va résoudre la grille 
  if(j == 9){
    i++;
    j = 0; 
  }
  if((i == 9) && (j == 0)){
    return 1;
  }
  if(jeu[i][j] != 0){ 
    return resoudre(jeu, i, j + 1); //on vérifie sur chaque position si on a un 0 pour le compléter 
  }
  int chiffre;
  for(chiffre = 1; chiffre < 10; chiffre++){ //pour chaque chiffre on vérifie si on peut le placer à telle position
    if((verif_ligne(jeu, i, chiffre)) && (verif_colonne(jeu, j, chiffre)) && (verif_bloc(jeu, i, j, chiffre))){
      jeu[i][j] = chiffre; //on met le chiffre à la place dans la grille 
      if(resoudre(jeu, i, j + 1)){ //si elle est bonne à la position d'après alors elle est bonne 
        return 1;
      }
    }
  }
  jeu[i][j] = 0; //sinon on remet la case à 0
  return 0;
}
