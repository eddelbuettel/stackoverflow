
Rcpp::cppFunction("LogicalVector foo(NumericVector x) { return is_finite(x); }")
foo(c(1.0, Inf, -Inf, NA, NaN, 42))


Rcpp::cppFunction("void stop_if_na(const IntegerVector IV) {
  if (Rcpp::is_true(Rcpp::any(Rcpp::is_na(IV)))) {
    Rcpp::stop(\"`I` contains NA values\");
  }
}")
stop_if_na(1:5)
stop_if_na(c(1:5, NA, 7:9))
