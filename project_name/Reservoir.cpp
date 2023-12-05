#include "Reservoir.h"
#include <iostream>
using namespace std;

Reservoir::Reservoir():CapteurUltrason(Pin_Capteur_Ultrason){
    this->Vide=EtatReservoir();
    this->Dist_Fond = 150;
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
  this->Dist_Fond = CapteurUltrason.MeasureInMillimeters();
  this->Vide = EtatReservoir();
}

void Reservoir::Affichage(){
  cout << "Distance : " << Dist_Fond << " cm" << endl;
}

long Reservoir::Pourcentage(){
  return (long)(-0.83*this->Dist_Fond+124.9);
}
