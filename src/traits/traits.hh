#ifndef TRAITS_HH
#define TRAITS_HH

#include <vector>
#include <string>
#include <iostream>

class Traits
{
private:
    std::vector<std::string> trait_headers;
    std::vector<double> trait_values;
    std::vector<std::vector<double>> weight_matrix;

public:
    void print();
    
    Traits(std::vector<std::string> trait_headers);
    Traits();
    ~Traits();
};

#endif