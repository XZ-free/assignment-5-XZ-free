#include "RadioactiveNucleus.h"
#include <iostream>

RadioactiveNucleus::RadioactiveNucleus(double atomic_mass, int atomic_number, const std::string& nucleus_type, double half_life)
    : Nucleus(atomic_mass, atomic_number, nucleus_type), half_life(half_life), decayed(false) {} // Initializes base and radioactive-specific members

RadioactiveNucleus::~RadioactiveNucleus() {
    // emitted_photons will be cleared automatically by unique_ptr
} // Destructor ensures proper clean-up of photon pointers

RadioactiveNucleus::RadioactiveNucleus(const RadioactiveNucleus& other)
    : Nucleus(other.atomic_mass, other.atomic_number, other.nucleus_type),
      half_life(other.half_life),
      decayed(other.decayed)
{
    for (const auto& photon : other.emitted_photons) {
        if (photon)
            emitted_photons.push_back(std::unique_ptr<Photon>(static_cast<Photon*>(photon->clone())));
    }
} // Copy constructor performs deep copy of photons

RadioactiveNucleus& RadioactiveNucleus::operator=(const RadioactiveNucleus& other) {
    if (this == &other) return *this;
    atomic_mass = other.atomic_mass;
    atomic_number = other.atomic_number;
    nucleus_type = other.nucleus_type;
    half_life = other.half_life;
    decayed = other.decayed;
    emitted_photons.clear();
    for (const auto& photon : other.emitted_photons) {
        if (photon)
            emitted_photons.push_back(std::unique_ptr<Photon>(static_cast<Photon*>(photon->clone())));
    }
    return *this;
} // Copy assignment operator with deep copy logic

RadioactiveNucleus::RadioactiveNucleus(RadioactiveNucleus&& other) noexcept
    : Nucleus(other.atomic_mass, other.atomic_number, other.nucleus_type),
      half_life(other.half_life),
      decayed(other.decayed),
      emitted_photons(std::move(other.emitted_photons))
{
    other.decayed = false;
} // Move constructor transfers resources from 'other'

RadioactiveNucleus& RadioactiveNucleus::operator=(RadioactiveNucleus&& other) noexcept {
    if (this == &other) return *this;
    atomic_mass = other.atomic_mass;
    atomic_number = other.atomic_number;
    nucleus_type = other.nucleus_type;
    half_life = other.half_life;
    decayed = other.decayed;
    emitted_photons = std::move(other.emitted_photons);
    other.decayed = false;
    return *this;
} // Move assignment operator for transferring ownership

void RadioactiveNucleus::set_half_life(double hl) { half_life = hl; } // Modifies the half-life
double RadioactiveNucleus::get_half_life() const { return half_life; } // Returns the current half-life

bool RadioactiveNucleus::has_decayed() const { return decayed; } // Indicates if the nucleus has already decayed

std::vector<std::unique_ptr<Photon>> RadioactiveNucleus::decay() {
    if(decayed) {
        std::cerr << "Nucleus has already decayed." << std::endl;
        return {};
    }
    
    std::vector<std::unique_ptr<Photon>> photons;
    
    if(nucleus_type == "Cs") {
        double energy = 0.661;
        auto photon = std::make_unique<Photon>(energy);
        photon->print_data();
        photons.push_back(std::move(photon));
    }
    else if(nucleus_type == "Na") {
        double energy_gamma = 1.2745;
        auto photon_gamma = std::make_unique<Photon>(energy_gamma);
        photon_gamma->print_data();
        photons.push_back(std::move(photon_gamma));
        
        double energy_anni = 0.511;
        auto photon_anni1 = std::make_unique<Photon>(energy_anni);
        photon_anni1->print_data();
        photons.push_back(std::move(photon_anni1));
        
        auto photon_anni2 = std::make_unique<Photon>(energy_anni);
        photon_anni2->print_data();
        photons.push_back(std::move(photon_anni2));
    }
    else if(nucleus_type == "Co") {
        double energy1 = 1.173;
        auto photon1 = std::make_unique<Photon>(energy1);
        photon1->print_data();
        photons.push_back(std::move(photon1));
        
        double energy2 = 1.333;
        auto photon2 = std::make_unique<Photon>(energy2);
        photon2->print_data();
        photons.push_back(std::move(photon2));
    }
    else {
        std::cerr << "Decay mode for " << nucleus_type << " not implemented." << std::endl;
    }
    
    decayed = true;
    if (!photons.empty()) {
        emitted_photons.push_back(std::unique_ptr<Photon>(static_cast<Photon*>(photons[0]->clone())));
    }
    
    return photons;
} // Produces decay photons depending on the nucleus type and sets decayed to true

void RadioactiveNucleus::print_data() const {
    std::cout << "Radioactive Nucleus: " << nucleus_type 
              << ", Atomic Number: " << atomic_number 
              << ", Atomic Mass: " << atomic_mass 
              << ", Half-life: " << half_life << " s" << std::endl;
} // Outputs all relevant radioactive nucleus info
