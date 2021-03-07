//[[Rcpp::depends(RcppEigen)]]
#include <RcppEigen.h>

// [[Rcpp::export]]
Eigen::VectorXd demoSubset(const Eigen::VectorXd& b, std::vector<int> p) {
  //return b(p);
  //return b(Eigen::all, p);
  auto v = b(Eigen::all, p);
  return b;
}

/*** R
demoSubset(as.numeric(1:10), c(2L,4L,8L))
*/
