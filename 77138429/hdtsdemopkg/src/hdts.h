#ifndef HDTS_H
#define HDTS_H

#include <RcppArmadillo.h>

using namespace Rcpp;

// DEFINE FUNCTIONS

double BStest(const arma::mat & y1, const arma::mat & y2);
arma::vec CQtest(const arma::mat & y1, const arma::mat & y2);
arma::vec BStestby(const arma::mat & y1, const arma::mat & y2);

#endif
