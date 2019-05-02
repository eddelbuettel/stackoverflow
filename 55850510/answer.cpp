
#include <Rcpp.h>

// [[Rcpp::plugins(cpp11)]]
using namespace Rcpp;

// [[Rcpp::export]]
CharacterVector getColnames(const NumericMatrix &x) {
  size_t nc = x.cols();
  SEXP s = x.attr("dimnames");  // could be nil or list
  if (Rf_isNull(s)) {           // no dimnames, need to construct names
    CharacterVector res(nc);
    for (size_t i=0; i<nc; i++) {
      res[i] = std::string("V") + std::to_string(i);
    }
    return(res);
  } else {                      // have names, return colnames part
    List dn(s);
    return(dn[1]);
  }

}

/*** R
m <- matrix(1:9,3,3)
getColnames(m)
colnames(m) <- c("tic", "tac", "toe")
getColnames(m)
*/
