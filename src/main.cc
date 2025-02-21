#include "traits/traits.hh"
#include "algorithm/algorithm.hh"

int main(int argc, char const *argv[])
{
    Traits traits = Traits({"bondad", "compasion", "honestidad", "venganza", "traicion"});
    NormalDistribution d = NormalDistribution();
    d.initializer_mean(10);
    d.initializer_covariance();
    d.print();
    return 0;
}
