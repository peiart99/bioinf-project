#include <iostream>
#include <fstream>
#include "include/Generator.h"
#include "include/Spectrum.h"
#include "include/Greedy.h"

void saveToFile(int DNA_length, int k, int ne, int pe, std::vector<int> data, std::string filename)
{
    std::fstream in_file;
    in_file.open(filename, std::ios_base::app);
    in_file << "Wartość n: " << DNA_length << std::endl;
    in_file << "Wartość k: " << k << std::endl;
    in_file << "Procent błędów negatywnych: " << ne << "%" << std::endl;
    in_file << "Procent błędów pozytywnych: " << pe << "%" << std::endl;
    for(auto result : data)
    {
        in_file << result << std::endl;
    }
    in_file.close();
}

void runTests()
{
    std::vector<std::string> instance_test_dataset_500;
    std::vector<std::string> instance_test_dataset_600;
    std::vector<std::string> instance_test_dataset_700;
    //int parameter_test_k = 10;
    //int parameter_test_DNA_length = 700;
    for(int i{0}; i < 40; i++)
    {
        instance_test_dataset_500.push_back(generateDNA(500));
        instance_test_dataset_600.push_back(generateDNA(600));
        instance_test_dataset_700.push_back(generateDNA(700));
    }
    for(int i{6}; i <= 10; i++)
    {
        std::vector<int> results_500;
        std::vector<int> results_600;
        std::vector<int> results_700;
        for(auto DNA : instance_test_dataset_500)
        {
            std::string result = greedyAlgorithm(DNA, i, 2, 0);
            results_500.push_back(levenshteinDistance(DNA, result));
        }
        saveToFile(500, i, 2, 0, results_500, "tests500");
        for(auto DNA : instance_test_dataset_600)
        {
            std::string result = greedyAlgorithm(DNA, i, 2, 0);
            results_600.push_back(levenshteinDistance(DNA, result));
        }
        saveToFile(600, i, 2, 0, results_600, "tests600");
        for(auto DNA : instance_test_dataset_700)
        {
            std::string result = greedyAlgorithm(DNA, i, 2, 0);
            results_700.push_back(levenshteinDistance(DNA, result));
        }
        saveToFile(700, i, 2, 0, results_700, "tests700");
    }


//    std::vector<std::string> parameter_test_dataset;
//    int parameter_test_k = 10;
//    int parameter_test_DNA_length = 700;
//    for(int i{0}; i < 60; i++)
//    {
//        parameter_test_dataset.push_back(generateDNA(parameter_test_DNA_length));
//    }
//
//    for (int i {2}; i <= 10; i+=2)
//    {
//        std::vector<int> results;
//        for(auto DNA : parameter_test_dataset)
//        {
//            std::string result = greedyAlgorithm(DNA, parameter_test_k, i, 0);
//            results.push_back(levenshteinDistance(DNA, result));
//        }
//        saveToFile(parameter_test_DNA_length, parameter_test_k, i, 0, results, "testsNEG");
//    }
//
//    for (int i {2}; i <= 10; i+=2)
//    {
//        std::vector<int> results;
//        for(auto DNA : parameter_test_dataset)
//        {
//            std::string result = greedyAlgorithm(DNA, parameter_test_k, 0, i);
//            results.push_back(levenshteinDistance(DNA, result));
//        }
//        saveToFile(parameter_test_DNA_length, parameter_test_k, 0, i, results, "testsPOS");
//    }

}


int main()
{
    runTests();
    return 0;
}