#ifndef BIOINF_PROJECT_GENERATOR_H
#define BIOINF_PROJECT_GENERATOR_H

#include <string>
#include <iostream>
#include <random>
#include <chrono>
#include <vector>
#include <algorithm>

int generateRandomNumber(int min_value, int max_value);
std::string generateDNA(int length);
int levenshteinDistance(std::string original, std::string reconstructed);

#endif //BIOINF_PROJECT_GENERATOR_H
