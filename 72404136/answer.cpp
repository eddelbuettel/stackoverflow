#include <Rcpp.h>
#include <fstream>
using namespace Rcpp;

// [[Rcpp::export]]
Rcpp::NumericVector Rcpp_test(std::string filename, size_t size) {
    Rcpp::NumericVector v(size);
    FILE *in = fopen(filename.c_str(), "rb");
    if (in == nullptr) Rcpp::stop("Cannot open file", filename);
    auto nr = fread(&v[0], sizeof(double), size, in);
    if (nr != size) Rcpp::stop("Bad payload");
    Rcpp::Rcout << nr << std::endl;
    fclose(in);
    return v;
}

/*** R
set.seed(123)
rv <- runif(10)
filename <- "test.bin"
if (!file.exists(filename)) {
  output_file <- file(description="test.bin",open="a+b")
  writeBin(rv, output_file, size=8)
  close(output_file)
}
nv <- Rcpp_test(filename, 10)
data.frame(rv, nv)
all.equal(rv,nv)
*/
