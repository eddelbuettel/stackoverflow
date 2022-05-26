
Rcpp::cppFunction("NumericVector goodVec(int n) { return NumericVector(n); }")
sum(goodVec(1e7))
