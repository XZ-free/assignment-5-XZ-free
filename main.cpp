#include <iostream>
#include <vector>
#include <memory>
#include "StableNucleus.h"
#include "RadioactiveNucleus.h"
#include "Photon.h"
#include "Electron.h"
/**
 * @brief 
 *  1. This assignment assumes positron anihilated with surrounding electron 
 * immediately after it is produced and became into two photons.
 *  2. StableNucleus does not contain decay method and calling it will cause program suspension
 *  3. Testing process follows the logic of:
 * create nuclei -> decay -> pair production -> radiation -> photoelectric -> compton scattering
 * 
 * This assignment uses generative AI to help with debug and grammar check.
 */
int main() {
    std::vector<std::unique_ptr<Nucleus>> nuclei;
    
    nuclei.push_back(std::make_unique<RadioactiveNucleus>(22.0, 11, "Na", 2.6));
    nuclei.push_back(std::make_unique<RadioactiveNucleus>(137.0, 55, "Cs", 30.0));
    nuclei.push_back(std::make_unique<RadioactiveNucleus>(60.0, 27, "Co", 5.3));
    nuclei.push_back(std::make_unique<StableNucleus>(56.0, 26, "Fe"));
    
    std::vector<std::unique_ptr<Photon>> all_photons;
    
    for(auto& nucleus : nuclei) {
        if(auto r_nucleus = dynamic_cast<RadioactiveNucleus*>(nucleus.get())) {
            std::cout << "\nDecaying nucleus: " << r_nucleus->get_nucleus_type() << std::endl;
            auto photons = r_nucleus->decay();
            for(auto& ph : photons) {
                all_photons.push_back(std::move(ph));
            }
        } else {
            std::cout << "\nStable nucleus: " << nucleus->get_nucleus_type() 
                      << " does not decay." << std::endl;
        }
    }
    
    for(auto& photon : all_photons) {
        std::cout << "\nPhoton before interaction: ";
        photon->print_data();
        
        auto electrons = pair_production(*photon);
        if(electrons.empty()) {
            std::cout << "Pair production not possible for this photon." << std::endl;
        } else {
            std::cout << "Pair production produced " << electrons.size() << " electrons." << std::endl;
            std::cout << "\nElectron before radiation: ";
            electrons[0]->print_data();
            auto radiated_photon = radiate(*electrons[0]);
            if(radiated_photon) {
                std::cout << "Radiated photon: ";
                radiated_photon->print_data();
            }
            std::cout << "Electron after radiation: ";
            electrons[0]->print_data();
        }
        
        double pe_energy = photoelectric_effect(*photon);
        std::cout << "Photoelectric effect: Photon energy = " << pe_energy << " MeV" << std::endl;
        
        double theta = 60.0 * M_PI / 180.0;
        compton_effect(*photon, theta);
        std::cout << "After Compton effect: ";
        photon->print_data();
    }
    
    return 0;
}
