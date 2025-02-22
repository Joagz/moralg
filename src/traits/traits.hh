#ifndef TRAITS_HH
#define TRAITS_HH

#include <vector>
#include <string>
#include <iostream>
#include "../math/gaussian.hh"

class Traits
{
private:
    std::vector<std::string> trait_headers;
    std::vector<double> trait_values;
    MultivariateGaussian gaussian;

public:
    void print();
    void update(std::vector<double>);

    Traits(std::vector<std::string> trait_headers);
    Traits();
    ~Traits();
};

#endif