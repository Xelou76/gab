#include <stdio.h>
#include <stdlib.h>
#include "windows.h"
#include "biblio_fonction_préparation.h"
#include "time.h"
#include "structures.h"



int main()
{
    Joueur joueurs[4];
    CaseDePlateau plateauDeJeu[NOMBRE_DE_CASES_DU_PLATEAU];

    int result = menuPrincipal(joueurs, plateauDeJeu);



    ///TOUR DU JOUEUR 1, TIRAGE DES DEs, AVANCE SUR LE PLATEAU ET REAFFICHE LE NOUVEAU PLATEAU
    printf("\n\nAu JOUEUR 1 de jouer !\n");
    int de=0, de2=0, de3=0, de4=0;
    int valeurDe = lancerLesDes(&de, &de2, &de3, &de4);

    joueurs[0].positionPlateau += valeurDe;

    system("cls");
    afficherPlateau(plateauDeJeu, joueurs);
    printf("\nVous avez avance de %d cases", valeurDe);


    ///TOUR DU JOUEUR 2, TIRAGE DES DEs, AVANCE SUR LE PLATEAU ET REAFFICHE LE NOUVEAU PLATEAU
    printf("\n\nAu JOUEUR 2 de jouer !\n");

    valeurDe = lancerLesDes(&de, &de2, &de3, &de4);

    joueurs[1].positionPlateau += valeurDe;

    system("cls");
    afficherPlateau(plateauDeJeu, joueurs);
    printf("\nVous avez avance de %d cases", valeurDe);




    ///DEFINITION d'un plateau lambda de char
    /*char TABLEAU[LENTABLEAU];
    for (int i = 0; i<LENTABLEAU; i++)
        {
            TABLEAU[i] = 'A'+ i;
        }
    affichage_Tableau(TABLEAU);*/

    ///LANCER DE DES ET DEPLACEMENT EN FONCTION DES DES
    /*int de=0, de2=0, de3=0, de4=0;
    int *ptde  =&de;
    int *ptde2 =&de2;
    int *ptde3 =&de3;
    int *ptde4 =&de4;
    int valeurDe=0;

    /*valeurDe = tirage_Au_Sort(&de, &de2, &de3, &de4);

    TABLEAU[valeurDe] = 4;
    system("cls");
    affichage_Tableau(TABLEAU);
    printf("\rResultat du premier lancer : De1 = %d  De2 = %d",*ptde,*ptde2);

    if((de3 + de4)!=0)
        {
            printf("\rResultat du second lancer : De3 = %d  De4 = %d",*ptde3,*ptde4);
        }

    printf("\n\nVous vous etes deplace de %d cases\n", valeurDe+1);*/


///NOMS DES JOUEURS
    /*int choixDuMenu = menu_Principal();
    char NOMSDESJOUEURS[4][15];
    int nombreDeJoueur=0;
    switch (choixDuMenu)
    {
        case 1 : nombreDeJoueur = saisirJoueursAvecTableau(NOMSDESJOUEURS);
    }
    menuTourDeJeu(NOMSDESJOUEURS);

    t_case TABLEAU[Lenghtableau];
    for (int i=0;i<Lenghtableau ;i++ ){
        TABLEAU[i].numeroCase = i;
        TABLEAU[i].pion = 3+i;
    }
    /*
    //saisie et affichage du nombre de joueur et de leur noms
    char NOMSDESJOUEURS[4][15];

    int nombreDeJoueur = saisirJoueursAvecTableau(NOMSDESJOUEURS);
    printf("\nnombre de joueurs :  %d", nombreDeJoueur);

    for(int i=0; i<nombreDeJoueur; i++)
    {
        printf("\nJoueur %d: %s",i+1, NOMSDESJOUEURS[i]);
    }
    */


    return 0;
}




