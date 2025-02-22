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
    void update_steps();
    void set_covariance(size_t i, size_t j, double cov);
    void set_covariance(std::vector<std::vector<double>> covariance_matrix);
    void set_mean(std::vector<double> mean);
    size_t steps;
    size_t size;
    double lambda; // decay factor

public:
    void print();
    size_t get_size();
    void update_belief(std::vector<double> &new_val);

    double get_covariance(size_t i, size_t j);
    std::vector<std::vector<double>> get_covariance();
    std::vector<double> get_mean();

    MultivariateGaussian(size_t size, double decay_factor);
    MultivariateGaussian();
    ~MultivariateGaussian();
};

#endif