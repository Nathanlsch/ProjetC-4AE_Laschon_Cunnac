#ifndef TRAPPE_H
#define TRAPPE_H
#include "Porte.h"
#include <Servo.h>
#include "conf_flo.h"



class Trappe : public Porte{

  private :
    Servo ServoTrap;
  public :

  //Constructor
  Trappe();

  //Functions
  void Open_Door();
  void Close_Door();

};

#endif