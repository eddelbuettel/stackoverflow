
#include <Rcpp.h>

using namespace Rcpp;

// [[Rcpp::export]]
List f() {
  List X(2);
  X[0] = rep(0,2);
  X[1] = rep(0,3);
  return X;
}

// [[Rcpp::export]]
List g() {
  IntegerVector v0 = rep(0,2);
  IntegerVector v1 = rep(0,3);
  Rcout << "Sizes are " << v0.size() << " and " << v1.size() << std::endl;
  return List::create(v0, v1);
}


/*** R
f()
g()
*/
