#include <stdio.h>
#include <stdlib.h>
#include "windows.h"
#include "biblio_fonction_préparation.h"
#include "structures.h"
#include "time.h"
#include "stdbool.h"


int LancerLesDes()
{
    int de1 = 0, de2 = 0;
    int valeurDesDes = 0;
    srand(time(NULL));  //Permet d'avoir des valeurs de rand() différentes à chaque éxecution

    de1 = rand() %7;
    de2 = rand() %7;

    return valeurDesDes = de1 + de2;
}

void AcheterPropriete(t_caseDePlateau PLATEAUS[LONGUEUR_PLATEAU], t_joueur JOUEURS[4], int indiceJoueur,int indicePlateau)
{
    ///Opérations sur le PLATEAU
    strcpy(PLATEAUS[indicePlateau].proprioCase, JOUEURS[indiceJoueur].pseudo); //il faut utiliser cette fonction de copie de chaîne de caractère au risque d'avoir une erreur. ON ne peut pas assigner un tableau à un autre tableau
    PLATEAUS[indicePlateau].proprietaireCase = indiceJoueur;

    ///Opérations sur le JOUEUR

    int propriete = JOUEURS[0].nombreDePropriete ;

    int possession = JOUEURS[indiceJoueur].POSSESSIONS[JOUEURS[indiceJoueur].nombreDePropriete];
    int numerocase = PLATEAUS[indicePlateau].numeroCase;

    JOUEURS[indiceJoueur].POSSESSIONS[JOUEURS[indiceJoueur].nombreDePropriete] = PLATEAUS[indicePlateau].numeroCase ;    //il faut faire gaffe que le nombreDePropriété d'un joueur est bien initialisé
    //Le joueur qui achète la case. Son tableau repertoriant toutes ses propriétés s'agrandit, on accède à ce tableau à l'indice "nombre de propriétés totales que le joueur possède" +1 pour ajouter une nouvelle proprieté au total.

    JOUEURS[indiceJoueur].nombreDePropriete += 1;   //Le Joueur vient d'acheter une nouvelle propriété, j'incrémente son nombreDePropriété

    ///Contrôle console du bon déroulement de l'opération
   // printf("\n%s est maintenant le proprietaire de la case %s, il possede %d POSSESSIONS au total", PLATEAUS[indicePlateau].proprioCase, PLATEAUS[indicePlateau].nomDeCase, JOUEURS[indiceJoueur].nombreDePropriete);

}

void DeplacerJoueur(t_caseDePlateau PLATEAUS[LONGUEUR_PLATEAU], t_joueur JOUEURS[4], int indiceJoueur,int indicePlateau, int valeurDeplacement)
{
    //JOUEURS[indiceJoueur].positionPlateau = PLATEAUS[indicePlateau].numeroCase +valeurDeplacement

    JOUEURS[indiceJoueur].positionPlateau += valeurDeplacement ;
}
