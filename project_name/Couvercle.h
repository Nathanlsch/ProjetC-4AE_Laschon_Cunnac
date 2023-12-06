#ifndef COUVERCLE_H
#define COUVERCLE_H
#include "Porte.h"
#include <Servo.h>
#include "conf_flo.h"

class Couvercle : public Porte{

  private:

  Servo ServoCouv;

  public:

  //Constructor
  Couvercle();

  void Open_Door();
  void Close_Door();

};

#endif