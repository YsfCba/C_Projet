#include <stdio.h>
#include <string.h>
#include "classe.h"

#ifndef ECOLE_H
#define ECOLE_H

#define MAXCLASSE 5

/* la structure école permet d'enregistrer le nom de l'école, le nb de classes et le tableau 
qui représente chaque classe avec ses informations spécifiques, la liste de ses élèves et les 
infos sur chaque élève car il appelle un tableau de structures classe qui appelle les structures élèves*/

struct ecole
{
    char nom_ecole[20];
    int nb_classe;
    struct classe tab_classe[MAXCLASSE];
};


// voici les fonctions dont le codage se trouvent dans le fichier "ecole.c"
// chaque fonction est expliquée dans le fichier .c

void RemplirEcole(struct ecole *E); //sert à saisir l'école, c'est à dire son nom et chaques classes les unes après les autres

void AfficherEcole(struct ecole E); //sert à afficher RemplirEcole

void AffecterNiveau(struct ecole *E); // ajouter le niveau "CP, CE1, CE2, CM1, CM2"

void RechercherEleve(const struct eleve *E, struct ecole EC);  // Permet de rechecher un élève dans l'école

#endif