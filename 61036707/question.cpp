#include <Rcpp.h>
using namespace Rcpp;
// [[Rcpp::export]]
NumericVector matrix2vector(NumericMatrix m, const bool byrow=false){
  if (byrow){
    Rcout << "warning: default by column\n";
    m = transpose(m);
  }
  return NumericVector(m);
}

/*** R
m <- matrix(1:15,5,3)
print(matrix2vector(m, byrow = TRUE))
print(matrix2vector(m, byrow = FALSE))
*/
