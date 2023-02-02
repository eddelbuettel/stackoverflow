
#include <Rcpp/Lighter>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>

// [[Rcpp::depends(RcppGSL)]]

class ZigguratGSL {
public:
    ZigguratGSL(uint32_t seed=12345678) {
        gsl_rng_env_setup() ;
        r = gsl_rng_alloc (gsl_rng_default);
        gsl_rng_set(r, seed);
    }
    ~ZigguratGSL() {
        gsl_rng_free(r);
    }
    double normZig() {
        const double sigma=1.0;
        return gsl_ran_gaussian_ziggurat(r, sigma);
    }
    double normPlain() {
        const double sigma=1.0;
        return gsl_ran_gaussian_ziggurat(r, sigma);
    }
    void setSeed(const uint32_t seed) {
        gsl_rng_set(r, seed);
    }
private:
    gsl_rng *r;
};

static ZigguratGSL gsl;

// [[Rcpp::export]]
void setseedGSL(const uint32_t s) {
    gsl.setSeed(s);
    return;
}

// [[Rcpp::export]]
Rcpp::NumericVector rnormGSLZig(int n) {
    Rcpp::NumericVector x(n);
    for (int i=0; i<n; i++) {
        x[i] = gsl.normZig();
    }
    return x;
}

// [[Rcpp::export]]
Rcpp::NumericVector rnormGSLPlain(int n) {
    Rcpp::NumericVector x(n);
    for (int i=0; i<n; i++) {
        x[i] = gsl.normPlain();
    }
    return x;
}

// [[Rcpp::export]]
Rcpp::NumericVector rcppLoop(int n) {
    Rcpp::NumericVector x(n);
    for (int i=0; i<n; i++) {
        x[i] = R::rnorm(1.0,0.0);
    }
    return x;
}

// [[Rcpp::export]]
Rcpp::NumericVector rcppDirect(int n) {
    return Rcpp::rnorm(n, 1.0, 0.0);
}


/*** R
setseedGSL(42)
rnormGSLZig(5)
rnormGSLZig(5)    # different
setseedGSL(42)
rnormGSLZig(5)    # as before


library(microbenchmark)
n <- 1e5
res <- microbenchmark(rnormGSLZig(n), rnormGSLPlain(n), rcppLoop(n), rcppDirect(n))
res
*/
