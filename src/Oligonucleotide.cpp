#include "../include/Oligonucleotide.h"

Oligonucleotide::Oligonucleotide(std::string _data):
used{false}, data{_data} {

}

void Oligonucleotide::printData() {
    std::cout << "Data: " << data << std::endl;
}

