
#define ARMA_64BIT_WORD 1
#include <RcppArmadillo.h>

// [[Rcpp::depends(RcppArmadillo)]]

using namespace Rcpp ;

// [[Rcpp::export]]
void convertSparse(S4 mat) {

    // obtain dim, i, p. x from S4 object
    IntegerVector dims = mat.slot("Dim");
    arma::urowvec i = Rcpp::as<arma::urowvec>(mat.slot("i"));
    arma::urowvec p = Rcpp::as<arma::urowvec>(mat.slot("p"));
    arma::vec x     = Rcpp::as<arma::vec>(mat.slot("x"));

    int nrow = dims[0], ncol = dims[1];

    // use Armadillo sparse matrix constructor
    arma::sp_mat res(i, p, x, nrow, ncol);
    Rcout << "SpMat res:\n" << res << std::endl;
}

// [[Rcpp::export]]
void convertSparse2(S4 mat) {         // slight improvement with two non-nested loops

    IntegerVector dims = mat.slot("Dim");
    arma::urowvec i = Rcpp::as<arma::urowvec>(mat.slot("i"));
    arma::urowvec p = Rcpp::as<arma::urowvec>(mat.slot("p"));
    arma::vec x     = Rcpp::as<arma::vec>(mat.slot("x"));

    int nrow = dims[0], ncol = dims[1];
    arma::sp_mat res(nrow, ncol);

    // create space for values, and copy
    arma::access::rw(res.values) = arma::memory::acquire_chunked<double>(x.size() + 1);
    arma::arrayops::copy(arma::access::rwp(res.values), x.begin(), x.size() + 1);

    // create space for row_indices, and copy
    arma::access::rw(res.row_indices) = arma::memory::acquire_chunked<arma::uword>(i.size() + 1);
    arma::arrayops::copy(arma::access::rwp(res.row_indices), i.begin(), i.size() + 1);

    // create space for col_ptrs, and copy
    arma::access::rw(res.col_ptrs) = arma::memory::acquire<arma::uword>(p.size() + 2);
    arma::arrayops::copy(arma::access::rwp(res.col_ptrs), p.begin(), p.size() + 1);

    // important: set the sentinel as well
    arma::access::rwp(res.col_ptrs)[p.size()+1] = std::numeric_limits<arma::uword>::max();

    // set the number of non-zero elements
    arma::access::rw(res.n_nonzero) = x.size();

    Rcout << "SpMat res:\n" << res << std::endl;
}


/*** R
suppressMessages({
  library(methods)
  library(Matrix)
})
i <- c(1,3:6)
j <- c(2,9,6:8)
x <- 5 * (1:5)
A <- sparseMatrix(i, j, x = x)
print(A)
convertSparse(A)

i <- 56789
j <- 87654
x <- 42
B <- sparseMatrix(i, j, x=x)
#print(B)
convertSparse(B)
convertSparse2(B)
*/
