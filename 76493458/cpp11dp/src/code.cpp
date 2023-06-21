
#include <cpp11.hpp>
#include <cpp11/doubles.hpp>
using namespace cpp11;

[[cpp11::register]] doubles_matrix<> Xt(doubles_matrix<> X)
{
    int NX = X.nrow();
    int MX = X.ncol();
    writable::doubles_matrix<> R(MX, NX);
    for (int i = 0; i < MX; i++)
    {
        for (int j = 0; j < NX; j++)
        {
            R(i, j) = X(j, i);
        }
    }
    return R;
}
