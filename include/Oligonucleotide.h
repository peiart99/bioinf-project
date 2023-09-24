#ifndef BIOINF_PROJECT_OLIGONUCLEOTIDE_H
#define BIOINF_PROJECT_OLIGONUCLEOTIDE_H
#include <iostream>
#include <vector>
#include <memory>
#include "../include/Oligonucleotide.h"

class Oligonucleotide {
private:
    bool used;
    std::string data;
    std::vector<std::pair<std::shared_ptr<Oligonucleotide>, int>> connected_oligos;

public:
    explicit Oligonucleotide(std::string _data);
    void printData();
};


#endif //BIOINF_PROJECT_OLIGONUCLEOTIDE_H
