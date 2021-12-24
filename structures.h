#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED
#include "stdbool.h"

typedef struct casedeplateau{

    int numeroCase; // � supprimer lorsque j'aurais le nom des cases ; comme j'utilise un TABLEAU, mes cases sont d�j� num�rot�s
    int proprietaireCase;   //-1 si pas de propri�taire, sinon indice du joueur proprio (entre 0 et 4)
    int typeDeCase;     //  0 : propri�t� / 1 : Chance / 2 : Communaut� / 3 : Impot / 4: Parc gratuit / 6 : D�part / 7: Prison
    int prixAchat;
    int prixLoyer;

    char nomDeCase[40];
    char proprioCase[15];   //pseudo du joueur propri�taire de la case

}t_caseDePlateau;

typedef struct joueur{

    char pion;
    char pseudo[15];
    char POSSESSIONSNOMS[28][40];

    int positionPlateau;
    int soldeBancaire;
    int POSSESSIONS[28]; //tableau d'entiers r�pertoriant toutes les propri�t�s (leur num�ro de case) d'un joueur
    int nombreDePropriete;  //nombre total de propri�t� que poss�de un joueur
    int numero; //utile ? car j'ai les indices de mon tableau de joueurs

    bool isPlayerInPrison;
}t_joueur;


#endif // STRUCTURES_H_INCLUDED
