#include "Couvercle.h"
#include <iostream>
using namespace std;

Couvercle::Couvercle(){
  ServoCouv.attach(Pin_Servo_Couvercle, Servo_Angle_O, Servo_Angle_180);
  ServoCouv.write(Valeur_Fermeture_Couvercle);
  etat = 0;
}

void Couvercle::Open_Door(){
  ServoCouv.write(Valeur_Ouverture_Couvercle);
}

void Couvercle::Close_Door(){
  ServoCouv.write(Valeur_Fermeture_Couvercle);
}

void Couvercle::gestionCouvercle(){
  if(etat==0){
    Serial.println("etat0");
    this->etat = 1;
    this->Open_Door();
  } else {
    this->etat = 0;
    Serial.println("etat1");
    this->Close_Door();
  }
}