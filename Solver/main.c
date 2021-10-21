#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "solver.h"

int main (void)
{
    int grille[9][9] =
    {
        {9,0,0,1,0,0,0,0,5},
        {0,0,5,0,9,0,2,0,1},
        {8,0,0,0,4,0,0,0,0},
        {0,0,0,0,8,0,0,0,0},
        {0,0,0,7,0,0,0,0,0},
        {0,0,0,0,2,6,0,0,9},
        {2,0,0,3,0,0,0,0,6},
        {0,0,0,2,0,0,9,0,0},
        {0,0,1,9,0,4,5,7,0}
    };

    printf("Grille avant\n");
    affichage(grille);

    Valid(grille,0);

    printf("Grille apres\n");
    affichage(grille);
}
