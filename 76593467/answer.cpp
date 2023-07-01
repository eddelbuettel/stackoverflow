#include <RcppArmadillo.h>
#include <RcppGSL.h>
#include<omp.h>
#include<gsl/gsl_math.h>

// [[Rcpp::plugins(cpp17)]]
// [[Rcpp::depends(RcppArmadillo)]]
// [[Rcpp::depends(RcppGSL)]]
// [[Rcpp::plugins(openmp)]]

// [[Rcpp::depends(RcppEigen)]]
// [[Rcpp::depends(RcppNumerical)]]
#include <RcppNumerical.h>

using namespace Numer;
using namespace arma;

// [[Rcpp::export]]
double log_sum_exp(const   arma::vec &x) {
  double maxVal= x.max();

  double sum_exp=sum(exp(x-maxVal));
  return log(sum_exp)+maxVal ;
}

class mixture_quantile: public MFuncGrad
{
private:
  const double a;
  const arma::vec mu, sd, pi;
public:
  mixture_quantile( const double &a_,const arma::vec & mu_, const arma::vec &sd_, const arma::vec &pi_) : a(a_), mu(mu_), sd(sd_), pi(pi_) {}

  double f_grad(Constvec&  x0, Refvec grad)
  {
    double x=x0[0];

    arma::vec std_x=(x-mu)/sd, log_pi=log(pi);

    arma::vec  log_norm_cdf=std_x ;
    log_norm_cdf.transform( [](double val) { return R::pnorm5(val,0,1,1,1); } );

    log_norm_cdf+=log_pi;

    double log_mixture_cdf=log_sum_exp(log_norm_cdf);

    double root_f=log_mixture_cdf-log(a);
    const double f= gsl_pow_2(root_f ); //function to return


    //derivative
    arma::vec wh= -.5*(square(std_x) +M_LNPI +M_LN2 ) -log(sd) + log_pi -log_mixture_cdf;

    grad[0]= 2*root_f * exp(log_sum_exp(wh));
    return f;
  }
};

// [[Rcpp::export]]
arma::mat gauss_solve_mat(const arma::vec &mu,const  arma::vec &sd,const arma::vec &pi,
                          unsigned d, unsigned nthr=1)
{
  const unsigned nmix=mu.n_elem, n=100;
  mat mumat(d,nmix), sdmat(d,nmix), pimat(d,nmix);
  mumat.each_col()=mu,  sdmat.each_col()=sd, pimat.each_col()=sd;

  mat a(n,d,fill::randu );
  mat result(size(a));

  // #pragma omp parallel for num_threads(nthr)
  for(unsigned j = 0; j < d; ++j){
    vec tmpvec=a.col(j);


    for(unsigned i=0;i<n;++i){
      // Initial guess
      double fopt;
      mixture_quantile f(a(i,j),mumat.col(j),sdmat.col(j),pimat.col(j));
      // mixture_quantile f(a(i,j),mu,sd,pi);

      Eigen::VectorXd guess(1);

      guess[0]=0.;
      int res = optim_lbfgs(f, guess, fopt);
      //cout<<"i="<<i<<" j="<<j<<endl;
      if(res < 0)
        cout<<"fail to converge. fopt= "<<fopt<<endl;
      // Rcpp::stop("fail to converge");
      tmpvec(i)=guess[0];
    }
    result.col(j)=tmpvec;
  }

  return result;
}

/*** R
mu <- c(11.7669  , 11.2504 ,  11.6544  , 11.3683 ,  11.5435  , 13.1097  ,  1.1653  , 11.6884 ,  10.2279 ,  14.3162)
sd <- c(0.3040 , 0.2813  , 0.2953 ,  0.3056 ,  0.2825  , 0.2853  , 0.2775  , 0.3007  , 0.2980   ,0.2816)
pi <- c(0.0451 ,  0.1389 ,  0.1883 ,  0.1031 ,  0.0666 ,  0.1938 ,  0.0011 ,  0.2541 ,  0.0042 ,  0.0050)

str(gauss_solve_mat(mu,sd,pi,d=10,   nthr=1))
*/
