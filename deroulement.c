#include <stdio.h>
#include <stdlib.h>
#include "windows.h"
#include "biblio_fonction_préparation.h"
#include "structures.h"
#include "time.h"
#include "stdbool.h"


void DeroulementTourDeJeuUnJoueur(t_caseDePlateau PLATEAUS[LONGUEUR_PLATEAU], t_joueur JOUEURS[4], int indiceJoueur, int indicePlateau, int nombreJoueur)
{
    bool isPlayerTurnOver = false, isPlayerOnRent = false, hasPlayerNotPaid = true, isDiceThrown = false, isScreenReprinted = false;
    bool isPlayerOnRentPrint = false, isCase1aPrint = false, isCase1bPrint = false, isCase1cPrint = false, isCase1dPrint = false, isCase2Print = false , isCase3Print = false;

    int saisieChoix = 0, saisieDe = 0;
    int resultatDes = 0;

    int curseurXposition = 0, curseurYposition = 0;

    do //Repropose à l'utilisateur le menu de sélection tant qu'il n'a pas fini son tour
    {

///Affichage du tableau
        system("cls");
        afficherPlateau(PLATEAUS, JOUEURS, nombreJoueur);
        isScreenReprinted = true ;
///Affichage de messages d'informations en fonction de mes case
        if(isDiceThrown){
            Color (3,0); printf("\n\nVous avez avance de %d cases", resultatDes); Color(15,0);
        }
        if(isCase1aPrint){
            Color (10,0); printf("\n\n%s est maintenant le proprietaire de la %s, il possede %d POSSESSIONS au total", PLATEAUS[indicePlateau].proprioCase, PLATEAUS[indicePlateau].nomDeCase, JOUEURS[indiceJoueur].nombreDePropriete); Color(15,0);
            isCase1aPrint = false;
        }
        if(isCase1bPrint){
            Color (12,0); printf("\n\nUn autre joueur possède déjà cette propriete"); Color(15,0);
            isCase1bPrint = false;
        }
        if(isCase1cPrint){
            Color (12,0); printf("\n\nCette case n'est pas une propriete, vous ne pouvez pas l'acheter"); Color(15,0);
            isCase1bPrint = false;
        }
        if(isCase1dPrint){
            Color (12,0); printf("\n\nVous etes trop PAUVRE pour acheter cette propriete !"); Color(15,0);
            isCase1bPrint = false;
        }
        if(isCase2Print){
            //Color (12,0); printf("\n\n"); Color(15,0);
            afficherInfosCase(PLATEAUS, indicePlateau);
            isCase2Print = false;
        }
        if(isCase3Print){
            afficherInfosJoueur(JOUEURS, indiceJoueur);
            isCase3Print = false;
        }

        if(isDiceThrown){

            if(PLATEAUS[indicePlateau].proprietaireCase != -1 && PLATEAUS[indicePlateau].proprietaireCase!= indiceJoueur && hasPlayerNotPaid){  //si la case est possédée par qqn et si le propriétaire n'est pas le joueur actuel
                isPlayerOnRent = true;
                ///Affichage
                Color(13,0); printf("\nAttention %s !!", JOUEURS[indiceJoueur].pseudo);Color(12,0); printf("\nTaper sur le clavier pour payer le loyer de : %d bits a %s", PLATEAUS[indicePlateau].prixLoyer, JOUEURS[PLATEAUS[indicePlateau].proprietaireCase].pseudo); Color(15,0);
                getch();    //attend que l'utilisateur tape sur le clavier

                ///Transfert d'argent
                JOUEURS[indiceJoueur].soldeBancaire -= PLATEAUS[indicePlateau].prixLoyer ;  //le joueur paye le loyer
                JOUEURS[PLATEAUS[indicePlateau].proprietaireCase].soldeBancaire += PLATEAUS[indicePlateau].prixLoyer ;   //le proprio reçoit le loyer

                ///Validation des boolens
                isPlayerOnRentPrint = true ;
                hasPlayerNotPaid = false ;
                isPlayerOnRent = false ;
            }

            if(isPlayerOnRentPrint){
            Color(10,0); printf("\nVous avez paye le loyer, solde actuel : %d ",JOUEURS[indiceJoueur].soldeBancaire); Color(15,0);
            }

            if(!isPlayerOnRent){
                ///Affichage menu de choix
                do
                {
                    printf("\n\nC'est au tour de : ");
                    Color(13,0); printf("%s  ", JOUEURS[indiceJoueur].pseudo);
                    Color(10,0); printf("Solde : %d\n", JOUEURS[indiceJoueur].soldeBancaire);Color(15,0);

                    printf("\nSelectionner une action : \n\n1.Acheter la propriete  : %s\n2.Afficher les informations de la case\n3.Afficher infos Joueur\n4.Terminer le tour de jeu et passer au joueur suivant \nMon choix : ", PLATEAUS[indicePlateau].nomDeCase);
                    scanf("%d",&saisieChoix);

                }while(saisieChoix>4 || saisieChoix<1);

                ///Realisation en fonction du choix de l'utilisateur
                switch(saisieChoix)
                {
        ///ACHETER PROPRIETE
                    case 1 :
                        if(PLATEAUS[indicePlateau].typeDeCase == 0){  //si la case est une propriété
                            if(PLATEAUS[indicePlateau].proprietaireCase == -1)   //Si la propriété n'a pas de propriétaire
                            {
                                if(PLATEAUS[indicePlateau].prixAchat <= JOUEURS[indiceJoueur].soldeBancaire){
                                    AcheterPropriete(PLATEAUS, JOUEURS, indiceJoueur, indicePlateau);   // on l'achète
                                    isCase1aPrint = true;    //a la fin de la boucle j'afficherais le message a ("Vous avez acheté la propriété")
                                }else{isCase1dPrint = true;};

                            }else{isCase1bPrint = true;}; //a la fin de la boucle j'afficherais le message b ("Propriété déjà acheté")
                        }else{isCase1cPrint = true;}

                        break;

        ///Afficher infos Case
                    case 2 :
                            isCase2Print = true;
                        break ;

        ///Afficher infos Joueur
                    case 3 :
                            isCase3Print =true;
                        break ;
        ///Terminer le tour de jeu et passer au joueur suivant
                    case 4 :
                            isPlayerTurnOver = true; //le tour de jeu du joueur est finalisé
                            printf("Le tour de %s est maintenant termine", JOUEURS[indiceJoueur].pseudo);
                        break;
                } //switch(saisieChoix)

            }//if(!isPlayerOnRent)

        } //if(isDiceThrown)

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
            if(JOUEURS[indiceJoueur].positionPlateau + resultatDes > 39){   //si la joueur va effectuer un tour complet du plateau
               JOUEURS[indiceJoueur].positionPlateau = (JOUEURS[indiceJoueur].positionPlateau + resultatDes) - 39;
               indicePlateau = (indicePlateau + resultatDes) - 39;  //seulement 39 indices différents
            }
            else{
                JOUEURS[indiceJoueur].positionPlateau += resultatDes;
                indicePlateau += resultatDes;
            }
            isDiceThrown = true ;
        }

    }while(!isPlayerTurnOver && isScreenReprinted); //accolade do/while(! isPlayerTurnOver)

}   //accolade void DeroulementTourDeJeuUnJoueur

void DeroulementPartie(t_caseDePlateau PLATEAUS[LONGUEUR_PLATEAU], t_joueur JOUEURS[4], int nombreDeJoueur)
{
    for(int j=0; j<NOMBRE_DE_TOUR; j++){
        for(int i=0 ; i<nombreDeJoueur ; i++){

            int indiceJoueur = i ;
            int indicePlateau = JOUEURS[indiceJoueur].positionPlateau;

            DeroulementTourDeJeuUnJoueur(PLATEAUS, JOUEURS, indiceJoueur, indicePlateau, nombreDeJoueur );

        }
    }

} //accolade void DeroulementPartie


