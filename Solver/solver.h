#ifndef SOLVER_H
#define SOLVER_H

void affichage (int grille[9][9]);
int NotInLine (int k, int grille[9][9], int i);
int NotInColumn (int k, int grille[9][9], int j);
int NotInSquare (int k, int grille[9][9], int i, int j);
int Valid (int grille[9][9], int position);
int main (int argc,char* argv[]);
int strL(char b[]);
int IsGoodToStart (int grille[9][9]);

#endif
