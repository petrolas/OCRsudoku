#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


// Fonction d'affichage
void affichage (int grille[9][9])
{
    for (int i=0; i<9; i++)
    {
        for (int j=0; j<9; j++)
        {
            printf( ((j+1)%3) ? "%d " : "%d|", grille[i][j]);
        }
        putchar('\n');
        if (!((i+1)%3))
            puts("------------------");
    }
    puts("\n\n");
}

bool NotInLine (int k, int grille[9][9], int i)
{
    for (int j=0; j < 9; j++)
        if (grille[i][j] == k)
            return false;
    return true;
}

bool NotInColumn (int k, int grille[9][9], int j)
{
    for (int i=0; i < 9; i++)
        if (grille[i][j] == k)
            return false;
    return true;
}

bool NotInSquare (int k, int grille[9][9], int i, int j)
{
    int _i = i-(i%3), _j = j-(j%3); 
    for (i=_i; i < _i+3; i++)
        for (j=_j; j < _j+3; j++)
            if (grille[i][j] == k)
                return false;
    return true;
}


int strL(char b[])
{
	int i =0;
	int nb = 0;
	while (b[i] != (char)0)
	{
		nb++;
		i++;
	}
	return nb;
}

bool Valid (int grille[9][9], int position)
{
    if (position == 9*9)
        return true;

    int i = position/9, j = position%9;

    if (grille[i][j] != 0)
        return Valid(grille, position+1);

    for (int k=1; k <= 9; k++)
    {
        if (NotInLine(k,grille,i) && NotInColumn(k,grille,j) && NotInSquare(k,grille,i,j))
        {
            grille[i][j] = k;

            if ( Valid(grille, position+1) )
                return true;
        }
    }
    grille[i][j] = 0;

    return false;
}

