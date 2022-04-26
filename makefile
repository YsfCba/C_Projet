
#cible principale
notreecole.out : main.c ecole.o classe.o eleve.o date.o
	gcc main.c ecole.o classe.o eleve.o date.o -o notreecole.out


#dependances

date.o : date.c date.h
	gcc -c date.c

eleve.o : eleve.c eleve.h date.o
	gcc -c eleve.c

classe.o : classe.c classe.h eleve.o
	gcc -c classe.c

ecole.o : ecole.c ecole.h classe.o
	gcc -c ecole.c


