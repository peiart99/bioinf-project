#include "../include/Spectrum.h"

Spectrum::Spectrum(std::string _DNA, int _oligo_length)
: DNA {_DNA}, oligo_length{_oligo_length}, duplicates{0}
{
    //std::cout << DNA << std::endl;
}

void Spectrum::generateOligonucleotides() {
    for(int i {0}; i <= (DNA.length() - oligo_length); i++)
    {
        std::string oligo {DNA.substr(i, oligo_length)};
        //std::cout << oligo << std::endl;
        if(unique_oligos.find(oligo) != unique_oligos.end())
        {
            //std::cout << "Duplicate" << std::endl;
            duplicates++;
        }else
        {
            unique_oligos.emplace(oligo);
            //Oligonucleotide new_oligo(oligo);
            auto new_oligo = std::make_shared<Oligonucleotide>(oligo);
            oligos.push_back(new_oligo);
        }
    }
}

void Spectrum::printOligos() {
    for(auto oligo : oligos)
    {
        oligo->printData();
        oligo->printConnections();
    }
}

void Spectrum::connectOligos() {
    for(int i{0} ; i < oligos.size(); i++)
    {
        for(int j{0} ; j < oligos.size(); j++)
        {
            int current_run {1};
            bool reached_end {false};
            if(j != i)
            {
                while(!reached_end && current_run < oligo_length)
                {
                    int matches {0};
                    int l {0};
                    for(int k{current_run}; k < oligo_length; k++)
                    {
                        if(oligos.at(i)->getData().at(k) == oligos.at(j)->getData().at(l))
                        {
                            matches++;
                        }else
                        {
                            break;
                        }
                        l++;
                        if(l >= oligo_length - current_run)
                        {
                            reached_end = true;
                            if((oligo_length - matches) >= 1 && (oligo_length - matches) < oligo_length)
                            {
                                oligos.at(i)->addConnected(oligos.at(j), oligo_length - matches);
                            }
                            break;
                        }
                    }
                    current_run++;
                }
            }
        }
    }
    this->sortOligoConnections();
}

void Spectrum::addPositiveErrors(double percentage) {
    double full_number = oligos.size() / ((100 - percentage) / 100);
    int errors_to_add = ceil(full_number - oligos.size());
    //std::cout << "Pos erros to add: " << errors_to_add << std::endl;

    //std::cout << 100 - percentage << "% spektrum to: " << oligos.size() << std::endl;
    while(errors_to_add > 0)
    {
        std::string oligo = generateDNA(oligo_length);
        if(unique_oligos.find(oligo) != unique_oligos.end())
        {
            //std::cout << "Duplicate" << std::endl;
        }else
        {
            unique_oligos.emplace(oligo);
            auto new_oligo = std::make_shared<Oligonucleotide>(oligo);
            oligos.push_back(new_oligo);
            errors_to_add--;
        }
    }
    //std::cout << "Po dodaniu wymaganych oligo: " << oligos.size() << std::endl;
}

void Spectrum::addNegativeErrors(double percentage) {
    double multiplier = percentage / 100;
    //std::cout << "Multiplier: " << multiplier << std::endl;
    int errors_by_percentage = ceil(multiplier * oligos.size());
    //std::cout << "Err by percentage: " << errors_by_percentage << std::endl;
    if(duplicates >= errors_by_percentage)
    {
        //std::cout << "Duplikaty: " << duplicates << " Errory neg przez procent: " << errors_by_percentage << std::endl;
        return;
    }else
    {
        int errors_to_add {errors_by_percentage - duplicates};
        //std::cout << "Lista oligo: " << oligos.size() << "Oligo do usuniecia: " << errors_to_add << " ";
        oligos.erase(oligos.begin() + 1, oligos.begin() + errors_to_add + 1);
        //std::cout << "Lista oligo po usunieciu: " << oligos.size() << std::endl;
    }
}

std::string Spectrum::greedyAlgorithm() {
    this->traverseOligos(oligos.at(0));
    if(result_DNA.size() > DNA.size())
        return result_DNA.substr(0, DNA.size());
    else
        return result_DNA;
}

void Spectrum::traverseOligos(std::shared_ptr<Oligonucleotide> oligo) {
    //std::cout << "Oligo con number: " << oligo->getConnectionNumber() << std::endl;
    result_DNA.append(oligo->getData());
    oligo->markAsUsed();
    if(result_DNA.size() >= DNA.size())
    {
        return;
    }
    if(oligo->bestConnectionExists())
    {
        this->traverseOligos(oligo->getBestConnection());
    }else
        return;
}

void Spectrum::sortOligoConnections() {
    for(int i{0}; i < oligos.size(); i++)
    {
        oligos.at(i)->sortConnectionsByWeight();
    }
}

std::string Spectrum::getResult() {
    return result_DNA;
}

