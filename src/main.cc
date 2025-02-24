#include "traits/traits.hh"
#include "math/gaussian.hh"
#include "math/matrix.hh"
#include "math/vec.hh"
#include "math/functions.hh"
#include <cmath>

int main(int argc, char const *argv[])
{

  Traits traits = Traits({"bondad", "compasion", "mezquindad"}, 100);
  std::cout << "\n";

  traits.update({-10, -30, 100});
  traits.update({-10, -10, 20});
  traits.update({-50, 0, 80});
  traits.print();
  std::cout << "\n";

  traits.update({40, 50, -60});
  traits.update({20, 10, -5});
  traits.update({2, 5, -1});
  traits.print();
  std::cout << "\n";


  traits.update({100, 0, 0});
  traits.update({0, 100, 0});
  traits.print();
  std::cout << "\n";

  return 0;
}
