#include <RcppArmadillo.h>
// [[Rcpp::depends(RcppArmadillo)]]

#include <Ziggurat.h>
// [[Rcpp::depends(RcppZiggurat)]]

using namespace Rcpp;
using namespace arma;

static Ziggurat::Ziggurat::Ziggurat zigg;

// [[Rcpp::export]]
vec zzrnorm(int n) {
  vec x(n);
  for (int i=0; i<n; i++) {
    x(i) = zigg.norm();
  }
  return x;
}

// [[Rcpp::export]]
vec zzrnorm_ss(int n, unsigned long int set_seed) {
  zigg.setSeed(set_seed);
  vec x(n);
  for (int i=0; i<n; i++) {
    x(i) = zigg.norm();
  }
  return x;
}

/*** R
RcppZiggurat::zsetseed(1)
RcppZiggurat::zrnorm(3)
#[1] -1.4808858  0.9991196 -0.4898021
#
RcppZiggurat::zsetseed(1)
RcppZiggurat::zrnorm(3)
# [1] -1.4808858  0.9991196 -0.4898021
#
RcppZiggurat::zsetseed(1)
#
zzrnorm(3)
#           [,1]
#[1,] -1.1409054
#[2,]  0.8759027
#[3,] -0.1969075
#
RcppZiggurat::zsetseed(1)
#
zzrnorm(3)
#           [,1]
#[1,] -0.1245053
#[2,]  0.2695581
#[3,] -0.4185105
#
zzrnorm_ss(3, 1)
#           [,1]
#[1,] -1.4808858
#[2,]  0.9991196
#[3,] -0.4898021
#
zzrnorm_ss(3, 1)
#           [,1]
#[1,] -1.4808858
#[2,]  0.9991196
#[3,] -0.4898021
*/
