// by user thc

#include <Rcpp.h>
#include <algorithm>
using namespace Rcpp;

// [[Rcpp::export]]
uint64_t choosecpp(uint64_t n, uint64_t k) {
  if(k == 0) return 1;
  return (n * choosecpp(n - 1, k - 1)) / k;
}

// [[Rcpp::export]]
IntegerMatrix combncpp(int N, int K) {
  if(K > N) Rcpp::stop("K > N");
  std::string bitmask(K, 1);
  bitmask.resize(N, 0);

  uint64_t n_combos = choosecpp(N,K);
  IntegerMatrix results(n_combos, K);
  uint64_t row_position = 0;
  do {
    uint64_t col_position = 0;
    for (int i = 0; i < N; ++i)  {
      if (bitmask[i]) {
        results(row_position, col_position) = i+1;
        col_position++;
      }
    }
    row_position++;
  } while (std::prev_permutation(bitmask.begin(), bitmask.end()));
  return results;
}
