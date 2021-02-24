#include <Rcpp.h>

// [[Rcpp::export]]
Rcpp::IntegerVector test(Rcpp::CharacterVector SampleInModel,
                         Rcpp::CharacterVector SampleInPlink) {
  Rcpp::IntegerVector posSampleInPlink = Rcpp::match(SampleInModel, SampleInPlink);
  return posSampleInPlink;
}

/*** R
test(c(1,3,5,7,9),1:10)
*/
