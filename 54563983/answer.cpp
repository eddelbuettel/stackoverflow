#include <Rcpp.h>

// [[Rcpp::export]]
double extractFromBigDataFrame(Rcpp::DataFrame d, bool verbose=false) {
  int n = d.length();
  double sum = 0;
  for (int i=0; i<n; i++) {
    // we are making a simplifying assumption here that each column is numeric
    Rcpp::NumericVector x = d[i];
    double elem = x[0];
    sum += elem;
    if (verbose) print(x);
  }
  return sum;
}

/*** R
m <- matrix(1:1000, 2, 500)
d <- as.data.frame(m)
extractFromBigDataFrame(d)
rowSums(m)  # comparison
*/
