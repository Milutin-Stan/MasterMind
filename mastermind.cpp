#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "mastermind.hpp"

using namespace std;


//Constructeur

Mastermind::Mastermind(int redondance,int tailleCode,int nbEssaisMax){
    this -> redondance = redondance;
    this -> tailleCode = tailleCode;
    this -> nbEssaisMax = nbEssaisMax;
    this -> secret = new int[4];
    this -> essai = new int[4];
    this -> nbBienPlaces=0;
    this -> nbMalPlaces=0;
    this -> fini=false;
}
Mastermind::~Mastermind(){
    
}




void Mastermind::usage(){
    cout << "L'utillisateur doir deviner 4couleurs et leurs emplacements pendant un certain nombre de tours"<<endl;
    cout << "L'ordi indiqura avec des pions combien de couleurs nous avons trouvé et combien de couleurs sont bien placées" <<endl;
}

void Mastermind::choisirSolution(){
    srand(time(NULL)); //Initializer le choix au hazard
    int r=0;
    
    for (int i=0; i<=3; i++){
        r=rand () % 8 + 1;//Entre 1 et 8
      
        secret[i]=r;
    }
    cout << secret[0] << endl;
    cout << secret[1] << endl;
    cout << secret[2] << endl;
    cout << secret[3] << endl;
}

void Mastermind::saisirEssai(){
    int a,b,c,d;
    
    cin >> a >> b >> c >> d;
    
    int i=0;
    essai[i]=a;
    i++;
    essai[i]=b;
    i++;
    essai[i]=c;
    i++;
    essai[i]=d;
}

int Mastermind::bienPlaces(){
    int b=0;
    for (int i=0;i<=3;i++){
        if(secret[i]==essai[i])
            b++;
    }
    return b;
}

int Mastermind::malPlaces(){
    int m=0;
    for (int i=0;i<=3;i++){
        
        for (int j=0;j<=3;j++){
            if(secret[i] == essai[j] && i!=j)
                m++;
        }
    }
    return m;
}

void Mastermind::verifierEssai(){

    this -> nbBienPlaces = bienPlaces();
    this -> nbMalPlaces = malPlaces();
}

void Mastermind::afficherResultat(){
    
    cout <<"R = " << this -> nbBienPlaces << endl;
    cout <<"B = " << this -> nbMalPlaces << endl << endl << endl;
}

bool Mastermind::estFinie(){
    if(this -> nbBienPlaces == 4)
      return true;
}
