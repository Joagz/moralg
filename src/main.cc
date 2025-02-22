#include "traits/traits.hh"
#include "math/gaussian.hh"
#include "math/matrix.hh"
#include "math/vec.hh"
#include "math/functions.hh"
#include <cmath>

int main(int argc, char const *argv[])
{

    /*
     * search: sliding window approach
     */

    /* for decay_factor good values depend on the amount of data points we sample,
     we should map a sigmoid to range from a very low decay when less data points
     exist, up to approximately 1 when we have 100 points, so for example

    \frac{1}{1+\exp\left(-\frac{1}{\lambda}x\right)}

    with \lambda                    = 45.51, gives approximately 0.9 when x = 100

    In the calculation below, the estimation gives really good, for
    x                               = 50 the results show

    octave                          : 4> M0-cov(data)
ans                                 =

    -3.4633e-02  -9.2653e-02   3.6531e-03
    -9.2653e-02  -2.7829e-01  -2.0469e-02
     3.6531e-03  -2.0469e-02   9.8082e-02

    which are great for our purposes. This estimation of \lambda gives good
    results for the current interval of values [0,10]

    However let's try random values in [0,20]

    The results in matlab give

octave                              : 7> M0-cov(data)
ans                                 =

  -1.121592  -0.194776   0.131796
  -0.194776   0.171796  -0.077286
   0.131796  -0.077286   0.038408

    which is not a big difference, however it is obvious that this error grows.
    This is maybe due to numerical unstability in the calculations, giving bigger
    numbers because our vectors have also a greater degree of freedom (variances from
    0 to 20 are greater that from 0 to 10).

    we should run some "normalization" step and divide everything by the greater value.

    Doing this for the second example gives this result

    M0                              =

   9.3000e-02   2.4000e-02  -4.0000e-03
   2.4000e-02   8.7000e-02  -1.2000e-02
  -4.0000e-03  -1.2000e-02   9.3000e-02

octave                              : 10> cov(data)
ans                                 =

   9.2499e-02   2.3997e-02  -4.5245e-03
   2.3997e-02   8.3226e-02  -1.2114e-02
  -4.5245e-03  -1.2114e-02   9.0249e-02

octave                              : 11> M0-cov(data)
ans                                 =

   5.0102e-04   3.0612e-06   5.2449e-04
   3.0612e-06   3.7745e-03   1.1429e-04
   5.2449e-04   1.1429e-04   2.7510e-03

    this is much better now. Also this constraints our values to be less than
    1, which is what we expect for weights. But, the values in the M0 matrix are
    too tiny, we maybe should "normalize" them with a sigmoid to get proper values.

    However let's try with a realistic example, let's suppose we want the game to
    have at most 10 points for event for each trait.

M0                                  =

   1.0100e-01  -3.0000e-03  -1.0000e-02
  -3.0000e-03   9.3000e-02  -3.0000e-03
  -1.0000e-02  -3.0000e-03   1.0500e-01

octave                              : 14> cov(data)
ans                                 =

   9.8616e-02  -2.0735e-03  -9.9265e-03
  -2.0735e-03   9.2343e-02  -2.4653e-03
  -9.9265e-03  -2.4653e-03   1.0116e-01

octave                              : 15> M0-cov(data)
ans                                 =

   2.3837e-03  -9.2653e-04  -7.3469e-05
  -9.2653e-04   6.5714e-04  -5.3469e-04
  -7.3469e-05  -5.3469e-04   3.8408e-03

The norm of this matrix is

K =

    0.00238  -0.000927  -7.35e-05
  -0.000927   0.000657  -0.000535
  -7.35e-05  -0.000535    0.00384

octave:45> norm(K)
ans = 0.00393 // very good result

    The results show that it is a good approximation, also the M0 matrix could serve
    our purposes perfectly, this given that real values are *not random*, they are
    intended to be related some way.

    */

    Traits traits = Traits({"bondad", "compasion", "mezquindad"});

    double steps = 10;
    double goal = .9;
    double coeff = -100 / std::log(1 / goal - 1);

    MultivariateGaussian gaussian = MultivariateGaussian(3, sigmoid(steps, coeff));

    std::vector<Vector<double>> list;

    // vector of traits examples
    list.push_back(Vector<double>({1, .5, -.4}));
    list.push_back(Vector<double>({0, -.1, 1}));
    list.push_back(Vector<double>({-.3, 0, .5}));
    list.push_back(Vector<double>({0, 0, 1}));
    list.push_back(Vector<double>({.4, .9, -.4}));
    list.push_back(Vector<double>({1, 1, -.8}));
    list.push_back(Vector<double>({1, .1, 0}));
    list.push_back(Vector<double>({0, .1, 0}));
    list.push_back(Vector<double>({-.4, .4, .1}));
    list.push_back(Vector<double>({0, 0, -1}));

    for (auto v : list)
    {
        gaussian.update_belief(v.data);
        v.print_as_matlab_vector();
    }

    Matrix<double> matrix = Matrix<double>(gaussian.get_covariance(), gaussian.size, gaussian.size);
    matrix.symmetric = true;
    matrix.print_as_matlab_matrix(0);

    std::cout << "sigmoid: " << sigmoid(steps, coeff) << std::endl;

    return 0;
}
