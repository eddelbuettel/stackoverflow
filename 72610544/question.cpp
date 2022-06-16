#include <Rcpp.h>

using namespace Rcpp;

// [[Rcpp::export]]
int cpp_saveAsBin (const IntegerVector & imgData, const std::string fname) {
  FILE *outP = fopen(fname.c_str(), "wb");
  if (outP == NULL) Rcpp::stop("Cannot open file", fname);
  int res = fwrite(imgData, sizeof(int), imgData.size(), outP);
  fclose(outP);
  return (res);
}

/*** R
r <- 1:20
typeof(r)
class(r)
cpp_saveAsBin(r, "/tmp/test.raw.bin")
*/
