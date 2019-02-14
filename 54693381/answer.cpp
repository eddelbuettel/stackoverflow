
#include <Rcpp.h>

// [[Rcpp::export]]
Rcpp::List quickdemo() {
  Rcpp::CharacterVector v = Rcpp::CharacterVector::create("");
  v.attr("type") = "root";
  v.attr("sticon") = "fa-icon";
  v.attr("stclass") = "color";
  return Rcpp::List::create(Rcpp::Named("Name1") = v);
}

/*** R
quickdemo()
*/
