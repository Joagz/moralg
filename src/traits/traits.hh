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
    double bound;

public:
    void print();
    void update(std::vector<double>);

    // Define the bound of the trait points, by default it is set to 10.
    // In each update the maximum amount of points will be that bound.
    Traits(std::vector<std::string> trait_headers, double bound);
    Traits();
    ~Traits();
};

#endif