#include <Rcpp.h>

// [[Rcpp::export]]
Rcpp::NumericVector vectorTest(double globe, Rcpp::NumericVector speed) {
    Rcpp::NumericVector globevec(speed.size(), globe);
    return globevec + speed;
}

/*** R
speed <- c(1,2,3,4,5)
Tglobe <- 100
vectorTest(Tglobe, speed)
*/
