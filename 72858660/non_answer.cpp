
#include <RcppArmadillo.h>

// [[Rcpp::depends(RcppArmadillo)]]

// [[Rcpp::export]]
std::vector<double> intersectVectors(const arma::vec& x, const arma::vec& vals) {
    std::vector<double> res;
    std::set_intersection(x.begin(), x.end(),
                          vals.begin(), vals.end(),
                          std::back_inserter(res));

    return res;
}

/*** R
x <- c(1,1,1,4,2,4,4)
vals <- c(1,4)
intersectVectors(x, vals)
intersectVectors(vals, x)
*/
