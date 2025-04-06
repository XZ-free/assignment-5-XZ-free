#include "Particle.h"

Particle::Particle(double rest_mass, double energy)
    : rest_mass(rest_mass), energy(energy) {} // Initializes rest mass and energy

void Particle::set_rest_mass(double mass) { rest_mass = mass; } // Assigns rest mass
double Particle::get_rest_mass() const { return rest_mass; } // Returns rest mass

void Particle::set_energy(double e) { energy = e; } // Assigns total energy
double Particle::get_energy() const { return energy; } // Returns total energy

void Particle::print_data() const {
    std::cout << "Particle: Rest Mass = " << rest_mass 
              << " MeV, Energy = " << energy << " MeV" << std::endl;
} // Prints particle details
