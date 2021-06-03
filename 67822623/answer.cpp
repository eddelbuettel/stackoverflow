
#define STRICT_R_HEADERS
#include <unsupported/Eigen/CXX11/Tensor>
#include <Rcpp.h>
#include <RcppEigen.h>

// [[Rcpp::depends(RcppEigen)]]
using namespace std;
using namespace Eigen;

// [[Rcpp::export]]
Tensor<double, 2>  tensorContractTest(int n) {
    Tensor<double, 3> a(n, n, n);     a.setConstant(1.);
    Tensor<double, 1> b(n);           b.setConstant(1.);
    auto indexPair            = Eigen::array<IndexPair<int>, 1>{IndexPair<int>(2,0)};
    Tensor<double, 2> result  = a.contract(b, indexPair);
    return result;
}

/*** R
tensorContractTest(int 2)
*/
