#include <random>
#include <Rcpp.h>

std::mt19937 engine(123);

// [[Rcpp::export]]
Rcpp::NumericVector mygamma(int n, double a, double b) {
  Rcpp::NumericVector v(n);
  std::gamma_distribution<> gamma(a, b);
  for (auto i=0; i<n; i++) {
    v[i] = gamma(engine);
  }
  return v;
}

/*** R
mygamma(3, 0.5, 0.5)
mygamma(3, 0.5, 0.5)
*/
