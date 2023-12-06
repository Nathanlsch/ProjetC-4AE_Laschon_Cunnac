#include "Trappe.h"
#include <iostream>
using namespace std;

Trappe::Trappe(){
  ServoTrap.attach(Pin_Servo_Trappe, Servo_Angle_O, Servo_Angle_180);
}

void Trappe::Open_Door(){
  ServoTrap.write(Valeur_Ouverture_Trappe);
}

void Trappe::Close_Door(){
  ServoTrap.write(Valeur_Fermeture_Trappe);
}
