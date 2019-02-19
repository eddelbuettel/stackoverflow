#include <Rcpp.h>
using namespace Rcpp;

//[[Rcpp::export]]
List return_a(NumericMatrix a, NumericMatrix b){
  //the function only returns the input matrix a
  List result(1);
  result(0) = a;
  return(result);
}


//[[Rcpp::export]]
List wrapper_cpp(NumericMatrix a, NumericMatrix b){
  //the function is a dummy wrapper for much more code
  List results(1);
  List Step1 = return_a(a,b);
  NumericMatrix tmp = Step1(0);
  results(0) = tmp;
  return(results);
}
