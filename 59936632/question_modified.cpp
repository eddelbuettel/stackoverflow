#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
NumericVector fun() {

  IntegerVector v = rep(1, 5);
  NumericVector w{1.0, 2.0, 3.0};

  // Attempt 1.
  for (int k = 0; k < 3; ++k){
    NumericVector s = cumsum(w);
    w = s;
  }

  // Attempt 2.
  // IntegerVector tempv;
  // for(int k = 0; k < 3; ++k){
  //   tempv = cumsum(v);
  //   v = tempv;
  // }

  // can reproduce error more simply with the following:
  // so issue is assigning back to variable or change of class?
  // v = cumsum(v);

  // Attempt 3.
  // IntegerVector tempv;
  // for(int k = 0; k < 3; ++k){
  //   tempv = cumsum(v);
  //   v = as<IntegerVector>(tempv);
  // }

  return w;
}

/*** R
fun()
*/
