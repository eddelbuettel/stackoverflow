#include <Rcpp.h>
using namespace Rcpp;
#include <stdio.h>
using namespace std;
#include <cstdlib>

// [[Rcpp::export(name = "diceNumcpp")]]
int diceNum(NumericVector iso1, NumericVector iso2){

  NumericVector is1 = clone(iso1);
  NumericVector is2 = clone(iso2);
  int n = 0;
  int m = 0;
  int match = 0;

  while (is1[n]!=0){      //issue occurs with 'n' reference
    Rcpp::Rcout << n << " " << m << std::endl;
    if (is2[m]==0){       //and again here with 'm' reference
      n++;
      m=0;
    }
    if (is1[n]!=0 && is2[m]!=0){  //same issue here with this line and the next
      if (abs(is1[n]-is2[m])/is2[m]<0.01){
        match++;
      }
      m++;
    }
  }
  return match;
}
