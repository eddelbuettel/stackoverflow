#include <Rcpp.h>

// [[Rcpp::export]]
double nontrivial(int iters) {
    double sum = 0;
    for (int i = 0; i < iters; ++i) {
        sum += log(i * 1.0);
    }
    return sum;
}
