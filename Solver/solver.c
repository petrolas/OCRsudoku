#include <stdlib.h>
#include <stdio.h>


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



int NotInLine (int k, int grille[9][9], int i)
{
    for (int j=0; j < 9; j++)
        if (grille[i][j] == k)
            return 0;
    return 1;
}

int NotInColumn (int k, int grille[9][9], int j)
{
    for (int i=0; i < 9; i++)
        if (grille[i][j] == k)
            return 0;
    return 1;
}

int NotInSquare (int k, int grille[9][9], int i, int j)
{
    int _i = i-(i%3), _j = j-(j%3); 
    for (i=_i; i < _i+3; i++)
        for (j=_j; j < _j+3; j++)
            if (grille[i][j] == k)
                return 0;
    return 1;
}

int IsGoodToStart (int grille[9][9])
{
	for (int i=0; i<9; i++)
	{
		for (int j=0; j<9; j++)
		{
			if(grille[i][j] != 0)
			{
				//Column
				int b = 0;
				int val = grille[i][j];
				int bool = 0;
				while(b < 9 && !bool)
				{
					if (b != i)
						bool = grille[b][j] == val;
					if (b != j && !bool)
						bool = (grille[i][b] == val);
					b++;
				}
				if(bool)
					return !bool;
				if((i == 1 && j == 1) || (i == 4 && j == 1) || (i == 7 && j == 1))
				{
					bool = !(!(grille[i-1][j-1] == val) && !(grille[i-1][j] == val)&& !(grille[i-1][j+1] == val)&& !(grille[i][j-1] == val)&& !(grille[i][j+1] == val)&& !(grille[i+1][j-1] == val)&& !(grille[i+1][j] == val)&& !(grille[i+1][j+1] == val));
				}
				if(bool)
					return !bool;
				if((i == 1 && j == 4) || (i == 4 && j == 4) || (i == 7 && j == 4))
				{
					bool = !(!(grille[i-1][j-1] == val) && !(grille[i-1][j] == val)&& !(grille[i-1][j+1] == val)&& !(grille[i][j-1] == val)&& !(grille[i][j+1] == val)&& !(grille[i+1][j-1] == val)&& !(grille[i+1][j] == val)&& !(grille[i+1][j+1] == val)); 
				}
				if(bool)
					return !bool;
				if((i == 1 && j == 7) || (i == 4 && j == 7) || (i == 7 && j == 7))
				{
					bool = !(!(grille[i-1][j-1] == val) && !(grille[i-1][j] == val)&& !(grille[i-1][j+1] == val)&& !(grille[i][j-1] == val)&& !(grille[i][j+1] == val)&& !(grille[i+1][j-1] == val)&& !(grille[i+1][j] == val)&& !(grille[i+1][j+1] == val)); 
				}
				if(bool)
					return !bool;
			}
		}
	}
	return 1;
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

int Valid (int grille[9][9], int position)
{
    if (position == 9*9)
        return 1;

    int i = position/9, j = position%9;

    if (grille[i][j] != 0)
        return Valid(grille, position+1);

    for (int k=1; k <= 9; k++)
    {
        if (NotInLine(k,grille,i)&& NotInColumn(k,grille,j)&& NotInSquare(k,grille,i,j))
        {
            grille[i][j] = k;

            if ( Valid(grille, position+1))
                return 1;
        }
    }
    grille[i][j] = 0;

    return 0;
}

