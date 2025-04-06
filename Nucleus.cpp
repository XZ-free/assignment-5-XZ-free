#include "Nucleus.h"

Nucleus::Nucleus(double atomic_mass, int atomic_number, const std::string& nucleus_type)
    : atomic_mass(std::fabs(atomic_mass)), atomic_number(std::fabs(atomic_number)), nucleus_type(nucleus_type) {} // Initializes the nucleus with given mass, number, and type

void Nucleus::set_atomic_mass(double mass) {
    if(mass <=0) {
        std::cerr << "[Warning] Mass cannot be lower than zero. Absolute value is taken";
    }
    atomic_mass = std::fabs(mass); 
} // Assigns the atomic mass
double Nucleus::get_atomic_mass() const { return atomic_mass; } // Retrieves the atomic mass

void Nucleus::set_atomic_number(int number) { atomic_number = number; } // Assigns the atomic number
int Nucleus::get_atomic_number() const { return atomic_number; } // Retrieves the atomic number

void Nucleus::set_nucleus_type(const std::string& type) { nucleus_type = type; } // Assigns the nucleus type
std::string Nucleus::get_nucleus_type() const { return nucleus_type; } // Retrieves the nucleus type

void Nucleus::print_data() const {
    std::cout << "Nucleus: " << nucleus_type 
              << ", Atomic Number: " << atomic_number 
              << ", Atomic Mass: " << atomic_mass << std::endl;
} // Outputs the nucleus information
