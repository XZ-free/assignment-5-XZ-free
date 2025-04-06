
#ifndef PHOTON_H
#define PHOTON_H

#include "Particle.h"
#include <vector>
#include <memory>
#include "Electron.h"
/**
 * @brief 
 * A photon class derived from Particle, representing a massless particle with possible electron association.
 */
class Photon : public Particle {
private:
    std::vector<std::unique_ptr<Electron>> associated_electrons; // Holds electrons created by pair production

public:
    Photon(double energy); // Constructor for Photon
    virtual ~Photon() = default; // Default destructor
    
    Photon(const Photon& other); // Copy constructor
    Photon& operator=(const Photon& other); // Copy assignment
    Photon(Photon&& other) noexcept; // Move constructor
    Photon& operator=(Photon&& other) noexcept; // Move assignment
    
    virtual void print_data() const override; // Prints photon's energy
    
    virtual Particle* clone() const override; // Clones this photon
    
    friend double photoelectric_effect(const Photon& photon); // Friend function for photoelectric effect
    friend void compton_effect(Photon& photon, double theta); // Friend function for Compton scattering
    friend std::vector<std::unique_ptr<Electron>> pair_production(Photon& photon); // Friend function for pair production
};

#endif
