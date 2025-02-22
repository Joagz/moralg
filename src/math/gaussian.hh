#ifndef GAUSSIAN_HH
#define GAUSSIAN_HH

#include <vector>
#include <string>
#include <iostream>

class MultivariateGaussian
{
private:
    std::vector<double> mean;
    std::vector<std::vector<double>> covariance_matrix;
    
    void initializer_mean(size_t size);
    void initializer_covariance();

public:
    size_t size;
    size_t steps;
    double lambda; // decay factor

    void update_steps();
    void print();
    void update_belief(std::vector<double> &new_val);

    std::vector<std::vector<double>> get_covariance();
    double get_covariance(size_t i, size_t j);
    void set_covariance(size_t i, size_t j, double cov);
    void set_covariance(std::vector<std::vector<double>> covariance_matrix);

    std::vector<double> get_mean();
    void set_mean(std::vector<double> mean);
    
    MultivariateGaussian(size_t size, double decay_factor);
    MultivariateGaussian();
    ~MultivariateGaussian();
};

#endif