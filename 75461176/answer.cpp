
#include <Rcpp.h>

extern "C" {
    void mytest_f(int l, int m, int n, int *a, int *c);
}

// [[Rcpp::export]]
Rcpp::IntegerVector c_mytest_f(Rcpp::IntegerVector a3D) {

    // receives the 3D array
    Rcpp::IntegerVector dim = a3D.attr("dim");

    int l = dim[0],
        m = dim[1],
        n = dim[2];

    Rcpp::IntegerVector c(l*m*n); // vectors are contiguous

    mytest_f(l, m, n, &(a3D[0]), &(c[0]));

    return c;
}
