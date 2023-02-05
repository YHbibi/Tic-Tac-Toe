#include <stdio.h>

void remplireVide( char M[3][3], int l, int c)
{
	int i,j;
		
		for(i=0; i<l; i++)
		{
			for(j=0; j<c; j++)
				 M[i][j]=' ';// initialiser la matrice du jeu
		}
}

// verifier si la position est deja reservée
int exist(char M[3][3], int *l, int *c)
{
	
	if ( M[(*l)-1][(*c)-1] != ' '  ) //  if ( M[(*l)-1][(*c)-1]  == 'O'  ||  M[(*l)-1][(*c)-1] == 'X' )
	{
		printf("\n\t->Cette place est occupee !\n");
		return( true );
	}
	else
		return (false );
}

void remplire(char M[3][3], int *l, int *c)
{
	printf ("\n\tQuelle est la place du votre pierre ?  : ");	
		do
		{
			printf ("\n\t\tLigne (max 3): ");
			scanf("%d", l);
			printf ("\t\tColone (max 3): ");
			scanf("%d", c);		
		}while(  (*l)<=0 || (*l)>3  || ( (*c)<=0 || (*c)>3)  || exist(M, l, c)  );
					
}

void affiche( char M[3][3], int l, int c)
{
	int i,j;
	
	puts("\n");
	for(i=0; i<l; i++)
	{
		for(j=0; j<c; j++)			
		{
			printf("|  %c  ", M[i][j] );
		}
		printf("|  \n|_________________|\n");
	  	
	}	
	puts("\n");
}

int verifVertical(char M[3][3], int c, char tour)
{
	int i=0;

		if( M[i][c] == tour )
		{
			if( M[i+1][c] == tour )
			{
				if( M[i+2][c] == tour )
				{
					return (true);		
				}
			}
		}
	return (false);		
}

int verifVerticales(char M[3][3], char tour )
{
	int j=0;
	int resultat=false;
	while(j<3 && !resultat )
	{
		resultat=verifVertical(M,j,tour);
		j++;
	}
		return (resultat);
}

int verifHorizontal(char M[3][3], int l, char tour)
{
	int i=0;

		if( M[l][i] == tour )
		{
			if( M[l][i+1] == tour )
			{
				if( M[l][i+2] == tour )
				{
					return (true);		
				}
			}
		}	
	return (false);	
}

int verifHorizontales(char M[3][3], char tour )
{
	int i=0;
	int resultat=false;
	
	while(i<3 && !resultat )
	{
		resultat=verifHorizontal(M,i,tour);
		i++;
	}
		return (resultat);
}

int verifDiagonalPrincipal(char M[3][3], char tour)
{
	int i=0;
	int j=0;

			if( M[i][j]== tour )
			{
				if( M[i+1][j+1]== tour )
				{
					if( M[i+2][j+2]== tour )
					{
						return (true);
					}
				}
			}	
	return (false);	
}

int verifDiagonalSecondaire(char M[3][3], char tour)
{
	int i=0;
	int j=2;

			if( M[i][j]== tour )
			{
				if( M[i+1][j-1]== tour )
				{
					if( M[i+2][j-2]== tour )
					{
						return (true);
					}
				}	
			}				
	return (false);	
}

int test(char M[3][3], char tour)
{
	return (  verifVerticales(M,tour)  || verifHorizontales(M,tour) || verifDiagonalPrincipal(M,tour) || verifDiagonalSecondaire(M,tour)  );

}

//P.P
int main()
{	
	int l, c;
	char tour, M[3][3];
	char player1[20], player2[20];
		
	puts("Binvenue dans le jeu de XO  :\n ");
	printf("Donner le nom du joueur qui choisit du jouer avec X : ");
	scanf("%s",player1);
	printf("Donner le nom du joueur qui choisit du jouer avec O : ");
	scanf("%s",player2);
		
	// initialisation du matrice du jeu
	remplireVide( M, 3, 3);
	
			//	tour du X
			printf("\n=>Tour du %s :",player1);
			tour='X';				
			remplire(M, &l, &c);					
			M[l-1][c-1] =tour;
			//Affichage de la matrice
			affiche( M, 3, 3);
			
	int terminer =false;
	int nbEssai=0;
	int nbEssaiMax= 3*3;
	while( nbEssai< nbEssaiMax-1 )
	{		
			// tour du O
			printf("\n=>Tour du %s :",player2);
			tour='O';
			remplire(M, &l, &c);
			M[l-1][c-1] = tour;
				terminer = test(M, tour);
				if(terminer)
				{
					printf("\n=>BRAVO ! %s gagne",player2);
					affiche( M, 3, 3);
					break;
				}
			//Affichage de la matrice
			affiche( M, 3, 3);
			
			//	tour du X
			printf("\n=>Tour du %s :",player1);
			tour='X';				
			remplire(M, &l, &c);					
			M[l-1][c-1] =tour;
				terminer = test(M, tour);
				if(terminer)
				{
					printf("\n=>BRAVO ! %s gagne",player1);
					affiche( M, 3, 3);
					break;
				}
			//Affichage de la matrice
			affiche( M, 3, 3);
			
			nbEssai += 2;		
	}
	
	if(!terminer)
		puts ("=>Match nul ! Pas de vainqueur ");			
}
