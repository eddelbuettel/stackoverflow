
#include <Rcpp.h>

// [[Rcpp::export]]
Rcpp::CharacterMatrix foo(Rcpp::CharacterMatrix x) {
  for (int i=0; i<x.rows(); i++) {
    for (int j=0; j<x.cols(); j++) {
      std::string s(x(i,j));
      s[0] = std::toupper(s[0]);
      x(i,j) = s;
    }
  }
  return x;
}

/*** R
foo(matrix(c("the","quick","brown","fox"),2,2))
*/
