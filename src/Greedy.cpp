#include "../include/Greedy.h"

std::string greedyAlgorithm(std::string sequence, int oligo_length, int negative_error_percentage, int positive_error_percentage)
{
    Spectrum spectrum(sequence, oligo_length);
    spectrum.generateOligonucleotides();
    if(negative_error_percentage > 0)
    {
        spectrum.addNegativeErrors(negative_error_percentage);
    }
    if(positive_error_percentage > 0)
    {
        spectrum.addPositiveErrors(positive_error_percentage);
    }
    spectrum.connectOligos();
    std::string result = spectrum.greedyAlgorithm();
    //std::cout << "Result: " << result << std::endl;
    return spectrum.getResult();
}