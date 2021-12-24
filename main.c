#include <stdio.h>
#include <stdlib.h>
#include "windows.h"
#include "biblio_fonction_préparation.h"
#include "structures.h"
#include "time.h"
#include "stdbool.h"




int main()
{
    ///CREATION DE MON TABLEAU DE JOUEUR ET DE MON PLATEAU DE JEU
    t_joueur JOUEURS[4];
    t_caseDePlateau PLATEAUX[LONGUEUR_PLATEAU];

    InitaliserJoueurEtPlateau(JOUEURS, PLATEAUX);

    int nombreDeJoueur = SaisirJoueurs(JOUEURS);

    afficherPlateau(PLATEAUX, JOUEURS, nombreDeJoueur);

    DeroulementPartie(PLATEAUX, JOUEURS, nombreDeJoueur);


    return 0;
}




