#include "traits/traits.hh"
#include "math/gaussian.hh"
#include "math/matrix.hh"
#include "math/vec.hh"

int main(int argc, char const *argv[])
{
    Traits traits = Traits({"bondad", "compasion", "honestidad", "venganza", "traicion"});

    /*
     * search: sliding window approach
     */

    /* for decay_factor good values depend on the amount of data points we sample,
     we should map a sigmoid to range from a very low decay when less data points
     exist, up to approximately 1 when we have 100 points, so for example

    \frac{1}{1+\exp\left(-\frac{1}{l}x\right)}

    with l = 50, gives approximately 0.88 when x = 100

    the variance_bias is a linear error "fix", it really depends but a value
    between 0.3, 0.6 should be good enough.

    We don't want so exact variances but this also depends on the range of the variables
    If the variable range is [a,b], if b-a is bigger, the error should increase faster.

    In this example, matlab returns the following results after comparing the covariance of
    the data points and the approximation given in this code snippet

    octave:20> M0-cov(data)
ans =

  -3.1486e+01  -5.0051e-02  -5.1485e-02
  -5.0051e-02  -3.1619e+01  -4.8444e-02
  -5.1485e-02  -4.8444e-02  -3.1403e+01

    As you can see, the errors are not so big, negative errors in the diagonal mean that our
    variance_bias is a bit larger that necessary.
    */
    MultivariateGaussian gaussian = MultivariateGaussian(3, 0.9, 0.6);

    for (int i = 0; i < 100; i++)
    {
        double x = rand() % 11;
        double y = rand() % 11;
        double z = rand() % 11;
        Vector<double> vec = Vector<double>({x, y, z});
        gaussian.update_belief(vec.data);
        vec.print_as_matlab_vector();
    }

    Matrix<double> matrix = Matrix<double>(gaussian.get_covariance(), gaussian.size, gaussian.size);
    matrix.symmetric = true;
    matrix.print_as_matlab_matrix(0);

    return 0;
}
