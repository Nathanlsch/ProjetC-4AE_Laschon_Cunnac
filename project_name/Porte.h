#ifndef PORTE_H
#define PORTE_H
#include <Servo.h>
#include "conf_flo.h"

class Porte{

  private:
  
  public:

  //Constructor
  Porte();

  //Function 
  virtual void Open_Door();
  virtual void Close_Door();


};

#endif