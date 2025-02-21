#ifndef TRAITS_HH
#define TRAITS_HH

#include <vector>
#include <string>
#include <iostream>

class Traits
{
private:
    std::vector<std::string> trait_headers;
    std::vector<double> trait_values;
    std::vector<std::vector<double>> weight_matrix;

    void print()
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

        std::cout << "Weight Matrix:\n";
        for (const auto &row : weight_matrix)
        {
            for (const auto &val : row)
            {
                std::cout << val << " ";
            }
            std::cout << "\n";
        }
    }

public:
    Traits(std::vector<std::string> trait_headers)
    {
        this->trait_headers = trait_headers;

        this->trait_values = std::vector<double>(this->trait_headers.size());
        std::fill(this->trait_values.begin(), this->trait_values.end(), 0);

        this->weight_matrix = std::vector<std::vector<double>>(this->trait_headers.size(), std::vector<double>(this->trait_headers.size()));

        for (size_t i = 0; i < this->trait_headers.size(); i++)
        {
            std::vector<double> row = std::vector<double>(this->trait_headers.size());
            std::fill(row.begin(), row.end(), 0);
            row.at(i) = 1;

            this->weight_matrix.at(i) = row;
        }

        print();
    }
    Traits() {};
    ~Traits() {};
};

#endif