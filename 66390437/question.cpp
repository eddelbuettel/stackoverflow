//[[Rcpp::depends(RcppEigen)]]
#include <RcppEigen.h>
using namespace Eigen;

// [[Rcpp::export]]
Eigen::VectorXd fastnnls_eigen(const Eigen::MatrixXd& a, const Eigen::VectorXd& b, int maxit = 50) {
  Eigen::VectorXd x = (a).llt().solve((b));

  while(maxit-- > 0){

    // find values in x greater than zero
    // set values less than zero to zero
    bool x_is_nonneg = true;
    std::vector<int> nz;
    for(int i = 0; i < x.size(); ++i){
      if(x(i) > 0){
        nz.push_back(i);
      }
      else if(x(i) < 0) {
        x_is_nonneg = false;
        x(i) = 0;
      }
    }
    if(x_is_nonneg) break;

    // update x with solutions from only indices given in "nz"
    x(nz) = a(nz, nz).llt().solve((b(nz)));   // *************ERROR ON THIS LINE
  }
  return(x);
}
