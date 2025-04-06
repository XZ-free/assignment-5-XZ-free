#include "Electron.h"
#include "Photon.h"
#include <iostream>
#include <random>

Electron::Electron(double rest_mass, double energy)
    : Particle(rest_mass, energy) {} // Initializes electron with given rest mass and energy

Electron::Electron(const Electron& other)
    : Particle(other.rest_mass, other.energy), radiated_photons() {} // Copy constructor does not copy radiated photons

Electron& Electron::operator=(const Electron& other) {
    if(this != &other) {
        rest_mass = other.rest_mass;
        energy = other.energy;
        radiated_photons.clear();
    }
    return *this;
} // Copy assignment resets local photon list

Electron::Electron(Electron&& other) noexcept
    : Particle(other.rest_mass, other.energy), radiated_photons(std::move(other.radiated_photons)) {} // Move constructor

Electron& Electron::operator=(Electron&& other) noexcept {
    if(this != &other) {
        rest_mass = other.rest_mass;
        energy = other.energy;
        radiated_photons = std::move(other.radiated_photons);
    }
    return *this;
} // Move assignment transfers radiated photons

void Electron::print_data() const {
    std::cout << "Electron: Energy = " << energy 
              << " MeV, Rest Mass = " << rest_mass << " MeV" << std::endl;
} // Prints electron data

Particle* Electron::clone() const {
    return new Electron(*this);
} // Returns a new Electron copy

/**
 * @brief 
 * As requested by assignment to explain, exception of using @brief is used here.
 * random number from 0 to 0.99 is introduced here in order to take kinetic energy
 * away from electron and generate photon. for static electron, this function will throw error msg.
 */
std::unique_ptr<Photon> radiate(Electron& electron) {
    double kinetic_energy = electron.energy - electron.rest_mass;
    if(kinetic_energy <= 0) {
        std::cerr << "Electron has no kinetic energy to radiate." << std::endl;
        return nullptr;
    }
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 0.99);
    double fraction = dis(gen);
    double photon_energy = fraction * kinetic_energy;
    electron.energy -= photon_energy;
    auto photon = std::make_unique<Photon>(photon_energy);
    electron.radiated_photons.push_back(std::make_unique<Photon>(photon_energy));
    return photon;
} // Radiates a photon with random fraction of the electron's kinetic energy
