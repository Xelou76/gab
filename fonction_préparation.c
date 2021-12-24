#include <stdio.h>
#include <stdlib.h>
#include "windows.h"
#include "biblio_fonction_préparation.h"
#include "structures.h"

void initialiserJeu(Joueur joueurs[4], CaseDePlateau plateauDeJeu[NOMBRE_DE_CASES_DU_PLATEAU]){

    ///INITIALISATION du tableau des joueurs
//    Joueur joueurs[2];  le tableau est déjà défini dans le main, il est maintenant un paramètre de la fonction
    joueurs[0].pion = 3;    //pion du joueur 1 = coeur
    joueurs[1].pion = 4;    //pion du joueur 2 = trèfle

    joueurs[0].positionPlateau = 1; // les deux joueurs commencent à la première case
    joueurs[1].positionPlateau = 1;  // il me semble que c'est plutôt 0

    /// INITIALISATION DE MON PLATEAU
//    CaseDePlateau plateauDeJeu[NOMBRE_DE_CASES_DU_PLATEAU];
    int caseInitiale = 0;

    for (int i=0; i<NOMBRE_DE_CASES_DU_PLATEAU; i++)
    {
        plateauDeJeu[i].numeroCase=i+1;
        plateauDeJeu[i].pion = "";
        plateauDeJeu[i].pion = 3;
        plateauDeJeu[i].nombreDePions = 0;
        plateauDeJeu[caseInitiale].nombreDePions = 0;  // ne devrait pas être dans une boulce
    }
    afficherPlateau(plateauDeJeu, joueurs);

     char nomDesJoueurs[4][15];


    int nombreDeJoueurs = saisirJoueursDansTableau(nomDesJoueurs);
    printf("\nNombre de joueurs : %d ", nombreDeJoueurs);

    return 0;
}

int saisirJoueursDansTableau (char nomsDesJoueurs[4][15])
{
    int nombreDeJoueurs = 0;

    Color(14,0);
    do {
            printf("\nSaisir le nombre de Joueurs (max 4): ");
            scanf("%d", &nombreDeJoueurs);
        }while(nombreDeJoueurs<1 || nombreDeJoueurs >4);

    for (int i=0; i<nombreDeJoueurs; i++ )
    {
        printf("\nSaisir le nom du joueur %d : ", i+1);

        scanf("%s", nomsDesJoueurs[i]);
;


    }

    Color(13,0);
     for(int i=0; i<nombreDeJoueurs; i++)
    {
        //Color(5+i,0);
        printf("\nJoueur %d: %s",i+1, nomsDesJoueurs[i]);
    }

    Color(15,0);
    return nombreDeJoueurs;
}

int lancerLesDes(int* ptde,int* ptde2,int* ptde3,int* ptde4)
// je ne comprends pas pourquoi il faut 4 pointeurs pour lancer 2 dés, je ne comprends pas non plus d'ailleurs pourquoi il faut des pointeurs

{
    int variable = 0;
    int valeurDeDes = 0;
    srand( time( NULL ) );

    //lancement des 2 des

    printf("\nEntrez 1 pour lancer les DEs\n");
    scanf("%d", &variable);

    while(variable!=1)
    {
        printf("\nVous avez mal jete les DEs, ressayer\n");
        printf("Entrez 1 pour lancer les DEs\n");
        scanf("%d", &variable);
    }

    /* if (variable==1){
        printf("\n");
        for (int i =0;i<2 ;i++ ){
          printf("\rLes des sont jetes         ");
          Sleep(300);
          printf("\rLes des sont jetes .       ");
          Sleep(300);
          printf("\rLes des sont jetes . .     ");
          Sleep(300);
          printf("\rLes des sont jetes . . .   ");
          Sleep(300);
        }

    }*/
    variable=0;

    *ptde  = rand() %7;
    *ptde2 = rand() %7;
    valeurDeDes = *ptde + *ptde2;

    //Si jamais on a fait un double, on relance les dés
    if(*ptde == *ptde2){
        printf("Wahou quelle chance !  UN DOUBLE !\n");
        printf("\nEntrez 1 pour RElancer les DEs\n");
        scanf("%d", &variable);

        while(variable!=1)
        {
            printf("\nVous avez mal jete les DEs, ressayer\n");
            printf("Entrez 1 pour lancer les DEs\n");
            scanf("%d", &variable);
        }

       /*if (variable==1){
            printf("\n");
            for (int i =0;i<2 ;i++ ){
              printf("\rLes des sont lances         ");
              Sleep(300);
              printf("\rLes des sont lances .       ");
              Sleep(300);
              printf("\rLes des sont lances . .     ");
              Sleep(300);
              printf("\rLes des sont lances . . .   ");
              Sleep(300);
            }
    }*/
    srand( time( NULL ) );

    *ptde3  = rand() %7;
    *ptde4 = rand() %7;
    }

    valeurDeDes = valeurDeDes + *ptde3 + *ptde4;
    variable=0;
    printf("\n");
    return valeurDeDes;
}



