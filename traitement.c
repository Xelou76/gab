#include <stdio.h>
#include <stdlib.h>
#include "windows.h"
#include "biblio_fonction_pr�paration.h"
#include "structures.h"
#include "time.h"
#include "stdbool.h"


int LancerLesDes()
{
    int de1 = 0, de2 = 0;
    int valeurDesDes = 0;
    srand(time(NULL));  //Permet d'avoir des valeurs de rand() diff�rentes � chaque �xecution

    de1 = rand() %7;
    de2 = rand() %7;

    return valeurDesDes = de1 + de2;
}

void AcheterPropriete(t_caseDePlateau PLATEAUS[LONGUEUR_PLATEAU], t_joueur JOUEURS[4], int indiceJoueur,int indicePlateau)
{
    ///Op�rations sur le PLATEAU
    strcpy(PLATEAUS[indicePlateau].proprioCase, JOUEURS[indiceJoueur].pseudo); //il faut utiliser cette fonction de copie de cha�ne de caract�re au risque d'avoir une erreur. ON ne peut pas assigner un tableau � un autre tableau
    PLATEAUS[indicePlateau].proprietaireCase = indiceJoueur;

    ///Op�rations sur le JOUEUR

    int propriete = JOUEURS[0].nombreDePropriete ;

    int possession = JOUEURS[indiceJoueur].POSSESSIONS[JOUEURS[indiceJoueur].nombreDePropriete];
    int numerocase = PLATEAUS[indicePlateau].numeroCase;

    JOUEURS[indiceJoueur].POSSESSIONS[JOUEURS[indiceJoueur].nombreDePropriete] = PLATEAUS[indicePlateau].numeroCase ;    //il faut faire gaffe que le nombreDePropri�t� d'un joueur est bien initialis�
    //Le joueur qui ach�te la case. Son tableau repertoriant toutes ses propri�t�s s'agrandit, on acc�de � ce tableau � l'indice "nombre de propri�t�s totales que le joueur poss�de" +1 pour ajouter une nouvelle propriet� au total.

    JOUEURS[indiceJoueur].nombreDePropriete += 1;   //Le Joueur vient d'acheter une nouvelle propri�t�, j'incr�mente son nombreDePropri�t�

    ///Contr�le console du bon d�roulement de l'op�ration
   // printf("\n%s est maintenant le proprietaire de la case %s, il possede %d POSSESSIONS au total", PLATEAUS[indicePlateau].proprioCase, PLATEAUS[indicePlateau].nomDeCase, JOUEURS[indiceJoueur].nombreDePropriete);

}

void DeplacerJoueur(t_caseDePlateau PLATEAUS[LONGUEUR_PLATEAU], t_joueur JOUEURS[4], int indiceJoueur,int indicePlateau, int valeurDeplacement)
{
    //JOUEURS[indiceJoueur].positionPlateau = PLATEAUS[indicePlateau].numeroCase +valeurDeplacement

    JOUEURS[indiceJoueur].positionPlateau += valeurDeplacement ;
}
