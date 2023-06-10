
#include <Rcpp/Lightest>

inline bool dupevec(Rcpp::NumericVector x, Rcpp::NumericVector y) {
    return x[0] == y[0] && x[1] == y[1] && x[2] == y[2];
}

// [[Rcpp::export(rng=false)]]
Rcpp::LogicalVector dupes(Rcpp::NumericMatrix M) {
    int n = M.ncol();
    Rcpp::LogicalVector lv(n);
    for (int i=0; i<n; i++) {
        bool val = false;
        Rcpp::NumericVector x = M.column(i);
        for (int j=i+1; !val && j<n; j++) {
            val = dupevec(x, M.column(j));
        }
        lv[i] = val;
    }
    return lv;
}

/*** R
set.seed(123)
N <- 15
M <- matrix(sample(c(1,2,3), N*3, replace=TRUE), 3, N)
M
dupes(M)
duplicated(t(M), fromLast=TRUE)
microbenchmark::microbenchmark(Rcpp=dupes(M), R=duplicated(t(M), fromLast=TRUE), times=100)
*/
