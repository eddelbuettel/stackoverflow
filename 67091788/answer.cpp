// [[Rcpp::depends(RcppArmadillo)]]
#include <RcppArmadillo.h>

// [[Rcpp::export]]
arma::colvec Demo(arma::mat n, int K){
    arma::colvec N(K, arma::fill::zeros);
    for(int j=0; j<K; ++j){
        for(int i=0; i<(K-j); ++i){
            N[j] += accu(n.submat(i,0,i,j));
        }
    }
    return N;
}

/***R
K = 4
n = cbind(c(1008, 5112, 1026, 25, 0), 0, 0, 0, 0)
Demo(n,K)

for(i in 1:3) {
 print(Demo(n,K))
 print(K)
 print(n)
}
*/
