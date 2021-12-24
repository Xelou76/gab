#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED

typedef struct casedeplateau{

    int numeroCase; // à supprimer lorsque j'aurais le nom des cases ; comme j'utilise un TABLEAU, mes cases sont déjà numérotés
    int proprietaireCase;   //-1 si pas de propriétaire, -2 si pas disponible à l'achat, sinon indice du joueur proprio (entre 0 et 4)
    int typeDeCase;     //  0 : propriété / 1 : Chance / 2 : Communauté / 3 : Impot / 4: Parc gratuit / 6 : Départ / 7: Prison
    char pion;
    int nombreDePions;
    char nomDeCase[40];
    char proprioCase[15];

}t_caseDePlateau;

typedef struct joueur{

    char pion;
    int positionPlateau;
    int soldeBancaire;
    char pseudo[15];
    int POSSESSIONS[28]; //tableau d'entiers répertoriant toutes les propriétés (leur numéro de case) d'un joueur
    int nombreDePropriete;  //nombre total de propriété que possède un joueur
    int numero; //utile ? car j'ai les indices de mon tableau de joueurs

}t_joueur;

#endif // STRUCTURES_H_INCLUDED
