#include "Photon.h"
#include "Electron.h"
#include <iostream>
#include <cmath>

Photon::Photon(double energy)
    : Particle(0.0, energy) {} // Initializes photon with zero rest mass and given energy

Photon::Photon(const Photon& other)
    : Particle(other.rest_mass, other.energy), associated_electrons() {} // Copy constructor clears associated electrons

Photon& Photon::operator=(const Photon& other) {
    if(this != &other) {
        rest_mass = other.rest_mass;
        energy = other.energy;
        associated_electrons.clear();
    }
    return *this;
} // Copy assignment assigns mass/energy and clears association

Photon::Photon(Photon&& other) noexcept
    : Particle(other.rest_mass, other.energy),
      associated_electrons(std::move(other.associated_electrons)) {} // Move constructor transfers associated electrons

Photon& Photon::operator=(Photon&& other) noexcept {
    if(this != &other) {
        rest_mass = other.rest_mass;
        energy = other.energy;
        associated_electrons = std::move(other.associated_electrons);
    }
    return *this;
} // Move assignment operator

void Photon::print_data() const {
    std::cout << "Photon: Energy = " << energy << " MeV" << std::endl;
} // Prints photon energy

Particle* Photon::clone() const {
    return new Photon(*this);
} // Returns a copy of this photon

double photoelectric_effect(const Photon& photon) {
    return photon.energy;
} // Photoelectric effect simply returns photon's energy

void compton_effect(Photon& photon, double theta) {
    double m_e = 0.511;
    double new_energy = photon.energy / (1 + (photon.energy / m_e) * (1 - std::cos(theta)));
    photon.energy = new_energy;
} // Compton effect updates photon energy based on scattering angle

std::vector<std::unique_ptr<Electron>> pair_production(Photon& photon) {
    std::vector<std::unique_ptr<Electron>> electrons;
    double m_e = 0.511;
    if(photon.energy > 2 * m_e) {
        double electron_total_energy = m_e + (photon.energy / 2.0);
        auto e1 = std::make_unique<Electron>(m_e, electron_total_energy);
        auto e2 = std::make_unique<Electron>(m_e, electron_total_energy);
        electrons.push_back(std::move(e1));
        electrons.push_back(std::move(e2));
    } else {
        std::cerr << "Error: Photon energy insufficient for pair production." << std::endl;
    }
    return electrons;
} // Creates two electrons if energy > 2*m_e, otherwise returns empty
