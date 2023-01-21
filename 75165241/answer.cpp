
#include <RcppGSL.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>

// [[Rcpp::depends(RcppGSL)]]

// [[Rcpp::export]]
std::vector<unsigned int> foo(int n, const std::vector <double> p) {
    int k = p.size();
    std::vector<unsigned int> nv(k);
    gsl_rng_env_setup();
    gsl_rng *s = gsl_rng_alloc(gsl_rng_mt19937); // Create RNG instance
    gsl_ran_multinomial(s, k, n, &(p[0]), &(nv[0]));
    gsl_rng_free(s);

    return nv;
}

// [[Rcpp::export]]
std::vector<int> bar(int n, std::vector <double> p) {
    int k = p.size();
    std::vector<int> nv(k);
    R::rmultinom(n, &(p[0]), k, &(nv[0]));
    return nv;
}


/*** R
n <- 4000
p <- c(0.1, 0.2, 0.3, 0.4)
foo(n, p)
bar(n, p)
res <- rbenchmark::benchmark(foo(n,p), bar(n,p), replications=10000)
res
*/
