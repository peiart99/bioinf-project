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
    //std::cout << "Sekwencja: " << sequence <<std::endl;
    return sequence;
}

int levenshteinDistance(std::string original, std::string reconstructed)
{
    std::vector<std::vector<int>> matrix(original.size() + 1, std::vector<int>(reconstructed.size() + 1));
    int cost = 0;

    for(int i {0}; i <= original.size(); i++)
    {
        matrix.at(i).at(0) = i;
    }
    for(int j {0}; j <= reconstructed.size(); j++)
    {
        matrix.at(0).at(j) = j;
    }

    for(int i {1}; i <= original.size(); i++)
    {
        for(int j {1}; j <= reconstructed.size(); j++)
        {
            if(reconstructed.at(j - 1) == original.at(i - 1))
            {
                cost = 0;
            }else
            {
                cost = 1;
            }
            matrix.at(i).at(j) = std::min(
                    matrix.at(i-1).at(j) + 1,
                    std::min(
                            matrix.at(i).at(j - 1) + 1,
                            matrix.at(i-1).at(j-1) + cost
                            )
                    );
        }
    }

    return matrix.at(original.size()).at(reconstructed.size());

}