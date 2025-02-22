#include "traits.hh"

Traits::Traits(std::vector<std::string> trait_headers)
{
    this->trait_headers = trait_headers;

    this->trait_values = std::vector<double>(this->trait_headers.size());
    std::fill(this->trait_values.begin(), this->trait_values.end(), 0);
}

Traits::Traits()
{
}

Traits::~Traits() {}

void Traits::update(std::vector<double> traits)
{
    this->gaussian.update_belief(traits);

    std::vector<double> new_trait_values;

    // loop through covariance
    for (int i = 0; i < this->gaussian.get_size(); i++)
    {
        double y = 0;

        for (int j = 0; j < this->gaussian.get_size(); j++)
        {
            y += this->gaussian.get_covariance(i, j) * this->trait_values.at(j);
        }
        new_trait_values.push_back(y);
    }

    this->trait_values = new_trait_values;
}

void Traits::print()
{
    std::cout << "Trait Headers:\n";
    for (const auto &header : trait_headers)
    {
        std::cout << header << " ";
    }
    std::cout << "\n";

    std::cout << "Trait Values:\n";
    for (const auto &value : trait_values)
    {
        std::cout << value << " ";
    }
    std::cout << "\n";
}