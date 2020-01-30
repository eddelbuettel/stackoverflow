#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
IntegerVector fun() {

  IntegerVector v = rep(1, 5);

  // Attempt 1.
  for(int k = 0; k < 3; ++k){
    v = cumsum(v);
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

  return v;
}
