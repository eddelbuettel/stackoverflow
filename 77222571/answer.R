
Rcpp::cppFunction("bool isPosInf(double x) { return x == R_PosInf; }")
sapply(c(-Inf, Inf, 0), isPosInf)
# [1] FALSE  TRUE FALSE

Rcpp::cppFunction("bool isNegInf(double x) { return x == R_NegInf; }")
sapply(c(-Inf, Inf, 0), isNegInf)
# [1]  TRUE FALSE FALSE
