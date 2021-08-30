#include "svol_sisr_hilb.h"
#include "resamplers.h"
#include <RcppEigen.h>

// [[Rcpp::depends(RcppEigen)]]


// choose number of particles, and number of bits for inverse Hilbert curve map  
#define NP 500
#define NB 5
#define debug_mode false


// helpful notes:
// 1. 
// parameters passed to svol_pfilter() ctor are in the following order: phi, beta, sigma
// 2.
// uProposal will be dimension (time X (particles + 1))
// first NP columns will be used for state sampling 
// last column will be used for resampling at each time point
// 3. 
// choosing NP or NB too large will result in stackoverflow
// number of particles is set in two places: in the #define directive and also used in  your R script



// using Eigen::Map; 
// using Eigen::MatrixXd;
// using Eigen::VectorXd;
using hilb_sys_resamp_T = pf::resamplers::sys_hilb_resampler<NP,1,NB,double>;
using svol_pfilter = svol_sisr_hilb<NP,NB, hilb_sys_resamp_T, double, debug_mode>; 

//' Calculates approximate log-likelihood of simple stochastic volatility model (Taylor '82)
//'
//' @param y univariate time series vector
//' @param thetaProposal parameter vector (order is phi, beta, sigma)
//' @param uProposal standard normal variates of dimension time X (particles + 1)
//' @return approximate log-likelihood
// [[Rcpp::export]]
double svolApproxLL(Eigen::Map<Eigen::VectorXd> y, Eigen::Map<Eigen::VectorXd> thetaProposal, Eigen::Map<Eigen::MatrixXd> uProposal) {

  // construct particle filter object
  // param order: phi, beta, sigma
  svol_pfilter pf(thetaProposal(0), thetaProposal(1), thetaProposal(2)); 

  // iterate over the data 
  double log_like(0.0);
  Eigen::Matrix<double,1,1> yt;
  std::array<Eigen::Matrix<double,1,1>, NP> uStateTransition;
  Eigen::Matrix<double,1,1> uResample;
  for(int time = 0; time < y.rows(); ++time){
    
    // change types of inputs
    yt(0) = y(time);
    for(unsigned particle = 0; particle < NP; ++particle) {
      uStateTransition[particle] = uProposal.block(time,particle,1,1); 
    }
    uResample(0) = uProposal(time,NP);
    
    // std::cout << yt.transpose() << "\n";
    // for(unsigned int i = 0; i < NP; ++i)
    //   std::cout << uStateTransition[i] << ", ";
    // std::cout << "\n----------\n";
    
    // update particle filter and log-likelihood    
    pf.filter(yt, uStateTransition, uResample);
    log_like += pf.getLogCondLike();
  }
    
  return log_like;
}

// You can include R code blocks in C++ files processed with sourceCpp
// (useful for testing and development). The R code will be automatically 
// run after the compilation.


/*** R
numTime <- 3
numParts <- 500 # make sure this agrees with NP
u <- matrix(rnorm(numTime*(numParts+1)), ncol = numParts+1)
params <- c(.9, 1, .1) # -1 < phi < 1, beta, sigma > 0
hist(replicate(100, svolApproxLL(rnorm(numTime), params, u)))
*/
