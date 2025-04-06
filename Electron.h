// Brief: An electron class derived from Particle, capable of radiating photons.
#ifndef ELECTRON_H
#define ELECTRON_H

#include "Particle.h"
#include <vector>
#include <memory>

class Photon; // Forward declaration

class Electron : public Particle {
private:
    std::vector<std::unique_ptr<Photon>> radiated_photons; // Stores photons emitted by the electron

public:
    Electron(double rest_mass, double energy); // Constructor for Electron
    virtual ~Electron() = default; // Default destructor
    
    Electron(const Electron& other); // Copy constructor
    Electron& operator=(const Electron& other); // Copy assignment
    Electron(Electron&& other) noexcept; // Move constructor
    Electron& operator=(Electron&& other) noexcept; // Move assignment
    
    virtual void print_data() const override; // Prints electron energy and rest mass
    
    virtual Particle* clone() const override; // Clones this electron
    
    friend std::unique_ptr<Photon> radiate(Electron& electron); // Friend function to radiate a photon
};

#endif
