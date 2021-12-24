#include <stdio.h>
#include <stdlib.h>
#include "windows.h"
#include "biblio_fonction_préparation.h"
#include "structures.h"
#include "time.h"
#include "stdbool.h"


void DeroulementTourDeJeuUnJoueur(t_caseDePlateau PLATEAUS[LONGUEUR_PLATEAU], t_joueur JOUEURS[4], int indiceJoueur, int indicePlateau, int nombreJoueur)
{
    bool isPlayerTurnOver = false, isDiceThrown = false;
    bool isCase1aPrint = false, isCase1bPrint = false, isCase2Print = false ;

    int saisieChoix = 0, saisieDe = 0;
    int resultatDes = 0;

    while(! isPlayerTurnOver) //Repropose à l'utilisateur le menu de sélection tant qu'il n'a pas fini son tour
    {

///Affichage du tableau
        system("cls");
        afficherPlateau(PLATEAUS, JOUEURS, nombreJoueur);


///Affichage de messages d'informations en fonction de mes Case
        if(isDiceThrown){
            Color (3,0); printf("\n\nVous avez avance de %d cases", resultatDes); Color(15,0);
        }
        if(isCase1aPrint){
            Color (10,0); printf("\n\n%s est maintenant le proprietaire de la %s, il possede %d POSSESSIONS au total", PLATEAUS[indicePlateau].proprioCase, PLATEAUS[indicePlateau].nomDeCase, JOUEURS[indiceJoueur].nombreDePropriete); Color(15,0);
            isCase1aPrint = false;
        }
        if(isCase1bPrint){
            Color (12,0); printf("\n\nCette propriete n'est pas a vendre"); Color(15,0);
            isCase1bPrint = false;
        }
        if(isCase2Print){
            Color (12,0); printf("\n\n"); Color(15,0);
            isCase2Print = false;
        }

        if(isDiceThrown){
                ///Affichage menu de choix
            do
            {
                printf("\n\nC'est au tour de : ");
                Color(13,0);
                printf("%s\n", JOUEURS[indiceJoueur].pseudo);
                Color(15,0);
                char test[20];
                strcpy(test ,PLATEAUS[indicePlateau].nomDeCase );
                printf("%s", test);
                printf("\nSelectionner une action : \n\n1.Acheter la propriete  : %s / Tirer carte \n2.Afficher les informations de la case\n3.Terminer le tour de jeu et passer au joueur suivant \nMon choix : ", PLATEAUS[indicePlateau].nomDeCase);
                scanf("%d",&saisieChoix);

            }while(saisieChoix>3 || saisieChoix<1);

            ///Realisation en fonction du choix de l'utilisateur
            switch(saisieChoix)
            {
    ///ACHETER PROPRIETE
                case 1 :
                        if(PLATEAUS[indicePlateau].proprietaireCase == -1)   //Si la propriétée est considérée comme "ACHETABLE"
                        {
                            AcheterPropriete(PLATEAUS, JOUEURS, indiceJoueur, indicePlateau);   // on l'achète
                           // isNoCaseDone = false ;
                           isCase1aPrint = true;    //a la fin de la boucle j'afficherais le message a ("Vous avez acheté la propriété")
                        }
                        else{isCase1bPrint = true;}; //a la fin de la boucle j'afficherais le message b ("Propriété déjà acheté")
                    break;

    ///Afficher Options
                case 2 :
                        afficherOptions();
                        //isNoCaseDone = false ;
                    break ;

    ///Terminer le tour de jeu et passer au joueur suivant
                case 3 :
                        isPlayerTurnOver = true; //le tour de jeu du joueur est finalisé
                        printf("Le tour de %s est maintenant termine", JOUEURS[indiceJoueur].pseudo);
                    break;
            }
        }

///Lancer les Dés : première action du tour de jeu

        if(!isDiceThrown){
            do
            {
                printf("\n\nC'est au tour de : ");
                Color(13,0); printf("%s\n", JOUEURS[indiceJoueur].pseudo); Color(15,0);
                printf("\nEntrer 1 pour lancer les DEs : ");
                scanf("%d",&saisieDe);

            }while(saisieDe!=1);


            ///On lance les Des
            resultatDes = LancerLesDes();
            JOUEURS[indiceJoueur].positionPlateau += resultatDes;
            indicePlateau += resultatDes;
            isDiceThrown = true ;
        }


    } //accolade while(! isPlayerTurnOver)

}

void DeroulementPartie(t_caseDePlateau PLATEAUS[LONGUEUR_PLATEAU], t_joueur JOUEURS[4], int nombreDeJoueur)
{
    for(int i=0 ; i< nombreDeJoueur ; i++){

        int indiceJoueur = i ;
        int indicePlateau = JOUEURS[indiceJoueur].positionPlateau;

        DeroulementTourDeJeuUnJoueur(PLATEAUS, JOUEURS, indiceJoueur, indicePlateau, nombreDeJoueur );
    }
}


