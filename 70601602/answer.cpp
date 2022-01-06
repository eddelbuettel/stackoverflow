#include <Rcpp.h>

// [[Rcpp::export]]
Rcpp::List foo(Rcpp::NumericVector v) {

    // we just us a random vector here to determine: if positive
    // we inject a string, if negative NULL

    const std::string mystring = "helloworld";  // if positive

    int n = v.size();
    Rcpp::List z(n);

    for (int i=0; i<n; i++) {
        if (v[i] < 0) {
            z[i] = mystring;
        } else {
            z[i] = R_NilValue;
        }
    }

    return z;
}

/*** R
set.seed(123)
foo(rnorm(3))
set.seed(123456)
foo(rnorm(3))
*/
