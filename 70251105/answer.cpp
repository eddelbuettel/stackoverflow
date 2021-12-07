
#include <RcppArmadillo.h>

// [[Rcpp::depends(RcppArmadillo)]]

// [[Rcpp::export]]
arma::mat rowwiseAdd(arma::mat A, arma::mat B) {
    if (A.n_rows != B.n_rows || A.n_cols != B.n_cols)
        Rcpp::stop("Matrices must conform.");

    arma::mat C(A.n_rows, A.n_cols);

    for (size_t i=0; i < A.n_rows; i++) {
        arma::rowvec a = A.row(i);
        arma::rowvec b = B.row(i);
        arma::rowvec c = a + b;
        C.row(i) = c;
    }
    return C;
}

/*** R
A <- matrix(1:9, 3, 3)
B <- matrix(9:1, 3, 3)
rowwiseAdd(A, B)
*/
