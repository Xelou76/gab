#ifndef BIBLIO_FONCTION_PRÈPARATION_H_INCLUDED

#define BIBLIO_FONCTION_PRÈPARATION_H_INCLUDED
#include "structures.h"

#define Lenghtableau 5
#define LENTABLEAU 32
#define NOMBRE_DE_CASES_DU_PLATEAU 32
#define NOMBRE_DE_JOUEURS 2


/// MENUS
int menuPrincipal(Joueur joueurs[4], CaseDePlateau plateauDeJeu[NOMBRE_DE_CASES_DU_PLATEAU]);
void menuTourDeJeu(char NOMSDESJOUEURS[4][15]);


///Affichage
void afficherPlateau(CaseDePlateau plateauDeJeu[NOMBRE_DE_CASES_DU_PLATEAU], Joueur joueurs[NOMBRE_DE_JOUEURS] );
void afficherTableau(char TABLEAU[LENTABLEAU]);
void gotoligcol( int lig, int col );
void Color(int couleurDuTexte,int couleurDeFond);
void afficherOptions();
void afficherOptionsOuJeVeux(int lig, int col, int colTexte, int colFond);
void afficherInfosCase();


///SAISIE / JEU

void initialiserJeu(Joueur joueurs[4], CaseDePlateau plateauDeJeu[NOMBRE_DE_CASES_DU_PLATEAU]);
int saisirJoueursDansTableau (char NOMSDESJOUEURS[4][15]);
int lancerLesDes(int* ptde,int* ptde2,int* ptde3,int* ptde4);

#endif // BIBLIO_FONCTION_PRÈPARATION_H_INCLUDED
