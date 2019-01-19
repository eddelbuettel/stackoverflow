#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]

double est_qaf(NumericVector x, NumericVector y, int maxlag, NumericMatrix
perms, NumericMatrix quants){

int npr = sqrt(perms.nrow());
NumericMatrix result_x(perms.nrow(), maxlag);
NumericMatrix result_y(perms.nrow(), maxlag);

  for (int i=0; i<maxlag; i++) {
    NumericVector gamma_x(perms.nrow());
    NumericVector gamma_y(perms.nrow());

    for (int j=0; j<perms.nrow(); j++) {
      gamma_x[j] = pow(x.size()-(i+1), -1) * sum((x[Range(0, x.size()-(i+2))] <= quants(((j%(j+1)-(j%npr))/npr),0)) * (x[Range(1+i,x.size())] <= quants(j%npr,0))) - perms(i,0)*perms(i,1);
      gamma_y[j] = pow(y.size()-(i+1), -1) * sum((y[Range(0, y.size()-(i+2))] <= quants(((j%(j+1)-(j%npr))/npr),1)) * (y[Range(1+i,y.size())] <= quants(j%npr,1))) - perms(i,0)*perms(i,1);
   }
   result_x(_,i) = gamma_x;
   result_y(_,i) = gamma_y;
  }
  return(sum(pow(as_vector(result_x) - as_vector(result_y), 2.0)));
}

/*** R

dist_qaf <- function(x, y, maxlag, levels){

  quantiles <- apply(cbind(as.numeric(x), as.numeric(y)), 2,
                   function(z) quantile(z, probs = levels))

  permutations <- as.matrix(expand.grid(levels, levels))

  dist <- est_qaf(as.numeric(x), as.numeric(y), maxlag = maxlag,
                  quants = quantiles, perms = permutations)

  return(dist)
}

set.seed = 1
X <- matrix(rnorm(250 * 500), nrow = 250, ncol = 500)

dist_mat <- matrix(NA, nrow = ncol(X), ncol = ncol(X))
index <- lower.tri(dist_mat , diag = FALSE)
comb <- combn(1:ncol(X), m = 2, simplify = FALSE)

## this is HUGE, not running it

#dist_mat[index] <- lapply(comb, function(i) dist_qaf(X[,i[1]], X[,i[2]], maxlag = 30, levels = seq(from = 0.1, to = 0.9, by = 0.2)))
#dist_mat <- as.dist(dist_mat)

#sum(is.na(dist_mat))
*/
