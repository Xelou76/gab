#include "structures.h"

#define LONGUEUR_PLATEAU 31

///INITIALISATION
void InitaliserJoueurEtPlateau(t_joueur JOUEURS[4], t_caseDePlateau PLATEAUX[LONGUEUR_PLATEAU]);
int SaisirJoueurs(t_joueur JOUEURS[4]);

/// MENUS
int menu_Principal();
int menuTourDeJeu(t_caseDePlateau PLATEAUS[LONGUEUR_PLATEAU], t_joueur JOUEURS[4], int indiceJoueur, int indicePlateau );


///AFFICHAGE
void afficherPlateau(t_caseDePlateau TAB[LONGUEUR_PLATEAU], t_joueur JOUEURS[4], int nombreDeJoueur);
void affichage_Tableau(char TABLEAU[LONGUEUR_PLATEAU]);
void gotoligcol( int lig, int col );
void Color(int couleurDuTexte,int couleurDeFond);
void afficherOptions();
void afficherOptionsOuJeVeux(int lig, int col, int colTexte, int colFond);
void afficherInfosCase(t_caseDePlateau PLATEAUS[LONGUEUR_PLATEAU], int indicePlateau);


///DEROULEMENT JEU
void deroulementTourDeJeuUnJoueur(t_caseDePlateau PLATEAUS[LONGUEUR_PLATEAU], t_joueur JOUEURS[4], int indiceJoueur, int indicePlateau,int nombreJoueur);

///TRAITEMENTS
int tirage_Au_Sort(int* ptde,int* ptde2,int* ptde3,int* ptde4);
void AcheterPropriete(t_caseDePlateau PLATEAUS[LONGUEUR_PLATEAU], t_joueur JOUEURS[4], int indiceJoueur, int indicePlateau);
