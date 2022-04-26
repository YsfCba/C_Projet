#include "ecole.h"


//fonction qui permet de saisir l'école entièrement: le nom de l'école, chaque classe avec le nom de la maîtresse, le niveau et la liste des élèves
void RemplirEcole(struct ecole *E)   //pointeur * car on change le contenu d'un paramètre : saisie
{
    int i;
    int j;
    printf ("Saisir le nom de l'école : ");
    scanf ("%s", E-> nom_ecole);
    printf("\n");

    //cette boucle i permet de parcourir les différentes classes
    printf("Veuillez saisir les classes du CP au CM2 dans l'ordre.\n");
    for (i=0; i<MAXCLASSE; i++)
    {
        printf("-----------classe %d-------------\n",i+1);      //on peut remplacer par la fonction (remplir_classe)
        
  
        printf("entrer le nom de la maitresse : ");
        scanf ("%s", E -> tab_classe[i].maitresse);
        printf("entrer le niveau de la classe : ");
        scanf ("%s", E -> tab_classe[i].niveau);
    

        for(j=0; j<MAXELEVE; j++) // la boucle j pour remplir les informations de chaque élève du tableau d'élèves d'une classe
       {
       SaisirEleve(&E->tab_classe[i].tab_eleve[j]); 
        
        /* printf("Saisissez l'identité de l'élève %d au format: \nNom Prénom jj/mm/aaaa \n",j+1);
        scanf("%s %s %d/%d/%d", E->tab_classe[i].tab_eleve[j].nom, E->tab_classe[i].tab_eleve[j].prenom, &E->tab_classe[i].tab_eleve[j].date_jour, &E->tab_classe[i].tab_eleve[j].date_mois, &E->tab_classe[i].tab_eleve[j].date_an);
        */}
                    //on peut remplacer par la fonction (affecter_eleve)
    }
}


// cette fonction premet d'afficher toute l'école (affichage du nom de l'école et de toutes classes et de tous les élèves de chaque classe)
void AfficherEcole(struct ecole E){
 
    int i, j; 
    printf("\n");
    printf("\n");
    printf("\n Nom de l'école : %s\n", E.nom_ecole); 

    for(i=0; i<MAXCLASSE; i++)
    {
        printf("----------classe %d----------\n", i+1);
        printf("Nom de la maitresse : %s \n", E.tab_classe[i].maitresse);
        printf("Niveau : %s \n", E.tab_classe[i].niveau);
        printf("\n");
        
        for(j=0; j<MAXELEVE; j++)
        {
        printf("Elève %d : %s %s %d/%d/%d \n",j+1, E.tab_classe[i].tab_eleve[j].nom, E.tab_classe[i].tab_eleve[j].prenom, E.tab_classe[i].tab_eleve[j].date_jour, E.tab_classe[i].tab_eleve[j].date_mois, E.tab_classe[i].tab_eleve[j].date_an);   
        }
        printf("\n");
    }
}

void LireClasseNiveau(struct ecole E)
{
int niv;

    printf ("Saisissez 1 pour lire la classe CP, 2 pour le CE1, 3 pour le CE2, 4 pour le CM1 et 5 pour le CM2 : ");
    scanf("%d", &niv);

    if (niv==1) 
    {
        printf("\n--------Classe de CP------------.\n");   
        ImprimerClasse(E.tab_classe[0]); // je saisis la classe dans la tab_classe[0] qui correspond au CP  
    }
    if (niv==2) 
    {
        printf("\n--------Classe de CE1------------\n");   
        ImprimerClasse(E.tab_classe[1]); // je saisis la classe dans la tab_classe[0] qui correspond au CP  
    }
     if (niv==3) 
    {
        printf("\n--------Classe de CE2------------\n");   
        ImprimerClasse(E.tab_classe[2]); // je saisis la classe dans la tab_classe[0] qui correspond au CP  
    }
     if (niv==4) 
    {
        printf("\n--------Classe de CM1------------\n");   
        ImprimerClasse(E.tab_classe[3]); // je saisis la classe dans la tab_classe[0] qui correspond au CP  
    }
     if (niv==5) 
    {
        printf("\n--------Classe de CM2------------\n");   
        ImprimerClasse(E.tab_classe[4]); // je saisis la classe dans la tab_classe[0] qui correspond au CP  
    }
}


