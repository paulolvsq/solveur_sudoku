#ifndef _F_H
#define _F_H
#include <stdio.h>

void afficher_jeu(int jeu[9][9]);
int verif_ligne(int jeu[9][9], int ligne, int chiffre);
int verif_colonne(int jeu[9][9], int colonne, int chiffre);
int verif_bloc(int jeu[9][9], int ligne, int colonne, int chiffre);
int resoudre2(int jeu[9][9], int position);
int resoudre(int jeu[9][9], int i, int j);

#endif
