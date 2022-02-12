
Sys.setenv(PKG_CPPFLAGS="-DRCPP_ARMADILLO_FIX_Field")  ## sets #define RCPP_ARMADILLO_FIX_Field
Rcpp::cppFunction("arma::field<arma::vec> testgg(int k, int h, int g) { arma::field<arma::vec> res(k, h, g); return(res);}", depends="RcppArmadillo")
testgg(2,3,4)
