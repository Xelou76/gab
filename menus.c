#include <stdio.h>
#include <stdlib.h>
#include "windows.h"
#include "biblio_fonction_pr�paration.h"
#include "structures.h"

int menuPrincipal(Joueur joueurs[4], CaseDePlateau plateauDeJeu[NOMBRE_DE_CASES_DU_PLATEAU])
{
    int saisieChoix = 0;

    do {printf("Menu Principal, selectionner une action a effectuer : \n\n1. Nouvelle partie\n2. Sauvegarder partie\n3. Charger partie\n4. Regles\n5. Nom d'equipe\n6. Exit\nMon choix : ");
    scanf("%d", &saisieChoix);
     printf("\n saisieChoix vaut : %d", saisieChoix);
    }while(saisieChoix>6 || saisieChoix <1);

    switch (saisieChoix)
    {
    case 1: printf("\nNouvelle Partie\n");

    initialiserJeu(joueurs, plateauDeJeu);

    printf("\nJeu initialis\x82");
        break;
    case 2 : printf("\nVous avez choisi SAVE GAME, merci d'attendre que les developpeurs finissent leur boulot");
        break;
    case 3 : printf("\nVous avez choisi LOAD GAME, merci d'attendre que les developpeurs finissent leur boulot");
        break;
    case 4 : printf("\nVous avez choisi RULES, merci d'attendre que les developpeurs finissent leur boulot");
        break;
    case 5 : printf("\nVous avez choisi TEAM NAME, merci d'attendre que les developpeurs finissent leur boulot");
        break;
    case 6 : printf("\nVous avez choisi EXIT, merci d'attendre que les developpeurs finissent leur boulot");
        break;
    //default: printf("1. New Game\n2. Save Game\n3. Load Game\n4. Rules\n5. Team Name\n6. Exit");scanf("%d",saisieChoix);
//    break;
    }
    printf("\n saisieChoix vaut : %d", saisieChoix);
    return saisieChoix;
    //� quoi �a sert de renvoyer saisieChoix ?
}

void menuTourDeJeu(char NOMSDESJOUEURS[4][15])
{
    int choixMenu = 0;
    int saisieChoix = 0;
    //� quoi sert saisieChoix dans cette fonction ?  Il faudrait utiliser le m�me nom dans les 2 fonctions : soit choixMenu soit saisieChoix.  saisieChoix me semble mieux

    do
    {
        printf("\nC'est au tour de : ");
        Color(13,0);
        printf("%s\n", NOMSDESJOUEURS[0]); //il faut r�ussir � adapter l'affichage en fonction du joueur en question
        Color(15,0);
        printf("Selectionner une action : \n1.Lancer les DEs\n2.Deplacer le pion\n3.Afficher les informations d'une case\nMon choix : ");
        scanf("%d",&choixMenu);
    }while(choixMenu>3 || choixMenu<1);


    switch(choixMenu)
    {
        case 1 : Color(10,0); printf("Vous allez lancer les des");  Color(15,0);
//        lancerLesDes();

            break;
        case 2 : printf("Choix 2");
            break;
    }

}
