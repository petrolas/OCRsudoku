#ifndef SOLVER_H
#define SOLVER_H

void affichage (int grille[9][9]);
bool NotInLine (int k, int grille[9][9], int i);
bool NotInColumn (int k, int grille[9][9], int j);
bool NotInSquare (int k, int grille[9][9], int i, int j);
bool Valid (int grille[9][9], int position);
int main (void);

#endif
