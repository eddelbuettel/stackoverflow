#include <R.h>
#include <Rmath.h>
#include <Rcpp.h>
#include <Eigen/Dense>

using Rcpp::List;
using Rcpp::_;
using namespace Eigen;

List pkgfn(){
    ArrayXd r_beta = ArrayXd::Random(4);
    auto r_beta_vec = vector<double>(r_beta.data(), r_beta.data()+4);
    return List::create(_["r_beta"] = r_beta_vec);
}
