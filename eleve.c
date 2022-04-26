#include <stdio.h>
#include <string.h>

struct eleve
{
   char nom[20];    /* nom éleve */
   char prenom[20]; /* prénom éleve  */

   int date_jour;
   int date_mois;
   int date_an;
};

void SaisirEleve(struct eleve *Ek)
{ 
    printf("Saisir le nom de l'élève:");
    scanf("%s", Ek->nom);
    printf("Saisir le prénom :");
    scanf("%s", Ek->prenom);
    printf("Saisir la date de naissance au fomat  jj/mm/aaaa : ");
    scanf("%d/%d/%d", &Ek->date_jour,&Ek->date_mois,&Ek->date_an);
}

void AfficherEleve1(struct eleve Ek)
{
    int i;

    printf(" Le nom de l'élève est  %s le prénom est %s et sa date de naissance est  %.2d/%.2d/%d\n", Ek.nom, Ek.prenom, Ek.date_jour,Ek.date_mois,Ek.date_an);
    printf("\n");
}

void AfficherEleve(struct eleve E) //sert à lire les informations sur un élève et pouvoir les modifier si erreurs 
{   
    int i;

    printf(" Le nom de l'élève est  %s le prénom est %s et sa date de naissance est  %.2d/%.2d/%d\n", E.nom, E.prenom, E.date_jour,E.date_mois,E.date_an);
    printf("\n"); 
    
    printf("Veuillez vérifier les informations saisies, si elles sont correctes entrer 1, si elles sont incorrectes taper 0.\n");
    scanf("%d",&i);

    if (i==0) {  /* si elles sont fausse, il faut reécrire les informations  */
        SaisirEleve(&E);
        }
        
    if (i!=0) {
        printf(" L'élève est correctement inscrit dans l'école\n");
         /* sortir la modification   */
        }       
}

// cette fonction permet de saisir les informations d'un nouvel élève
void AffecterEleve(struct eleve *NewEleve)
{
    printf("\nVeuillez entrer l'identité du nouvel élève au format NOM Prénom jj/mm/aaaa : \n");
    scanf("%s %s %d/%d/%d",NewEleve->nom, NewEleve->prenom, &NewEleve-> date_jour, &NewEleve->date_mois, &NewEleve->date_an);
    printf("\nNom : %s  \nPrénom : %s  \nDate de naissance : %d/%d/%d",NewEleve->nom, NewEleve->prenom, NewEleve-> date_jour, NewEleve->date_mois, NewEleve->date_an);
}