#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
int test_null(Nullable<DataFrame> p1 = R_NilValue){

  if (p1.isNull()) {
    NumericMatrix T(2,2);
    Rcout << T << std::endl;
  } else {
    DataFrame S(p1);
    NumericMatrix T(S.nrow());
    Rcout << T << std::endl;
  }
  return (42);
}

/*** R
test_null(NULL)
test_null(data.frame(a=1:3, b=letters[1:3]))
*/
