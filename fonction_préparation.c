#include <stdio.h>
#include <stdlib.h>
#include "windows.h"
#include "biblio_fonction_préparation.h"
#include "structures.h"
#include "time.h"
#include "stdbool.h"


void InitaliserJoueurEtPlateau(t_joueur JOUEURS[4], t_caseDePlateau PLATEAUX[LONGUEUR_PLATEAU])
{
///JOUEUR
    for (int i=0; i<4; i++)
    {
        JOUEURS[i].positionPlateau = 1;
        JOUEURS[i].nombreDePropriete = 0;
        JOUEURS[i].soldeBancaire = 1500;
    }

    JOUEURS[0].pion = 3;    //Pion du Joueur 1 : coeur
    JOUEURS[1].pion = 4;    //        Joueur 2 : Trèfle
    JOUEURS[2].pion = 5;    //        Joueur 3 : Carreaux
    JOUEURS[3].pion = 6;    //        Joueur 4: Pique

    //Le tableau répertoriant toutes les propriétés d'un joueur est initialisé à 0
    for(int i=0; i<4;i++)
    {
        for (int j=0; j<28; j++)
        {
            JOUEURS[i].POSSESSIONS[j] = 0;
            int test = JOUEURS[i].POSSESSIONS[j];
        }
    }

///PLATEAU
    for (int i=0; i<LONGUEUR_PLATEAU; i++)
    {
        PLATEAUX[i].numeroCase=i+1;
        PLATEAUX[i].nombreDePions = 0;
        PLATEAUX[i].proprietaireCase = -1;
    }

    ///Noms des cases
    strcpy(PLATEAUX[0].nomDeCase , "Case Départ") ;
    strcpy(PLATEAUX[1].nomDeCase , "Rue marron 1") ;
    strcpy(PLATEAUX[2].nomDeCase , "Caisse de communaute") ;
    strcpy(PLATEAUX[3].nomDeCase , "Impot sur le revenu ") ;
    strcpy(PLATEAUX[4].nomDeCase , "Gare Montparnasse") ;
    strcpy(PLATEAUX[5].nomDeCase , "Rue bleu clair 1") ;
    strcpy(PLATEAUX[6].nomDeCase , "CHANCE") ;
    strcpy(PLATEAUX[7].nomDeCase , "Rue bleu clair 2") ;
    strcpy(PLATEAUX[8].nomDeCase , "Rue bleu clair 2") ;
    strcpy(PLATEAUX[9].nomDeCase , "PRISON") ;
    strcpy(PLATEAUX[10].nomDeCase , "Rue rose 1") ;
    strcpy(PLATEAUX[11].nomDeCase , "Co&Electricité") ;
    strcpy(PLATEAUX[12].nomDeCase , "Rue rose 2") ;
    strcpy(PLATEAUX[13].nomDeCase , "Rue rose 3") ;
    strcpy(PLATEAUX[14].nomDeCase , "Gare de Lyon") ;
    strcpy(PLATEAUX[15].nomDeCase , "Rue orange 1") ;
    strcpy(PLATEAUX[16].nomDeCase , "Caisse de communaute") ;
    strcpy(PLATEAUX[17].nomDeCase , "Rue orange 2") ;
    strcpy(PLATEAUX[18].nomDeCase , "Rue orange 3") ;
    strcpy(PLATEAUX[19].nomDeCase , "Parc Gratuit") ;
    strcpy(PLATEAUX[20].nomDeCase , "Rue rouge 1") ;
    strcpy(PLATEAUX[21].nomDeCase , "CHANCE") ;
    strcpy(PLATEAUX[22].nomDeCase , "Rue rouge 2") ;
    strcpy(PLATEAUX[23].nomDeCase , "Rue rouge 3") ;
    strcpy(PLATEAUX[24].nomDeCase , "Gare du NORD") ;
    strcpy(PLATEAUX[25].nomDeCase , "Rue jaune 1") ;
    strcpy(PLATEAUX[26].nomDeCase , "Rue jaune 2") ;
    strcpy(PLATEAUX[27].nomDeCase , "Co&Eau") ;
    strcpy(PLATEAUX[28].nomDeCase , "Rue jaune 3") ;
    strcpy(PLATEAUX[29].nomDeCase , "Aller en PRISON") ;
    strcpy(PLATEAUX[30].nomDeCase , "Rue verte 1") ;
    strcpy(PLATEAUX[31].nomDeCase , "Rue verte 2") ;
    strcpy(PLATEAUX[32].nomDeCase , "Caisse de communaute") ;
    strcpy(PLATEAUX[33].nomDeCase , "Rue verte 3") ;
    strcpy(PLATEAUX[34].nomDeCase , "Gare de Saint-Lazare") ;
    strcpy(PLATEAUX[35].nomDeCase , "CHANCE") ;
    strcpy(PLATEAUX[36].nomDeCase , "Rue bleu 1") ;
    strcpy(PLATEAUX[37].nomDeCase , "Taxe de Luxe") ;
    strcpy(PLATEAUX[38].nomDeCase , "Rue bleu 2") ;

    ///Type des cases
             //  0 : propriété / 1 : Chance / 2 : Communauté / 3 : Impot / 4: Parc gratuit / 6 : Case Départ / 7: Aller en Prison / 8: PRISON

    for (int i =0; i<LONGUEUR_PLATEAU ; i++)
    {
        PLATEAUX[i].typeDeCase = 0;
    }

    PLATEAUX[0].typeDeCase = 6   ;
    PLATEAUX[2].typeDeCase = 2   ;
    PLATEAUX[3].typeDeCase = 3   ;
    PLATEAUX[6].typeDeCase = 1   ;
    PLATEAUX[9].typeDeCase = 8   ;
    PLATEAUX[16].typeDeCase = 2  ;
    PLATEAUX[19].typeDeCase = 4  ;
    PLATEAUX[21].typeDeCase = 1  ;
    PLATEAUX[29].typeDeCase = 7  ;
    PLATEAUX[32].typeDeCase = 2  ;
    PLATEAUX[35].typeDeCase = 1  ;
    PLATEAUX[37].typeDeCase = 3  ;
}

int SaisirJoueurs(t_joueur JOUEURS[4])
{
    int nombreDeJoueur = 0;

    Color(14,0);
    do {
            printf("Saisir le nombre de Joueurs (max 4): ");
            scanf("%d", &nombreDeJoueur);
        }while(nombreDeJoueur<1 || nombreDeJoueur >4);

    for (int i=0; i<nombreDeJoueur; i++ )
    {
        printf("\nSaisir le nom du joueur %d : ", i+1);
        scanf("%s", JOUEURS[i].pseudo);
    }
    system("cls");
    Color(13,0);
     for(int i=0; i<nombreDeJoueur; i++)
    {
        //Color(5+i,0);
        printf("Joueur %d: %s\n",i+1, JOUEURS[i].pseudo);
    }

    Color(15,0);
    printf("\n");
    return nombreDeJoueur;
}


