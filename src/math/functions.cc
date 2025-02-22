#include "functions.hh"
#include <cmath>

double sigmoid(double x, double l) {
    return 1/(1 + std::exp(-(1/l)*x));
}

double sigmoid(double x) {
    return 1/(1 + std::exp(-x));
}
