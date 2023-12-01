#ifndef RESERVOIR_H
#define RESERVOIR_H
#include "Ultrasonic.h"
#include "conf_flo.h"

class Reservoir{
    
    private:
    
    bool Vide;
    long Dist_Fond;
    long Dist_Max = 15;
    Ultrasonic CapteurUltrason;
    
    public:

    //Constructeur
    Reservoir();
    //Destructeur
    ~Reservoir();

    /*getVide -> Retourne l'état du réservoir 
    EtatReservoir retourne vrai si la distance mesurée par le capteur est supérieur à la distance max établit
    Fonctionnement général : Capteur ultrasons capte la distance avec les croquettes
                            Si cette distance augmente c'est que le niveau de croquettes descend.
                            Le réservoir devient vide à partir d'une certaine distance. Donc si d > dmax => Vide = true
                            */
    bool getVide();          
    bool EtatReservoir();
    void MAJ();
    void Affichage();
};

#endif
