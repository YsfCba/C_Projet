#include "classe.h"

void RemplirClasse(struct classe *C)
{ int i;
printf("Saisir le nom de la maitresse : ");
scanf("%s", C->maitresse);
printf("Saisir le niveau de la classe : ");
scanf("%s", C->niveau);
  for(i=0; i < MAXELEVE ;i++)
    {
  	SaisirEleve(&C->tab_eleve[i]);
    }
	
}

void ImprimerClasse(struct classe C)
{ int i;
printf("La maitresse est : %s.\n", C.maitresse);
printf("Classe de %s.\n", C.niveau);
  for(i=0; i < MAXELEVE ;i++)
  	{
      AfficherEleve1(C.tab_eleve[i]);
    }
printf("Il y a %d élèves dans la classe.",i);
}
