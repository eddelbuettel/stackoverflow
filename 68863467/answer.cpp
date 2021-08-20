#include <Rcpp.h>

// [[Rcpp::export]]
std::vector<double> vecpow(const std::vector<double> base,
                           const std::vector<double> exp) {

    std::vector<double> out(base.size());
    std::transform(base.begin(), base.end(), exp.begin(), out.begin(),
                   [&](double lhs, double rhs) -> double { return std::pow(lhs, rhs); });
    return out;
}

// [[Rcpp::export]]
Rcpp::NumericVector vecpow2(Rcpp::NumericVector base, Rcpp::NumericVector exp) {

    Rcpp::NumericVector out(base.size());
    std::transform(base.begin(), base.end(), exp.begin(), out.begin(),
                   [&](double lhs, double rhs) -> double { return std::pow(lhs, rhs); });
    return out;
}

/*** R
vecpow(0:3, 4:1)
vecpow2(0:3, 4:1)
*/
