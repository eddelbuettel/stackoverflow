// https://gallery.rcpp.org/articles/sorting/
// https://www.geeksforgeeks.org/sorting-a-vector-in-c/
#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
NumericVector cpp_sort_numeric_works(NumericVector arr, std::string dir = "ASC" ) {
    NumericVector _arr = clone(arr);
    if(dir != "ASC") {
        std::sort(_arr.begin(), _arr.end(), std::greater<int>());
    } else {
        std::sort(_arr.begin(), _arr.end());
    }
    return _arr;
}

NumericVector _partial_sort(NumericVector arr, int p, std::string dir = "ASC") {
    NumericVector _arr = clone(arr);
    if(dir != "ASC") {
        std::nth_element(_arr.begin(), _arr.begin()+p-1, _arr.end(), std::greater<int>());
    } else {
        std::nth_element(_arr.begin(), _arr.begin()+p-1, _arr.end());
    }
    return _arr;
}

// [[Rcpp::export]]
NumericVector cpp_sort_numeric(NumericVector arr, NumericVector partial, std::string dir = "ASC") {
    NumericVector _arr = clone(arr);
    if (partial[0] == -1)  { // only positive values allowed ...
        if(dir != "ASC") {
            std::sort(_arr.begin(), _arr.end(), std::greater<int>());
        } else {
            std::sort(_arr.begin(), _arr.end());
        }
    } else {
        for (auto& p : partial) {
            _arr = _partial_sort(_arr, p, dir);
        }
    }
    return _arr;
}

/*** R
v <- c(1,2,3,2,1,0,-1,2)
cpp_sort_numeric_works(v)
cpp_sort_numeric_works(v, "DESC")
w <- v
w[1] <- -1
cpp_sort_numeric(v, w)
cpp_sort_numeric(v, w, "DESC")
*/
