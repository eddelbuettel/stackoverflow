#include <RcppEnsmallen.h>
// [[Rcpp::depends(RcppEnsmallen)]]


class Himmelblau{
public:
  double Evaluate(const arma::mat& x) {
    return ( x[0]*x[0] + x[1] - 11.0 )*( x[0]*x[0] + x[1] - 11.0 ) + (x[0] + x[1]*x[1] - 7.0)*(x[0] + x[1]*x[1] - 7.0);
  }
  void Gradient(const arma::mat& x, arma::mat& gradient){
    gradient[0] = 4*x[0]*(-11.0 + x[0]*x[0] + x[1]) + 2.0*(-7.0 + x[0] + x[1]*x[1]);
    gradient[1] = 2*(-11.0 + x[0]*x[0] + x[1]) + 4*x[1]*(-7.0 + x[0] + x[1]*x[1]);

  }

  void Shuffle(){}

  size_t NumFunctions(){
    return 1;
  }
};

// [[Rcpp::export]]
arma::mat himmelblau_adam(const arma::vec& x){

  Himmelblau hb;

  arma::mat beta = arma::mat(1,2);

  beta[0] = x[0];
  beta[1] = x[1];


  ens::Adam opt(0.001, 16, 0.9, 0.999, 1e-8, 10000, 1e-5, true);

  opt.Optimize(hb,beta);


  arma::mat beta2 = arma::mat(1,3);

  beta2[0] = beta[0];
  beta2[1] = beta[1];
  beta2[2] = hb.Evaluate(beta);

  return beta2;
}
