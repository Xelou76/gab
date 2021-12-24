#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED

typedef struct casedeplateau{

    int numeroCase; // � supprimer lorsque j'aurais le nom des cases ; comme j'utilise un TABLEAU, mes cases sont d�j� num�rot�s
    int proprietaireCase;   //-1 si pas de propri�taire, -2 si pas disponible � l'achat, sinon indice du joueur proprio (entre 0 et 4)
    int typeDeCase;     //  0 : propri�t� / 1 : Chance / 2 : Communaut� / 3 : Impot / 4: Parc gratuit / 6 : D�part / 7: Prison
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
    int POSSESSIONS[28]; //tableau d'entiers r�pertoriant toutes les propri�t�s (leur num�ro de case) d'un joueur
    int nombreDePropriete;  //nombre total de propri�t� que poss�de un joueur
    int numero; //utile ? car j'ai les indices de mon tableau de joueurs

}t_joueur;

#endif // STRUCTURES_H_INCLUDED
