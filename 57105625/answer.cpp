
#include <RcppArmadillo.h>

// [[Rcpp::depends(RcppArmadillo)]]

// -- for { } init below
// [[Rcpp::plugins(cpp11)]]

// [[Rcpp::export]]
arma::mat getMatrix() {
  const arma::mat a = { {0, 1, 2, 3} ,   /*  initializers for row indexed by 0 */
                        {4, 5, 6, 7} ,   /*  initializers for row indexed by 1 */
                        {8, 9, 10, 11}   /*  initializers for row indexed by 2 */
  };
  return a;
}

// [[Rcpp::export]]
double tf(arma::mat x){
  double aa = arma::as_scalar(arma::sum(arma::sum(x+x)));
  return(aa);
}

/*** R
tf( getMatrix() )
*/
