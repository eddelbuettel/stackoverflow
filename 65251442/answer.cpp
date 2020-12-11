
#include <RcppEigen.h>

// [[Rcpp::depends(RcppEigen)]]

// [[Rcpp::export]]
void showNames(SEXP m) {
  Rcpp::NumericMatrix nm(m);     // to easily access attributes
  Rcpp::List dmnm = nm.attr("dimnames");
  print(dmnm);

  // continue as before
  Eigen::MatrixXd Mat = Rcpp::as<Eigen::MatrixXd>(m); // make Mat from m as before
  // ... some stuff with Mat
}

/*** R
mat <- matrix(1:4,ncol=2)
colnames(mat) <- c("col1","col2")
attributes(mat)

showNames(mat)
*/
