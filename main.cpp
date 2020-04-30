//==============================================================
// Programme : mastermind
//
// Role :     Jeu du Mastermind
//
// Principe : Saisie d'un code secret
//            Saisie d'un essai et le compare au code secret
//            Affichage du nombre de chiffres bien et mal places
//
// Version : 
// Date de creation : 
// Auteur :           
// Etablissement :
//
//==============================================================
#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "mastermind.hpp"
// Programme principal
int main() 
{
    // TODO :
    
    // 1. Instancier un objet de type Mastermind en utilisant le constructeur par défaut
    Mastermind m1;
    
    // Avant de jouer, il est conseillé d'afficher les règles du jeu
    m1.usage();
    
    // 2. Implémenter le diagramme de séquence "jouer une manche"
    int f=0;
    m1.choisirSolution();
    while (m1.estFinie()==false || f == 10){
       
    m1.saisirEssai();
    m1.verifierEssai();
    m1.afficherResultat();
    m1.estFinie();
    f++;
    
    }
    return 0;
}

