#include <iostream>
#include "include/Generator.h"
#include "include/Spectrum.h"

int main()
{
//    for(int i {0}; i < 100; i++)
//        generateDNA(500);
    std::string dena;
    dena = generateDNA(16);
    Spectrum spec(dena, 4);
    spec.generateOligonucleotides();
    spec.printOligos();

    return 0;
}