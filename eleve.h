#include <stdio.h>
#include <string.h>
#include "date.h"

#ifndef ELEVE_H
#define ELEVE_H

// definition de structure 
struct eleve
{
   char nom[20];    /* nom éleve */
   char prenom[20]; /* prénom éleve  */

   int date_jour;
   int date_mois;
   int date_an;

};

void AfficherEleve(struct eleve E); //sert à afficher un élève
void SaisirEleve(struct eleve *E); //sert à saisir les informations d'un élève
void AffecterEleve(struct eleve *NewEleve); //sert à entrer les informations d'un nouvel élève
void AfficherEleve1(struct eleve Ek);
#endif
