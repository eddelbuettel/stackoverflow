#include <Rcpp.h>

// [[Rcpp::export]]
int exampleOutside(Rcpp::IntegerMatrix mat, int iters) {
  for(int i = 0; i < iters; ++i) {
    std::vector<int> vec;
    std::iota(std::begin(vec), std::end(vec), 0);
  }
  return 0;
}
