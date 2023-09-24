#ifndef BIOINF_PROJECT_GREEDY_H
#define BIOINF_PROJECT_GREEDY_H

#include <iostream>
#include "../include/Spectrum.h"

std::string greedyAlgorithm(std::string sequence, int oligo_length, int negative_error_percentage, int positive_error_percentage);

#endif //BIOINF_PROJECT_GREEDY_H