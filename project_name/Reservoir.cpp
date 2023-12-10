#include "Reservoir.h"
#include <iostream>
using namespace std;

Reservoir::Reservoir():CapteurUltrason(Pin_Capteur_Ultrason){
    this->Vide=EtatReservoir();
    this->Dist_Fond = 79;
  }

Reservoir::~Reservoir(){

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
  cout << "Distance : " << Dist_Fond << " mm" << endl;
  delay(1000);
}

long Reservoir::Pourcentage() {
  const long reservoirLength = 68;  // Assuming the reservoir length is 68mm

  // Ensure the distance is within the valid range (0 to reservoirLength)
  long clampedDist = max(0L, min(reservoirLength, this->Dist_Fond));

  // Calculate the percentage based on linear interpolation
  long percentage = 100 - ((clampedDist * 100) / reservoirLength);

  cout << percentage << endl;
  return percentage;
}