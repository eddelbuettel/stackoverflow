
#include <Rcpp.h>

// [[Rcpp::export]]
int bar(Rcpp::List test){
    Rcpp::DataFrame df(test["df"]);
    Rcpp::IntegerVector ivec = df["A"];
    return Rcpp::sum(ivec);
}

/*** R
zz <- list(df = data.frame(A = 1:3,B=letters[1:3]),some_other_variable = 2)
bar(zz)
*/
