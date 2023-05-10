#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
double fC() {
  return 0.0;
}

NumericVector ru()  { return Rcpp::runif(1); }


// [[Rcpp::export]]
void test(Function g) {

  for(int j=0;j<10;++j) {
     NumericVector z=g();
     Rcout<<ru()<<" ";
  }
  Rcout<<"\n";
  for(int j=0;j<10;++j) Rcout<<ru()<<" ";
  Rcout<<"\n";
}

/*** R

fR <- function(x) {0.0}

test(fR)

test(fC)

*/
