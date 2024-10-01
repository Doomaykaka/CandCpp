#include <string>
#include <iostream>
#include <fstream>

#include "Cold.h"

using namespace std;

void Cold::set_readiness(bool readiness)
{
    this->readiness = readiness;
}

bool Cold::get_readiness()
{
    return readiness;
}

void Cold::save(std::ofstream& fout) {
    Drink::save(fout);
    fout.write(reinterpret_cast<char*>(&readiness), sizeof(readiness));
}


void Cold::load(std::ifstream& fin) {
    Drink::load(fin);
    fin.read(reinterpret_cast<char*>(&readiness), sizeof(readiness));
}
