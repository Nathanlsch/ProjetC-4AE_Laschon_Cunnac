#include <Servo.h>  // on inclut la bibliothèque servo

Servo servoMoteur;   // on crée un objet servo appelé servoMoteur

void setup(){ 
  // on associe le sero à la broche 2 d'Arduino
  servoMoteur.attach(2,554,2800);
}
 
void loop(){
  // on déplace le servo à la position 0º
  servoMoteur.write(0);
  delay(5000);  // pause de 1 seconde
  
  // on déplace le servo à la position 90º
  servoMoteur.write(180);
  delay(5000);  // pause 1 seconde
}






















/*#include "Application.h"
#include "Affichage.h"

Application myApplication;

void setup() 
{
  // put your setup code here, to run once:
  myApplication.init();
}

void loop() 
{
  // put your main code here, to run repeatedly:
  myApplication.run();
}*/
