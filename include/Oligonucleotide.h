#ifndef BIOINF_PROJECT_OLIGONUCLEOTIDE_H
#define BIOINF_PROJECT_OLIGONUCLEOTIDE_H
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include "../include/Oligonucleotide.h"

class Oligonucleotide {
private:
    bool used;
    std::string data;
    std::vector<std::pair<std::shared_ptr<Oligonucleotide>, int>> connected_oligos;

public:
    explicit Oligonucleotide(std::string _data);
    void addConnected(std::shared_ptr<Oligonucleotide> oligo, int connection_level);
    void printData();
    void printConnections();
    void sortConnectionsByWeight();
    std::string getData();
    int getConnectionNumber();
    bool bestConnectionExists();
    bool checkIfUsed();
    void markAsUsed();
    std::shared_ptr<Oligonucleotide> getBestConnection();
};


#endif //BIOINF_PROJECT_OLIGONUCLEOTIDE_H
