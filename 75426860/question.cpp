#include <Rcpp/Lighter>

// [[Rcpp::export]]
Rcpp::List test_lapply_function1() {
    Rcpp::IntegerVector x = Rcpp::seq_len(10);
    Rcpp::List y = Rcpp::lapply(x, Rcpp::seq_len);

    return(y);
}

Rcpp::List test_lapply_function2() {
    Rcpp::IntegerVector x = Rcpp::seq_len(10);
    Rcpp::List l = Rcpp::List::create(Rcpp::Named("res") = Rcpp::wrap(Rcpp::sum(x)));
    return(l);
}
