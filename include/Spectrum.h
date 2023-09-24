#ifndef BIOINF_PROJECT_SPECTRUM_H
#define BIOINF_PROJECT_SPECTRUM_H
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <set>
#include <cmath>
#include "../include/Oligonucleotide.h"
#include "../include/Generator.h"

class Spectrum {

private:
    std::string DNA;
    std::string result_DNA;
    int oligo_length;
    int duplicates;
    std::set<std::string> unique_oligos;
    std::vector<std::shared_ptr<Oligonucleotide>> oligos;

public:
    Spectrum(std::string _DNA, int _oligo_length);
    void generateOligonucleotides();
    void connectOligos();
    void printOligos();
    void addPositiveErrors(double percentage);
    void addNegativeErrors(double percentage);
    std::string greedyAlgorithm();
    void traverseOligos(std::shared_ptr<Oligonucleotide> oligo);
    void sortOligoConnections();
    std::string getResult();


};


#endif //BIOINF_PROJECT_SPECTRUM_H
