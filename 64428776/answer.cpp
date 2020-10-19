// lightly edited version of question, working fine for me
#define ARMA_64BIT_WORD 1
#include <RcppArmadillo.h>
// [[Rcpp::depends(RcppArmadillo)]]

// [[Rcpp::export]]
int test(arma::sp_mat W){
  Rcpp::Rcout << "W is good\n";
  //W.print("W");
  return 0;
}

/*** R
# define the diagonal matrix
nrows <- 1e6
W <- Matrix::Diagonal(nrows)

# call Rcpp function
test(W)

# also:  test(Matrix::Diagonal(1e7))
#        test(Matrix::Diagonal(1e8))
*/
