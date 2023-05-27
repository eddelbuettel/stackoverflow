#include <RcppArmadillo.h>
#include <omp.h>

// [[Rcpp::depends(RcppArmadillo)]]
// [[Rcpp::plugins(openmp)]]

// [[Rcpp::export]]
arma::mat mod_cube(int nrun, int d, int nthr=1) {
    arma::mat x(d, nrun);
#pragma omp parallel for shared(x) num_threads(nthr)
    for (size_t run = 0; run < nrun; run++) {
        x.col(run).fill((double) run+1);
    }
    return x;
}

/*** R
mod_cube(10, 10, 10)
*/
