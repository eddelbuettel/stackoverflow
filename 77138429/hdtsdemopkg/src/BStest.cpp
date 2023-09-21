#include "hdts.h"

using namespace Rcpp;

double BStest(const arma::mat & y1, const arma::mat & y2)
{
  int n1 = y1.n_cols;int n2 = y2.n_cols;
  int p = y1.n_rows;
  arma::colvec mu1=arma::mean(y1, 1); arma::mat z1=y1-arma::repmat(mu1,1,n1);
  arma::colvec mu2=arma::mean(y2, 1); arma::mat z2=y2-arma::repmat(mu2,1,n2);
  int n=n1+n2-2;
  double invtau=double(n1*n2)/(n1+n2);
  double stat=arma::as_scalar((mu1-mu2).t()*(mu1-mu2));
  arma::mat z=join_horiz(z1,z2);
  arma::mat S;
  if(p<=n)
  {
    S=(z*z.t())/n;//tr(Sigmahat)
  }
  else
  {
    S=(z.t()*z)/n;
  }
  double trSn=arma::trace(S);//tr(Sigmahat^2)
  double trSn2=arma::accu(S%S);//tr(Sigmahat^2)
  double Bn2=double(n*n)/((n+2)*(n-1))*(trSn2-trSn*trSn/n);//unbiased estimator for B
  double statn=(invtau*stat-trSn)/sqrt(2*double(n+1)/n*Bn2);
  return statn;
}
