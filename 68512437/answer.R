Rcpp::cppFunction("NumericVector logvec(NumericVector v) { return log(v); }")
logvec(seq(1.0, 2.0, by=0.25))
