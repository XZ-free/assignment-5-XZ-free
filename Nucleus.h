#ifndef NUCLEUS_H
#define NUCLEUS_H

#include <iostream>
#include <string>
#include <cmath>
#include <utility>
/**
 * @brief 
 *  A base class for inheritance, storing atomic mass, atomic number, and a type string.
 */
class Nucleus {
protected:
    double atomic_mass;
    int atomic_number;
    std::string nucleus_type;

public:
    Nucleus(double atomic_mass, int atomic_number, const std::string& nucleus_type); // Constructor
    virtual ~Nucleus() = default; // Virtual destructor
    
    void set_atomic_mass(double mass); // Sets the atomic mass
    double get_atomic_mass() const; // Get the atomic mass
    
    void set_atomic_number(int number); // Sets the atomic number
    int get_atomic_number() const; // Get the atomic number
    
    void set_nucleus_type(const std::string& type); // Sets the nucleus type string
    std::string get_nucleus_type() const; // Get the nucleus type string
    
    virtual void print_data() const; // Prints nucleus data
};

#endif
