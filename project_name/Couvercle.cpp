#include "Couvercle.h"
#include <iostream>
using namespace std;

Couvercle::Couvercle(){
  ServoCouv.attach(Pin_Servo_Couvercle, Servo_Angle_O, Servo_Angle_180);
}

void Couvercle::Open_Door(){
  ServoCouv.write(Valeur_Ouverture_Couvercle);
}

void Couvercle::Close_Door(){
  ServoCouv.write(Valeur_Fermeture_Couvercle);
}