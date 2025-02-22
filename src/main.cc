#include "traits/traits.hh"
#include "math/gaussian.hh"

int main(int argc, char const *argv[])
{
    Traits traits = Traits({"bondad", "compasion", "honestidad", "venganza", "traicion"});

    /*
    * search: sliding window approach
    */

    MultivariateGaussian gaussian = MultivariateGaussian(3, 0.57); // choose a weight factor
    std::vector<double> vec1 = {1, 6, 7};
    std::vector<double> vec2 = {7, 5, 1};
    std::vector<double> vec3 = {1, 1, 0};
    std::vector<double> vec4 = {9, 1, 5};
    std::vector<double> vec5 = {0, 2, 4};
    std::vector<double> vec6 = {3, 4, 12};
    std::vector<double> vec7 = {2, 6, 8};
    std::vector<double> vec8 = {1, 17, 5};
    gaussian.update_belief(vec1);
    gaussian.update_belief(vec2);
    gaussian.update_belief(vec3);
    gaussian.update_belief(vec4);
    gaussian.update_belief(vec5);
    gaussian.update_belief(vec6);
    gaussian.update_belief(vec7);
    gaussian.update_belief(vec8);

    gaussian.print();
    return 0;
}
