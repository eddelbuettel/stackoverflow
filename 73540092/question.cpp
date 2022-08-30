#include <Rcpp.h>
#include<math.h>
// [[Rcpp::depends(BH)]]

#include <Rcpp.h>
#include <boost/integer/common_factor_rt.hpp>
#include <boost/math/distributions/binomial.hpp>
using boost::math::binomial;

using namespace Rcpp;

// [[Rcpp::export]]
double simonProb(double p, int n1, int r1, int n, int r)
{
  double part1;
  double x;
  binomial b1(n1, p);
  binomial b2(n - n1, p);

  part1 = cdf(b1, r1);
  x = 0;
  for (int i=r1+1; i <= std::min(n1, r); i++) {
    // Rcout << "i: " << i << "; n1: " << n1 << "; r1: " << r1 << "; n: " << n
    //       << " r: " << r << std::endl;
    x +=  pdf(b1, i) * cdf(b2, r-i);
  }
  return (part1 + x);
}

//Mander and Thompson equation at top of page 574
// [[Rcpp::export]]
double manderProb(double p, int n1, int r1, int r2, int n, int r)
{
  double part1;
  double x;
  binomial b1(n1, p);
  binomial b2(n - n1, p);

  part1 = cdf(b1, r1);
  x = 0;
  for(int i=r1+1; i <= r2; i++) {
    x += pdf(b1, i) * cdf(b2, r-i);
  }
  return part1 + x;
}

// [[Rcpp::export]]
DataFrame augmentGridC(DataFrame d) {
  Rcpp::IntegerVector nTotal = d["nTotal"];
  Rcpp::IntegerVector rTotal = d["rTotal"];
  Rcpp::IntegerVector nStage1 = d["nStage1"];
  Rcpp::IntegerVector rFutility = d["rFutility"];
  Rcpp::DoubleVector p0 = d["p0"];
  Rcpp::DoubleVector p1 = d["p1"];
  Rcpp::DoubleVector alpha = d["Alpha"];
  Rcpp::DoubleVector beta = d["Beta"];

  int n = d.nrows();
  std::vector<double> Type1(n);
  std::vector<double> Type2(n);
  std::vector<double> PETNull(n);
  std::vector<double> PETAlt(n);
  std::vector<double> AveSizeNull(n);
  std::vector<double> AveSizeAlt(n);

  DataFrame rv;

  for (int i=0; i < n; i++) {
    binomial b0(nStage1[i], p0[i]);
    binomial b1(nStage1[i], p1[i]);

  }
  if (d.containsElementNamed("rSuccess")) {
    //Mander & thompson design
    Rcpp::DoubleVector rSuccess = d["rSuccess"];
    for (int i=0; i < n; i++) {
      binomial b0(nStage1[i], p0[i]);
      binomial b1(nStage1[i], p1[i]);

      Type1[i] = 1 - manderProb(p0[i], nStage1[i], rFutility[i], rSuccess[i], nTotal[i], rTotal[i]);
      Type2[i] = manderProb(p1[i], nStage1[i], rFutility[i], rSuccess[i], nTotal[i], rTotal[i]);
      PETNull[i] = 1 - cdf(b0, rSuccess[i]) + cdf(b0, rFutility[i]);
      PETAlt[i] = 1 - cdf(b1, rSuccess[i]) + cdf(b1, rFutility[i]);
      AveSizeNull[i] = nStage1[i] + (1-PETNull[i])*(nTotal[i] - nStage1[i]);
      AveSizeAlt[i] = nStage1[i] + (1-PETAlt[i])*(nTotal[i] - nStage1[i]);
    }
    rv = DataFrame::create(_["nTotal"] = nTotal,
                           _["nStage1"] = nStage1,
                           _["rTotal"] = rTotal,
                           _["rFutility"] = rFutility,
                           _["rSuccess"] = rSuccess,
                           _["p0"] = p0,
                           _["p1"] = p1,
                           _["Alpha"] = alpha,
                           _["Beta"] = beta,
                           _["Type1"] = Rcpp::wrap(Type1),
                           _["Type2"] = Rcpp::wrap(Type2),
                           _["PETNull"] = Rcpp::wrap(PETNull),
                           _["PETAlt"] = Rcpp::wrap(PETAlt),
                           _["AveSizeNull"] = Rcpp::wrap(AveSizeNull),
                           _["AveSizeAlt"] = Rcpp::wrap(AveSizeAlt));
  } else {
    //Simon's design
    for (int i=0; i < n; i++) {
      binomial b0(nStage1[i], p0[i]);
      binomial b1(nStage1[i], p1[i]);
      Type1[i] = 1.0 - simonProb(p0[i], nStage1[i], rFutility[i], nTotal[i], rTotal[i]);
      Type2[i] = simonProb(p1[i], nStage1[i], rFutility[i], nTotal[i], rTotal[i]);
      PETNull[i] = cdf(b0, rFutility[i]);
      PETAlt[i] = cdf(b1, rFutility[i]);
      AveSizeNull[i] = nStage1[i] + (1 - cdf(b0, rFutility[i]))*(nTotal[i]-nStage1[i]);
      AveSizeAlt[i] = nStage1[i] + (1 - cdf(b1, rFutility[i]))*(nTotal[i]-nStage1[i]);
    }
    rv = DataFrame::create(_["nTotal"] = nTotal,
                           _["nStage1"] = nStage1,
                           _["rTotal"] = rTotal,
                           _["rFutility"] = rFutility,
                           _["p0"] = p0,
                           _["p1"] = p1,
                           _["Alpha"] = alpha,
                           _["Beta"] = beta,
                           _["Type1"] = Rcpp::wrap(Type1),
                           _["Type2"] = Rcpp::wrap(Type2),
                           _["PETNull"] = Rcpp::wrap(PETNull),
                           _["PETAlt"] = Rcpp::wrap(PETAlt),
                           _["AveSizeNull"] = Rcpp::wrap(AveSizeNull),
                           _["AveSizeAlt"] = Rcpp::wrap(AveSizeAlt));
  }
  return rv;
}

