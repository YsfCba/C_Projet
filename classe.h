#include <stdio.h>
#include <string.h> // pour les chaines de caractères
#include "eleve.h"


#ifndef CLASSE_H
#define CLASSE_H


#define MAXELEVE 2 //sert à pouvoir changer le nombre maximum d'élève dans une classe sans avoir à toucher à tout le code

struct classe
{
    char niveau[10];
    char maitresse[20];
    int nb_eleve;
    struct eleve tab_eleve[MAXELEVE]; //tableau pour avoir la liste des élèves de la classe et les informations correspondantes à chaque élève
};

void RemplirClasse(struct classe *C); //sert à saisir une classe

void ImprimerClasse(struct classe C); //afficher une classe

#endif