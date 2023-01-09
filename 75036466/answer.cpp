#include <RcppArmadillo/Lightest> // new 'lighter' header

// [[Rcpp::depends(RcppArmadillo)]]
// [[Rcpp::export]]
arma::icube make3dvec(){
    arma::icube v(2,2,2);
    for (int x = 0; x < 2; x++){
        for (int y = 0; y < 2; y++){
            for (int z = 0; z < 2; z++){
                v(x,y,z) = (x + 1) * (y + 1) * (z + 1);
            }
        }
    }
    return v;
}

/*** R
make3dvec()
*/
