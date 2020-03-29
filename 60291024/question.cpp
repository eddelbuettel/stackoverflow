#include <Rcpp.h>

// [[Rcpp::export]]
Rcpp::List foo(Rcpp::List bc) {
  for (Rcpp::List::iterator i = bc.begin(); i != bc.end(); ++i) {
    SEXP a = *i;
    Rcpp::print(a);
  }

  return(bc);
}

/*** R
ll <- list(a = c(1, 2, 3, 4), b = c(4, 3, 2, 1))
foo(ll)
*/
