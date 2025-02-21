#include "algorithm.hh"

void NormalDistribution::print()
{
    std::cout << "Mean: size " << mean.size() << std::endl;
    for (const auto &m : mean)
    {
        std::cout << m << " ";
    }
    std::cout << "\n";

    std::cout << "Covariance Matrix:\n";
    for (const auto &row : covariance_matrix)
    {
        for (const auto &val : row)
        {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }
}

void NormalDistribution::initializer_mean(size_t size)
{
    mean = std::vector<double>(size);
    std::fill(mean.begin(), mean.end(), 0);
    mean.shrink_to_fit();
}

void NormalDistribution::initializer_covariance()
{
    if (mean.size() <= 0)
    {
        std::cout << "Please, run initializer_mean(size_t size) first\n";
    }
    // build covariance matrix
    size_t k = 1;
    for (size_t i = 0; i < k && k <= this->mean.size(); i++)
    {
        std::vector<double> row = std::vector<double>(k);

        std::fill(row.begin(), row.end(), 0);
        row.at(k - 1) = 1;

        this->covariance_matrix.push_back(row);

        k++;
    }

    this->covariance_matrix.shrink_to_fit();
}

double NormalDistribution::get_covariance(size_t i, size_t j) {
    
}

NormalDistribution::NormalDistribution() {

};
NormalDistribution::~NormalDistribution() {};
