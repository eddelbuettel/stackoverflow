
#include <armadillo>

int main() {
  arma::mat m = {
    {1.0000e+00  ,          0,          0,          0,-6.5919e-17, 2.8284e-01},
    {          0 , 1.0000e+00,          0,          0, 2.8284e-01,-7.6328e-17},
    {          0 ,          0, 1.0000e+00, 2.8284e-01,          0,          0},
    {          0 ,          0, 2.8284e-01, 1.0000e+00,          0,          0},
    {-6.5919e-17 , 2.8284e-01,          0,          0, 1.0000e+00,          0},
    { 2.8284e-01 ,-7.6328e-17,          0,          0,          0, 1.0000e+00}
  };

  m.print();
  arma::vec eigval;
  arma::mat eigvec;

  arma::eig_sym(eigval, eigvec, m, "std");

  eigval.print("Eigen Values");
  eigvec.print("Eigen Vector");

  exit(0);
}
