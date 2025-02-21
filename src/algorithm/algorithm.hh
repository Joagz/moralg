#ifndef ALGORITHM_HH
#define ALGORITHM_HH

#include <vector>
#include <string>
#include <iostream>

class NormalDistribution
{
private:
    std::vector<double> mean;
    std::vector<std::vector<double>> covariance_matrix;

public:
    void print();
    void initializer_mean(size_t size);
    void initializer_covariance();

    double get_covariance(size_t i, size_t j);
    std::vector<double> get_mean();

    NormalDistribution();
    ~NormalDistribution();
};

#endif