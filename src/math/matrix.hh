#include <vector>
#include <iostream>

template <typename T>
class Matrix
{
private:
public:
    std::vector<std::vector<T>> data;
    size_t size_x, size_y;
    bool symmetric;

    void print_as_matlab_matrix(int num)
    {
        std::cout << "M" << num << " = [" << std::endl;
        for (size_t i = 0; i < this->size_x; i++)
        {
            std::vector<T> row = this->data.at(i);
            for (size_t j = 0; j < this->size_x; j++)
            {
                double el = 0;

                if (row.size() > j)
                {
                    el = row.at(j);
                }
                else if (symmetric)
                {
                    el = this->data.at(j).at(i);
                }

                printf("%.3f ", el);
            }
            std::cout << std::endl;
        }
        std::cout << "]" << std::endl;
    }

    Matrix(std::vector<std::vector<T>> data)
    {
        this->data = data;
        this->size_x = data.size();
        this->size_y = data.size();
    }

    Matrix(std::vector<std::vector<T>> data, size_t size_x, size_t y)
    {
        this->data = data;
        this->size_x = size_x;
        this->size_y = size_y;
    }

    Matrix() {}
    ~Matrix() {}
};
