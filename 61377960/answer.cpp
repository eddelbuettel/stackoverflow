
#include <Rcpp.h>

using namespace Rcpp;

// [[Rcpp::export]]
NumericVector NNE(IntegerVector X, IntegerVector Y, IntegerVector XY,
                  IntegerVector xy, NumericVector P, int radius ) {

  int n = X.size();
  NumericVector vN(n);
  NumericVector vSum(n);
  NumericVector vAvg(n);

  // for each xy determine neighborhood Sum and count (N)
  for(int i=0; i<n; i++) {
    vN[i] = 0.0;
    vSum[i] = 0.0;

    // traverse neighborhood, if the xy exists in the input
    // vector then accumulate the values, otherwise ignore

    for(int dx=-1*radius; dx<=radius; dx++) {
      for(int dy=-1*radius; dy<=radius; dy++) {

        // construct an xy index for the neighborhood die
        xy[0] = ( (X[i]+dx) * 10000 ) + (Y[i]+dy);

        // check to see if index above exists in input set
        IntegerVector m = Rcpp::match(xy, XY);

        // if valid then accumulate and count
        if(m[0] != NA_INTEGER) {
          vN[i] = vN[i] + 1.0;
          vSum[i] = vSum[i] + P[ m[0] ];
        }
      }
    }

    vAvg[i] = vSum[i] / vN[i];
  }

  return vAvg;
}

/*** R
cat("Built\n")
*/
