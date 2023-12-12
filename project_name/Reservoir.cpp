/*********************************************************************
 * @file  Reservoir.cpp
 * @brief Fichier source de la classe Reservoir
 *********************************************************************/
#include "Reservoir.h"
#include <iostream>
using namespace std;

Reservoir::Reservoir()
  : CapteurUltrason(Pin_Capteur_Ultrason) {
  this->Vide = EtatReservoir();
  this->Dist_Fond = 90;
}

Reservoir::~Reservoir() {
}

bool Reservoir::getVide() {
  return this->Vide;
}

bool Reservoir::EtatReservoir() {
  if (Dist_Fond >= Dist_Max) {
    return true;
  } else {
    return false;
  }
}

void Reservoir::MAJ() {
  this->Dist_Fond = CapteurUltrason.MeasureInMillimeters();   // Mesure la distance jusqu'au fond du réservoir
  this->Vide = EtatReservoir();        // Met à jour l'état du réservoir en fonction de la nouvelle distance
}

void Reservoir::Affichage() {
  cout << "Distance : " << Dist_Fond << " mm" << endl;
  delay(1000);
}

long Reservoir::Pourcentage() {
  const long reservoirLength = 90;  // he reservoir length is 90mm

  // Ensure the distance is within the valid range (0 to reservoirLength)
  long clampedDist = std::max(0L, std::min(reservoirLength, this->Dist_Fond));

  // Calculate the percentage based on linear interpolation with floating point division
  double percentage = 100 - static_cast<double>(clampedDist - 20) / 70 * 100;

  // Ensure that the percentage is within the valid range (0 to 100)
  percentage = std::max(0.0, std::min(100.0, percentage));

  Serial.println(percentage);

  return static_cast<long>(percentage);
}