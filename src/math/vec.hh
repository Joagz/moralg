#include <vector>
#include <iostream>

template <typename T>
class Vector
{
private:
public:
    std::vector<T> data;
    void print_as_matlab_vector() {
        for (auto el : data)
        {
            std::cout << el << " ";
        }
        std::cout << std::endl;
    }

    Vector(/* args */) {}
    Vector(std::vector<T> data) { this->data = data; }
    ~Vector() {}
};
