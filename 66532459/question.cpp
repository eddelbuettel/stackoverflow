// CharacterVector example
#include <Rcpp.h>
using namespace Rcpp;
template<typename T, typename S>
bool any_na(S x){
    T xx = as<T>(x);
    for (auto i : xx){
        if (T::is_na(i))
            return true;
    }
    return false;
}

// [[Rcpp::export(rng = false)]]
LogicalVector rcpp_any_na(SEXP x){
    return any_na<CharacterVector>(x);
}

// [[Rcpp::export(rng = false)]]
SEXP overhead(SEXP x){
    CharacterVector xx = as<CharacterVector>(x);
    return wrap(xx);
}

// [[Rcpp::export(rng = false)]]
bool rcpp_c_api(SEXP x) {
    R_xlen_t n = Rf_length(x);
    for (R_xlen_t i = 0; i < n; i++) {
        if(STRING_ELT(x, i) == NA_STRING)
            return true;
  }
  return false;
}

// courtesy of the checkmate package
// [[Rcpp::export(rng=false)]]
R_xlen_t rcpp_altrep(SEXP x) {
#if defined(R_VERSION) && R_VERSION >= R_Version(3, 5, 0)
    if (STRING_NO_NA(x))
        return 0;
#endif
    const R_xlen_t nx = Rf_xlength(x);
    for (R_xlen_t i = 0; i < nx; i++) {
        if (STRING_ELT(x, i) == NA_STRING)
            return i + 1;
    }
    return 0;
}


/***R
library(microbenchmark)

srt <- c("A",NA_character_)
lng <- c(rep("A", 1e6), NA_character_)
microbenchmark(short = function(srt) { anyNA(srt) },
               long = function(lng) { anyNA(lng) },
               times=1000)

N <- 1e6
vec <- sample(letters, N, TRUE)
vec[N] <- NA_character_
anyNA(vec)                      # to check


microbenchmark(
  anyNA       = anyNA(vec),
  Rcpp_plain  = rcpp_c_api(vec),
  Rcpp_tmpl   = rcpp_any_na(vec),
  Rcpp_altrep = rcpp_altrep(vec),
  #Rcpp_Function = any_na3(vec),
  #overhead = overhead(vec),
  times = 5000
#  unit="relative"
)
*/
