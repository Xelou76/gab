#include <stdio.h>
#include <stdlib.h>
#include "windows.h"
#include "biblio_fonction_préparation.h"
#include "structures.h"
#include "time.h"
#include "stdbool.h"

void afficherPlateau(t_caseDePlateau TAB[LONGUEUR_PLATEAU], t_joueur JOUEURS[4], int nombreDeJoueur)
{
    int i=0;

    for (i=0; i<LONGUEUR_PLATEAU; i++)        //affiche mon tableau sans respecter les 4 lignes et 8 colonnes du plateau
    {
        printf("%d", TAB[i].numeroCase);
        for(int j=0; j<nombreDeJoueur; j++)
        {
            if (JOUEURS[j].positionPlateau == TAB[i].numeroCase - 1){
                printf("%c", JOUEURS[j].pion );
            }
        }
        printf(" | ");
    }

}

void affichage_Tableau(char TABLEAU[LONGUEUR_PLATEAU])
{

    for (int i=0;i<8 ;i++ ){
       printf("%c",TABLEAU[i]) ;
       printf("  |  ");
    }
    printf("\n");
    for (int i=8;i<16 ;i++ ){
       printf("%c",TABLEAU[i]) ;
       printf("  |  ");
    }
    printf("\n");
    for (int i=16;i<24 ;i++ ){
       printf("%c",TABLEAU[i]) ;
       printf("  |  ");
    }
    printf("\n");
    for (int i=24;i<32 ;i++ ){
       printf("%c",TABLEAU[i]) ;
       printf("  |  ");
    }
    printf("\n");
}

void memoriserPositionCurseur(int* posX, int* posY) //https://codes-sources.commentcamarche.net/forum/affich-540998-console-et-position-du-curseur
{
    GetConsoleScreenBufferInfo (GetStdHandle(STD_OUTPUT_HANDLE), &coninfo);
    *posX = coninfo.dwCursorPosition.X;
    *posY = coninfo.dwCursorPosition.Y;
}



void gotoligcol( int x, int y ) //permet de déplacer le curseur à l'endroit ou l'on souhaite
{

// ressources

COORD mycoord;

mycoord.X = x;

mycoord.Y = y;

SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );

}

void Color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
     /*
    0 : Noir
    1 : Bleu foncé
    2 : Vert foncé
    3 : Turquoise
    4 : Rouge foncé
    5 : Violet
    6 : Vert caca d'oie
    7 : Gris clair
    8 : Gris foncé
    9 : Bleu fluo
    10 : Vert fluo
    11 : Turquoise
    12 : Rouge fluo
    13 : Violet 2
    14 : Jaune
    15 : Blanc
    */
}


void afficherOptions()
{
    gotoligcol(0 ,60);
    Color(10,0);
    printf("1.afficher infos de la case");
    Color(15, 0);
    gotoligcol(2,60);
    Color(10,0);
    printf("2.Lancer les des");
    Color(15, 0);
    gotoligcol(4,60);
    Color(10,0);
    printf("3.Voir compte en banque");
    Color(15, 0);
}

void afficherOptionsOuJeVeux(int lig, int col, int colTexte, int colFond)
{
    gotoligcol(lig ,col);
    Color(colTexte,colFond);
    printf("1.ce que je veux ");
    Color(15, 0);
    gotoligcol(lig+1 ,col); //cela sera afficher une ligne en dessous du texte précédent
    Color(colTexte,colFond);
    printf("2.ce que je veux");
    Color(15, 0);
    gotoligcol(lig+2 ,col); //cela sera afficher 2 en dessous du premier texte
    Color(colTexte,colFond);
    printf("3.ce que je veux");
    Color(15, 0);
}

void afficherInfosCase(t_caseDePlateau PLATEAUS[LONGUEUR_PLATEAU], int indicePlateau)
{
    int curseurXposition = 0, curseurYposition = 0;

    memoriserPositionCurseur(&curseurXposition, &curseurYposition); //on sauvegarde l'emplacement initial du curseur
    gotoligcol(55, 4);

    if (PLATEAUS[indicePlateau].typeDeCase == 0){
        if(PLATEAUS[indicePlateau].proprietaireCase == -1){
            Color(10, 0);
            printf("La %s est diponible a l'achat. PRIX  = %d",PLATEAUS[indicePlateau].nomDeCase, PLATEAUS[indicePlateau].prixAchat); Color(15,0);
        }else{Color(11, 0);printf("La %s appartient a : %s", PLATEAUS[indicePlateau].nomDeCase, PLATEAUS[indicePlateau].proprioCase);Color(15, 0);};
    }else{Color(14, 0);printf("Cette case n'est pas une propriete");Color(15, 0);};

    gotoligcol(curseurXposition, curseurYposition); //on remet le curseur une ligne en dessous de la position initale

}

void afficherInfosJoueur(t_joueur JOUEURS[4], int indiceJoueur)
{
    int curseurXpositionInitiale = 0, curseurYpositionInitiale = 0;
    int posX = 55, posY = 6 ;
    memoriserPositionCurseur(&curseurXpositionInitiale, &curseurYpositionInitiale); //on sauvegarde l'emplacement initial du curseur

    gotoligcol(posX, posY);
    printf("Joueur : %s", JOUEURS[indiceJoueur].pseudo);

    gotoligcol(posX, posY +1);
    printf("Pion : %c", JOUEURS[indiceJoueur].pion);

    gotoligcol(posX, posY +2);
    printf("Solde bancaire : %d", JOUEURS[indiceJoueur].soldeBancaire);


    gotoligcol(posX, posY +3);
    printf("Nombre de propriete : %d", JOUEURS[indiceJoueur].nombreDePropriete);

    gotoligcol(posX, posY +4);
    if(JOUEURS[indiceJoueur].isPlayerInPrison){
        printf("Le joueur est-il en prison ?"); Color(12, 0); printf(" // OUI \\ ");
    }else{printf("Le joueur est-il en prison ?"); Color(10, 0); printf(" // NON \\ ");};

    gotoligcol(posX, posY +5);

    Color(2,0); printf("Possessions : "); Color(6,0);
    for(int j=0; j<=JOUEURS[indiceJoueur].nombreDePropriete; j++){
        gotoligcol(posX +14, posY +4 +j);
        printf("%s", JOUEURS[indiceJoueur].POSSESSIONSNOMS[j]);
    }
    Color(15,0);
    gotoligcol(curseurXpositionInitiale, curseurYpositionInitiale); //on remet le curseur une ligne en dessous de la position initale

}

