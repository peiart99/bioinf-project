#include "../include/Spectrum.h"

Spectrum::Spectrum(std::string _DNA, int _oligo_length)
: DNA {_DNA}, oligo_length{_oligo_length}
{
    std::cout << DNA << std::endl;
}

void Spectrum::generateOligonucleotides() {
    std::set<std::string> unique_oligos;
    for(int i {0}; i <= (DNA.length() - oligo_length); i++)
    {
        std::string oligo {DNA.substr(i, oligo_length)};
        std::cout << oligo << std::endl;
        if(unique_oligos.find(oligo) == unique_oligos.end())
        {
            std::cout << "Duplicate" << std::endl;
        }else
        {
            unique_oligos.emplace(oligo);
            Oligonucleotide new_oligo(oligo);
            oligos.push_back(std::move(new_oligo));
        }
    }
}

void Spectrum::printOligos() {
    for(auto oligo : oligos)
    {
        oligo.printData();
    }
}

