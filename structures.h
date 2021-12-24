#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED

typedef struct Casedeplateau{

    int numeroCase;
    char pion;
    int nombreDePions;

}CaseDePlateau;

typedef struct Joueur{

    char pion;
    int positionPlateau;
    int soldeBancaire;

}Joueur;

#endif // STRUCTURES_H_INCLUDED
