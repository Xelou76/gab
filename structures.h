#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED
#include "stdbool.h"

typedef struct casedeplateau{

    int numeroCase; // à supprimer lorsque j'aurais le nom des cases ; comme j'utilise un TABLEAU, mes cases sont déjà numérotés
    int proprietaireCase;   //-1 si pas de propriétaire, sinon indice du joueur proprio (entre 0 et 4)
    int typeDeCase;     //  0 : propriété / 1 : Chance / 2 : Communauté / 3 : Impot / 4: Parc gratuit / 6 : Départ / 7: Prison
    int prixAchat;
    int prixLoyer;

    char nomDeCase[40];
    char proprioCase[15];   //pseudo du joueur propriétaire de la case

}t_caseDePlateau;

typedef struct joueur{

    char pion;
    char pseudo[15];
    char POSSESSIONSNOMS[28][40];

    int positionPlateau;
    int soldeBancaire;
    int POSSESSIONS[28]; //tableau d'entiers répertoriant toutes les propriétés (leur numéro de case) d'un joueur
    int nombreDePropriete;  //nombre total de propriété que possède un joueur
    int numero; //utile ? car j'ai les indices de mon tableau de joueurs

    bool isPlayerInPrison;
}t_joueur;


#endif // STRUCTURES_H_INCLUDED
