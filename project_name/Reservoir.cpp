#include "Reservoir.h"
#include <iostream>
using namespace std;

Reservoir::Reservoir():CapteurUltrason(Pin_Capteur_Ultrason){
    this->Vide = false;
    this->Dist_Max = CapteurUltrason.MeasureInCentimeters();
  }

bool Reservoir::getVide(){
  return this->Vide;
}

/*Reservoir::setVide(bool Etat){
      Vide = Etat;
}*/

bool Reservoir::EtatReservoir(){
  if (Dist_Fond >= Dist_Max){
    return true;
  }else{
    return false;
  }
}

void Reservoir::MAJ(){
  this->Dist_Fond = CapteurUltrason.MeasureInCentimeters();
  this->Vide = EtatReservoir();
}

void Reservoir::Affichage(){
  cout << "Distance : " << Dist_Fond << " cm" << endl;
}

