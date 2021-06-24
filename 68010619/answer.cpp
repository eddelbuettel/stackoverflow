
#include <Rcpp.h>

// [[Rcpp::export]]
Rcpp::IntegerVector testfunc(Rcpp::IntegerVector vec1) {
    int n = vec1.size();
    Rcpp::IntegerVector output(n);
    for ( int i = 0; i < n; i++) { //for loop to go through each element in vector
        if (vec1[i] < 0){
            output[i] = -1;
        } else if (vec1[i] == 0){
            output[i] = 0;
        } else {
            output[i] = 1;
        }
    }
    return output;
}

/*** R
vec <- c(-1L, -1L, 0L)
testfunc(vec)
*/
