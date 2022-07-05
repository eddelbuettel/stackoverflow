

Rcpp::cppFunction("
  arma::uvec ind(arma::uvec x, arma::uvec y){
   arma::vec a(x.size(), arma::fill::zeros);
   for (auto i:y) a = a +  (x==i);
   return arma::find(a) + 1;
  }
 ", 'RcppArmadillo')

c(ind(v, vals))
[1] 1 2 3 4 6 7
