#include "hdts.h"

using namespace Rcpp;

// BStestby
// [[Rcpp::export]]
arma::vec BStestby(const arma::mat & y1, const arma::mat & y2)
{
int n1 = y1.n_cols;int n2 = y2.n_cols;
int p = y1.n_rows;
arma::colvec mu1=arma::mean(y1, 1);
arma::mat z1=y1-arma::repmat(mu1,1,n1);
arma::colvec mu2=arma::mean(y2, 1);
arma::mat z2=y2-arma::repmat(mu2,1,n2);
int n=n1+n2;
double invtau=double(n1*n2)/n;
double stat=arma::as_scalar((mu1-mu2).t()*(mu1-mu2));
arma::mat z=join_horiz(z1,z2);
arma::mat S;
if(p<=n)
{
S=(z*z.t())/(n-2);//tr(Sigmahat)
}
else
{
S=(z.t()*z)/(n-2);
}
double trSn=arma::trace(S);//tr(Sigmahat^2)
double trSn2=arma::accu(S%S);//tr(Sigmahat^2) ##element-wise multiplication
double trSn3=arma::trace(S*S*S);//tr(Sigmahat^3)
double htrSn2 = pow((n-2),2)*(trSn2-trSn*trSn/(n-2))/(n-3)/n;
double htrSn3 = pow((n-2),4)*(trSn3-3*trSn*trSn2/(n-2)+2*pow(trSn,3)/pow((n-2),2))/(n*n-n-6)/(n*(n-4));

double statn=invtau*stat-trSn;
double beta0 = -(n-1)*htrSn2*htrSn2/htrSn3/(n-3);
double beta1 = (n-3)*htrSn3/htrSn2/(n-2);
double d = (n-1)*(n-2)*pow(htrSn2,3)/pow(htrSn3,2)/pow((n-3),2);
double statstd = statn/sqrt(2*(n-1)*htrSn2/(n-2));

arma::vec stats(5);
stats(0)=statn;
stats(1)=beta0;
stats(2)=beta1;
stats(3)=d;
stats(4)=statstd;
return stats;
}
