#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
NumericMatrix testFunction1(IntegerVector idx, NumericMatrix x){
    NumericMatrix temp(idx.size(),idx.size());
    for(R_len_t i=0; i< idx.size(); i++){
        for(R_len_t j=0; j< idx.size(); j++){
            temp(i,j) = R::rnorm(x(idx[i],idx[j]), 1);
        }
    }
    return temp;
}

/*** R
set.seed(42)
testFunction1(1:4, matrix(1:16, 4, 4))
*/
