#ifndef PARTICLE_H
#define PARTICLE_H

#include <iostream>
/**
 * @brief 
 *  Abstract base class for inheritance, storing rest mass and total energy.
 */
class Particle {
protected:
    double rest_mass; // Rest mass in MeV
    double energy; // Total energy in MeV

public:
    Particle(double rest_mass, double energy); // Constructor
    virtual ~Particle() = default; // Virtual destructor
    
    void set_rest_mass(double mass); // Sets the rest mass
    double get_rest_mass() const; // Gets the rest mass
    
    void set_energy(double energy); // Sets the total energy
    double get_energy() const; // Gets the total energy
    
    virtual void print_data() const; // Prints particle info
    
    virtual Particle* clone() const = 0; // Pure virtual method for cloning
};

#endif
