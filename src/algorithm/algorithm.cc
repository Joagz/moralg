#include "algorithm.hh"

// calculate mean
void updateMean(MultivariateGaussian *gaussian, std::vector<double> &new_val)
{
    std::vector<double> mean = std::vector<double>(gaussian->size);
    std::vector<double> old_mean = gaussian->get_mean();

    for (size_t i = 0; i < gaussian->size; i++)
    {
        // use formula for the aritmetic mean
        mean.at(i) = (old_mean.at(i) * gaussian->steps + new_val.at(i)) / (gaussian->steps + 1);
    }

    gaussian->set_mean(mean);
}

void updateCovariance(MultivariateGaussian *gaussian, std::vector<double> &new_val)
{
    std::vector<std::vector<double>> old_covariance = gaussian->get_covariance();
    std::vector<double> mean = gaussian->get_mean();

    for (size_t i = 0, row_size = 1; i < row_size && row_size <= gaussian->size; i++, row_size++)
    {
        for (size_t j = 0; j <= i; j++)
        {
            double delta1 = new_val.at(i) - mean.at(i);
            double delta2 = new_val.at(j) - mean.at(j);

            gaussian->set_covariance(i, j, gaussian->get_covariance(i, j) + (delta1 * delta2 - gaussian->lambda * gaussian->get_covariance(i, j)) / (gaussian->steps + 1));
        }
    }
}
