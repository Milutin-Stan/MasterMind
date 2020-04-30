//==============================================================
// Fichier : mastermind.h
//
// Role :     Déclaration de la classe Mastermind
//
// Date de creation : septembre 2014
// Auteur :           Thierry VAIRA (tvaira@free.fr)
// Etablissement :    LT LA SALLE Avignon  
//
// Evolution du document :
//
//==============================================================

#ifndef MASTERMIND_H
#define MASTERMIND_H

// valeurs par défaut
#define NB  4   // nombre de pions dans le code
#define MAX 10  // nombre d'essais maximum

// En mode débuggage, le code secret est affiché (cheat mode)
//#define DEBUG

class Mastermind
{
    private:
        int *secret;      // code secret
        int *essai;       // essai
      //  int *code;        // sauvegarde du code secret
        int nbBienPlaces;    // nombre de bien places
        int nbMalPlaces;     // nombre de mal places
        int redondance;      // indique si la redondance des couleurs dans le code est admise (=1)
        int tailleCode;      // nombre de pions de couleurs composant le code secret
        int nbEssaisMax;     // nombre d'essais maximum pour une partie
    //   int nbEssais;        // nombre d'essais
        bool fini;           // indique si la partie est terminée (=true)
        
    public:
        Mastermind(int redondance=0, int tailleCode=NB, int nbEssaisMax=MAX);
        ~Mastermind();
        void usage(); // affiche les règles du jeu
        void choisirSolution(); // génère (pseudo-)alératoirement le code secret
        void saisirEssai(); // assure la saisie du code par le joueur
        void verifierEssai(); // détermine le nombre de pions bien placés et mal placés
        void afficherResultat(); // affiche le résultat de l'essai et de la partie si celle-ci est finie
        bool estFinie(); // retourne vrai si la partie est finie sinon faux
        
    private:    
        int  bienPlaces(); // détermine et retourne le nombre de pions bien placés
        int  malPlaces();  // détermine et retourne le nombre de pions mal placés
};

#endif
