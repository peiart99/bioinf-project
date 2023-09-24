#include "../include/Oligonucleotide.h"

Oligonucleotide::Oligonucleotide(std::string _data):
used{false}, data{_data} {

}

void Oligonucleotide::printData() {
    std::cout << "Data: " << data << std::endl;
}

std::string Oligonucleotide::getData() {
    return data;
}

void Oligonucleotide::addConnected(std::shared_ptr<Oligonucleotide> oligo, int connection_level) {
    connected_oligos.emplace_back(std::shared_ptr<Oligonucleotide>(std::move(oligo)), connection_level);
}

void Oligonucleotide::printConnections() {
    //std::cout << "Connections: ";
    for(const auto& oligo : connected_oligos)
    {
        std::cout << oligo.first->getData() << ", " << oligo.second << "| ";
    }
    std::cout << std::endl;
}

void Oligonucleotide::sortConnectionsByWeight() {
    std::sort(connected_oligos.begin(), connected_oligos.end(), [](auto &left, auto &right) {
        return left.second < right.second;
    });
}

int Oligonucleotide::getConnectionNumber() {
    return connected_oligos.size();
}

std::shared_ptr<Oligonucleotide> Oligonucleotide::getBestConnection() {
    for (int i {0}; i < connected_oligos.size(); i++)
    {
        if(!connected_oligos.at(i).first->checkIfUsed())
        {
            return connected_oligos.at(i).first;
        }
    }
    //return connected_oligos.at(0).first;
}

bool Oligonucleotide::bestConnectionExists() {
    bool found {false};
    for (int i {0}; i < connected_oligos.size(); i++)
    {
        if(!connected_oligos.at(i).first->checkIfUsed())
        {
            found = true;
            return found;
        }
    }
    return found;
}

bool Oligonucleotide::checkIfUsed() {
    return used;
}

void Oligonucleotide::markAsUsed() {
    used = true;
}

