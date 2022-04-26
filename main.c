#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "ecole.h"


int main()
{
    struct ecole JULE_FERRY;
    struct classe CP;
    struct eleve ELEVE;
    int choix;
       
// Nous avons choisi de faire un menu afin de faciliter l'utilisation de l'application, du coup on utilise un SWITCH.


    printf("--------------------------Gestion de l'école----------------------");
    printf("\n");
    printf("1. Saisir l'école\n");
    printf("2. Lire l'école\n");  
    printf("3. Saisir une classe\n"); 
    printf("4. Afficher une classe \n"); 
    printf("5. Afficher un élève\n"); 
    printf("6. Saisir un nouvel élève\n"); 
    printf("7. Rechercher un élève\n");
    printf("8. Sortir de l'application\n");
    printf("\n");

    do{
        printf("\nVoici le menu, entrer le nombre correspondant à votre choix : \n");
        scanf("%d",&choix);
        
        switch(choix)
        {
        case 1 : RemplirEcole(&JULE_FERRY);
            break;
        
        case 2 : AfficherEcole(JULE_FERRY);
            break;
        
        case 3 : SaisirClasseNiveau(&JULE_FERRY);
            break;
        
        case 4 : LireClasseNiveau(JULE_FERRY);
            break;
        
        case 5 : AfficherEleve(ELEVE);
            break;
        
        case 6 : AffecterNiveau(&JULE_FERRY);
            break;
        
        case 7 : RechercherEleve(&ELEVE, JULE_FERRY);
            break;
        
        case 8 : printf("\n");
            break;
        
        default : printf("Votre saisie est incorrecte.");
    
        }
    }while(choix!=8);
printf("Vous avez quitté l'application. Merci\n");




// Pour créer et lire le fichier .bin
{
    FILE *fichier;
    
    fichier = fopen("monecole.bin","wb");
    if (fichier != NULL)
    {
        fwrite(&JULE_FERRY,sizeof(struct ecole),1,fichier);
        fclose(fichier);
    }
    // Lecture du fichier
    fichier = fopen("monecole.bin","rb");
    if (fichier != NULL)
    {
        fread(&JULE_FERRY,sizeof(struct ecole),1,fichier);
        fclose(fichier);
    }
}    












// Pour ecrire en clair

/* {   
    int argc;
    char *arg;
    
    FILE* fichier = NULL;

    fichier = fopen("test.txt", "w");

    if (fichier != NULL)
    {
    fputc('A', fichier); // Écriture du caractère A
    fclose(fichier);
    }

    return 0;


} */

// Pour lire en claire 

/* #define TAILLE_MAX 1000

   
{
    FILE* fichierClair = NULL;
    char chaine[TAILLE_MAX] = "";
    char *champ;
    struct ecole E;

    fichier = fopen("test.xls", "r");
                                                                    
    if (fichier != NULL)
    {
      while(!feof(fichierenclair)) // je lis jusqu'à la fin
    {

    fgets(E,2000,fichierenclair);

    champ =strtok(ligne,";");
    strcpy(E ,champ);
    champ =strtok(NULL,";");
    }
    fclose(fichierClair);
    }

return 0;
} */


}
