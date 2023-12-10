#include "Trappe.h"
#include <iostream>
using namespace std;

Trappe::Trappe(){
  ServoTrap.attach(Pin_Servo_Trappe, 700,2200);
}

void Trappe::Open_Door(){
  ServoTrap.write(Valeur_Ouverture_Trappe);
}

void Trappe::Close_Door(){
  ServoTrap.write(Valeur_Fermeture_Trappe);
}

void Trappe::Distribution(){
  this->Open_Door();
  delay(200);
  this->Close_Door();
}
