#ifndef ALGORITHM_HH
#define ALGORITHM_HH
#include "../math/gaussian.hh"

void updateMean(MultivariateGaussian *gaussian, std::vector<double> &new_val);
void updateCovariance(MultivariateGaussian *gaussian, std::vector<double> &new_val);

#endif