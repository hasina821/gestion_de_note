#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct etudiant()
{
	int numero;
	string nom; 
	double note[20],coefficient[20],moyenne;
};
typedef struct etudiant etudiant;

void creetab(etudiant[],int , int);
void tribulle2(etudiant[],int);
void permut(double*,double*);
void afficherEt(etudiant[],int,int);
void afficheRes(etudiant[],int);
void calMoy(etudiant[],int,int);

int main(int argc, char*argv[])

{
	int taille,tailleNotes;
	etudiant etud[150];
	printf("Saisir le nombre d'etudiant");
	scanf("%d",&taille);
	printf("Saisir nombre de note");
	scanf("%d",&tailleNotes);
	creetab(etud,taille,tailleNotes);
	afficherEt(etud,taille,tailleNotes);
	calMoy(etud,taille,tailleNotes);
	tribulle2(etud,taille);
	printf("\n--------------Resultat d'examen--------");
	afficherEt(etud,taille);
	return 0;
}

void creetab(etudiant et[],int nb,int nbNotes)
{
	int i,j;
	for(i=0;i<nb;i++)
	{
		printf("Numero?");
		scanf("%d",&(et[i].numero));
		printf("Nom?").
		scanf("%s",&(et[i].nom));
			for (j = 0; j < nbNotes; j++)
			{
				printf("Notes?");
				scanf("%lf",&(et[i].notes[j]));
				printf("coefficients?");
				scanf("%lf",&(et[i].coefficients[j]));
				
			}
	}
}
 
void afficherEt(etudiant et[],int nb,int nbNotes)
{
	int i,j;
	printf("%7s","Numero");
	printf("%30s","Nom");
	for (int i = 1; i <= nbNotes; i++)
	{
		printf("%5s%i-%12s%i","Note",i,"coefficient",i);
	}
	printf("\n");
		for(i = 0;i<nb;i++)
		{
			printf("%7d",et[i].numero);
			printf("%30s",et[i].nom);
			for(j=0;j<nbNotes;j++)
			{
				printf("%6.2lf%13.2lf",et[i].notes[j],et[i].coefficients[j]);
				printf("-------------------------------\n-----------------------------");
			}
		}
}
void calMoy(etudiant et[],int nb,int nbNotes)
{
	int i,j;
	double sNotes,sCoef;
	for (int i = 0; i < nb; ++i)
	{
		sNotes=0.0;sCoef=0.0;
		for(j=0;j<nbNotes;j++)
		{
			sNotes+=et[i].Notes[j] * et[i].coefficients[j];
			sCoef +=et[i].coefficients[j];
		}
		et[i].moyenne=sNotes/sCoef;
	}
}
void permut(double* a,double* b)
{
	double c;
	c=*a;
	*a=*b;
	*b=c;

}
void tribulle2(etudiant et[],int nb)
{
	int onapermut,i,j;
	i=1;
	onapermut=1;
	while(onapermut)
	{
		j=nb-1;
		onapermut=0;
		while(j>=i)
		{
			if (et[j-1].moyenne<=et[j].moyenne)
			{
				permut(&(et[j-1].moyenne),&(et[j].moyenne));
				permut(&(et[j-1].numero),&(et[j].numero));
				permut(&(et[j-1].nom),&(et[j].nom));
				onapermut=1;
				
			}
			
			j--;
		}

		i++;
	}
 }
