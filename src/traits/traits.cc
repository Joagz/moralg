#include "traits.hh"
#include "../math/functions.hh"
#include <cmath>

static const double coeff = -100 / std::log(1 / .9 - 1);

Traits::Traits(std::vector<std::string> trait_headers, double bound)
{

    MultivariateGaussian gaussian = MultivariateGaussian(3, sigmoid(-100, coeff));
    this->bound = bound;
    this->gaussian = gaussian;
    this->trait_headers = trait_headers;
    this->trait_values = std::vector<double>(this->trait_headers.size());
    std::fill(this->trait_values.begin(), this->trait_values.end(), 0);
}

Traits::Traits()
{
    this->bound = 10;
}

Traits::~Traits() {}

void Traits::update(std::vector<double> traits)
{
    for (size_t i = 0; i < traits.size(); i++)
    {
        traits.at(i) = traits.at(i) / 10;
    }
    
    std::vector<double> new_trait_values;

    // loop through covariance
    for (size_t i = 0; i < traits.size(); i++)
    {
        double y = 0;

        for (size_t j = 0; j < traits.size(); j++)
        {
            y +=  this->gaussian.get_covariance(i, j) * traits.at(j);
        }
        new_trait_values.push_back(y + this->trait_values.at(i));
    }

    this->gaussian.update_belief(traits, sigmoid(this->gaussian.get_steps(), coeff));
    this->trait_values = new_trait_values;

}

void Traits::print()
{
    std::cout << "valores:\n";
    for (const auto &value : trait_values)
    {
        std::cout << int(value) << " ";
    }
    std::cout << "\n";
}