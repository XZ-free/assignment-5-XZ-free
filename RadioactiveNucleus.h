#ifndef RADIOACTIVENUCLEUS_H
#define RADIOACTIVENUCLEUS_H

#include "Nucleus.h"
#include <memory>
#include <vector>
#include "Photon.h"
/**
 * @brief 
 *  A derived class for radioactive nuclei, adding half-life and decay functionalities.
 */
class RadioactiveNucleus : public Nucleus {
private:
    double half_life; // Half-life in some time units
    bool decayed; // Indicates whether the nucleus has already decayed
    std::vector<std::unique_ptr<Photon>> emitted_photons; // Photons produced upon decay

public:
    RadioactiveNucleus(double atomic_mass, int atomic_number, const std::string& nucleus_type, double half_life); // Constructor
    ~RadioactiveNucleus(); // Destructor
    
    RadioactiveNucleus(const RadioactiveNucleus& other); // Copy constructor
    RadioactiveNucleus& operator=(const RadioactiveNucleus& other); // Copy assignment
    RadioactiveNucleus(RadioactiveNucleus&& other) noexcept; // Move constructor
    RadioactiveNucleus& operator=(RadioactiveNucleus&& other) noexcept; // Move assignment
    
    void set_half_life(double half_life); // Sets the half-life
    double get_half_life() const; // Returns the half-life
    
    bool has_decayed() const; // Checks if decay occurred
    
    std::vector<std::unique_ptr<Photon>> decay(); // Performs decay and returns produced photons
    
    virtual void print_data() const override; // Prints data for a radioactive nucleus
};

#endif
