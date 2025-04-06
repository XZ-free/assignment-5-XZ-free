#include "StableNucleus.h"

StableNucleus::StableNucleus(double atomic_mass, int atomic_number, const std::string& nucleus_type)
    : Nucleus(atomic_mass, atomic_number, nucleus_type) {} // Calls the base constructor with given values

void StableNucleus::print_data() const {
    std::cout << "Stable ";
    Nucleus::print_data();
} // Prepends "Stable" and then prints common nucleus data
