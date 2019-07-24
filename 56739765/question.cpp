#include <Rcpp.h>
using namespace Rcpp;
// [[Rcpp::plugins("cpp11")]]

// [[Rcpp::export]]
double sumExample() {
    // these are the matrix row elements I want to sum
    // (the column in this example will be fixed)
    IntegerVector a = {2,4,6};
    // create 10x10 matrix filled with random numbers [0,1]
    NumericVector v = runif(100);
    NumericMatrix x(10, 10, v.begin());
    // sum the row elements 2,4,6 from column 0
    NumericVector z1 = x.column(0);
    NumericVector z2 = z1[a];
    double result = sum( z2 );
    return(result);
}

/*** R
sumExample()
*/
