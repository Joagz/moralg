#include "algorithm.hh"

// calculate mean
void MultivariateGaussian::updateMean(std::vector<double> &new_val)
{
    std::vector<double> mean = std::vector<double>(this->get_size());
    std::vector<double> old_mean = this->get_mean();

    for (size_t i = 0; i < this->get_size(); i++)
    {
        // use formula for the aritmetic mean
        mean.at(i) = (old_mean.at(i) * this->get_steps() + new_val.at(i)) / (this->get_steps()  + 1);
    }

    this->set_mean(mean);
}

void MultivariateGaussian::updateCovariance(std::vector<double> &new_val)
{
    std::vector<std::vector<double>> old_covariance = this->get_covariance();
    std::vector<double> mean = this->get_mean();

    for (size_t i = 0, row_size = 1; i < row_size && row_size <= this->get_size(); i++, row_size++)
    {
        for (size_t j = 0; j <= i; j++)
        {
            double delta1 = new_val.at(i) - mean.at(i);
            double delta2 = new_val.at(j) - mean.at(j);

            this->set_covariance(i, j, this->get_covariance(i, j) + (delta1 * delta2 - this->lambda * this->get_covariance(i, j)) / (this->get_steps() + 1));
        }
    }
}
