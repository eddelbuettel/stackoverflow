#include <RcppArmadillo.h>
using namespace Rcpp;
using namespace arma;

// [[Rcpp::depends("RcppArmadillo")]]

// [[Rcpp::export]]
//List MatMultFunc(arma::sp_mat D, arma::mat X, arma::sp_mat BetaSp){
int MatMultFunc(const arma::sp_mat & D, const arma::mat & X, const arma::sp_mat & BetaSp){

    arma::vec tXB(D * (X * BetaSp));

    for (int m = 0; m < 1000; m++) {

        tXB = D * (X * BetaSp);
    }

    //return List::create(Named("tXB") = wrap(tXB));
    return 0;
}
