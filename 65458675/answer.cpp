#include <Rcpp.h>

// [[Rcpp::export]]
Rcpp::NumericVector colSkew(Rcpp::NumericMatrix x) {
    int nc = x.ncol();
    int nr = x.nrow();
    Rcpp::NumericVector colS(nc);
    for(int i = 0; i < nc; i++){
      double cMean = Rcpp::mean(x( Rcpp::_ ,i));
        double xSq = 0;
        double cSt = 0;
          for(int j = 0; j < nr; j++){
              xSq += std::pow(x(j,i), 2.0);
              cSt += std::pow(x(j,i) - cMean, 3.0);
          }
          double colMsq = nr * std::pow(cMean, 2.0);
          double cTT = std::sqrt((xSq - colMsq)) / (nr - 1);
          double colVar = cTT / (nr - 1);
          double colNew = nr * std::pow(colVar, 3);
          colS[i] = cSt / colNew;
      }
    return(colS);
}

/*** R
set.seed(42)
colSkew( matrix(rnorm(100), 100, 1) )
*/
