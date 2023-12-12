/*********************************************************************
 * @file  conf.h
 * @brief Fichier de configuration
 *********************************************************************/

#ifndef CONF_H
#define CONF_H

// Configuration pour l'affichage
#define NbLed 24  // Nombre de LEDs utilisées
#define DataIn 4  // Broche de données pour l'affichage

// Configuration pour le réservoir
#define Pin_Capteur_Ultrason 13  // Broche du capteur ultrason
#define Dist_Max 0               // Distance maximale pour considérer le réservoir comme plein
#define dist_fond_vide 90.0        // Distance jusqu'au fond du réservoir indiquant qu'il est vide
#define Dist_Max_Capteur 20      // Distance max considéré pour le capteur ne beug pas

// Configuration pour la porte et ses classes filles
#define Servo_Angle_0 580               // Angle du servo pour position 0 degré
#define Servo_Angle_180 2400            // Angle du servo pour position 180 degrés

// Configuration pour la trappe
#define Pin_Servo_Trappe 14             // Broche du servo pour la trappe
#define Valeur_Ouverture_Trappe 90       // Valeur d'ouverture de la trappe 
#define Valeur_Fermeture_Trappe 0      // Valeur de fermeture de la trappe 

// Configuration pour le couvercle
#define Pin_Servo_Couvercle 0           // Broche du servo pour le couvercle
#define Valeur_Ouverture_Couvercle 180  // Valeur d'ouverture du couvercle 
#define Valeur_Fermeture_Couvercle 0    // Valeur de fermeture du couvercle 

#endif