#ifndef STABLENUCLEUS_H
#define STABLENUCLEUS_H

#include "Nucleus.h"
/**
 * @brief 
 *  A derived class representing a stable nucleus (no decay functionality).
 */
class StableNucleus : public Nucleus {
public:
    StableNucleus(double atomic_mass, int atomic_number, const std::string& nucleus_type); // Constructor
    virtual ~StableNucleus() = default; // Default virtual destructor
    
    virtual void print_data() const override; // Prints data for a stable nucleus
};

#endif
