#include "../include/Generator.h"

int generateRandomNumber(int min_value, int max_value)
{
    std::default_random_engine eng;
    unsigned long int t = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    eng.seed(t);
    static std::mt19937 gen(eng());
    std::uniform_int_distribution<> dist(min_value,max_value);
    return dist(gen);
}

std::string generateDNA(int length)
{
    std::vector<char> nucleotides {'A', 'C', 'T', 'G'};
    std::string sequence;
    for (int i {0}; i < length; i++)
    {
        sequence.push_back(nucleotides.at(generateRandomNumber(0,3)));
    }
    std::cout << "Sekwencja: " << sequence <<std::endl;
    return sequence;
}