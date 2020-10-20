// lightly edited version of question, working fine for me
#define ARMA_64BIT_WORD 1
#include <RcppArmadillo.h>
// [[Rcpp::depends(RcppArmadillo)]]

// [[Rcpp::export]]
void spmatTest(arma::sp_mat M) {
  // show a simple access of matrix,
  // here we just sum elements on diagonal
  Rcpp::Rcout << "Sum of diag is "
              << arma::as_scalar(arma::sum(M.diag()))
              << std::endl;
}

/*** R
spmatTest( Matrix::Diagonal( 1e6 ))
spmatTest( Matrix::Diagonal( 1e7 ))
spmatTest( Matrix::Diagonal( 1e8 ))
*/
