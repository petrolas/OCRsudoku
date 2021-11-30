#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "solver.h"
#include "err.h"

//gcc -Wall -Werror -Wextra -o solver solver.c main.c
// ${RM} *.result


int main (int argc,char* argv[])
{
	if(argc != 2)
   		errx(1,"Nombre d'arguments incorrect");
   		
	int grille[9][9]; //Création de la grille pour stocker les valeurs
	
    	//Ouverture du fichier
	FILE* fichier = NULL;
	fichier = fopen(argv[1], "r");
	
	if(fichier != NULL)
	{
		char ligne[12];
		int x = 0;
		//Ouvre le fichier puis remplie la grille grâce au contenu
		while((fgets(ligne,12,fichier)) != NULL)
		{
			if(strL(ligne) == 11)
			{
				int y = 0;
				for(int i = 0; i < 11;i++)
				{
					if(!(i == 3 || i ==7))
					{
						if (ligne[i] == '.')
							grille[x][y] = 0;
						else
							grille[x][y] = ligne[i] -48;
						y++;
					}
				}
				x++;
			}
		}
		fclose(fichier); //"Ferme" le fichier
		if(IsGoodToStart(grille))
		{
			Valid(grille,0); //Résoult la grille
		}
		
		//Crée le nouveau nom pour le fichier sortant
		char Rname[] = ".result";
		strcat(argv[1],Rname);
		fichier = fopen(argv[1], "w");
		
		//Fichier sortant
		char ligne2[12];
		for(int i = 0;i<9;i++)
		{
			int count = 0;
			for(int j = 0;j<9;j++)
			{
				if (j%3 == 0 && j != 0)
				{
					ligne2[count]= ' ';
					count ++;
				}
				ligne2[count] = (char)grille[i][j]+48;
				count ++;
			}
			fputs("\n",fichier);
			if (i%3 == 0 && i != 0)
				fputs("\n",fichier);
			fputs(ligne2,fichier);
		}
		fputs("\n",fichier);
		fclose(fichier);
		printf("Done !\n");
		
	}
	else
	{
		//Renvoie Erreur en cas de fichier introuvable
		errx(1,"Impossible de lire ce fichier");
		
	}
	return 0;
}
