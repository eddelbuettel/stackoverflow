
#include <Rcpp.h>
#include <asa159.cpp>           // with small modifcations

// [[Rcpp::export]]
Rcpp::IntegerMatrix rcont2_cpp(Rcpp::IntegerVector rowsums, Rcpp::IntegerVector colsums) {
    int nrow = rowsums.length();
    int ncol = colsums.length();
    Rcpp::IntegerMatrix matrix(nrow, ncol);
    rcont2(nrow, ncol, rowsums.begin(), colsums.begin(), matrix.begin());
    return matrix;
}


/*** R
rs <- c(6, 5)
cs <- c(3, 4, 4)
rcont2_cpp(rs, cs)
rcont2_cpp(rs, cs)              // different answer as randomized algo
rcont2_cpp(rs, cs)              // different answer as randomized algo
*/
