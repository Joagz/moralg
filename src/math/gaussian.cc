#include "gaussian.hh"
#include "../algorithm/algorithm.hh"
#include <cmath>

void MultivariateGaussian::print()
{
    std::cout << "Mean: size " << mean.size() << std::endl;
    for (const auto &m : mean)
    {
        printf("%.3f ", m);
    }
    std::cout << "\n";

    std::cout << "Covariance Matrix:\n";
    for (const auto &row : covariance_matrix)
    {
        for (const auto &val : row)
        {
            printf("%.3f ", val);
        }
        std::cout << "\n";
    }
}

void MultivariateGaussian::initializer_mean(size_t size)
{
    mean = std::vector<double>(size);
    std::fill(mean.begin(), mean.end(), 0);
    mean.shrink_to_fit();
}

void MultivariateGaussian::initializer_covariance()
{
    if (this->size <= 0)
    {
        std::cout << "Please, run initializer_mean(size_t size) first\n";
    }
    // build covariance matrix
    size_t row_size = 1;
    for (size_t i = 0; i < row_size && row_size <= this->size; i++, row_size++)
    {
        std::vector<double> row = std::vector<double>(row_size);

        std::fill(row.begin(), row.end(), 0);
        row.at(row_size - 1) = 1;

        this->covariance_matrix.push_back(row);
    }

    this->covariance_matrix.shrink_to_fit();
}

std::vector<std::vector<double>> MultivariateGaussian::get_covariance()
{
    return this->covariance_matrix;
}

double MultivariateGaussian::get_covariance(size_t i, size_t j)
{
    // We have a "lower triangular" matrix, as the
    // covariance matrix is symmetric, we can invert
    // these indexes if j > i (trying to access an "upper
    // triangular" value)
    if (j > i)
    {
        size_t t = j;
        j = i;
        i = t;
    }

    return covariance_matrix.at(i).at(j);
}

void MultivariateGaussian::update_belief(std::vector<double> &new_val)
{
    updateMean(this, new_val);
    updateCovariance(this, new_val);
    this->update_steps();
}

void MultivariateGaussian::set_covariance(std::vector<std::vector<double>> covariance_matrix)
{
    this->covariance_matrix = covariance_matrix;
}

void MultivariateGaussian::set_covariance(size_t i, size_t j, double cov)
{
    this->covariance_matrix.at(i).at(j) = cov;
}

std::vector<double> MultivariateGaussian::get_mean()
{
    return this->mean;
}

void MultivariateGaussian::set_mean(std::vector<double> mean)
{
    this->mean = mean;
}

void MultivariateGaussian::update_steps()
{
    this->steps++;
}

size_t MultivariateGaussian::get_size() { return this->size; }

MultivariateGaussian::MultivariateGaussian(size_t size, double decay_factor)
{
    this->size = size;
    this->lambda = decay_factor;
    this->steps = 0;
    this->initializer_mean(size);
    this->initializer_covariance();
};

MultivariateGaussian::MultivariateGaussian()
{
    this->size = 0;
    this->steps = 0;
}

MultivariateGaussian::~MultivariateGaussian() {};