//fonction qui permet d'affecter un élève dans le niveau qui lui correspond selon sa date de naissance
void AffecterNiveau(struct ecole *E)
{
int annee;

        printf ("Saisissez l'année de naissance du nouvel élève : \n");
        printf("INFORMATION :\n");
        printf(" 2015 -> CP\t 2014 -> CE1\t 2013-> CE2\t 2012->CM1\t 2011-> CM2\n");
        scanf("%d",&annee);

    if (annee==2015) // un élève nait en 2015 ira en CP
    {
        printf("L'élève sera en classe de CP.\n");   
        SaisirEleve(&E->tab_classe[0].tab_eleve); // je saisis le nouvel élève dans la tab_classe[0] qui correspond au CP  
    }

    if (annee==2014)  // un élève nait en 2014 ira en CE1
    {
        printf("L'élève sera en classe de CE1.\n");   
        SaisirEleve(&E->tab_classe[1].tab_eleve); // je saisis le nouvel élève dans la tab_classe[1] qui correspond au CE1  
    }

    if (annee==2013)    // un élève nait en 2013 ira en CE2
    {
        printf("L'élève sera en classe de CE2.\n");   
        SaisirEleve(&E->tab_classe[2].tab_eleve);   
    }

    if (annee==2012)    // un élève nait en 2014 ira en CM1
    {
        printf("L'élève sera en classe de CM1.\n");   
        SaisirEleve(&E->tab_classe[3].tab_eleve);   
    }

    if (annee==2011)    // un élève nait en 2011 ira en CM2
    {
        printf("L'élève sera en classe de CM2.\n");   
        SaisirEleve(&E->tab_classe[4].tab_eleve);   
    }

    if (annee!=2015 && annee!=2014 && annee!=2013 && annee!=2012 && annee!=2011 )
    {
        printf("L'année n'est pas correcte, l'élève doit être né entre 2011 et 2015\n");
                
    }
}



//fonction qui permet de saisir une classe selon son niveau;
void SaisirClasseNiveau(struct ecole *E)
{
int niv;
int i;
    printf ("Saisissez 1 pour remplir la classe CP, 2 pour le CE1, 3 pour le CE2, 4 pour le CM1 et 5 pour le CM2 : ");
    scanf("%d", &niv);

    if (niv==1) 
    {
        printf("\nVous pouvez compléter les informations de la classe de CP.\n");   
        RemplirClasse(&E->tab_classe[0]); // je saisis la classe dans la tab_classe[0] qui correspond au CP  
    }
    if (niv==2) 
    {
        printf("\nVous pouvez compléter les informations de la classe de CE1.\n");   
        RemplirClasse(&E->tab_classe[1]); // je saisis la classe dans la tab_classe[0] qui correspond au CP  
    }
     if (niv==3) 
    {
        printf("\nVous pouvez compléter les informations de la classe de CE2.\n");   
        RemplirClasse(&E->tab_classe[2]); // je saisis la classe dans la tab_classe[0] qui correspond au CP  
    }
     if (niv==4) 
    {
        printf("\nVous pouvez compléter les informations de la classe de CM1.\n");   
        RemplirClasse(&E->tab_classe[3]); // je saisis la classe dans la tab_classe[0] qui correspond au CP  
    }
     if (niv==5) 
    {
        printf("\nVous pouvez compléter les informations de la classe de CM2.\n");   
        RemplirClasse(&E->tab_classe[4]); // je saisis la classe dans la tab_classe[0] qui correspond au CP  
    }
}

void RechercherEleve(const struct eleve *E, struct ecole EC)
{
int i;
int j;
char prenom[26];
char nom[26];

printf("Veuillez entrer le nom et prénom de l'élève recherché : \n");
printf("Entrez le nom : ");
scanf("%s", E->nom);
printf("Entrez le prénom : ");
scanf("%s", E->prenom);

for (i=0; i<MAXCLASSE; i++)
{
    for (j=0; j<MAXELEVE; j++)
    {
        if ((strcmp(EC.tab_classe[i].tab_eleve[j].nom,E->nom)==0) && (strcmp(EC.tab_classe[i].tab_eleve[j].prenom,E->prenom)==0))
            {
            printf("L'élève est inscrit dans l'école.\n"); //pour nous donner la classe si eleve present
            return;
            }
    }
} 
printf("L'enfant n'est pas inscrit dans cette école. Nous allons l'inscrire.\n");
AffecterNiveau(&EC);
}