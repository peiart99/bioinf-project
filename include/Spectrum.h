#ifndef BIOINF_PROJECT_SPECTRUM_H
#define BIOINF_PROJECT_SPECTRUM_H
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <set>
#include "../include/Oligonucleotide.h"

class Spectrum {

private:
    std::string DNA;
    int oligo_length;
    std::vector<Oligonucleotide> oligos;

public:
    Spectrum(std::string _DNA, int _oligo_length);
    void generateOligonucleotides();
    void printOligos();

};


#endif //BIOINF_PROJECT_SPECTRUM_H
