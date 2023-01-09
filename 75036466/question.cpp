#include <Rcpp.h>

using namespace Rcpp;

// [[Rcpp::export]]

IntegerVector fit(){
  int d[2][2][2] = {0};
  IntegerVector V = IntegerVector(Dimension(8));
  int Count = 0;
  for (int X = 0; X < 2; X++){
    for (int Y = 0; Y < 2; Y++){
      for (int Z = 0; Z < 2; Z++){
        d[X][Y][Z] = (X + 1) * (Y + 1) * (Z + 1);
        V(Count) = d[X][Y][Z];
        Count = Count + 1;
      }
    }
  }
  return V;
}
