#include <Rcpp.h>
using namespace Rcpp;
// [[Rcpp::export]]
void pearson(NumericMatrix E, IntegerVector v){
    int rows = E.nrow();
    int cols = E.ncol();
    int j, irow, jrow;
    double rowsum;
    NumericVector means(rows);
    int k = 0;
    double cov, varx, vary;
    double pearson;

    for(irow = 0; irow < rows; irow++){
        rowsum = 0;
        for(j = 0; j < cols; j++){
            rowsum += E(irow, j);
        }
        means[irow] = rowsum / cols;
    }

    for(irow = 0; irow < rows - 1; irow++){
        for(jrow = irow + 1; jrow < rows; jrow++){
            cov = 0;
            varx = 0;
            vary = 0;
            for(j = 0; j < cols; j++) {
                cov += (E(irow, j) - means[irow]) * (E(jrow, j) - means[jrow]);
                varx += std::pow(E(irow, j) - means[irow], 2);
                vary += std::pow(E(jrow, j) - means[jrow], 2);
            }
            pearson = cov / std::sqrt(varx * vary);
            v[k] = (int) (pearson * 10000);
            k++;
        }
    }
}

/*** R
testin <- matrix(rnorm(1000 * 1100), nrow = 1000, ncol = 1100)
testout <- integer( (nrow(testin) * (nrow(testin) - 1)) / 2 )
pearson(testin, testout) # success!
cat("Done 1\n")
testin <- matrix(rnorm(16000 * 17000), nrow = 16000, ncol = 17000)
testout <- integer( (nrow(testin) * (nrow(testin) - 1)) / 2 )
pearson(testin, testout) # sad
cat("Done 2\n")
*/
