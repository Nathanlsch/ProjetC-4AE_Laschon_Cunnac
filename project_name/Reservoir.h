#ifndef RESERVOIR_H
#define RESERVOIR_H
#include "Ultrasonic.h"
#include "conf_flo.h"

class Reservoir{
    
    private:
    
    bool Vide;
    Ultrasonic CapteurUltrason;
    
    public:

    //Constructeur
    Reservoir();
    //Destructeur
    ~Reservoir();

    //Get et set pour avoir l'état du réservoir
    /*getVide -> Retourne l'état du réservoir 
    Fonctionnement général : Capteur ultrasons capte la distance avec les croquettes
                            Si cette distance augmente c'est que le niveau de croquettes descend.
                            Le réservoir devient vide à partir d'une certaine distance. Donc si d > dmax => Vide = true
                            */
    bool getVide();          
    void setVide(bool Etat);

    bool EtatReservoir();
};

#endif
